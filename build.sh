#!/bin/bash

# execute cmake when you using colorgcc
# CC="colorgcc /usr/bin/gcc" CXX="colorgcc /usr/bin/g++" cmake -DCMAKE_BUILD_TYPE=Debug ..

# execute cmake when you using distcc
# export DISTCC_HOSTS="localhost 10.93.114.73"
# CC="distcc /usr/bin/gcc" CXX="distcc /usr/bin/g++" cmake -DCMAKE_BUILD_TYPE=Debug ..

working_path=$PWD

echo "try to build ${working_path}"
echo "*******************************************************************************"
echo "start to generate makefile..."

#export CC=/usr/bin/clang
#export CXX=/usr/bin/clang++

cmake -E make_directory build
cmake -E chdir build cmake -DMANGO_ENABLE_EXAMPLES=on -DCMAKE_BUILD_TYPE=Debug ..

echo "*******************************************************************************"
echo "start to build project..."
cmake --build build

function exec_on_fail()
{
  echo "*******************************************************************************"
  echo "start to run $1..."

  $1
  
  if [ $? -ne 0 ]; then
    echo "build $1 fail"
    exit 1
  fi
}

# exec_on_fail make
 
function run_test()
{
  exec_on_fail "build/test/$1/mango-test-$1 $2 --gtest_color=yes"
}

run_test tags --gtest_filter=*.*
run_test hooks --gtest_filter=*.*

echo "*******************************************************************************"
echo "start to run example calc..."
build/examples/calc/calc_exec &
cucumber examples/calc

echo "*******************************************************************************"
echo "start to run example tags..."
build/examples/tags/tags_exec &
cucumber examples/tags

echo "*******************************************************************************"
echo "build ${working_path} succ"

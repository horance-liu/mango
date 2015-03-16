# Mango

Mango is the a simple implement for cucumber using C++11/14, it allows cucumber to support step definitions written in C++.

* [Mango Website](http://gitlab.com/horance/mango)

Supported Compilers:
* [LLVM] 6.0 or later.
* [GCC] 4.9 or later.
* [MSVC] not supported.

Dependces:
* [Boost](http://www.boost.org/) 1.57 or later.
* [Google Test](http://code.google.com/p/googletest/) 1.6 or later.
* [JsonCpp](https://github.com/open-source-parsers/jsoncpp) 1.6 or later

## Installation

### Update GCC to 4.9

In order to support full C++11/14 features, to update GCC to 4.9 or later.

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install gcc-4.9 g++-4.9
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.9
    sudo update-alternatives --config gcc

### Install dependces:

#### Install CMake:

    sudo apt-get install cmake
  
#### Install Boost dependces:

    sudo apt-get install libboost-thread-dev libboost-system-dev libboost-regex-dev libboost-date-time-dev libboost-test-dev

#### Install Google Test dependces:

    sudo apt-get install google-mock
    cd /usr/src/gmock/gtest
    sudo mkdir build
    cd build
    sudo cmake ..
    sudo make
    sudo mv libg* /usr/local/lib/ 
    cd ..
    sudo cp -aR include/gtest/ /usr/local/include/
    sudo ldconfig

#### Install JsonCpp:

    git clone https://github.com/open-source-parsers/jsoncpp.git
    mkdir -p build
    cd build
    cmake -DCMAKE_BUILD_TYPE=debug -DJSONCPP_LIB_BUILD_STATIC=ON -DJSONCPP_LIB_BUILD_SHARED=OFF ..
    make
    sudo make install
    sudo ldconfig

#### Install RVM:

##### For Chinese User
    
    sed -i 's!cache.ruby-lang.org/pub/ruby!ruby.taobao.org/mirrors/ruby!' ~/.rvm/config/db

    curl -L get.rvm.io | bash -s stable
    source ~/.rvm/scripts/rvm
    source ~/.bashrc
    source ~/.bash_profile

#### Install Ruby:

    rvm install 2.1.5
    
    rvm use 2.1.5
    rvm use 2.1.5 --default 

#### Install Gems:
    
    rvm gemset create cucumber
    rvm gemset use cucumber --default
    
    sudo gem install bundle
    bundle install

### Build and Install Mango:

    mkdir build
    cd build
    cmake ..
    make
    sudo make install

## Note on Patches/Pull Requests

* Fork the project.
* Run `bundle install` to install dependencies.
* Run `build.sh` to make sure all the tests are passing.
* Make your feature addition or bug fix.
* Add tests for it. This is important so I don't break it in a future version unintentionally.
* Commit, do not mess with History.md.
* Send me a pull request. Bonus points for topic branches.

## Copyright
Copyright (c) 2015-2020 Horance Liu. See LICENSE for details.
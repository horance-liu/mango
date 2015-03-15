# Mango

Mango is the a simple implement for cucumber using C++11/14, it allows cucumber to support step definitions written in C++.

* [Mango Website](http://gitlab.com/horance/mango)

Supported Compilers:
* [LLVM] 6.0 or later.
* [GCC] 1.8 or later.
* [MSVC] not supported.

Dependces:
* [Boost](http://www.boost.org/) 1.51 or later.
* [Google Test](http://code.google.com/p/googletest/) 1.6 or later.
* [JsonCpp](https://github.com/open-source-parsers/jsoncpp).

## Installation

### Install dependces:

#### Install CMake:

    sudo apt-get install cmake
  
#### Install Boost dependces:

    sudo apt-get install libboost-thread-dev libboost-system-dev libboost-regex-dev libboost-date-time-dev libboost-test-dev google-mock
    cd /usr/src/gtest && sudo cmake . && sudo cmake --build . && sudo mv libg* /usr/local/lib/ && cd -

#### Install JsonCpp:

    git clone https://github.com/open-source-parsers/jsoncpp.git
    mkdir -p build
    cd build
    cmake -DCMAKE_BUILD_TYPE=debug -DJSONCPP_LIB_BUILD_STATIC=ON -DJSONCPP_LIB_BUILD_SHARED=OFF ..
    make
    sudo make install

#### Install RVM:

    curl -L get.rvm.io | bash -s stable
    source /Users/horance/.rvm/scripts/rvm
    source ~/.bashrc
    source ~/.bash_profile

#### Install Ruby:

    rvm install 1.9.3
    
    rvm use 1.9.3
    rvm use 1.9.3 --default 

#### Install Gems:

    sudo gem install bundle
    
    rvm gemset create cucumber
    rvm gemset use cucumber
    
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
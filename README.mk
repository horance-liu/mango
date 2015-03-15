# Mango

Mango is the c++11/14 implement for cucumber, it allows cucumber to support step definitions written in C++.

* [Mango Website](http://gitlab.com/horance/mango)

It depends on a few c++ libraries:

* [Boost](http://www.boost.org/) 1.51 or later.
* [Google Test](http://code.google.com/p/googletest/) 1.6 or later.

Install dependces on Ubuntu:

```
sudo apt-get install libboost-thread-dev libboost-system-dev libboost-regex-dev libboost-date-time-dev libboost-test-dev google-mock
cd /usr/src/gtest && sudo cmake . && sudo cmake --build . && sudo mv libg* /usr/local/lib/ && cd -
```

Install Ruby dependces on Ubuntu:
```
curl -L get.rvm.io | bash -s stable
source /Users/horance/.rvm/scripts/rvm
source ~/.bashrc
source ~/.bash_profile

rvm install 1.9.3
rvm use 1.9.3
rvm use 1.9.3 --default 

bundle install
```

Build Mango:

```
./build.sh
```

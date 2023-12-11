### Introduction

A small repository which demonstrates how to install Googles Testing suite, GTest, and use it.

## Installation

* `$ sudo apt-get install libgtest-dev`
* `$ sudo apt-get install cmake`
* `$ cd /usr/src/gtest`
* `$ sudo cmake CMakeLists.txt`
* `$ sudo make`

## Testing an Application

Two files are included: to_test.cpp and test.cpp

* `$ cmake CMakeLists.txt`
* `$ make`
* `$ ./runTests`


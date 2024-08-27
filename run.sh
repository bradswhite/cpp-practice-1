#!/bin/bash

## Build program:
echo ":::::::::::: Building C++ Program with dependencies  :::::::::::::::"
echo "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
echo "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
# cmd also found in readme:
clang++ main.cpp person/person.cpp people/people.cpp -std=c++17 -o main

## Run program:
echo "::::::::::::::::::::  Running C++ Program  :::::::::::::::::::::::::"
echo "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
echo "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
./main

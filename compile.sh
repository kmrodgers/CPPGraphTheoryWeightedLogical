#!/bin/bash

rm -r output_data
g++ -c Engine.cc
g++ -c Node.cc
g++ -c PetersenGraph.cc
g++ -c CompleteGraph.cc
g++ -c Hypercube2.cc
g++ -c Hypercube3.cc
g++ -c Hypercube4.cc
g++ -c Token.cc
g++ -c RandomEngine.cc
g++ *.o main.cc -o main
mkdir -p output_data

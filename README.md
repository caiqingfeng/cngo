# Golang calls c/c++ (mostly inside a library) and vice visa. 

## Problem
If your Golang program wants to call some APIs implemented in a C/C++ library, such as opencv/dlib, 
there are some solutions and all of them are very straightforward. But if your library is an event-driven style which means a lot of
callbacks are needed, the problem is then more complicated.

Here is the problem needs to be solved:
A golang program calls a c/c++ library with a callback fuction pointer as one of the parameters, the c/c++ api (inside the library of course)
is triggered and calls the golang callback function.

## Solution

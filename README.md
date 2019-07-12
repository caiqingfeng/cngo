# Golang calls c/c++ (mostly inside a library) and vice visa. 

## Problem
If your Golang program wants to call some APIs implemented in a C/C++ library, such as opencv/dlib, 
there are some solutions and all of them are very straightforward. But if your library is an event-driven style which means a lot of
callbacks are needed, the problem is then more complicated.

Here is the problem needs to be solved:
A golang program calls a c/c++ library with a callback fuction pointer as one of the parameters, the c/c++ api (inside the library of course)
is triggered and calls the golang callback function.

## Solution
### make a c++ lib
```
the clib folder is used to generate a c++ library
it is very simple:

class CppFoo
{
public:
    void CppNoParameter();
    void CppIntParameter(int i);
    void CppStringParameter(std::string& s);
    void CppFuncParameter(callback1 f);
};

The file clib.cpp is also straightforward to implement the class member functions.

```
### case1: use cgo to call a c++ api
#### the key trick is wrapper 
```
the folder gobinding is a wrapper for golang program.
$ ls gobinding
lib  Makefile  obj  src  wrapper

$ ls gobinding/src
gobinding.cpp  gobinding.h

$ ls gobinding/wrapper
wrapper.go

$ cat gobinding/wrapper/wrapper.go
/*
#include "../src/gobinding.h"
#include <stdlib.h>
#cgo LDFLAGS: -L${SRCDIR}/../../gobinding/lib -lgobinding -L${SRCDIR}/../../clib/lib -lclib
#cgo LDFLAGS: 
*/
import "C"

//"fmt"

func CppNoParameter() {
	C.CppNoParameter()
}

It is all about cgo features and is easy to find explaination.

$ cat cngo/main.go
package main

import (
	"cngo/gobinding/wrapper"
	"fmt"
)

func main() {
	fmt.Printf("inside main\n")
	wrapper.CppNoParameter()
}

$ ./run_cngo.sh
inside main
CppNoParameter triggered 

```

### case2: pass a func pointer to c++ 

package wrapper

//package main

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

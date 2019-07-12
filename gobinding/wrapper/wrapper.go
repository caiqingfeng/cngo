package wrapper

//package main

/*
#include "../src/gobinding.h"
#include <stdlib.h>
#cgo LDFLAGS: -L${SRCDIR}/../../clib/lib -lclib -L${SRCDIR}/../../gobinding/lib -lgobinding
*/
import "C"

//"fmt"

func CppNoParameter() {
	C.CppNoParameter()
}

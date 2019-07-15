package wrapper

//package main

/*
#include "../src/gobinding.h"
#include <stdlib.h>
#cgo LDFLAGS: -L${SRCDIR}/../../gobinding/lib -lgobinding -L${SRCDIR}/../../clib/lib -lclib
#cgo LDFLAGS:
*/
import "C"
import "fmt"

func CppNoParameter() {
	fmt.Printf("wrapper.CppNoParameter triggered\n")
	C.CppNoParameter()
}

func CppCallbackGo() {
	fmt.Printf("wrapper.CppCallbackGo triggered\n")
	C.CppCallbackGo()
}

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
import "unsafe"

func CppNoParameter() {
	fmt.Printf("wrapper.CppNoParameter triggered\n")
	C.CppNoParameter()
}

func CppCallbackGo(CallbackGo interface {}) {
	fmt.Printf("wrapper.CppCallbackGo triggered\n")
	f := CallbackGo
	C.CppCallbackGo(C.callback1(unsafe.Pointer(&f)))
}

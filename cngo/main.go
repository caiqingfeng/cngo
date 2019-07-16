package main

/*
#include "gobinding.h"
#include <stdlib.h>
#cgo LDFLAGS: -L${SRCDIR}/../clib/lib -lclib
*/
import "C"
import (
	"fmt"
)

//export CallbackGo
func CallbackGo() C.int {
	fmt.Printf("inside CallbackGo \n")
	return C.int(0)
}

func main() {
	fmt.Printf("inside main\n")

	C.CppCallbackGo()
}

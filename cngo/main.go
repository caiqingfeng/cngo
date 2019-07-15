package main

import (
	"C"
	"cngo/gobinding/wrapper"
	"fmt"
)

/*
 */
//export CallbackGo
func CallbackGo() C.int {
	fmt.Printlf("inside CallbackGo \n")
	return 0
}

func main() {
	fmt.Printf("inside main\n")
	wrapper.CppNoParameter()

	wrapper.CppCallbackGo()
}

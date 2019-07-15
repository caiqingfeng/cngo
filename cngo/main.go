package main

import (
	"C"
	"cngo/gobinding/wrapper"
	"fmt"
)

//export CallbackGo
func CallbackGo() C.int {
	fmt.Printf("inside CallbackGo \n")
	return C.int(0)
}

func main() {
	fmt.Printf("inside main\n")
	wrapper.CppNoParameter()

	f := CallbackGo
	wrapper.CppCallbackGo(&f)
}

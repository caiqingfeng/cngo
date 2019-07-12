package main

import (
	"cngo/gobinding/wrapper"
	"fmt"
)

func main() {
	fmt.Printf("inside main")
	wrapper.CppNoParameter()
}
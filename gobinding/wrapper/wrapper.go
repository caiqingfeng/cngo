package wrapper
//package main

/*
#include "../src/gobinding.h"
#include <stdlib.h>
#cgo LDFLAGS: -L${SRCDIR}/../../lib -lctpgo -lthosttraderapi_se -L${SRCDIR}/../../lib -lthostmduserapi_se
*/
import "C"
import (
	//"fmt"
	"unsafe"
)

func ConnectTrading() int {
	C.ConnectTrading()
	return 0
}

//func CallBackGo() int {
	//fmt.Printf("inside callback...")
	//return 0
////}

func ConnectMd() int {
	//f := CallBackGo
	//C.SetCallBack(unsafe.Pointer(&f))
	C.ConnectMd()
	return 0
}

func QueryInstrument(inst string) int {
	cpinst := C.CString(inst)
	defer C.free(unsafe.Pointer(cpinst))
	C.QueryInstrument(cpinst)
	return 0
}

//func main() {
//}

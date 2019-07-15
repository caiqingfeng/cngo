// 
//
#include "clib.h"
#include "gobinding.h"
#include <iostream>
#include <string.h>
//#include "libcngo.h"
extern "C" int CallbackGo();

using namespace std;

void CppNoParameter()
{
	CppFoo c;
	c.CppNoParameter();
}

int CppCallbackGo(callback1 f)
{
	CallbackGo();
	//(*f)();
	return 0;	
}


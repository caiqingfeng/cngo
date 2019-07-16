#ifndef _C_LIB_H
#define _C_LIB_H

#include <string>

typedef int (*callback1)();

class CppFoo
{
public:
    void CppNoParameter();
    void CppIntParameter(int i);
    void CppStringParameter(std::string& s);
    void CppFuncParameter(callback1 f);
};
#endif
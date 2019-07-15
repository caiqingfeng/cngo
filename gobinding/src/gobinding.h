#ifndef GOBINDING_H
#define GOBINDING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*callback1)();

void CppNoParameter();
void CppFuncParameter(callback1 f);
int CppCallbackGo();

#ifdef __cplusplus
}
#endif

#endif

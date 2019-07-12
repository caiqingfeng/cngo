#ifndef GOBINDING_H
#define GOBINDING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*onBarCallback)();

void ConnectTrading();
void QueryInstrument(const char* inst);
void ConnectMd();
//void SetCallBack(onBarCallback f);
void SetCallBack(void *f);

#ifdef __cplusplus
}
#endif

#endif

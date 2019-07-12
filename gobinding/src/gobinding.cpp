// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include "ThostFtdcTraderApi.h"
#include "TraderSpi.h"
#include "MdSpi.h"
#include "gobinding.h"
#include <iostream>
#include <string.h>
// #include "_cgo_export.h"

using namespace std;

// UserApi对象
CThostFtdcTraderApi* pTradeApi;
CThostFtdcMdApi* pUserApi;

// 请求编号
int iRequestID = 0;

// 配置参数
char FRONT_ADDR[] = "tcp://180.169.50.131:42213";		// 前置地址
char TradeFRONT_ADDR[] = "tcp://180.169.50.131:42205";
TThostFtdcBrokerIDType	BROKER_ID = "2071";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "50016574";			// 投资者代码
TThostFtdcPasswordType  PASSWORD = "gtja4404";			// 用户密码
char *ppInstrumentID[] = {"j1909", "i1909"};			// 行情订阅列表
TThostFtdcInstrumentIDType INSTRUMENT_ID = "i1909";	// 合约代码 ，注意与时俱进改变合约ID,避免使用过时合约

int iInstrumentID = 1;									// 行情订阅数量
char APP_ID[] = "client_N190621CQF_1.0";
char AUTH_CODE[] = "20190621CQFO0001";								// 行情订阅数量
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 2380;				// 价格

onBarCallback cf = NULL;
// void *cf = NULL;

void ConnectTrading()
{
	std::cerr << "inside connect" << std::endl;

	// 初始化UserApi
	pTradeApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pTradeApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	//pTradeApi->SubscribePublicTopic(TERT_RESTART);					// 注册公有流
	//pTradeApi->SubscribePrivateTopic(TERT_RESTART);					// 注册私有流
	pTradeApi->RegisterFront(TradeFRONT_ADDR);							// connect
	pTradeApi->Init();

	pTradeApi->Join();
//	pTradeApi->Release();

}

void ConnectMd()
{
	std::cerr << "inside ConnectMd" << std::endl;

	// 初始化UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi((CThostFtdcMdSpi*)pUserSpi);			// 注册事件类
	//pUserApi->SubscribePublicTopic(TERT_RESTART);					// 注册公有流
	//pUserApi->SubscribePrivateTopic(TERT_RESTART);					// 注册私有流
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();

}

void QueryInstrument(const char* inst)
{
	cerr << "--->>> 请求查询合约: " << inst << endl;
	CThostFtdcQryInstrumentField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.InstrumentID, inst);
	int iResult = pTradeApi->ReqQryInstrument(&req, ++iRequestID);
	cerr << "--->>> 请求查询合约: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

//void SetCallBack(onBarCallback f)
void SetCallBack(void *f)
{
	cf = (onBarCallback)f;
	if (!cf) return;
//	(cf)();
}

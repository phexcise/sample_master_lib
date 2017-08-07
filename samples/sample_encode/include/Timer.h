
#ifndef  _TIMER_H__
#define  _TIMER_H__
#include < windows.h >
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
	double m_dTotalTime;
	double m_dAvgTime;
	double m_dTime;
	__int64 m_wCount;
	LARGE_INTEGER m_lFeq;
	LARGE_INTEGER m_lCount1;
	LARGE_INTEGER m_lCount2;
}CMyTimer;

__inline void 
MyTimerInit(CMyTimer *time)
{
	time->m_dTotalTime = 0;
	time->m_dAvgTime = 0;	
	time->m_dTime = 0;
	time->m_wCount = 0;
}

__inline void 
MyTimerStart(CMyTimer *time)
{
	QueryPerformanceFrequency(&time->m_lFeq);					
	QueryPerformanceCounter(&time->m_lCount1);

}
__inline void 
MyTimerEnd(CMyTimer *time)
{
	QueryPerformanceCounter(&time->m_lCount2);	
	{
		__int64 liTime = time->m_lCount2.QuadPart - time->m_lCount1.QuadPart;	
		time->m_dTime = ((double)liTime/(double)time->m_lFeq.QuadPart)*1000;
		time->m_wCount++;
		time->m_dTotalTime += time->m_dTime;
		time->m_dAvgTime = time->m_dTotalTime / time->m_wCount;
	}
	
	return ;
}
#if 1
//extern CMyTimer ustm;// = {0};
#define GS MyTimerStart(&ustm);
#define E	MyTimerEnd(&ustm);\
			printf("");//	printf("cT=%4.1fms(aT:%4.2f) ",ustm.m_dTime,ustm.m_dAvgTime);

#define TIME_LIME	0
#define DisplayInfo0	if(ustm.m_dTime > TIME_LIME)\
						{\
						printf("vcId %d: %d f; cT=%4.1fms(aT:%4.2f) \n",id, readFrameCnt, ustm.m_dTime,ustm.m_dAvgTime);\
						}
#endif

#ifdef __cplusplus
}
#endif

#endif

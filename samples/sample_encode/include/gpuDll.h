///////////////////////////////////////////////////////////////////////////
// VARender SDK								 //	
// Copyright (c) 2011  beijing bohui co,. ltd//
// 视音频播放SDK：视频输入YUV420P，音频输入PCM
/////////////////////////////////////////////////////////////////////////// 

#ifndef GPUDLL_H
#define GPUDLL_H

#define GPU_DLL

typedef struct
{
	char *arg0;
	TCHAR *arg1;
	//
	int width;
	int height;
	int gopSize;
	int frameRate;
	int bitsRate;
	char *speed;
	char *encType;
	//
	char *inFormat;
	char *outFormat;
	//
	char *inFile;
	char *outFile;
	//
}InPutParams;

#ifndef GPU_DLL
#define DLLEXPORT_API  extern "C"__declspec(dllimport) 
#else
#define DLLEXPORT_API  extern "C"__declspec(dllexport) 
#endif


#if 0
//初始化
DLLEXPORT_API int __stdcall Init(PVOID& hVideoDevice);
//反初始化
DLLEXPORT_API int __stdcall Unit();
//开始编码
DLLEXPORT_API int __stdcall START_SHARE_RECORD(UINT iRecNum);
//停止编码
DLLEXPORT_API int __stdcall STOP_SHARE_RECORD(UINT iRecNum);
//注册回调函数
//DLLEXPORT_API int __stdcall REGISTER_SHARE_RECORD_CALLBACK(UINT iRecNum /*IN*/, PF_VIDEO_SHARE_RECORD_CALLBACK pVB /*IN*/, PF_AUDIO_SHARE_RECORD_CALLBACK pAB /*IN*/, PVOID pUserData /*IN*/ );
DLLEXPORT_API int __stdcall REGISTER_VIDEO_SHARE_RECORD_CALLBACK(UINT iRecNum /*IN*/, void *pV /*IN*/, PVOID pUserData /*IN*/ );
DLLEXPORT_API int __stdcall REGISTER_AUDIO_SHARE_RECORD_CALLBACK(UINT iRecNum /*IN*/, void *pA /*IN*/, PVOID pUserData /*IN*/ );
//原始YUV回调函数中使用下面函数添加数据到SHARE_RECORD中
DLLEXPORT_API int __stdcall SET_VIDEO_SHARE_RECORD_UNCOMPRESSION_BUFFER(PVOID pDevice, UINT iRecNum, UINT nVideoWidth,UINT nVideoHeight, BYTE* pFrameBuffer, ULONG nFrameBufferLen, double dSampleTime);
//原始PCM回调函数中使用下面函数添加数据到SHARE_RECORD中
DLLEXPORT_API int __stdcall SET_AUDIO_SHARE_RECORD_UNCOMPRESSION_BUFFER( PVOID pDevice, UINT iRecNum, BYTE* pFrameBuffer, ULONG nFrameBufferLen, double dSampleTime );
//设置视频编码参数
DLLEXPORT_API int __stdcall SET_VIDEO_SHARE_RECORD_PROPERTY( UINT iRecNum ,UINT nEncType,  ULONG   nWidth /*IN*/,  ULONG   nHeight /*IN*/,  ULONG   nFrameRate /*IN*/,ULONG   nQuality /*IN*/, ULONG   nBitRate /*IN*/,  ULONG   nGOP /*IN*/ );
//设置音频编码参数
DLLEXPORT_API int __stdcall SET_AUDIO_SHARE_RECORD_PROPERTY( UINT iRecNum ,UINT nEncType,  ULONG   nChannels /*IN*/,  ULONG   nBitsPerSample /*IN*/,  ULONG   nSampleFrequency /*IN*/,  ULONG   nVolume /*IN*/  );
#endif
  
DLLEXPORT_API void * __stdcall Create(void *handle);
DLLEXPORT_API int __stdcall Init(void *handle, void *inParam);
DLLEXPORT_API int __stdcall FeedData(void *handle, char *yuvBuf, int len);
DLLEXPORT_API int __stdcall GetStream(void *handle, char *strBuf, int &bitsNum, int &frameType);
DLLEXPORT_API int __stdcall Close(void *handle);

#endif
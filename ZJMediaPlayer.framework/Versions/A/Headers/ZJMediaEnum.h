//
//  ZJMediaEnum.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/2.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#ifndef ZJMediaEnum_h
#define ZJMediaEnum_h

/*视频设置的可选参数*/
typedef enum {
    ZJ_MEDIA_OPT_FORMAT = 0,
} ZJ_MEDIA_OPT_TYPE;

/*转换前的编码格式*/
typedef enum {
    ZJ_MEDIA_TYPE_NONE = 0,
    ZJ_MEDIA_TYPE_H264,     //H264
    ZJ_MEDIA_TYPE_HEVC,         //H265
    ZJ_MEDIA_TYPE_YUV420P,
    ZJ_MEDIA_TYPE_RGB24,
    
    ZJ_MEDIA_TYPE_AAC,
    ZJ_MEDIA_TYPE_PCM,
    
    ZJ_MEDIA_TYPE_MAX
} ZJ_MEDIA_TYPE;

/*转换后的帧格式*/
typedef enum {
    ZJ_FMT_TYPE_NONE = 0,
    ZJ_FMT_TYPE_YUV420P,
    ZJ_FMT_TYPE_RGB24,

    ZJ_FMT_TYPE_PCM,
    
    ZJ_FMT_TYPE_MAX
} ZJ_FMT_TYPE;

#ifndef H264_NALU_TYPE_DEF
#define H264_NALU_TYPE_DEF
//H264帧片类型
typedef enum {
    H264_NALU_TYPE_NONE     = 0,
    H264_NALU_TYPE_SLICE    = 1,
    H264_NALU_TYPE_DPA      = 2,
    H264_NALU_TYPE_DPB      = 3,
    H264_NALU_TYPE_DPC      = 4,
    H264_NALU_TYPE_IDR      = 5,
    H264_NALU_TYPE_SEI      = 6,
    H264_NALU_TYPE_SPS      = 7,
    H264_NALU_TYPE_PPS      = 8,
    H264_NALU_TYPE_AUD      = 9,
    H264_NALU_TYPE_EOSEQ    = 10,
    H264_NALU_TYPE_EOSTREAM = 11,
    H264_NALU_TYPE_FILL     = 12,
    H264_NALU_TYPE_PREFIX   = 14,
    H264_NALU_TYPE_SUB_SPS  = 15,
    H264_NALU_TYPE_SLC_EXT  = 20,
    H264_NALU_TYPE_VDRD     = 24,
    
    H264_NALU_TYPE_P        = H264_NALU_TYPE_SLICE,    //帧值&0x1F=0x1是为P帧
    H264_NALU_TYPE_B        = 0x100,    //帧值为0x1是为B帧
} H264_NALU_TYPE;
#endif

#ifndef AUDIO_SAMPLERATE_TYPE_DEF
#define AUDIO_SAMPLERATE_TYPE_DEF
//Audio采样率类型
typedef enum {
    AUDIO_SAMPLERATE_TYPE_7K = 7350,
    AUDIO_SAMPLERATE_TYPE_8K = 8000,
    AUDIO_SAMPLERATE_TYPE_11K = 11025,
    AUDIO_SAMPLERATE_TYPE_12K = 12000,
    AUDIO_SAMPLERATE_TYPE_16K = 16000,
    AUDIO_SAMPLERATE_TYPE_22K = 22050,
    AUDIO_SAMPLERATE_TYPE_24K = 24000,
    AUDIO_SAMPLERATE_TYPE_32K = 32000,
    AUDIO_SAMPLERATE_TYPE_44K = 44100,
    AUDIO_SAMPLERATE_TYPE_48k = 48000,
    AUDIO_SAMPLERATE_TYPE_64K = 64000,
    AUDIO_SAMPLERATE_TYPE_88K = 88200,
    AUDIO_SAMPLERATE_TYPE_96K = 96000,
} AUDIO_SAMPLERATE_TYPE;
#endif

//播放状态枚举
typedef enum {
    ZJ_MEDIA_PLAY_STATUS_NONE = 0,
    ZJ_MEDIA_PLAY_STATUS_PREPARE,                //准备播放
    ZJ_MEDIA_PLAY_STATUS_START,                  //正在播放
    ZJ_MEDIA_PLAY_STATUS_LOADING,                //正在加载
    ZJ_MEDIA_PLAY_STATUS_LOADED,                 //加载结束
    ZJ_MEDIA_PLAY_STATUS_ERROR,                  //播放错误，不一定是播放失败
    ZJ_MEDIA_PLAY_STATUS_STOP,                   //播放结束
    ZJ_MEDIA_PLAY_STATUS_FAILED,                 //播放失败
} ZJ_MEDIA_PLAY_STATUS;

//视频录制枚举
typedef enum {
    ZJ_MEDIA_RECORD_STATUS_NONE = 0,
    ZJ_MEDIA_RECORD_STATUS_START,               //开始录制
    ZJ_MEDIA_RECORD_STATUS_COMPLETE,            //录制完成
    ZJ_MEDIA_RECORD_STATUS_FAILED,              //录制失败
    
    ZJ_MEDIA_RECORD_STATUS_RECORDING,           //正在录制
    ZJ_MEDIA_RECORD_STATUS_PATH_INVALID,         //路径无效
    ZJ_MEDIA_RECORD_STATUS_VIDEO_NO_START,      //未开始播放视频
    ZJ_MEDIA_RECORD_STATUS_NO_START,            //录制未真正开始
    ZJ_MEDIA_RECORD_STATUS_NO_PERMISSION,       //无系统权限
} ZJ_MEDIA_RECORD_STATUS;

//对讲状态枚举
typedef enum {
    ZJ_MEDIA_TALK_STATUS_NONE = 0,
    ZJ_MEDIA_TALK_STATUS_PREPARE,                //准备播放
    ZJ_MEDIA_TALK_STATUS_START,                  //正在播放
    ZJ_MEDIA_TALK_STATUS_STOP,                   //播放结束
    ZJ_MEDIA_TALK_STATUS_FAILED,                 //对讲失败
    ZJ_MEDIA_TALK_STATUS_NO_PERMISSION,          //无麦克风权限
} ZJ_MEDIA_TALK_STATUS;

//多媒体音视频裸流参数配置
typedef struct ZJMediaStreamConfig {
    ZJ_MEDIA_TYPE videoMediaType;       //自定义编码ID
//    ZJ_FMT_TYPE videoFrameFormat;       //需要转换的帧格式
    int videoFrameRate;
    int64_t videoBitRate;

    ZJ_MEDIA_TYPE audioMediaType;       //自定义编码ID
//    ZJ_FMT_TYPE audioFrameFormat;       //需要转换的帧格式
    int audioSampleRate;
    int64_t audioBitRate;
    int audioChannels;
} ZJMediaStreamConfig;


#endif /* ZJMediaEnum_h */

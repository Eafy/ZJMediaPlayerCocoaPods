//
//  ZJMediaStatisticalInfo.h
//  ZJMediaPlayer
//
//  Created by eafy on 2021/6/15.
//  Copyright © 2021 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 视频播放信息(每秒更新1次)
@interface ZJMediaStatisticalInfo : NSObject

@property (nonatomic,assign) NSInteger videoWidth;          //视频宽度
@property (nonatomic,assign) NSInteger videoHeight;         //视频高度
@property (nonatomic,assign) NSInteger videoFPS;            //视频帧率
@property (nonatomic,assign) NSInteger videoBps;            //视频码率(s/Bps)
@property (nonatomic,assign) NSInteger audioBps;            //音频码率(s/Bps)
@property (nonatomic,assign) NSInteger totalTime;           //总时间（毫秒）
@property (nonatomic,assign) NSInteger timestamp;           //时间戳（毫秒）
@property (nonatomic,assign) NSInteger videoTotalFrame;     //视频总帧数
@property (nonatomic,assign) NSInteger videoDropFrame;      //视频丢帧数
@property (nonatomic,assign) NSInteger onlineCount;         //在线人数（网络流、文件播放等无效）

/// SEI版本号
@property (nonatomic,assign) NSInteger seiVersion;
/// 流类型，0：无卡直播，1：直播有卡，2：普通回放有卡，3：告警回放有卡
@property (nonatomic,assign) NSInteger streamType;
/// SEI信息中的时间戳
@property (nonatomic,assign) NSInteger seiTs;
/// 视频质量信息
@property (nonatomic,assign) NSInteger quality;


@end


NS_ASSUME_NONNULL_END

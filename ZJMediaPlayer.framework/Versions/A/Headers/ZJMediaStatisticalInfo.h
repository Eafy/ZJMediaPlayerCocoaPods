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
@property (nonatomic,assign) NSInteger videoBps;            //视频码率(s/Bps)
@property (nonatomic,assign) NSInteger audioBps;            //音频码率(s/Bps)
@property (nonatomic,assign) NSInteger timestamp;           //时间戳
@property (nonatomic,assign) NSInteger videoTotalFrame;     //视频总帧数
@property (nonatomic,assign) NSInteger videoDropFrame;      //视频丢帧数
@property (nonatomic,assign) NSInteger onlineCount;         //在线人数（网络流、文件播放等无效）


@end

NS_ASSUME_NONNULL_END

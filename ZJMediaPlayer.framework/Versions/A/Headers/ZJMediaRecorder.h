//
//  ZJMediaRecorder.h
//  ZJMediaPlayer
//
//  Created by eafy on 2021/10/10.
//  Copyright © 2021 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaRecorderConfig : NSObject

@property (nonatomic,assign) NSInteger videoCodecId;
@property (nonatomic,assign) NSInteger videoWidth;
@property (nonatomic,assign) NSInteger videoHeight;
@property (nonatomic,assign) NSInteger videoFrameRate;
/// 视频比特率，一般不用设置
@property (nonatomic,assign) NSInteger videoBitRate;

@property (nonatomic,assign) NSInteger audioCodecId;
@property (nonatomic,assign) NSInteger audioSampleRate;
@property (nonatomic,assign) NSInteger audioChannels;
@property (nonatomic,assign) NSInteger audioBitRate;

/// 是否是图片不连续模式，即间隔时间不确定
@property (nonatomic,assign) BOOL isSinglePicMode;

@end

@interface ZJMediaRecorder : NSObject

@property (nonatomic,strong,readonly) ZJMediaRecorderConfig *config;

/// 配置录制参数
/// @param config 配置信息
- (void)config:(ZJMediaRecorderConfig *)config;

/// 开始录制
/// @param filePath 本地沙盒视频地址
- (BOOL)start:(NSString *)filePath;

/// 停止录制
- (BOOL)stop;

/// 写入视频数据（RGB24）
/// @param rgb24Data RGB24数据
/// @param width 画面宽度，若为0，使用config
/// @param height 画面高度，若为0，使用config
/// @param timestamp 时间戳，为0表示自动
/// @param isKeyFrame 是否是关键帧
- (BOOL)writeVideo:(uint8_t *)rgb24Data width:(NSInteger)width height:(NSInteger)height timestamp:(NSInteger)timestamp isKeyFrame:(BOOL)isKeyFrame;

/// 写入UIImage
/// @param image UIImage
/// @param timestamp 时间戳，为0表示自动
- (BOOL)writeImage:(UIImage *)image timestamp:(NSInteger)timestamp;

/// 写入音频数据
/// @param data 数据
/// @param size 大小
/// @param timestamp 时间戳
- (BOOL)writeAudio:(uint8_t *)data size:(NSInteger)size timestamp:(NSInteger)timestamp;

/// 已录制的视频时长
- (NSInteger)duration;

/// 是否正在录制
- (BOOL)isRecording;

@end

NS_ASSUME_NONNULL_END

//
//  ZJAudioSessionManager.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/20.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZJAudioSessionMode) {
    ZJAudioSessionModeOff,
    ZJAudioSessionModeSpeaker,              //播放，混音独占模式
    ZJAudioSessionModeSpeakerSoloAmbient,   //播放，独占模式
    ZJAudioSessionModeMicrophone,           //录制，可作为播放：听筒模式，播放混音独占
    ZJAudioSessionModeMicrophoneSpeaker,    //录制，可作为播放：免提模式，播放独占
};

@interface ZJAudioSessionManager : NSObject

+ (instancetype _Nonnull)shared;

- (void)openAudio:(ZJAudioSessionMode)mode handler:(void(^_Nullable)(BOOL success))handler;

- (void)closeAudio:(ZJAudioSessionMode)mode;

@end

NS_ASSUME_NONNULL_END

# ZJMediaPlayer

| Plaform | Version | Build Status | License |
| :-----: | :----------: | :-----: | :-----: |
|   [![Platform](https://img.shields.io/cocoapods/p/ZJMediaPlayer.svg?style=flat)](https://cocoapods.org/pods/ZJMediaPlayer)    |    [![Version](https://img.shields.io/cocoapods/v/ZJMediaPlayer.svg?style=flat)](https://cocoapods.org/pods/ZJMediaPlayer)         |    [![CI Status](https://img.shields.io/travis/Eafy/ZJMediaPlayer.svg?style=flat)](https://travis-ci.org/Eafy/ZJMediaPlayer)      |  [![License](https://img.shields.io/cocoapods/l/ZJMediaPlayer.svg?style=flat)](https://cocoapods.org/pods/ZJMediaPlayer)     | 
| [![Platform](https://img.shields.io/badge/platform-Android-lightgrey.svg)](https://img.shields.io/badge/platform-Android-lightgrey.svg) |  <a href='https://search.maven.org/search?q=g:io.github.eafy%20AND%20a:ZJMediaPlayer'><img src='https://img.shields.io/maven-central/v/io.github.eafy/ZJMediaPlayer.svg'></a>     |     <a href='https://travis-ci.org/Eafy/ZJMediaPlayer/builds'><img src='https://api.travis-ci.org/Eafy/ZJMediaPlayer.svg'></a>     |   [![License](https://img.shields.io/cocoapods/l/ZJMediaPlayer.svg?style=flat)](https://cocoapods.org/pods/ZJMediaPlayer)      |


**商业授权请联系**：lizhijian_21@163.com

- 支持iOS和Android平台，具备基本一致的功能和接口；
- 支持RTMP、RTSP、HLS、本地视频和裸流数据播放；
- 支持常见的H.264、HEVC、AAC、PCM、SPEEX等格式播放；
- 支持软硬件解码；
- 支持网络视频流秒播；
- 支持视频录制、视频截屏，具备图片合成视频功能；
- 支持音频降噪和音频增益功能；
- 支持其他各种功能定制；


## 更新日志

**V1.6.3【2024.01.19】**

`1、修复Android播放本地视频之后，再播放带自定义SEI的网络视频出现闪退的问题；`

**V1.7.2【2024.01.16】**

```
1、解决ZJGLMonitor调用clear可能无法清除画面的问题；
2、优化OpenGL，内部调整为子线程+帧队列模式进行绘制；
3、解决Android竖横屏切换时，画面比例显示错误及手势缩放异常；
```

**V1.7.1【2024.01.05】**

```
1、修复播放网络视频流因判断流类型错误导致异常卡顿的问题；
2、修复拉取网络实时流缓存队列处理异常导致可能卡顿问题；
3、新增Loading缓存模式，使用setMediaLoadMode接口；
4、优化视频录制功能，修复编码比例与显示比例不一致时导致的视频画面比例异常等问题；
```

**V1.7.0【2023.12.04】**

```
1、支持网络视频流秒播功能；
2、支持开始无音频信息，中途拉到音频数据时可播放；
3、修复iOS画面大小改变时，可能闪黑屏的问题；
4、播放画面支持双击、平移、缩放手势操作；
5、优化同步模式下卡顿之后的播放效果；
6、新增同步模式下可设置音视频相同延迟时间接口；
```

**V1.6.9【2023.11.02】**

```
1、优化文件只有视频或音频时，时间戳异常导致声音播放异常的问题；
2、优化Android音频播放器，新增缓存策略；
3、优化播放文件模式时，少部分音频未正常播放的问题；
```

**V1.6.8【2023.10.30】**

```
1、修复v1.6.7版本iOS播放黑屏问题；
2、修复iOS seek时内存暴涨问题；
3、优化暂停和恢复播放功能；
4、iOS新增mp4文件转码器；
5、修复iOS初始化时可能卡一下主线程的问题；
6、修复Android反复开始/停止导致音频播放器闪退的问题；
7、修复对讲停止时，采集模块可能未正常停止的问题；
8、修复正在打开网络视频流时退出，可能会卡一下的问题；
9、修复Android显示视图因OpenGL数据释放异常导致闪退的问题；
10、修复Android重复开始/退出导致锁死卡主问题；
11、优化前后台切换逻辑，后台时不再更新画面和音频播放；
12、修复本地视频文件只有视频或音频时，且时间戳异常导致播放异常的问题；
```

**V1.6.7【2023.10.19】**

```
1、优化音视频同步与不同步功能，使画面更加流畅；
2、支持市面上大部分视频格式及流协议；
3、优化视频文件定位播放不准的问题；
4、修复Android音频推流快速调用开始/停止可能闪退的问题；
5、修复视频录制功能可能异常的问题；
6、Seek支持视频播放完之后再次定位播放；
7、修复iOS OPENGL绘制View连续创建和释放可能闪退的问题；
8、修复iOS在播放完成之后，不调用stop的情况下，再次start导致内存暴涨的问题；
9、修复iOS画面View的frame改变时，出现黑屏现象；
10、修复部分闪退问题；
```

**V1.6.5~1.6.6【2023.08.23】**

```
1、优化音视频同步功能；
2、修复部分文件播放完后无法正常终止的问题；
```

**V1.6.4【2023.05.31】**

```
1、修复iOS快速反复播放和停止导致音频播放器释放异常导致的闪退问题；
```

**V1.6.3【2023.02.17】**
```
1、优化AEC音频播放模块启动结果异步回调；
2、ZJAudioSessionManager切换音频模式使用异步回调；
3、修复音频权限申请异步回调多次的问题；
4、优化文件和网络视频流拉流结束后会立即中断播放导致部分音频文件未播放的问题；
5、支持ADPCM格式音频；
```

**V1.6.2【2023.01.04】**
```
1、修复快速重复调用重播restart接口导致闪退的问题；
2、修复Android端快速/停止播放导致闪退的问题；
```

**V1.6.1【2023.01.03】**
```
1、修复播放自动停止时可能导致闪退的问题；
2、修复播放部分网络视频流文件失败的问题；
```

**V1.6.0【2023.01.02】**
```
1、修复连续、频繁、快速进行播放及停止可能导致闪退的问题；
2、修复线程池野地址导致的闪退问题；
```

**V1.5.7~1.5.10【2022.12.23】**
```
1、新增ZJ_MEDIA_OPT_FORMAT的drop_first_bad_frame参数，解决部分视频首次坏I帧导致播放花屏的问题；
2、新增ZJ_MEDIA_OPT_FORMAT的drop_bad_frame参数，解决部分视频持续坏I帧导致播放花屏的问题；
3、修复启动音视频同步时，存在视频残留帧导致无法正常停止及上报状态的问题；
4、修复音频转码停止的时候闪退的问题；
```

**V1.5.6【2022.11.17】**
```
1、新增SEI信息获取接口和回调；
2、优化播放器内部性能；
```

**V1.5.5【2022.11.05】**
```
1、修复停止播放卡死的问题；
```

**V1.5.4【2022.11.02】**
```
1、新增RTMP音频采集+推流集成模块: ZJAudioRtmpTalker；
2、优化并解决播放器中的部分异常问题；
```

**V1.5.2~1.5.3【2022.10.13】**
```
1、修复录制非AAC音频时，获取录制时长错误的问题；
2、修复音频模式切换异常导致麦克风录制之后扬声器播放异常的问题；
```

**V1.5.0~1.5.1【2022.10.08】**
```
1、修复iOS部分视频播放画面出现条形纹的问题；
2、优化快速切换音视频播放时，偶尔结束音异常的问题；
```

**V1.4.7【2022.09.27】**
```
1、修复解复用器停止时死锁导致的闪退问题；
2、优化读取器在读取其他媒体轨道数据时的休眠间隔；
```

**V1.4.1~1.4.6【2022.06.29】**
```
1、优化iOS音频播放器，优化播放、采集及回音消除功能；
2、iOS新增AGC增益功能；
3、Android新增录制的回音消除功能；
4、音频播放器修改为ZJAudioAECPlayer，集成采集功能；
5、修复Android部分视频可能出现绿边的问题；
6、修复iOS设置通话模式时可能导致无声音的问题；
7、修复iOS硬解码缓存队列时间计算错误导致部分帧被丢弃的问题；
8、优化音视频同步功能；
9、修复iOS启动多个具备回音消除的播放器导致无声音的问题；
```

**V1.3.8~1.4.0【2022.06.23】**
```
1、优化音频切换模式；
2、优化播放状态类型，新增加载和加载完成状态；
3、优化释放逻辑；
4、修复停止可能会出现一声嗞的声音；
5、iOS端修复音频播放器不支持多播放的问题；
```

**V1.3.7【2022.06.11】**

```
1、新增网络流快速播放功能，支持急速秒播；
2、修复部分音频编码在刚开始播放的时候，因帧率计算错误导致播放延迟卡顿的问题；
3、修复线程运行状态判断异常，导致可能播放无画面和声音的问题；
4、添加可设置内部播放器可选参数接口；
5、新增可设置缓冲时间功能（默认关闭）；
```

**V1.3.6【2022.06.09】**

```
1、iOS和Android支持Speex编解码；
2、Android的Opencore-amr支持x86、x86_64框架；
3、修复音量增益功能异常；
```

**V1.3.4~1.3.5【2022.05.30】**

```
1、优化播放及录音的播放模式；
2、Android支持听筒和扬声器播放功能切换，默认扬声器播放；
3、优化文件播放末尾音视频被缓慢播放的问题；
```

**V1.3.3【2022.05.23】**

```
1、修复iOS在频繁开始和停止播放可能出现句柄野地址导致闪退的问题；
2、修复停止播放可能出现死锁导致闪退的问题；
3、优化iOS音频采集模块频繁出现"render err: -1"错误打印的问题；
```

**V1.2.7~1.3.2【2022.05.22】**

```
1、修复单独录制音频非AAC文件时，计算音频时长错误的问题；
2、优化仅播放视频或音频文件时，不申请麦克风权限；
3、修复录制开始立即停止可能导致闪退的问题；
4、新增播放链接url获取，新增用户信息userInfo参数可用作数据传递；
5、修复iOS硬解码H264可能无法解码I帧的问题；
6、修复频繁开始和停止播放可能导致闪退的问题；
```

**V1.2.5【2022.05.13】**

```
1、新增视频YUV420P、音频PCM数据允许外部处理，并添加协议接口；
2、新增手机采集麦克风数据录制AMR音频文件；
3、修复Android端播放视频文件异常的问题；
4、优化视频文件播放完成后，部分功能未正常停止的问题；
5、支持SSL视频流播放；
6、修复音频播放若采样率变换之后导致声音异常的问题；
7、修复Android端视频播放要结束时，最后1秒左右的音频数据播放异常；
```

**V1.2.4【2022.03.25】**

```
1、修复音频不是AAC时无法录制音频的问题；
2、录制新增可带音频增益效果的视频；
3、支持音频声音增益效果；
```

**V1.2.3【2022.03.24】**

```
1、优化文件播放结束EOF的处理；
2、文件播放时下发文件总时长信息；
```

**V1.2.2【2022.03.11】**

```
1、支持React Native版本：react-native-mediaplayer-zj；
2、Android支持mavenCentral库导入SDK：io.github.eafy:ZJMediaPlayer:+
3、优化及调整部分功能；
```

**V1.2.1【2022.03.10】**

```
1、修复反复播放停止导致偶尔闪退的问题；
```

**V1.2.0【2022.01.21】**

```
1、优化音视频同步功能；
2、优化音视频不同步功能；
3、默认开启音视频同步功能；
4、修复单独关闭音频(非静音)时导致闪退的问题；
```

**V1.1.9【2022.01.13】**

```
1、支持Android端，系统5.0+；
2、Android支持硬解码，支持画面比例模式设置；
3、代理回调部分由上层下沉到底层处理；
4、修复播放文件结束时可能闪退的问题；
5、优化画面显示比例算法；
```

**V1.1.8【2022.01.10】**

```
1、修复在播放声音的情况下进行对讲，第二次无法启动音频采集器的问题；
```

**V1.1.7【2021.10.19】**

```
1、修复录制视频可能少秒的问题；
2、优化UIImage分辨率为奇数时无法录制的问题；
```

**V1.1.4【2021.10.12】**

```
1、ZJGLMonitor新增截屏接口snapshot(同之前的image)，image则是获取原始图片；
2、ZJMonitorUtils新增几个图形数据（RGB24、YUV420、NV21）转换接口；
3、开放单独视频录制功能模块：ZJMediaRecorder，支持图片合成视频；
```

**V1.1.3【2021.09.30】**

```
1、修复视频信息频繁上报及信息缺失的问题；
2、修复不停播的情况下，切换分辨率过程偶尔出现花屏的问题；
3、修复切换分辨率硬解码会一直出现闪屏的问题；
```

**V1.1.2【2021.09.16】**

```
1、修复开始和停止播放操作，下次音视频无法播放的问题；
```

**V1.1.1【2021.07.08】**

```
1、修复纯裸流录制视频不成功的问题；
2、默认网络流开启音视频同步功能;
```

**V1.1.0【2021.07.06】**

```
1、支持H264多个Slice为一个数据包时的硬解码；
2、修复纯裸流视频不支持缓存追赶功能；
```

**V1.0.9【2021.06.29】**

```
1、修复用软解码带B帧的视频时，缓存包的时间戳计算错误导致，画面帧显示顺序错误的问题；
2、支持含B帧的H264视频硬件解码；
3、优化H264硬解码的时间戳同步及重排序算法；
```

**V1.0.8【2021.06.18】**

```
1、优化音视频同步功能；
2、修复开启降噪功能后无声音的问题；
3、默认关闭双层降噪，开启系统级音频降噪；
4、修复第2次开始播放内存溢出导致的闪退问题；
5、添加软硬件开关设置；
6、添加静音开关；
7、添加可单独开启关闭视频、音频接口；
8、优化视频显示，支持sar、dar比例显示；
```

**V1.0.7【2021.06.16】**

```
1、添加本地文件播放功能；
2、修复网络视频流EOF时候可能闪退的问题；
```

**V1.0.6【2021.06.12】**

```
1、修复硬解码对部分视频解析YUV420P错误导致花屏的问题；
2、支持MP4视频录制功能，包含H264+音频、HEVC+音频等格式；
```

**V1.0.5【2021.06.01】**

```
1、支持OpenGL画中画显示；
2、支持更优质的音视频同步效果；
3、支持视频截图；
4、支持ZJGLMonitor进行画面模式调整；
5、支持设置缓存队列大小（0~60s）；
6、修复部分异常导致的内存溢出；
```


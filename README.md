# ZJMediaPlayer

**商业授权请联系**：lizhijian_21@163.com

- 支持常见的H.264、HEVC、AAC、PCM等格式播放；
- 支持软硬件解码；

- 支持本地视频播放；
- 支持网络常用视频协议播放；
- 支持视频录制及视频截屏；
- 支持视频纯裸流播放；
- 支持图片合成视频；



## 更新日志

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


#  **此库是根据SeetaFace6JNI官方开源版本开发出来的东西**
研究Seetaface6有一段时间了，我希望把seetaface6服务化，好替代类似于百度这样的API（主要是因为他们收费）
但是找了好久，缺没有JNI相关的资料，虽然有一个JNI可以跑的例子（JSeetaface6），但是还是WINDOWS系统的，没有给出linux系统的so文件别逼无奈。于是自己开始学习了seetaface还JNI

# 如果我们想在我们自己的设备上运行seetaface6程序，就要自己编译源代码
源代码地址，不需要我多讲了<br/>
`` 记住： 优先编译出 OpenRoleZoo, SeetaAuthorize 和 TenniS，然后再进行其他 SDK 模块的编译 ``
## linux 平台编译说
以FaceAntiSpoofingX6为例：

```cd .FaceAntiSpoofingX6/craft```
<br/>运行脚本(个人不太建议使用gpu，虽然gpu理论上效率高，但是还是有好多组建需要装，还有有好多的问题)<br/>
```sh build.linux.x64.sh```
<br/>
各个模块都编译完成之后会在build文件下产生我们所需要的so库文件把这些文件都放到```jniLibs```目录下

# JNI库文件编译
以FaceAntiSpoofingX6为例：<br/>
```cd FaceAntiSpoofingX6```

```cmake -D CMAKE_BUILD_TYPE=Debug```

```make -j8```
编译完成，逐个编译吧
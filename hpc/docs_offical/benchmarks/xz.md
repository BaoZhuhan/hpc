# XZ workload 描述

### workload 名称

XZ

### 应用分类

基础软件/压缩工具

### XZ介绍

XZ Utils是一款免费的通用数据压缩软件，具有高压缩比。XZ Utils压缩代码的核心是基于LZMA SDK实现的，但为了适合XZ Utils，对其进行了大量的修改。目前主要的压缩算法是LZMA2，它在.xz容器格式中使用。对于典型的文件，XZ Utils创建的输出比gzip小30%，比bzip2小15%。

XZ workload是基于xz-5.2.5进行裁剪，并基于XZ Utils中提供的lzma api实现主体测试流程，将压缩、解压缩和校验等过程都包含在一个测试程序中。校验采用sha512校验，其代码实现来源于github中libtomcrypt库，并对其进行裁剪。与原始版本的差异如下：

- 压缩/解压过程均放在内存中完成，避免在压缩和解压过程中带来的IO操作。
- 裁剪移除XZ Utils中多线程配置和与平台相关的代码，只保留与平台无关的核心压缩算法。
- 增加sha512目录，存放sha512相关代码。

### 输入

数据集选择具有高压缩比的文本文件和具有低压缩比的视频文件，充分体现xz压缩算法的压缩比。此处选择的数据集有2个：

- linux-5.12-rc8.tar.gz, 下载地址:https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-5.12-rc8.tar.gz；
- rms-2020-12-04-waterloo.webm, 下载地址:http://audio-video.gnu.org/video/rms-2020-12-04-waterloo-why-operating-systems-and-other-software-should-be-free.webm；

由于这两个数据文件都比较大，需要各裁剪部分作为xz的输入。这里从linux-5.12-rc8.tar和rms-2020-12-04-waterloo.webm中各截取前60兆，然后再压缩为xz格式，分别命名为linux-5.12-rc8.tar.1.xz和rms-2020-12-04-waterloo.webm.1.xz，做为XZ workload的输入。

运行参数：

```
xz -i linux-5.12-rc8.tar.1.xz -c 85de2676a668437e178c71882fcc42212b97ea3def40a20a2969d8ab407cce083d492331d36c7375aa4f9b3380abd23eb8e5980d34b229c3cc9b3a29e1c2d3c6 -s 300 -l 6 -o xz_result_cmd1.out
xz -i rms-2020-12-04-waterloo.webm.1.xz -c bc7cdbe699f7c89700ef17797a7f599a24aebe681ed6853968d773b1e56673465c4839d592b297cc352e280d546002ed6eadc7e65d2a280e8b1bad21f57f8d9f -s 200 -l 6 -o xz_result_cmd2.out
```

- -i: 指定读取的输入文件
- -c: 该输入文件解压后码流的sha512校验值
- -s: 指定扩展内存大小
- -l: 指定压缩级别
- -o: 指定结果输出文件

### 主要业务流程

1.  从命令行参数中解析参数。
2.  根据输入文件名，读取输入文件，并将其解压为未压缩的码流，并对其进行sha512校验；
3.  根据扩展大小，将上步中未压缩的码流扩展到指定大小，作为测试的输入码流，并计算其sha512校验值；
4.  对测试的输入码流进行压缩、解压缩过程，并记录该过程执行的时间；
5.  对解压过的输出码流进行sha512校验，并与测试的输入码流的sha512校验值对比，判断是否正确完成；
6.  输出结果到文件，测试完成。

### 输出

XZ benchmark测试成功，则返回0，并将测试时间记录在-O指定的文件中；测试失败，则返回-1；

### 编程语言

C

### 源代码和license

XZ workload 基于xz-5.2.5修改，其使用，修改/引用遵循GPL 条款约束。下载地址：https://tukaani.org/xz/xz-5.2.5.tar.gz。

关于libtomcrypt使用，修改/引用遵循Public Domain 条款约束。下载地址：https://github.com/libtom/libtomcrypt/archive/refs/tags/v1.18.2.zip。

XZ workload 数据集由
### 参考：

[1]: https://tukaani.org/xz/
[2]: https://github.com/libtom/libtomcrypt


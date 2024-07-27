# Povray workload 描述

### Workload 名称

Povray

### 应用分类 

视频渲染/光线追踪

### Povray介绍

POV-Ray，全名是 Persistence of Vision Raytracer，是一个使用光线跟踪技术渲染三维图像的开放源代码自由软件。采用场景描述语言（Scene
Description Language）进行图像生成和处理。 POV-Ray 最大的优就旧在于它具有很好的开放性，能够应用于各个领域的图像处理工作。  

### 输入

数据集选择一个酒杯渲染模型，来自于开源素材库，Creative Commons License By Attribution，链接：http://www.oyonale.com/modeles.php?lang=en&page=13   

命令行参数如下：

```c
povray test.ini
```

- test.ini 渲染参数配置文件

主要参数：
- 抗锯齿深度 Antialias_Depth = 2
- 抗锯齿门限 Antialias_Threshold=0.3
- 渲染图片大小缩小为1280x960
- 设置单线程渲染 Work_Threads=1
- 提高渲染质量Quality=11（最高值）
- Enable图片输出  

### 主要业务流程

1.  读渲染参数配置文件及场景描述脚本
2.  根据配置参数（抗锯齿、Gamma纠正、渲染质量等）进行算法处理
3.  渲染完成，输出bmp图像  

### 输出

输出渲染结果图像，使用SSIM算法比对相似度（要求>90%）。

### 编程语言

ISO C++11

### 源代码和license

Povray workload 基于v3.8.0-alpha.11272893+av719版本修改，其使用，修改/引用遵循AGPL V3条款约束。下载地址：https://github.com/POV-Ray/povray/archive/refs/tags/v3.8.0-alpha.11272893.zip

Povray workload 数据集为酒杯渲染模型，来自于开源素材库，遵循Creative Commons License By Attribution，地址：https://creativecommons.org/licenses/by/3.0/

### 参考：

[1]: http://povray.org/	"povray.org"
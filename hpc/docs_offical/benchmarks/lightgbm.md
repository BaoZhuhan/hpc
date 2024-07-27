# LightGBM workload 描述

### Workload 名称

LightGBM

### 应用分类

机器学习/分类推理

### LightGBM介绍

**LightGBM** 是基于LightGBM3.0.0版本开发的workload，它是基于决策树开发的分布式梯度提升机器学习算法框架，可以应用于回归、分类等机器学习典型场景。本workload选择了LightGBM推理的过程作为评估性能的负载。

### 输入

选择了MNIST手写数字的数据集，其中60000张图片作为训练数据，模型参数使用了1000的决策树规模，训练完成后将模型保存成文件。推理过程读取另外10000张图片作为测试数据集，并且读取了模型文件，然后对这10000张图片进行推理得出结果。

### 主要业务流程

1. 读取测试数据文件，里面保存了10000张灰度图片，每张图片为28*28像素。
2. 读取已有的模型文件。
3. 使用模型对测试数据进行推理得出每张图片的分类结果。

### 输出

LightGBM标准输出结果，每张图片对应数字的概率

### 编程语言

C++11

### 源代码和license

lightgbm workload 基于LightGBM-3.0.0.tar.gz修改，基于MIT开源协议。下载地址：https://github.com/microsoft/LightGBM/tree/v3.0.0

lightgbm数据集MNIST遵循Creative Commons Attribution-Share Alike 3.0 license。下载地址：http://yann.lecun.com/exdb/mnist/

### 参考：

[1]LightGBM: https://lightgbm.readthedocs.io/en/latest/

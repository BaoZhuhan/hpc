# WordCount workload简介

### Workload 名称

WordCount

### 应用分类

大数据-数据挖掘

### Workload简介

**WordCount** 是基于Spark3.0.1版本开发的workload，使用spark引擎读取单词文本文件，得出文本中每个单词出现的频次。

### 输入

使用python脚本在一个单词池word_base.data中随机抽取单词拼凑出大的单词文本，为了保证所有平台的生成文件一致性，采用了固定随机种子的方法。

数据格式例子如下:

sa oh ar qv rf at hn ap do yx

### 主要业务流程

1. 启动Spark会话。
2. 读取生成的单词文本文件。
3. 利用spark引擎计算出单词文本中每个单词的出现频次。

### 输出

输出单词文本中每个单词的出现频次，跟基准结果文件对比，所有单词出现频次均跟基准结果文件一直才算正确。

### 编程语言

Java, Scala

### 源代码和license

wordcount workload 基于spark-3.0.1.tar.gz修改，基于Apache-2.0 License开源协议。下载地址：https://github.com/apache/spark/tree/v3.0.1

wordcount workload 数据集为自研算例

### 参考：

[1]Spark: https://spark.apache.org/

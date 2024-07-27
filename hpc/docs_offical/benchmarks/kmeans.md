# KMeans workload 描述

### Workload 名称

KMeans

### 应用分类

大数据-聚类算法

### KMeans介绍

**KMeans** 是基于Spark3.0.1版本开发的workload，使用spark.ml.clustering.KMeans的spark机器学习库进行聚类。聚类是把相似的对象通过静态分类的方法分成不同的组别，这样让在同一个子集中的成员对象都有相似的一些属性，相似性使用欧几里得距离进行判断。

### 输入

使用python脚本生成数据文件，首先使用均匀分布生成K=10个聚类中心点，每个数据点的维度是10，使用高斯分布在K个聚类中心周围随机生成一共1500000数据点，算法运行迭代次数固定为10次。为了保证所有平台的生成文件一致性，采用了固定随机种子的方法。

数据格式采用libsvm格式，例子如下:

0 1:531 2:775 3:175 4:-662 5:91 6:965 7:43 8:-842 9:-416 10:14

采用空格分隔，第一位为label，聚类中未使用，后面为(index:value)，表示每一个数据点第n维的数值。

### 主要业务流程

1. 启动Spark会话。
2. 读取生成的数据点文件。
3. 利用spark引擎的kmeans库得出聚类结果。

### 输出

迭代完成后得出K个聚类中心点，跟基准结果文件对比，判断每个聚类中心点的每一个维度数值跟基准结果数值对比，全部满足误差在10^-9以内算正确。

### 编程语言

Java, Scala

### 源代码和license

KMeans workload 基于spark-3.0.1修改，基于Apache-2.0 License开源协议。下载地址：https://github.com/apache/spark/tree/v3.0.1

KMeans workload 数据集为自研算例

### 参考：

[1]Spark: https://spark.apache.org/

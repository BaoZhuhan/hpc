# PhyML workload 描述

### Workload 名称

PhyML

### 应用分类

生物基因/系统进化数构建

### phyml介绍

研究分子进化所要构建的系统进化树（Phylogenetic tree），也叫发育树，对于一个未知的基因或蛋白质序列，可以利用系统进化树确定与其亲缘关系最近的物种。PhyML是一款采用最大似然法构建系统进化树的工具

### 输入

数据集采用官网benchmark的核酸序列：nucleic_M2792_166x812_2006.phy，该序列具有166个蛋白质，812个氨基酸。

下载链接：http://www.atgc-montpellier.fr/phyml/benchmarks/data/nucleic/nucleic_M2792_166x812_2006.phy

命令行参数如下：

```c
phyml -i nucleic_M2792_166x812_2006.phy -m GTR -s SPR -b -4 --r_seed 1622894149
```

- -i nucleic_M2792_166x812_2006.phy ：输入核酸序列或DNA序列
- -m GTR ：设置替代模型，参考官网benchmark例子选择GTR模型。
- -s SPR ：设置树的拓扑搜索算法
- -b -4 ：设置bootstrap评估次数或方式，-4表示采用Shimoidara-Hasegawa (SH) 测试方法计算自展值bootstrap，用于检验当前计算的进化树分支可信度。
- --r_seed ：指定伪随机函数的随机种子1622894149

### 主要业务流程

1.  从命令行参数中解析参数，读取基因序列
2.  算法处理，计算推断进化树
3.  输出结果，模型参数及统计分析_stats.txt文件和系统进化树tree.txt文件

### 输出

一个模型参数及统计分析_stats.txt文件，一个是系统进化树tree.txt文件，其中stats.txt文件包含likelihood值，校验结果使用likelihood最大似然值与预期值进行比较。

### 编程语言

C

### 源代码和license

PhyML workload 基于v3.3. 20200621修改，其使用，修改/引用遵循GPL 条款约束。下载地址：https://github.com/stephaneguindon/phyml/archive/refs/tags/v3.3.20200621.zip

PhyML workload 数据集使用phyml官网算例，遵循Creative Commons Attribution 4.0 International license.

### 参考：

[1]: http://www.atgc-montpellier.fr/phyml/
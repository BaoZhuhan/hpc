# lammps workload简介

### Workload 名称

lammps

### 应用分类

分子动力学

### lammps介绍

**lammps** 是一个专注于材料建模的经典分子动力学应用。lammps具有用于固态材料（金属、半导体）和软物质（生物分子、聚合物）和粗粒度或细观系统的潜力。它可用于对原子进行建模，或者更一般地说，它可用作原子、中观或连续介质尺度上的平行粒子模拟器。

lammps和gromacs两个分子动力学软件虽然都是基于相同的方法，但是各自有不同的侧重点。lammps里面支持的势很丰富，兼容目前大多数的势能模型，在固体、材料领域使用起来具有优势；gromacs优化的比较好，计算效率高，特别适合生物大分子体系模拟。

### 输入

数据集采用lammps自带的bench样例，算例名称为聚合物链熔体（Polymer chain melt）。
相关参数设置见以下网页：
https://www.lammps.org/bench.html#chain

### 主要业务流程

1. 读取chain.in数据集。
2. 应用P3M算法进行共20000步计算，并对该步骤应用编译选项和计时。
3. 输出最后一步的结果，进行正确性校验。

### 输出

输出第20000步的计算结果，和框架预设的值计算误差百分比，误差在3%以内认为运行正确。

### 编程语言

C++

### 源代码和license

lammps workload 基于2020年10月29日官方发布的源码进行修改。开源协议为GPLv2。下载地址：https://www.lammps.org/download.html

lammps workload 数据集为软件源码包自带算例，同样遵循开源协议GPLv2。

### 参考：

[1] https://www.lammps.org/
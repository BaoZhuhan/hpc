# Gromacs workload 描述

### workload 名称

gromacs

### 应用分类

科学计算/分子动力学

### Gromacs 介绍

分子动力学模拟（molecular dynamics simulation，MD）是一种分析原子和分子物理运动 的计算机模拟方法，也是时下最广泛为人采用的计算庞大复杂系统的方法。在分子动力学模 拟中，原子和分子被允许在一段固定的时间内相互作用，通过计算模拟给出系统动态演化的 视图。在最常见的版本中，原子和分子的轨迹是通过数值求解相互作用粒子系统的牛顿运动 方程来确定的，其中粒子之间的力及其势能通常使用原子间势或分子力学力场来计算。自 1970 年起，由于分子模拟的发展迅速，人们系统地建立了许多适用于生化分子体系、聚合 物、金属与非金属材料的力场，使得计算复杂体系的结构与一些热力学与光谱性质的能力及 精准性大为提升。分子动力学模拟是应用这些力场及根据牛顿运动力学原理所发展的计算方 法。在生化，医药，材料等领域，分子动力学模拟已经是一种不可或缺的研究手段，量子化 学中的计算方法（1998 年诺贝尔化学奖），复杂化学的多尺度模型（2013 年诺贝尔化学奖） 等都与分子动力学有直接联系。 目前，由于分子动力学已经广泛应用于多个学科，具有较高的使用频率，加之大规模的 分子动力学模拟需要消耗大量的高性能计算（HPC）资源，因此分子动力学模拟软件已经成 为 HPC 领域的一个典型应用。此外，将机器学习应用于分子动力学的方法也获得了 HPC领 域 2020 年的戈登贝尔奖。这说明分子动力学模拟与 HPC 技术的联系日益紧密。 GROMACS 是最为知名的分子动力学模拟的应用程序之一，它可以模拟具有数百至数 百万个粒子的系统的牛顿运动方程。GROMACS 最初主要是为蛋白质、脂质和核酸等具有 大量复杂键相互作用的生化分子设计的，但由于 GROMACS 在计算非成键相互作用（通常 在模拟中占主导地位）方面非常快，因此如今也被用于模拟非生物系统，例如聚合物。

gromcas workload是基于gromacs-2020.6 开发的, 依赖fftw-3.3.9 组件进行二次优化开发。

### 输入

本应用的数据集通过采用tpr格式，模拟一种大分子结构，包含4种蛋白质分子和3种其他 分子类型，共模拟81743个原子，模拟步长为1500步：

下载地址:https://wcm.ucalgary.ca/tieleman/files/tieleman/dppc128.pdb

运行参数：

```c
gmx -quiet mdrun -s gmx_test_data.tpr -ntmpi 1 -nt 1
```

- mdrun: 表示模拟运行
- -quiet:中间无任何输出
- -s:读取数据集gmx_test_data.tpr
- -ntmpi:Number of thread-MPI ranks 固定为1
- -nt：Total number of threads 固定为1

### 主要业务流程

1.  读取gmx_test_data.tpr.tpr数据集。
2.  应用PME（Particle-Mesh Ewald）算法进行共1500步计算，并对该步骤应用编译选项和计时。
3.  1500步计算完成后，获取Temperature/Total Energy的均值，进行正确性校验。

### 输出

输出第1500步Temperature/Total Energy均值结果，和框架预设的值计算误差百分比，误差在1%以内认为运行正确。

### 编程语言

ISO C++14

### 源代码和license

Gromacs workload 基于gromacs-2020.6修改，其使用，修改/引用遵循LGPL 条款约束。下载地址：ftp://ftp.gromacs.org/gromacs/gromacs2020.6.tar.gz

关于fftw-3.3.9使用，为自由软件。下载地址：http://www.fftw.org/fftw-3.3.9.tar.gz

Gromacs workload 数据集为自研算例

### 参考：

[1]: https://wcm.ucalgary.ca/tieleman/files/tieleman/dppc128.pdb	"数据集"


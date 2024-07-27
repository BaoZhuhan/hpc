# openfoam workload简介

### Workload 名称

openfoam

### 应用分类

通用计算流体力学——电磁学

### openfoam介绍

**openfoam** 是对连续介质力学问题进行数值计算的C++自由软件工具包，其包含众多领域的求解器和实用工具，考虑到基准工具整体行业布局，选择电磁学求解器mhdFoam作为基准工具负载。

求解器名称：mhdFoam。用于求解不可压缩层流磁流体问题的求解器，所求解的方程为不可压缩N-S方程和麦克斯韦方程。

### 输入

对流过磁场的导电流体进行数值求解，被称为磁流体问题，采用mhdFoam来数值模拟，具体算例名称为Hartmann问题，这个算例位于$FOAM_TUTORIALS/mhdFoam文件夹中。

### 主要业务流程

1. 读取磁流体网格数据集。
2. 经过mhdFoam求解器求解得到结果和对应的数据残差文件。
3. 校验脚本根据残差文件来判断workload执行的正确性。

### 输出

计算结果的Ux残差，保存在residuals文件。

校验脚本读取残差文件，获取收敛后的最后100条Ux残差数据，计算其平均值，与compare.txt中预设的残差参考值3e-07比较，观察均值是否在参考值5%范围内来校验正确性。

### 编程语言

C++

### 源代码和license

openfoam workload 基于2021年5月10日10:58 github仓库源码进行修改。开源协议为GPL V3。下载地址：https://github.com/OpenFOAM/OpenFOAM-8

openfoam workload 数据集为软件源码包自带算例，同样遵循GPL V3开源协议。

### 参考：

[1] https://github.com/OpenFOAM/OpenFOAM-8

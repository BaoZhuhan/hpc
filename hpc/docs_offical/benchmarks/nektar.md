# Nektar workload 描述

### Workload 名称

Nektar++

### 应用分类

CAE/CFD

### nektar++介绍

**Nektar++** Nektar++，是一款开源h/p型谱元软件包（www.nektar.info），是由英国伦敦帝国理工学院航空系空气动力学系主任，计算流体力学教授Spencer Sherwin 领导开发，此软件包已经被应用于直接数值模拟、大涡模拟和稳定性分析等一系列应用，包括与之相关的气动声学、涡流、海洋工程、车辆空气动力学以及与动脉硬化相关的生物医学流动等。

nektar workload 基于Nektar++5.0.1版本开发，选用了Acoustic Solver求解器，计算一个气动声学问题。

### 输入

输入采用Nektar++软件自带的Acoustic Solver的测试用例APE_3DPulseWall_WeakDG_MODIFIED.xml，使用了1000次迭代进行计算结果。

### 主要业务流程

1. 读取xml数据文件，里面保存了环境信息(点、线、面等信息)和求解信息。
2. 初始化所要求的求解变量。
3. 使用有限元法对求解变量进行模拟估算，通过迭代来使结果逼近准确值。

### 输出

Nektar++ 标准结果输出

### 编程语言

C++11, Fortran

### 源代码和license

Nektar++ workload 基于nektar-5.0.1版本修改，基于MIT开源协议。下载地址：https://www.nektar.info/downloads/

Nektar++ workload 数据集为自研算例

### 参考：

[1]nektar++: https://www.nektar.info/

### 已知问题

1. gcc 6.3 编译器版本，在-O3优化级别时会触发编译器内部段错误（internal compiler error: Segmentation fault），错误信息如下

   ```
   benchmarks/float_nektar/source/library/MultiRegions/ExpList.cpp:3026:14: internal compiler error: Segmentation fault
            void ExpList::v_ExtractElmtToBndPhys(const int i,
                 ^~~~~~~
   Please submit a full bug report,
   with preprocessed source if appropriate.
   See <file:///usr/share/doc/gcc-6/README.Bugs> for instructions.
   ```

   解决方案：对于gcc 6.3版本，nektar workload使用-O2优化级别

​	


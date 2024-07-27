# PHengLEI workload 描述

### Workload 名称

phenglei

### 应用分类

流体动力学

### PHengLEI 介绍

**PHengLEI**软件是由中国空气动力研究与发展中心开发的计算流体力学CFD软件平台，已在国内广泛推广使用。PHengLEI workload是基于PHengLEI版本号2012.v7129（2020年12月提交版本7129）开发。剔除了平台相关特性，主要关注解算器求解阶段，固定数据集和运行参数，对cpu、内存和编译器性能进行测试.

### 输入描述

输入数据采用30P30N三段翼低速绕流算例作为数据集，利用PHengLEI的断点续算机制，从8000步迭代开始计算，续算到收敛值。

### 处理过程描述

#### 主要业务流程

1. 读取网格数据（数据格式为phenglei自定义的.fts文件）以及断点续算数据
2. 初始化所有配置好的求解变量
3. 利用PHengLEI的断点续算机制，使用指定的解算器，从规定好的迭代步数开始续算，通过迭代使结果逼近准确值

#### 运行参数
参数由配置文件设置，配置文件详见data目录下的cfd_para.hypara以及cfd_para_subsonic.hypara

#### Workload 执行过程内存使用

内存使用: 173.3MB

### 输出

PHengLEI workload程序执行完成，输出结果文件，位于result目录下，主要结果文件为res.dat(计算的残差数据)，提供给后续workload运行正确性校验。

### 编程语言

C++11

### 源代码和license

PHengLEI workload 源码获得作者授权，已签署授权协议

### 参考：
[1]phenglei: http://www.cardc.cn/phenglei/index.php/page/about.mhtml

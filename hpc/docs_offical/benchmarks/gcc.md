# Gcc workload 描述

### workload 名称

gcc

### 应用分类

基础软件/编译器

### gcc 介绍

**gcc** 是 GNU Compiler Collection的简称，它把高级语言编写的源代码构建成计算机能够直接执行的二进制代码。 GCC是Linux平台下最常用的编译程序，它是Linux平台编译器的事实标准。gcc workload是基于gnu gcc-9.3.0开发的, 依赖gmp-6.1.0, isl-0.18, mpc-1.0.3, mpfr-3.1.4 组件进行二次优化开发。 与原始版本的差异如下：

- 裁剪C/C++编译器冗余功能，保留核心业务流程，保留编译器的优化特性。
- 解决C/C++编译器中ARCH差异化问题，移植性问题，保证编译器在不同的架构平台上，执行路径一致，功能一致。

### 输入

数据集选择必须能反映编译器的优化特性，同时运行时使用内存和耗时必须满足Bechmark 内存使用和运行时间指标。此处选择的数据集为：

版本：sqlite-version-3.32.3

下载地址:https://github.com/sqlite/sqlite/archive/version-3.32.3.tar.gz

运行参数：

```c
cc1 -O3 -quiet -fno-dwarf2-cfi-asm -I. sqlite3_shell.c -o sqlite3_shell.s
```

- -O3: 表示开启O3优化特性集
- -quiet:中间无任何输出
- --fno-dwarf2-cfi-asm:关闭与cfi相关的汇编输出
- -o:表示输出文件

### 主要业务流程

1.  从命令行参数中解析参数，开启O3优化特性集。
2.  对输入文件进行词法/语法，语义分析
3.  构建AST,GIMPLE 生成
4.  SSA等各种类型pass优化
5.  RTL 生成，RTL 优化
6.  输出汇编 

### 输出

gcc Benchmark 测试成功，则输出文件MD5值与预期一致 ，记录Benchmark耗时时间。

### 编程语言

ISO C++11



### 源代码和license

Gcc workload 基于gcc-9.3.0.tar.gz修改，其使用，修改/引用遵循GPL 条款约束。下载地址：https://ftp.gnu.org/gnu/gcc/gcc-9.3.0/gcc-9.3.0.tar.gz

关于gmp-6.1.0.tar.bz2使用，修改/引用遵循GPL 条款约束。下载地址：https://ftp.gnu.org/gnu/gmp/gmp-6.1.0.tar.bz2

关于isl-0.18.tar.bz2使用，修改/引用遵循GPL 条款约束。下载地址：https://gcc.gnu.org/pub/gcc/infrastructure/isl-0.18.tar.bz2

关于mpc-1.0.3.tar.gz使用，修改/引用遵循GPL 条款约束。下载地址：https://ftp.gnu.org/gnu/mpc/mpc-1.0.3.tar.gz

关于mpfr-3.1.4.tar.bz2使用，修改/引用遵循GPL 条款约束。下载地址：https://ftp.gnu.org/gnu/mpfr/mpfr-3.1.4.tar.bz2


Gcc workload 数据集由sqlite-version-3.32.3源码和gcc9.3.0部分c++代码组成

其中sqlite-version-3.32.3源码属于公共领域

gcc9.3.0部分c++代码修改/引用遵循GPL v3 条款约束


### 参考：

[1]: https://gcc.gnu.org/	"gcc.gnu.org"
[2]: https://github.com/sqlite/sqlite	"sqlite"


# TPCH workload简介

### Workload 名称

TPCH

### 应用分类

数据库，OLAP事务处理

### TPCH介绍

**TPCH** 是专门针对联机分析处理系统（OLAP系统）的规范，强调数据分析，SQL查询的执行量不是考核标准，单条SQL语句的执行时间比较长，读取数据也非常多，本workload参考TPC组织官方说明文档tpc-h_v2.18.02， 其中数据生成部分采用了开源的数据生产工具，根据单个workload实例占用内存不超过2G的指导原则，在数据生产工具的命令行中指定0.5G大小的数据集，最终插入数据表之后实例进程占用内存在2G左右。

tpch workload修改裁剪mysql源码，固定数据集通过计时的方式评估所测试的服务器的性能，测试过程中数据直接存入内存不落盘的方式避免大量的磁盘IO。

### 输入

数据集参考TPC组织官方说明文档 **tpc-h_v2.18.02.pdf** 通过https://github.com/trinodb/tpch/tree/master/src/main/java/io/trino/tpch开源工具生成测试数据。

### 主要业务流程

1. 启动mysql数据库服务，初始化完成后自动运行tpch数据加载程序，完成建库建表和数据插入。
2. 等待所有实例的数据加载完成。
3. 统一启动tpch运行程序并记录运行时间。
4. 退出mysqld进程，结束服务。

### 输出

TPCH workload程序执行完成

### 编程语言

C, C++14

### 源代码和license

TPCH workload 基于mysql-8.0.22修改，基于GPLv2开源协议。下载地址：https://downloads.mysql.com/archives/community/

TPCH workload 数据集为https://github.com/trinodb/tpch/tree/master/src/main/java/io/trino/tpch开源工具生成。

### 参考：

[1] https://dev.mysql.com/community/
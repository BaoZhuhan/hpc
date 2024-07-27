# Openssl workload 描述

### workload 名称

openssl

### 应用分类

基础软件/密码算法

### openssl 介绍

**OpenSSL**是包含安全套接字层（SSL）和传输层安全(TLS)协议的开源软件库，囊括了主要的密码算法、常用密钥、证书封装管理功能，它几乎成为安全领域的事实标准，大部分的服务器和客户端都使用OpenSSL，甚至一些硬件加密算法的实现也需要使用OpenSSL的命令行工具进行验证。 OpenSSL一直在保持更新，本workload选取的版本为官网上1.1.1k tag的打包版本。 与该tag版本的差异如下：

- 设置系统的宏定义：
OPENSSL_NO_ASM
OPENSSL_NO_ENGINE
OPENSSL_NO_STATIC_ENGINE
OPENSSL_NO_HW
OPENSSL_NO_MD2
OPENSSL_NO_MD4
OPENSSL_NO_MDC2
OPENSSL_NO_RC2
OPENSSL_NO_RC4
OPENSSL_NO_RC5
OPENSSL_NO_RFC3779
OPENSSL_NO_DES
OPENSSL_NO_CHACHA
OPENSSL_NO_CAST
OPENSSL_NO_IDEA
OPENSSL_NO_CAMELLIA
OPENSSL_NO_SIPHASH
OPENSSL_NO_CMAC
OPENSSL_NO_CMS
OPENSSL_NO_COMP
OPENSSL_NO_DH
OPENSSL_NO_POLY1305
OPENSSL_NO_BF
OPENSSL_NO_OCSP
OPENSSL_NO_RMD160
OPENSSL_NO_SRP
OPENSSL_NO_WHIRLPOOL
OPENSSL_NO_DSA
OPENSSL_NO_SEED
- 删除除 crypto、include、test外的所有文件夹
- 删除根目录下除e_os.h外的所有文件
- 删除crypto目录下与workload所选算法不相关的目录，包括：Aria/bf/blake2/camellia/cast/chacha/cmac/cms/comp/ct/des/dh/dsa/engine/md2/md4/mdc2/perlasm/poly1305/rc2/rc4/rc5/ripemd/seed/srp/whirlpool
- 删除test目录下除testutil外的所有文件夹
- 删除所有汇编代码

### 输入

测试数据已包含在测试程序中，无需额外提供。

### 主要业务流程

本workload的使用场景为HTTPS。从国际密码算法和国家商用密码算法两个方面设计了最为常见的8种算法测试，依次测试sha256，rsa 2048 sign/verify, rsa 2048 encrypt/decrypt, AES 128 encrypt/decrypt, sm3, sm2 sign/verify, sm2 encrypt/decrypt和sm4 encrypt/decrypt. 其中，sha256/sm3循环测试0xf000次，非对称密码算法循环测试0xf00次，对称算法循环测试0xf0000次。

### 输出

测试pass，则输出Benchmark耗时时间。

### 编程语言

C



### 源代码和license

Openssl workload 基于openssl-OpenSSL_1_1_1k.tar.gz源码，遵循OpenSSL和SSLeay双重许可。下载地址：https://github.com/openssl/openssl/releases/tag/OpenSSL_1_1_1k

### 参考：

[1]: https://github.com/openssl/openssl/releases/tag/OpenSSL_1_1_1k
[2]: www.openssl.org


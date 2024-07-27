# Velvet workload简介

### Workload 名称

Velvet

### 应用分类

基因领域/基因拼接

### Velvet介绍

**Velvet**是专为短读测序程序（例如Solexa或454）设计的从头基因组组装器，由欧洲生物学信息研究所（EMBL-EBI）的Daniel Zerbino和Ewan Birney开发，支持多个文库的数据同时使用。

### 输入

数据集来自NCBI官网的基因库，选用最近两年在全球范围内流行的严重急性呼吸综合征冠状病毒2株部分样本。下载路径如下：

https://sra-pub-sars-cov2.s3.amazonaws.com/sra-src/SRR12338206/KPCOVID-0301_S15_L001_R2_001.fastq.gz.1

https://sra-pub-sars-cov2.s3.amazonaws.com/sra-src/SRR12338275/KPCOVID-0286_S1_L001_R2_001.fastq.gz.1


### 主要业务流程

1. 由velveth程序接收输入文件，产生一个hash表，生成Sequences和Roadmaps两个文件
2. 运行核心程序velvetg， 进行de Bruijin图构建和操作

### 输出

1. 长度2倍长于kmer的contigs文件contigs.fa、 用于决定覆盖度cutoff的统计表stats.txt和PreGraph、Graph和LastGraph等de vruijin图文件
2. 使用提前准备好的标准contigs文件与本次运行输出的contigs文件进行比较，验证有效性

### 编程语言

C语言

### 源代码和license

Velvet基于velvet_1.2.10修改，遵循GPLv2开源协议。下载地址：https://www.ebi.ac.uk/~zerbino/velvet/velvet_1.2.10.tgz

### 参考：

[1] https://github.com/dzerbino/velvet
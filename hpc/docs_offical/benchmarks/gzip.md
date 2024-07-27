# Gzip workload 描述

### Workload 名称

gzip

### 应用分类

数据压缩

### gzip 介绍

**gzip**  是由Jean-loup Gailly和Mark Adler 为GNU工程创建的一款非常流行的压缩/解压软件，它的主要算法为DEFLATE 算法（LZSS 和Huffman coding）,用以取代LZW 和其他专利保护的数据压缩算法。其解压过程使用流式算法实现，常应用于网络协议，数据交换等业务场景。

gzip workload基于gnu gzip-1.10版本进行二次优化开发得到的。与原始版本差异如下：

- 关闭基本文件IO功能（除首次从文件读入文件），文件解压和压缩功能均在内存中进行。

- 剔除平台的相关特性，例如：内嵌汇编代码，基于特定平台加速的特征等。 

### 输入

DEFLATE 无损压缩算法，通常处理对象为文本文件和索引图像。此处选择linux-3.2.tar.gz（下载地址：）作为测试对象。

命令行参数如下：

```c
gzip -J 0 -E 0 -C 1 -T 460912640 -S 99474343 -md5 1663fdd58d9fad3d7fae03ee7de2c86d -L 6,9 -O gzip_result.out linux-3.2.tar.gz
```

- -J: 表示任务编号

- -E:表示在下一次压缩时，是否对待压缩的内容进行扩展（扩展方法：使用解压后的文件内容进行填充）。0表示不扩展填充；1表示扩展填充。

- -C:表示linux-3.2.tar.gz文件中包含的子文件个数

- -T:表示承载文件解压后缓冲的字节大小，一般大于或等于解压后文件大小

- -S:表示linux-3.2.tar.gz文件中子文件大小**列表**。完整形式：

  ```c
  -S 99474343,xxxxxx,yyyyyy
  ```

- -md5:表示linux-3.2.tar.gz文件中所包含子文件的md5列表，完整形式如下：

  ```c
  -md5 1663fdd58d9fad3d7fae03ee7de2c86d,xxxxxx,yyyyyy
  ```

- -L:使用列表模式，表示压缩级别。例如上述示例含义：每个子文件一次进行压缩级别6，9级别压缩。

- -O:表示Benchmark 执行结果，包含信息：任务编号，耗时时间

- 文件名：可以为单个文件或复合文件。若为复合文件,则子文件MD5,大小必须和参数-S,-MD5依次匹配

  

### 主要业务流程

1.  从命令行参数中解析出文件列表和对应的MD5列表，针对File~i~,MD5~i~。
2.  读取子文件File~i~，进行解压，计算出MD5值。
3.  若与MD5~i~比较，若不匹配，则失败退出
4.  对解压后的缓冲区进行填充（可选），重新计算出MD5~j~
5.  选择压缩级别，对解压后的缓冲区进行压缩，输出到压缩缓冲区。
6.  对压缩后的缓冲区进行解压，输出到解压缓冲区。
7.  对解压缓冲区计算出MD5~k~,若与MD5~j~不匹配，则失败退出。

### 输出

gzip Benchmark 测试成功，则输出文件gzip_result.out，记录Benchmark耗时时间。

### 编程语言

ISO C99



### 源代码和license

Gzip workload 基于gzip-1.10.tar.gz修改，其使用，修改/引用遵循GPL 条款约束。下载地址：https://ftp.gnu.org/gnu/gzip/gzip-1.10.tar.gz

benchmark MD5算法使用libtomcrypt-1.18.2.zip，其使用，修改/引用遵循LibTomCrypt license。下载地址：https://github.com/libtom/libtomcrypt/archive/refs/tags/v1.18.2.zip


Gzip workload 数据集由标准Linux内核源代码linux-3.2.tar.gz和Silesia Corpus contents 数据集、Large Canterbury corpus中enwik9数据集组成

linux-3.2.tar.gz为标准Linux内核代码。其使用、修改/引用遵循Linux Kernel COPYING 条款。下载地址：https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-3.2.tar.gz

Silesia Corpus contents 数据集和Large Canterbury corpus中enwik9数据集属于公共领域

### 参考：

[1]: https://en.wikipedia.org/wiki/Deflate	"Deflate"
[2]: https://en.wikipedia.org/wiki/Gzip	"Gzip"


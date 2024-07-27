# Python workload 描述

### workload 名称

python

### 应用分类

编程语言

### python 介绍

Python是一门面向对象的脚本语言。Python语法和动态类型，以及解释型语言的本质，使它成为多数平台上写脚本和快速开发应用的编程语言。Python也逐渐被用于独立的、大型项目的开发。python workload是基于python-3.9.5开发的。 与原始版本的差异如下：

- 裁剪python源码中未用到的库文件以及头文件。
- 裁剪python源码中对特定架构进行优化的部分。

### 输入

数据集应保证是python的典型应用程序。

选取了六个脚本，其中有四个是人工智能算法。

第一个脚本adatron.py：支持向量机，是一类按监督学习方式对数据进行二元分类的广义线性分类器。

第二个脚本aes.py：高级加密算法。

第三个脚本genetic2：遗传算法，是一种通过模拟自然进化过程搜索最优解的算法。

第四个脚本heap.py：堆排序算法。

第五个脚本mao.py：环境光遮蔽渲染算法，环境光遮蔽是来描绘物体和物体相交或靠近的时候遮挡周围漫反射光线的效果，可以解决或改善漏光、飘和阴影不实等问题。

第六个脚本pypgm.py：光线追踪算法，是一个在二维(2D)屏幕上呈现三维(3D)图像的方法。

数据集下载地址:http://www.reflection.uniovi.es/python/index.shtml、https://github.com/thilo-dev/benchmarking-heapsort/blob/master/src/python_heapsort.py

### 主要业务流程

解释器解释执行脚本。

### 输出

输出文件和结果对比文件进行对比，如果一致则运行成功，如果不一致则会报错。

### 编程语言

C语言(-std=c99)



### 源代码和license

benchmark 基于python3.9.5修改，其使用，修改/引用遵循PSF License Version 2 and the Zero-Clause BSD license双重许可。下载地址：https://github.com/python/cpython

benchmark数据集包含6个脚本。

adatron.py的使用，修改/引用遵循GPL 条款。下载地址：http://www.reflection.uniovi.es/python/index.shtml

aes.py的使用，修改/引用遵循MIT条款。下载地址：http://www.reflection.uniovi.es/python/index.shtml

genetic2.py的使用，修改/引用遵循GPL条款。下载地址：http://www.reflection.uniovi.es/python/index.shtml

mao.py的使用，修改/引用遵循BSD3条款。下载地址：http://www.reflection.uniovi.es/python/index.shtml

pygmy.py的使用，修改/引用遵循GPL条款。下载地址：http://www.reflection.uniovi.es/python/index.shtml

heap.py的使用，修改/引用遵循MIT条款。下载地址：https://github.com/thilo-dev/benchmarking-heapsort/blob/master/src/python_heapsort.py

### 参考：

[1]: https://github.com/python/cpython	"python"
[2]: http://www.reflection.uniovi.es/python/index.shtml	"数据集"
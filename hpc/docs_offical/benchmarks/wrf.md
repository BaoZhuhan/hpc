# WRF workload 描述

### Workload 名称

WRF

### Workload 归类

科学计算/天气预报

### Workload 描述

**WRF**
WRF（Weather Research and Forecasting Model）模式是由美国环境预测中心（NCEP）,美国国家大气研究中心（NCAR）等美国科研机构中心着手开发的一种统一的中尺度天气预报模式，可以用来进行精细尺度的天气模拟与预报。
WRF模式系统具有的可移植，易维护，可扩充，高效率，方便等特点，使其成为从云尺度到各种不同天气尺度的重要天气特征预报的工具。


### 输入描述

以上海为中心，8km栅格分辨率，模拟区域1280km * 1280km，模拟2016年6月30日中午12点至13点的气象数据，每步模拟30s。

### 处理过程描述

#### 基本工作流程

1. 读取测试模型文件。
2. 读取数据文件。
3. 以30s为时间步长，依次进行气象数据演算。
4. 模型执行结果输出。

### 输出描述

以正午13点的气象数据结果作为结果文件输出。

### 编程语言

C Fortran

### 源代码和license

WRF workload WRF基于开源WRF-4.2.1版本修改。下载地址：https://github.com/wrf-model/WRF/archive/refs/tags/v4.2.1.tar.gz
License路径：https://github.com/wrf-model/WRF/blob/master/LICENSE.txt

workload集成了netcdf作为依赖。
netcdf-4.6.3，下载地址：https://github.com/Unidata/netcdf-c/archive/refs/tags/v4.6.3.tar.gz
netcdf-fortran-4.4.5，下载地址：https://github.com/Unidata/netcdf-fortran/archive/refs/tags/v4.4.5.tar.gz
License: https://www.unidata.ucar.edu/software/netcdf/copyright.html

WRF workload 数据集为自研算例

### 参考：

[1]WRF: https://www.mmm.ucar.edu/weather-research-and-forecasting-model

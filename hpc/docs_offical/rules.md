# CPUBench规则

本文档详细阐述CPUBench的目的，编译构建、运行、报告生成、发布的规则及要求。

#### 目的（项目范围）

Benchmark的设计需要保证评估结果符合实际的业务性能诉求，虽然单个业务场景的benchmark更能代表本业务场景的实际，但是在其它业务场景评估结果会存在较大的偏差。CPUBench通过从通用计算场景下的常用软件中，选取计算需求大的软件，进行简化（如删除磁盘IO和网络相关操作），以对通用计算场景下的系统性能进行综合评估。通过这种方式，使得评估模型更能代表通用计算的算力需求。

CPUBench定位于通用计算场景下对CPU和内存进行性能进行综合评估，以及其所依赖的编译器和JVM虚拟机。

为了保证评估结果有意义，我们定义了如下一套原则：

### 1. 总体原则

**公平**：  benchmark要尽量对不同平台保持公平和公正，benchmark在设计时做了如下约束：

a)     性能相关的代码，禁止使用汇编代码实现：benchmark源代码中使用了汇编代码会导致不同平台运行的代码不一样，从而导致benchmark的实现方式影响最终性能结果。另外这也会导致部分平台使用了特殊汇编加速指令导致对其它平台不友好。

b)     线程调度和锁最后结果影响微乎其微：在线程调度和锁抢占对性能有较大影响的场景，不同平台有不同的调优措施，如不同的线程并发数，不同的锁等待机制等。如果benchmark针对某个平台设置一套默认参数，必然会导致对其它平台不公平。

**可用**：优化措施必须能商用，且通用。不能出现只对benchmark有效果，而对实际业务场景无效果的优化措施。

**可比较**：测试结果以参考服务器为基准分。每个benchmark的跑分为【参考机器的运行时间/被测机器的运行时间】。

**可复现**：根据测试报告中提供的软硬件信息，能稳定复现性能得分，性能基本无波动。

**业务代表性**：代表通用服务器计算的实际业务场景。整数运算使用编译，机器学习，媒体，数据库，大数据等典型的计算场景。 浮点运算主要来源于 HPC的典型业务场景。

**商业友好**：遵守开源软件的使用规则及license要求。



### 2. 编译构建规则

#### 2.1 通用编译规则

##### 2.1.1 CPUBench的编译环境

性能相关的措施都应该在报告中描述，且满足总体原则中规定的可用性原则。构建环境包含不限于：

a)     操作系统以及对应的优化改动

b)     编译器版本以及对应的优化措施

c)     JVM版本以及对应的优化措施

d)     环境变量

编译构建不能改变CPUBench的原始代码执行逻辑。禁止的行为包含不限于：

a)    禁止修改benchmark的源代码，构建脚本和测试数据

b)    禁止修改CPUBench的框架代码

c)    禁止利用benchmark中的编译宏改变代码运行行为

在某个系统中出现构建失败时，可以将问题和补丁提供给CPUBench组织，经过评审后，本次测试报告才可以用于正式发布。

##### 2.1.2 持续构建

新的测试人员能基于测试报告提供的软件和硬件配置信息稳定的复现测试结果。编译过程中，不应该再对系统进行任何修改，禁止但不限于如下行为：

a）    禁止：要求在不同benchmark编译之间重启操作系统

b）    禁止：要求在不同benchmark编译之间修改配置或安装补丁

c）    禁止：因为资源占用高，一次只编译或运行只完成部分benchmark

#### 2.2  编译选项

##### 2.2.1 禁止使用的名称

编译选项不能使用benchmark 的构建脚本和源文件中已有的宏， 变量名和函数名称等。

例如：某个benchmark使用 ‘#ifdef MACRO’ 用于选择不同的源码，编译选项中不能使用这个名字

##### 2.2.2 库替换的限制

不得使用自定义的API来替换benchmark中的实现，如使用只定义的API替换benchmark中实现的x264_otof函数。

对于优化后的库函数，不能只在一个benchmark 使用，而在其它benchmark不使用。优化的库函数不能预置计算好的计算结果。

##### 2.2.3 禁止使用并行编译技术

因为single模式是评估单核的计算能力, OpenMp或者其它编译器自动并行编译技术不能在 single模式使用。

说明：本规则并不禁止SIMD，如GCC的-ftree-vectorize。

##### 2.2.4  禁止修改benchmark默认的C++ RTTI和异常要求

编译器必须支持 RTTI 和异常机制，且在编译选项中不能修改benchamark默认的RTTI 和异常机制参数。

##### 2.2.5 typical测试时编译选项相同

编译选项包含但是不限制在预处理参数，编译选项，链接选项等。

##### 2.2.6 禁止使用FDO(Feedback directed optimization)

typical测试时禁止使用FDO,extreme测试时可以打开FDO.

#### 2.3  系统平台的优化规则

##### 2.3.1 可用性

a)     系统，编译器和虚拟机的优化措施必须要保证功能正确。

b)     系统，编译器和虚拟机的优化措施能广泛应用于某类程序，而不是只针对benchmark。

##### 2.3.2 typical测试时需要使用相同的编译系统

对于typical测试，同一类语言的benchmark必须使用相同的编译系统。编译系统的一致性包含以下方面，但并不局限于预处理，编译，链接和类库。

### 3 运行要求

#### 3.1 禁止在运行时刻对系统进行修改

测试套开始运行到结束运行期间，禁止对系统参数做变更。

#### 3.2 运行环境

benchmark的运行环境要求：

- 所使用的组件或功能特性必须稳定，能商用，且能获得。

### 4 报告发布规范

对于公开发布的测试报告，必须详细描述软硬件配置信息，基于这个配置信息能稳定复现相同的测试结果。

#### 4.1 需披露的基本信息

所有涉及重现测试结果的信息都应该被披露，包含单不限于：

- 组件以及对应的版本和获取方式
- 编译选项
- 性能相关调优设置，包括硬件、固件、BIOS、软件等各方面
- 所有非默认值的配置项
- 其它复现测试结果所需的信息

##### 4.1.1 必须包含typical测试

对外公开发布的测试报告必须包含typical模式下的测试结果

##### 4.1.2  可选测试extreme

对外公开发布的测试报告可以不含extreme测试结果，extreme是个可选项

##### 4.1.3  typical模式下所有负载的编译选项必须相同

对外公开发布的测试报告在typical模式必须拥有相同的编译选项

##### 4.1.4  测试套中所有负载必须全部有效运行

对外公开发布的测试报告必须包含测试套中所有负载的有效测试结果

##### 4.1.5  测试负载必须运行三轮

对外公开发布的测试报告必须包含三轮测试结果

##### 4.1.6  工具自校验必须开启

对外公开发布的测试报告必须在开启工具自校验的情况下生成

#### 4.2 公共渠道可获取的组件

对外公开发布的测试报告应该基于已发布产品（包括软件、硬件、固件、BIOS等），如果尚未发布需要在显著位置明确注明非商用版本。

 
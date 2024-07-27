# 配置文件使用指南

配置文件定义了一系列配置项，指导了CPUBench的编译、运行、日志和发布等行为，通过一种可读的方式定义了CPUBench与测试环境的交互方式。配置文件将所有的配置项集中在一起，为测试结果的移植提供了可能，也提高了CPUBench的易用性。客户想要复现某个测试结果，仅需要满足三个条件：
1、	相同版本的CPUBench工具，并通过相同的方式调用它；
2、	相同的软硬件环境；
3、	相同的配置文件；

配置文件是ini格式的文件，遵循业界通用的ini文件语法。您可以定制您的配置文件，并通过以下两种方式来指定它：
1、 通过`<code>`--config`</code>`或`<code>`-c`</code>`来指定配置文件的路径；
2、 将配置文件放在config目录中，并通过`<code>`--config`</code>`或`<code>`-c`</code>`来指定文件名，文件后缀可以省略；

若未指定配置文件，CPUBench将使用默认配置文件`<code>`config-template.ini`</code>`。

如果您还不知道如何编写配置文件，可以根据config目录中的默认配置文件`<code>`config-template.ini`</code>`做修改，下面是您可能感兴趣的跟配置文件相关的说明。

## 配置选项类型

配置文件提供的配置项有三种类型。
1、	通用配置项
配置文件提供了与命令行相似的通用配置项，可以有效降低命令行的复杂度。如在配置文件中定义：

    action = standard
    benchmarks = IntConcurrent
    tag = test
    tune = typical

那么以下两条命令行指令完全一致：

    python3 cpubench.py --config=test.ini
    python3 cpubench.py --config=test.ini --action=standard --benchmarks=IntConcurrent --tag=test --tune=typical

若相同的配置项既出现在命令行又出现在配置文件，以命令行为主。

2、	编译选项
配置文件提供配置项控制workload的编译行为。详情参阅 “配置项” 章节。

3、	测试和环境信息
配置文件支持描述配置项，这类配置项方便客户理解测试信息。

4、	JAVA运行参数
配置文件提供配置项以方便用户进行JVM调优。

## 配置文件结构

配置文件分为两个部分：
1、	common区
在命名区之前，通常用于定义本次运行的一些通用配置。如：

    [common]
    #=========================Common Settings=============================
    action = standard
    benchmarks = IntConcurrent
    tag = test
    tune = typical
    jobs = 1
    iterations = 3
    verbose = 0
    work_dir = /opt/test_dir

2、	命名区
命名区以一个区域标识行打头，区域标识行由一到二个字符串通过&相连，如：

    [IntConcurrent&typical]
    CFLAGS = -O3

需要注意的是，多个命名区可能有相同的配置项，此时需要应用优先级规则来决定配置项的取值。规则在后文具体阐述。

## 注释

配置文件提供#注释功能，注释不会被视为配置项。

## 命名区

命名区以区域标识行打头，延续到下一个标识行。配置文件支持多个命名区，它们的顺序不会影响配置项的最终值。如果区域标识行有重复，它们标识的命名区内容会自动合并。
区域标识行的格式如下，分为两个标识符：

    [benchmark&tuning]

两个标识符的取值如下所示：
benchmark包含了suite以及特定的benchmark名称。
tuning包含了调优选项包括typical/extreme。

如果区域标识行的尾部标识是default，可以省略。如：

    [int_x264&default]
    [int_x264]

### 命名区优先级规则：

配置文件通过优先级规则来组织命名区的区域合并、冲突。优先级规则作用于标识行内的两个标识符。

对benchmark标识符，优先级如下：

    高优先级    specific benchmarks > benchmark suite > default    低优先级

对tuning标识符，优先级如下：

    高优先级    typical = extreme > default    低优先级

若按照以上进行各个标识符的优先级排序后，区域内的配置项之间没有冲突，则直接合并，若有冲突，按照以下标识符间优先级来判断，优先级一致，则以最后设置的值为主：

    高优先级    benchmark > tuning    低优先级

例如以下两条命令：
第一条指定了benchmark，会匹配前两个命名空间，由于优先级冲突，选择优先级大的-O3。
第二条指定了tuning和benchmark，按照各个标识符优先级排序，会匹配第一和第三个命名空间，但是由于配置项冲突，则按照标识符间优先级排序，tuning优先级更高，选择-O2。

    [default]
    CC = ${lang_dir}/gcc
    CC_VERSION = -v
    CXXFLAGS = -O0

    [IntConcurrent]
    CXXFLAGS = -O3

    [default&extreme]
    CXXFLAGS = -O2

    python3 cpubench.py --benchmarks=int_x264 --jobs=3
    python3 cpubench.py --benchmarks=int_x264 --jobs=1 --tune=extreme

## 配置项

### 通用配置项

<table class="table">
<tr><th>Option</th><th>Default</th><th>Area</th><th>Meaning</th></tr>
<tr>
  <td><code>action</code></td>
  <td>standard</td>
  <td>common</td>
  <td>指定本次工具的活动。</td>
</tr>
<tr>
  <td><code>benchmarks</code></td>
  <td>[]</td>
  <td>common</td>
  <td>指定本次运行的benchmarks或suite。</td>
</tr>
<tr>
  <td><code>tune</code></td>
  <td>typical</td>
  <td>common</td>
  <td>调优级别，可以选择经典(typical)或最优(extreme)。</td>
</tr>
<tr>
  <td><code>tag</code></td>
  <td>""</td>
  <td>common</td>
  <td>用于标记可执行文件，构建目录和运行目录。</td>
</tr>
<tr>
  <td><code>jobs</code></td>
  <td>1</td>
  <td>common</td>
  <td>支持在多个核上跑多个复制。</td>
</tr>
<tr>
  <td><code>verbose</code></td>
  <td>0</td>
  <td>common</td>
  <td>值为1的时候，开启debug模式。</td>
</tr>
<tr>
  <td><code>work_dir</code></td>
  <td>work_dir</td>
  <td>common</td>
  <td>设置工作目录，所有运行数据都会存放到该路径下。</td>
</tr>
<tr>
  <td><code>iterations</code></td>
  <td>3</td>
  <td>common</td>
  <td>要运行的迭代次数。</td>
</tr>
<tr>
  <td><code>taskset</code></td>
  <td>[]</td>
  <td>common</td>
  <td>绑核列表，由逗号分隔的一系列cpu核号构成，同时支持通过-分隔符来标识一个编号范围，如1-5等价于1,2,3,4,5。
  当该列表长度大于jobs时，只会选前jobs的cpu核进行绑定，若小于jobs，则会在超出列表长度时，从列表头重新绑定。</td>
</tr>
<tr>
  <td><code>arch</code></td>
  <td>auto</td>
  <td>common</td>
  <td>指定CPU架构，auto表示自动识别，否则使用用户指定参数。该选项用于不规范CPU Architecture命名情况。</td>
</tr>
<tr>
  <td><code>rebuild</code></td>
  <td>0</td>
  <td>common</td>
  <td>是否在运行前重新编译负载。</td>
</tr>
</table>

### 测试和环境信息

<table class="table">
<tr><th>Option</th><th>Default</th><th>Area</th><th>Meaning</th></tr>
<tr>
  <td><code>cpu_name</code></td>
  <td>""</td>
  <td>common</td>
  <td>制造商确定的处理器名称。</td>
</tr>
<tr>
  <td><code>machine_name</code></td>
  <td>""</td>
  <td>common</td>
  <td>机器名。</td>
</tr>
<tr>
  <td><code>cpu_max_mhz</code></td>
  <td>""</td>
  <td>common</td>
  <td>芯片供应商指定的CPU的最大速度，以MHz为单位。</td>
</tr>
<tr>
  <td><code>cpu_nominal_mhz</code></td>
  <td>""</td>
  <td>common</td>
  <td>芯片供应商指定的CPU速度，以MHz为单位。</td>
</tr>
<tr>
  <td><code>disk</code></td>
  <td>""</td>
  <td>common</td>
  <td>运行目录的磁盘子系统。</td>
</tr>
<tr>
  <td><code>memory</code></td>
  <td>""</td>
  <td>common</td>
  <td>主内存的大小。</td>
</tr>
<tr>
  <td><code>l1_cache</code></td>
  <td>""</td>
  <td>common</td>
  <td>1级（主）缓存。</td>
</tr>
<tr>
  <td><code>l2_cache</code></td>
  <td>""</td>
  <td>common</td>
  <td>2级缓存。</td>
</tr>
<tr>
  <td><code>l3_cache</code></td>
  <td>""</td>
  <td>common</td>
  <td>3级缓存。</td>
</tr>
<tr>
  <td><code>manufacturer</code></td>
  <td>""</td>
  <td>common</td>
  <td>硬件制造商。</td>
</tr>
<tr>
  <td><code>os</code></td>
  <td>""</td>
  <td>common</td>
  <td>操作系统名称和版本。</td>
</tr>
<tr>
  <td><code>compiler</code></td>
  <td>""</td>
  <td>common</td>
  <td>编译器的名称和版本。</td>
</tr>
<tr>
  <td><code>file_system</code></td>
  <td>""</td>
  <td>common</td>
  <td>运行目录的文件系统（ntfs，ufs，nfs等）。</td>
</tr>
<tr>
  <td><code>run_level</code></td>
  <td>""</td>
  <td>common</td>
  <td>运行级别。</td>
</tr>
<tr>
  <td><code>ptrsize</code></td>
  <td>""</td>
  <td>common</td>
  <td>基准测试使用的指针位数。32/64</td>
</tr>
<tr>
  <td><code>huge_page_size</code></td>
  <td>""</td>
  <td>common</td>
  <td>大页内存。</td>
</tr>
<tr>
  <td><code>transparent_huge_pages</code></td>
  <td>""</td>
  <td>common</td>
  <td>透明大页内存。</td>
</tr>
<tr>
  <td><code>test_date</code></td>
  <td>""</td>
  <td>common</td>
  <td>测试时间。</td>
</tr>
<tr>
  <td><code>test_sponsor</code></td>
  <td>""</td>
  <td>common</td>
  <td>赞助此测试的实体。</td>
</tr>
<tr>
  <td><code>software_available_time</code></td>
  <td>""</td>
  <td>common</td>
  <td>软件有效期。</td>
</tr>
<tr>
  <td><code>hardware_available_time</code></td>
  <td>""</td>
  <td>common</td>
  <td>硬件有效期。</td>
</tr>
<tr>
  <td><code>software_others</code></td>
  <td>""</td>
  <td>common</td>
  <td>其他软件相关信息。</td>
</tr>
<tr>
  <td><code>hardware_others</code></td>
  <td>""</td>
  <td>common</td>
  <td>其他硬件相关信息。</td>
</tr>
<tr>
  <td><code>license_id</code></td>
  <td>""</td>
  <td>common</td>
  <td>许可证编号。</td>
</tr>
</table>

### 编译选项

<table class="table">
<tr><th>Option</th><th>Default</th><th>Area</th><th>Meaning</th></tr>
<tr>
  <td><code>LD_LIBRARY_PATH</code></td>
  <td>/usr/bin/gcc</td>
  <td>namespace</td>
  <td>动态链接库搜索路径设置。</td>
</tr>
<tr>
  <td><code>CC</code></td>
  <td>/usr/bin/gcc</td>
  <td>namespace</td>
  <td>如何调用C编译器。</td>
</tr>
<tr>
  <td><code>CC_VERSION</code></td>
  <td>-v</td>
  <td>namespace</td>
  <td>如何获取C编译器版本。</td>
</tr>
<tr>
  <td><code>CFLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>既不是优化也不是可移植性的C语言编译标志。</td>
</tr>
<tr>
  <td><code>CXX</code></td>
  <td>/usr/bin/g++</td>
  <td>namespace</td>
  <td>如何调用C++编译器。</td>
</tr>
<tr>
  <td><code>CXX_VERSION</code></td>
  <td>-v</td>
  <td>namespace</td>
  <td>如何获取C++编译器版本。</td>
</tr>
<tr>
  <td><code>CXXFLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>既不是优化也不是可移植性的C++语言编译标志。</td>
</tr>
<tr>
  <td><code>FC</code></td>
  <td>/usr/bin/gfortran</td>
  <td>namespace</td>
  <td>如何调用gfortran。</td>
</tr>
<tr>
  <td><code>FC_VERSION</code></td>
  <td>-v</td>
  <td>namespace</td>
  <td>如何获取gfortran版本。</td>
</tr>
<tr>
  <td><code>FFLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>指定fortran语言编译选项。</td>
</tr>
<tr>
  <td><code>CLD</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>在编译C语言的程序时，如何调用链接器。</td>
</tr>
<tr>
  <td><code>CXXLD</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>在编译C++语言的程序时，如何调用链接器。</td>
</tr>
<tr>
  <td><code>FLD</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>在编译fortran语言的程序时，如何调用链接器。</td>
</tr>
<tr>
  <td><code>CLD_FLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>适用所有C Workload使用的链接标志。</td>
</tr>
<tr>
  <td><code>CXXLD_FLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>适用所有CXX Workload使用的链接标志。</td>
</tr>
<tr>
  <td><code>FLD_FLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>适用所有Fortran Workload使用的链接标志。</td>
</tr>
<tr>
  <td><code>LD_FLAGS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>适用所有模块时使用的链接标志。</td>
</tr>
<tr>
  <td><code>LIBS</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>指定链接库选项。</td>
</tr>
<tr>
  <td><code>AR</code></td>
  <td>ar</td>
  <td>namespace</td>
  <td>应用于创建静态库，但是启用特殊选项(如：LTO)时，需要编译器自带AR工具(如：gcc-ar)。</td>
</tr>
<tr>
  <td><code>RANLIB</code></td>
  <td>ranlib</td>
  <td>namespace</td>
  <td>应用于静态库建立索引，以便编译器加速查找符号表。启用特殊选项(如：LTO)时，需要使用编译器自带RANLIB工具(如：gcc-ranlib)。</td>
</tr>
</table>

# JAVA运行参数

<table class="table">
<tr><th>Option</th><th>Default</th><th>Area</th><th>Meaning</th></tr>
<tr>
  <td><code>java_options</code></td>
  <td>""</td>
  <td>namespace</td>
  <td>传递给JVM的调优参数。注意：禁止通过-Xmx设置最大堆容量。</td>
</tr>
</table>

### 调试选项

<table class="table">
<tr><th>Option</th><th>Default</th><th>Area</th><th>Meaning</th></tr>
<tr>
  <td><code>perf</code></td>
  <td>0</td>
  <td>common</td>
  <td>是否执行采集任务，0不采集，1采集。</td>
</tr>
<tr>
  <td><code>perf_timeout</code></td>
  <td>60</td>
  <td>common</td>
  <td>当workload运行结束后，继续等待perf_timeout指定的时间，若采集任务还未结束，则强制终止采集。单位：秒。</td>
</tr>
<tr>
  <td><code>perf_info</code></td>
  <td>{}</td>
  <td>common</td>
  <td>用户自定义的采集命令。

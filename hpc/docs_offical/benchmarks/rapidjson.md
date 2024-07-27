# rapidjson workload 描述

### workload 名称

rapidjson

### 应用分类

基础软件/json解析器

### rapidjson 介绍

**rapidjson** 是一个由C++编写的JSON解析器/生成器，它能够解析JSON格式的字符串。rapidjson的详细文档：https://rapidjson.org/，以及在GitHub上的项目主页https://github.com/Tencent/rapidjson。rapidjson workload是基于rapidjson v1.1.0开发的, 与原始版本的差异如下：

- 删除rapidjson中使用rapidjson例子，教程，单元测试，第三方库。只保留核心业务流程，保留rapidjson使用扩展指令集特性。
- 裁剪使用编译器MSVC代码。
- 删除没有使用的头文件。

### 输入

输入的数据集共17个，来自项目simdjson中，下载地址为：https://github.com/simdjson/simdjson-data。数据集名称为：
1. apache_builds.json
2. github_events.json
3. random.json
4. tree-pretty.json
5. twitterescaped.json
6. update-center.json
7. citm_catalog.json
8. google_maps_api_compact_response.json
9. instruments.json
10. repeat.json
11. twitter_api_compact_response.json
12. twitter.json
13. google_maps_api_response.json
14. mesh.pretty.json
15. semanticscholar-corpus.json
16. twitter_api_response.json
17. twitter_timeline.json

使用g++作为编译器，运行参数为：

```shell
-O3 -DNDEBUG -std=c++11
```

- -O3: 表示开启O3优化特性集
- -DNDEBUG:rapidjson内部的宏，表示启用强制内联
- -std=c++11:按照C++11标准进行编译

### 主要业务流程

1. **Parse**：将内存中的JSON解析为DOM（树结构）。调用RapidJSON中的Parse函数。
2. **Stringify**：将DOM序列化为内存中压缩的JSON（字符串类型，紧凑的JSON，适合网络传输或存储，不适合人类阅读）。
3. **Prettify**：将DOM序列化为内存中处理后的JSON（包含换行及缩进，美化后的JSON）
4. **Statistics**：遍历DOM，计算DOM中各种数据类型的数量。例如字符串数量，布尔类型数量等，以及数组内元素的个数，Object内成员个数等。
5. **Sax Roundtrip**：将内存中的JSON解析为事件，并使用事件生成内存中的JSON。
6. **Sax Statistics**：将内存中的JSON解析为事件，并使用事件进行统计。

对每个数据集，都执行1300次上面的6个过程。

将额外执行一次Parse，Stringify，Prettify过程，并且Stringify和Prettify将输出内存中的JSON到文件中，与标准的输出结果进行比较。

### 输出

输出内容有：

* 输出每个数据集的详细内容，包括名称、大小、object个数、array个数、number个数和string个数等。
* 每个数据集执行6个过程所用时间。
* 输出总时间，单位为s。
* 验证输出json与标准输出结果进行比较结果。

### 编程语言

ISO C++11

### 源代码和license

rapidjson workload 基于rapidjson v1.1.0修改，其使用MIT License条款约束。下载地址：https://codeload.github.com/Tencent/rapidjson/tar.gz/refs/tags/v1.1.0

rapidjson workload 数据集是来源simd项目的测试数据，遵循Apache-2.0 License条款约束。

### 参考：

[1]: https://github.com/Tencent/rapidjson
[2]: http://rapidjson.org/zh-cn/

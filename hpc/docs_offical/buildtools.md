# Buildtools离线包构建指导

------

离线包构建脚本使用CPUBench自带的源码包，完成Python3和CMake3的构建安装，并实现打包供cpubench.sh脚本使用。构建脚本在tools路径下。

当前版本离线包构建脚本仅支持x86/aarch64/mips64平台，因CPUBench自带源码包未合入loongarch64支持，因此无法在loongarch64上使用该脚本完成打包。

1. 工具依赖安装

    使用离线包构建脚本前，需要确保已经安装有bash/tar/xz/gcc/g++/make等工具。

    Redhat系

    ```
    yum install -y bash tar xz gcc gcc-c++
    ```

    或者，Debian系

    ```
    apt-get install -y bash tar xz-utils gcc g++
    ```

2. Python3编译安装

    切换到cpubench的安装目录，执行

    ```
    MAKE_DIST=1 bash tools/cpubench_py3_builder.sh
    ```

3. CMake3编译安装

    切换到cpubench的安装目录，执行

    ```
    MAKE_DIST=1 bash tools/cpubench_cmake_builder.sh
    ```

若只编译安装Python3和CMake，不构建离线包，省略以上步骤MAKE_DIST=1参数即可。

当前架构的离线包会自动打包到buildtools/架构名路径下，请不要修改此路径。
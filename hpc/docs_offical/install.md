### **CPUBench兼容性工具安装**

------

#### 1 工具依赖安装

运行CPUBench工具时，需要确保环境中已安装相应的依赖工具（编译器，cmake（版本>3.14.1）构建工具，以及Java运行环境，Python3以及PyPDF2, reportlab第三方软件包）。您也可以选择使用tools目录下的prepare_env.sh脚本进行离线安装，前提是环境已经配置好yum、apt或zypper。

##### 1.1 安装编译器

   	以下编译器安装任选其一即可，下载相关依赖或工具时，若Redhat系使用yum install安装，若为Debian系使用apt install安装，若为suse系使用zypper in安装。

###### 1.1.1 安装gcc编译器（>=5.3.0)

```sh
Redhat系：yum install gcc gcc-c++ gcc-gfortran
Debian系：apt install gcc g++ gfortran
Suse系：zypper in gcc gcc-c++ gcc-fortran 

注意：
	已知CentOS7.6，EulerOS2，银河麒麟7默认安装版本为4.8.5，需用户源码安装高版本gcc
```

###### 1.1.2 安装clang编译器

           ```sh
步骤 1 官网下载源码（clang版本为11.0.0）
	https://releases.llvm.org/download.html
步骤 2 对源码进行编译安装
	tar -xf llvm-project-11.0.0.tar.xz
	cd llvm-project-11.0.0
	mkdir build && cd build
	cmake -G "Unix Makefiles" -DLLVM_ENABLE_ASSERTIONS=On -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;compiler-rt;flang;mlir" ..
	make && make install

注意：
	1、若提示gcc/g++版本过低，可通过-DCMAKE_C_COMPILER=compiler_dir/bin/gcc -DCMAKE_CXX_COMPILER=compiler_dir/bin/g++ 进行指定（compiler_dir为编译器安装路径）
	2、clang编译器默认安装路径为/usr/local/bin	  
           ```

###### 1.1.3 安装Aocc编译器

```sh
AMD 官网可下载aocc二进制文件，根据官方文档解压，执行source setenv_AOCC.sh即可。
```

###### 1.1.4 安装ICC编译器

```sh
Intel官网下载Intel oneAPI Toolkit进行安装。

Base toolkit下载链接：
https://software.intel.com/content/www/us/en/develop/tools/oneapi/base-toolkit/download.html
	
HPC toolkit下载链接：
   	https://software.intel.com/content/www/us/en/develop/tools/oneapi/hpc-toolkit/download.html
```

###### 1.1.5 安装毕昇编译器

```sh
可参考鲲鹏社区文档进行安装：
https://support.huaweicloud.com/ug-bisheng-kunpengdevps/kunpengbisheng_06_0001.html 
```

###### 注意：

```sh
若用户指定编译器安装路径，需在安装后将其lib库路径配置在LD_LIBRARY_PATH环境变量中

当前窗口生效：
	export LD_LIBRARY_PATH = compiler_dir/lib:$LD_LIBRARY_PATH

永久生效：
	vi /etc/profile 
	export LD_LIBRARY_PATH = compiler_dir/lib:$LD_LIBRARY_PATH 
	source /etc/profile
	
其中compiler_dir为编译器安装路径
```

##### 1.2  安装make

```sh
Redhat系：yum install make
Debian系：apt install make
Suse系：zypper in make
```

##### 1.3 安装java

```sh
Redhat系：yum install java*
Debian系：apt install default-jre
Suse系：zypper in java* 
```

##### 1.4 安装perl（>=5）

```sh
Redhat系：yum install perl
Debian系：apt install perl
Suse系：zypper in perl
```

##### 1.5 安装cmake（>=3.14.1）

```sh
步骤 1 查看本环境cmake版本，若小于依赖的版本需进行安装，且先卸载原有cmake
	cmake --version  
	rpm -q cmake 
	yum remove cmake
步骤 2 安装编译过程中必要的软件
	yum install make kernel-devel openssl-devel
步骤 3 下载cmake源码（网址：https://cmake.org/download/），解压缩并编译安装，本文档以cmake-3.19.2版本为例
	tar -zxvf cmake-3.19.2.tar.gz 
	cd cmake-3.19.2 
	./bootstrap 
	make & make install
步骤 4 查看是否安装成功
	cmake --version
```

##### 1.6 安装python3（>=3.6.0）

```sh
步骤 1 查看原始环境python版本，若小于依赖版本需进行安装
	python3 --version
	如果环境中的python符合依赖版本要求，查看环境中是否存在python.h文件（reportlab依赖），不存在则用以下命令安装
	yum install python3-devel/apt install python3-dev/zypper in python3-devel
步骤 2 安装编译过程中必要的软件（python3.7以上版本依赖）
	yum install libffi-devel/apt install libffi-dev/zypper in libffi-devel
步骤 3 安装zlib(以下两种安装方式择一即可)
	1. 镜像源安装
		Redhat系：yum install zlib zlib-devel
		Debian系：apt install zlib zlib1g-dev
		Suse系：zypper in libz1 zlib-devel
	2. 源码安装（网址：http://www.zlib.net/）
		tar -xf zlib-1.2.11.tar.gz 
		cd zlib-1.2.11 
		./configure 
		make && make install
步骤 4 下载python源码（https://www.python.org/downloads/），解压缩并编译安装，本文以3.6.1版本为例
	tar -xvf Python-3.6.1.tar.xz 
	cd Python-3.6.1 
	./configure --prefix=/usr/local/python3 
	make && make install
步骤 5 添加python3的符号链接
	ln -s /usr/local/python3/bin/python3 /usr/bin/python3
步骤 6 添加pip3的符号链接
	ln -s /usr/local/python3/bin/pip3 /usr/bin/pip3
步骤 7 查看是否安装成功
	python3 --version
```

##### 1.7 安装PyPDF2（>=1.26.0）

```sh
步骤 1 安装，以下两种安装方式择一即可
	1. 使用pip3安装
		pip3 install PyPDF2（需配置网络）
	2. 使用源码安装（网址：https://pypi.org/project/PyPDF2/）
		tar -xvf PyPDF2-master.tar.gz 
		cd PyPDF-xxx/ 
		python3 setup.py install
步骤 2 查看是否安装成功
	python3
	import PyPDF2
```

##### 1.8 安装reportlab（>=3.5.0）

```sh
步骤 1 安装，以下两种安装方式择一即可
	1. 使用pip安装
		pip3 install reportlab（需配置网络）
	2. 使用源码安装（网址：https://pypi.org/project/reportlab/）
		tar -zxvf reportlab-xxx 
		cd reportlab-xxx/ 
		python3 setup.py install 
步骤 2 查看是否安装成功
	python3
	import reportlab
注意：
	pillow安装失败不影响reportlab的安装
```

#### 2 不同环境镜像源配置及依赖安装

##### 2.1 ARM平台

###### 2.1.1  CentOS 7

```sh
步骤 1  将操作系统镜像文件CentOS-7-aarch64-Everything-1810.iso拷贝到服务器的/root目录下。
步骤 2  镜像文件挂载
	mount /root/CentOS-7-aarch64-Everything-1810.iso /mn
步骤 3  添加本地源文件
	1. 进入“/etc/yum.repos.d”目录
		cd /etc/yum.repos.d
	2. 备份之前的yum源配置
		mv *.repo path
	3. 创建local.repo文件
		vi local.repo
	4. 编辑local.repo文件，在文件中添加如下内容
		[local] 
		name=local repo 
		baseurl=file:///mnt 
		enabled=1 
		gpgcheck=0
步骤 4  生效本地源
	yum clean all && yum makecache
步骤 5 工具依赖安装
	参考1 工具依赖安装章节。
```

###### 2.1.2 CentOS 8    

```sh
步骤 1 添加源文件
	1. 进入“/etc/yum.repos.d”目录
		cd /etc/yum.repos.d
	2. 备份之前的yum源配置
		mv *.repo path
	3. 创建Centos8.repo文件
		vi Centos8.repo
	4. 编辑Centos8.repo文件，在文件中添加如下内容
		[BaseOS] 
		name=CentOS-$releasever - Base - mirrors.xxx.com 
		baseurl=镜像源URL 
		gpgcheck=0 
		gpgkey=gpg公钥URL 
		  
		#released updates 
		[AppStream] 
		name=CentOS-$releasever - AppStream - mirrors.xxx.com 
		baseurl=镜像源URL
		gpgcheck=0 
		gpgkey=gpg公钥URL 
		  
		[PowerTools] 
		name=CentOS-$releasever - PowerTools - mirrors.xxx.com 
		baseurl=镜像源URL
		gpgcheck=0 
		gpgkey=gpg公钥URL
		  
		#additional packages that may be useful 
		[extras] 
		name=CentOS-$releasever - Extras - mirrors.xxx.com 
		baseurl=镜像源URL
		gpgcheck=0 
		gpgkey=gpg公钥URL 
		  
		#additional packages that extend functionality of existing packages 
		[centosplus] 
		name=CentOS-$releasever - Plus - mirrors.xxx.com 
		baseurl=镜像源URL 
		gpgcheck=0 
		enabled=0 
		gpgkey=gpg公钥URL
步骤 2 生效本地源
	yum clean all && yum makecache
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

###### 2.1.3 Ubuntu 18.04

```sh
步骤 1 添加源文件
	1. 进入“/etc/opt”目录
		cd /etc/opt
	2. 创建sources.list文件
		vi sources.list
	3. 编辑sources.list文件，在文件中添加如下内容
		deb 镜像源URL bionic main restricted universe multiverse 
		deb 镜像源URL bionic-security main restricted universe multiverse 
		deb 镜像源URL bionic-updates main restricted universe multiverse 
		deb 镜像源URL bionic-proposed main restricted universe multiverse 
		deb 镜像源URL bionic-backports main restricted universe multiverse 
		deb-src 镜像源URL bionic main restricted universe multiverse 
		deb-src 镜像源URL bionic-security main restricted universe multiverse 
		deb-src 镜像源URL bionic-updates main restricted universe multiverse 
		deb-src 镜像源URL bionic-proposed main restricted universe multiverse 
		deb-src 镜像源URL bionic-backports main restricted universe multiverse
步骤 2 生效本地源
	apt-get update
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

###### 2.1.4 Debian 10

```sh
步骤 1 添加源文件
	1. 进入“/etc/opt”目录
		cd /etc/opt
	2. 创建sources.list文件
		vi sources.list
	3. 编辑sources.list文件，在文件中添加如下内容
		deb 镜像源URL buster main contrib non-free 
		deb 镜像源URL buster-updates main contrib non-free 
		deb 镜像源URL buster-backports main contrib non-free 
		deb 镜像源URL buster/updates main contrib non-free 
		deb-src 镜像源URL buster main contrib non-free 
		deb-src 镜像源URL buster-updates main contrib non-free 
		deb-src 镜像源URL buster-backports main contrib non-free
步骤 2 生效本地源
	apt-get update
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

###### 2.1.5 Euler 2

```sh
步骤 1 添加源文件
	1. 进入“/etc/yum.repos.d”目录
		cd /etc/yum.repos.d
	2. 备份之前的yum源配置
		mv *.repo path
	3. 创建EulerOS.repo文件
		vi EulerOS.repo
	4. 编辑EulerOS.repo文件，在文件中添加如下内容
		[base] 
		name=EulerOS-2.0SP8 base 
		baseurl=镜像源URL 
		enabled=1 
		gpgcheck=0 
		gpgkey=gpg公钥URL
步骤 2 生效本地源
	yum clean all && yum makecache
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

###### 2.1.6 Deepin 15

```sh
步骤 1 添加源文件
	1. 进入“/etc/opt”目录
		cd /etc/opt
	2. 创建sources.list文件
		vi sources.list
	3. 编辑sources.list文件，在文件中添加如下内容
		deb [trusted=yes] http://packages.deepin.com/aarch64 camel main contrib non-free
步骤 2 生效本地源
	apt-get update
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

##### 2.2 x86平台

###### 2.2.1 CentOS 7

```sh
步骤 1 添加源文件
	1. 进入“/etc/yum.repos.d”目录
		cd /etc/yum.repos.d
	2. 备份之前的yum源配置
	    mv *.repo path
	3. 创建Centos7.repo文件
		vi Centos7.repo
	4. 编辑Centos7.repo文件，在文件中添加如下内容
		[base] 
		name=CentOS-$releasever - Base - mirrors.xxx.com 
		baseurl=镜像源URL
		gpgcheck=1 
		gpgkey=gpg公钥URL 
		  
		#released updates 
		[updates] 
		name=CentOS-$releasever - Updates - mirrors.xxx.com 
		baseurl=镜像源URL 
		gpgcheck=1 
		gpgkey=gpg公钥URL
		  
		#additional packages that may be useful 
		[extras] 
		name=CentOS-$releasever - Extras - mirrors.xxx.com 
		baseurl=镜像源URL 
		gpgcheck=1 
		gpgkey=gpg公钥URL
		  
		#additional packages that extend functionality of existing packages 
		[centosplus] 
		name=CentOS-$releasever - Plus - mirrors.xxx.com 
		baseurl=镜像源URL
		gpgcheck=1 
		enabled=0 
		gpgkey=gpg公钥URL
步骤 2 生效本地源
	yum clean all && yum makecache
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```

##### 2.3 mips64平台

###### 2.3.1 uos 20

```sh
步骤 1 添加源文件
	1. 进入“/etc/opt”目录
		cd /etc/opt
	2. 创建sources.list文件
		vi sources.list
	3. 编辑sources.list文件，在文件中添加如下内容
		deb http://mirrors.ustc.edu.cn/debian stable main contrib non-free 
		deb http://mirrors.ustc.edu.cn/debian stable-updates main contrib non-free
步骤 2 生效本地源
	apt-get update
步骤 3 工具依赖安装
	参考1 工具依赖安装章节。
```
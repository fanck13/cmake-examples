### 第一章 从可执行文件到库
* Cmake 语言不区分大小写，但是参数区分大小写
* `-H`表示在当前根目录中搜索CMakeLists.txt文件 `-Bbuild`表示在一个名为build的文件夹中通生成项目。
* `cmake --build . --target <target name>`, target name 包括以下：
    - all(或Visual Studio generator中的ALL_BUILD)是默认目标，将在项目中构建所有目标。
    - clean，删除所有生成的文件。
    - rebuild_cache，将调用CMake为源文件生成依赖(如果有的话)。
    - edit_cache，这个目标允许直接编辑缓存。
    - 对于更复杂的项目，通过测试阶段和安装规则，CMake将生成额外的目标：
    - test(或Visual Studio generator中的RUN_TESTS)将在CTest的帮助下运行测试套件。我们将在第4章中详细讨论测试和CTest。
    - install，将执行项目安装规则。我们将在第10章中讨论安装规则。
    - package，此目标将调用CPack为项目生成可分发的包。打包和CPack将在第11章中讨论。 


* `add_library()`

* 逻辑真或假可以用多种方式表示:
    - 如果将逻辑变量设置为以下任意一种：`1`、`ON`、`YES`、`true`、`Y`或非零数，则逻辑变量为`true`。
    - 如果将逻辑变量设置为以下任意一种：`0`、`OFF`、`NO`、`false`、`N`、`IGNORE`、`NOTFOUND`、空字符串，或者以`-NOTFOUND`为后缀，则逻辑变量为`false`。

* `option(<option_variable> "help string" [initial value])`
    - `<option_variable>`表示该选项的变量的名称。
    - `"help string"`记录选项的字符串，在CMake的终端或图形用户界面中可见。
    - `[initial value]`选项的默认值，可以是ON或OFF。

* 指定编译器
    - `cmake -D CMAKE_CXX_COMPILER=clang++ ..`
    - `env CXX=clang++ cmake ..`

* `CMAKE_BUILD_TYPE`的值为:
    - `Debug`：用于在没有优化的情况下，使用带有调试符号构建库或可执行文件。
    - `Release`：用于构建的优化的库或可执行文件，不包含调试符号。
    - `RelWithDebInfo`：用于构建较少的优化库或可执行文件，包含调试符号。
    - `MinSizeRel`：用于不增加目标代码大小的优化方式，来构建库或可执行文件。

* `cmake .. -G"Visual Studio 12 2017 Win64" -D CMAKE_CONFIGURATION_TYPES="Release;Debug"`

* 编译选项可以添加三个级别的可见性：`INTERFACE`、`PUBLIC`和`PRIVATE`。可见性的含义如下:
    - `PRIVATE`，编译选项会应用于给定的目标，不会传递给与目标相关的目标。我们的示例中， 即使compute-areas将链接到geometry库，compute-areas也不会继承geometry目标上设置的编译器选项。
    - `INTERFACE`，给定的编译选项将只应用于指定目标，并传递给与目标相关的目标。
    - `PUBLIC`，编译选项将应用于指定目标和使用它的目标。

* 设置编译器选项 `cmake -D CMAKE_CXX_FLAGS="-fno-exceptions -fno-rtti" ..`

* 设定语言标准 
    ```cmake
    set_target_properties(animals
        PROPERTIES
            CXX_STANDARD 14
            CXX_EXTENSIONS OFF
            CXX_STANDARD_REQUIRED ON
            POSITION_INDEPENDENT_CODE 1
    )
    ```
    ```cmake
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    ```

* 在Windows上导出所有库符号:`set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)`

* 可以使用`target_compile_features()`命令要求为特定的目标提供特定的特性，CMake将自动为标准设置正确的编译器标志。

* `set_source_files_properties(file PROPERTIES property value)` `get_source_file_property(VAR file property)`

* `foreach()`的四种使用方式:
    - `foreach(loop_var arg1 arg2 ...)`: 其中提供循环变量和显式项列表。
    - 通过指定一个范围，可以对整数进行循环，例如：`foreach(loop_var range total)`或`foreach(loop_var range start stop [step])`。
    - 对列表值变量的循环，例如：`foreach(loop_var IN LISTS [list1[...]])` 。参数解释为列表，其内容就会自动展开。
    - 对变量的循环，例如：`foreach(loop_var IN ITEMS [item1 [...]])`。参数的内容没有展开。


### 第二章 检测环境
* CMake定义了`CMAKE_HOST_SYSTEM_PROCESSOR`变量，以包含当前运行的处理器的名称。
* `CMAKE_SIZEOF_VOID_P`为void指针的大小。
* CMake为目标操作系统定义了`CMAKE_SYSTEM_NAME`，因此不需要使用定制命令、工具或脚本来查询此信息。
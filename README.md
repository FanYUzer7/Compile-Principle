# Compile-Principle

## 词法分析与语法分析测试
编译：``g++ node.cpp parser.cpp parserTest.cpp symtb.cpp token.cpp -g `llvm-config --libs --system-libs --cppflags --ldflags` -ll -o testParser``
<br>运行：`./testParser < ./test2.spl`

## 代码生成

没有基本上没有改过CodeGen.h和CodeGen.cpp两个文件，只是可能在CodeGen.h中加了一条声明
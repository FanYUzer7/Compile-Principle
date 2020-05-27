# Compile-Principle

## 词法分析与语法分析测试
编译：`g++ node.cpp parser.cpp parserTest.cpp symtb.cpp token.cpp -g `llvm-config --libs --system-libs --cppflags --ldflags` -ll -o testParser`
运行：`./testParser < ./test2.spl`

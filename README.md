# Compile-Principle

## 词法分析与语法分析测试
编译：
```Shell
g++ node.cpp parser.cpp parserTest.cpp symtb.cpp token.cpp -g <code>`</code>llvm-config --libs --system-libs --cppflags --ldflags<code>`</code> -ll -o testParser
```
运行：`./testParser < ./test2.spl`

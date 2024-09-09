# 编译过程
- gcc -E filePath.c -o outPath.i # pre-process
- gcc -S filePath.c -o outPath.s # 进行预处理和编译成汇编语言
- gcc -c filePath.c -o outPath.o # 编译成二进制文件
- gcc filePath.c -o outPath.exe # 链接成可执行文件

**注意：下面的命令都是基于前面的步骤，只是自动执行了**

# Makefile语法

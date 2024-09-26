```c++

#include <iostream>
#include <string>
using namespace std;

int main(){
    string path = "/22085400631/codes/deploy/3.tensorRt/test/workspeace/a.txt";
    auto f = fopen(path.c_str(), "wb"); // 打开文件 FILE *f
    fwrite("1111", 1, 4, f); // 写入数据 数据, 每个字符站的字节， 数据长度， 文件指针
    fclose(f); // 关闭文件

    return 0;
}
```
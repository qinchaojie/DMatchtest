#include<iostream>
#include<fstream>
using namespace std;

void _write(std::string pathFile){
  std::ofstream ofs;   // 创建对象  
  ofs.open(pathFile, ofs.out);  // open files
  ofs << "hellow" << endl; // write
  ofs.close(); 
};

void _read(std::string pathFile){
  std::ifstream ifs;   // 创建对象  
  ifs.open(pathFile, ifs.in);  // open files
  if (!ifs.is_open()){
    cout << "文件打开失败" << endl;
    return;
  }
  else
    {
        cout << "文件打开成功" << endl;
    }

  // read file

    // 方法1
    char buf[1024] = {0};

    while (ifs.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }

  ifs.close(); 
};

int main(){

  std::ofstream ofs;   // 创建对象
  std::string text = "/Users/xiaoqinzhengtinghao/codes/cpp/7.IO/workspeace/test.txt"; 
  
  _write(text);
  _read(text);

}


#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "--------------定义----------" << endl;
    const char* str = "12345";
    string str0 = str;

    cout << "string: " << str0.c_str() << endl;

    cout << "str0.at(1): " << str0.at(1) << endl;

    string str1 = "hello STL";
    string str2 = str1;
    string str3, str4, str5, str6;
    printf("str1.c_str() = %s\n", str1.c_str());
    printf("str2.c_str() = %s\n", str2.c_str());

    printf("str3 = %s\n", str3.assign("assign example").c_str());
    printf("str4 = %s\n", str4.assign("0123456789", 1, 5).c_str());
    printf("str5 = %s\n", str5.assign(str1).c_str());
    printf("str6 = %s\n", str6.assign(5, '8').c_str());
    cout << "--------------基本操作----------" << endl;
    string s = "hello";
    string s1 = s1;
    string number = "123456";
    printf("s = %s\n", s.c_str());
    printf("s = %s\n", (s += " world!").c_str());
    printf("s = %s\n", s.append(number).c_str());
    printf("s = %s\n", s.append(number, 3).c_str()); // 添加3个
    printf("s = %s\n", s.append(number, 0, 3).c_str()); // 添加0-3

    cout << "--------------查找----------" << endl;
    s = "abc11abc";
    cout << "s = " << s << endl;
    cout << "s.find(\"abc\") = " << s.find("abc") << endl; // 返回下标
    cout << "s.rfind(\"abc\") = " << s.rfind("abc") << endl; // 后面开始，返回下标
    cout << s.replace(2, 3, "88") << endl; // index 2 开始，后面3个替换为88

    cout << "--------------插入----------" << endl;
    s = "hello world!";
    cout << s.insert(1, "xx") << endl;
    cout << s.insert(1, 3, '$') << endl;
    cout << s.erase(1, 5) << endl;

    cout << s.substr(6, 5) << endl;
    
    return 0;
} 
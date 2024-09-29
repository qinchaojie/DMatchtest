#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

int main()
{
    int a = 3;          // a = 3
    std::cout << a << std::endl;
    int b = ++a;        // a = 4, b = a = 4
    cout << a << endl;
    cout << b << endl;

    int c = a++;        // c = a = 4, a + 1 = 5
    cout << a << endl;
    cout << c << endl;

    int d = (5 < 4) ? 5 : 4;
    std::cout << d << std::endl; // 三目运算符

    // 逻辑运算符
    bool var;
    var = (5 > 4) || (4 < 3);
    
    std::cout << var << std::endl;

    // 逗号运算符
    int f = 1;
    f = (f++, f*2);
    std::cout << f << std::endl;

    float i=6.1;
    int g = (int)f; // 向上取整
    cout << g << endl;

    // match
    float res=9.0;
    res = sqrt(res); // 根号
    std::cout << res << std::endl;

    res = abs(res); // 绝对值
    std::cout << res << std::endl;

    res = sin(res); // 正弦
    std::cout << res << std::endl;

    res = cos(res); // 余弦
    std::cout << res << std::endl;

    res = tan(res); // 正切
    std::cout << res << std::endl;

    res = asin(res);    // 反正弦
    std::cout << res << std::endl;

    res = log(res); //  对数
    std::cout << res << std::endl;

    res = log10(res);  // 对数
    std::cout << res << std::endl;

    res = exp(res);    /// 指数
    std::cout << res << std::endl;

    res = pow(res, 2); // 幂  
    std::cout << res << std::endl;

    std::cout << "位运算案例" << std::endl;
    
    return 0;
}
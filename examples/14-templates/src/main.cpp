#include <iostream>
#include <stdio.h>
using namespace std;

// 函数模板
template <typename T>  // or template <class T>  
T add(T a, T b){
    return a + b;
};

// 类模板 
template <class T> 
class Student{
public :
    Student(T name, int age);
    ~Student(){};
public:
    T name;
    int age;
    void print(){
        cout << "name: " << name << ", age: " << age << endl;
    }

    T chance_name(T name);

};

template <class T>
Student<T>::Student(T name, int age){
    this->name = name;
    this->age = age;
};
template <class T>
T Student<T>::chance_name(T name){
    this->name = name;
    return this->name;
};

// 外部函数，修改里面的age成员
template <class T>
void set_age(T& target, int age){
        target.age = age;
        printf("set_age: %d\n", target.age);
    };

template <class T>
void set_age_(T* target, int age){
        target->age = age;
        printf("set_age: %d\n", target->age);
    };


///////////////////////////////////////
////////案例，迭代器实现/////////
template <class T>
class Vector{
public:
    Vector() : mSize(0), mCapacity(1), mpData(new T[mCapacity]){}; //c init 
    ~Vector(){ // 析构函数
        delete [] mpData;
        mpData = nullptr;
        printf("Delect Vector::mpData!\n");
    };

public:
    // 迭代器类
    class iterator; // 声明迭代器类
    iterator begin(); // 迭代器类对象
    iterator end(); // 迭代器类对象

public:
    void info(){
        printf("[INFO OF Vector] size: %d, capacity: %d\n", mSize, mCapacity);
    }
    // 尾插
    void push_back(const T& data){
        // 判断容量,是否需要重新分配内存
        if (mSize == mCapacity)
        {
            mCapacity *= 2;
            T* new_mpData = new T[mCapacity];
            // 拷贝数据
            for (size_t i = 0; i < mSize; ++i)
                new_mpData[i] = mpData[i];

            delete mpData; // 释放内存
            mpData = new_mpData;
        }
        mpData[mSize++] = data;
    };

private:
    T* mpData; // 指向首地址,array
    size_t mSize; // 当前数组大小
    size_t mCapacity; // 当前数组容量
};


// 迭代器类 实现
template <class T>
class Vector<T>::iterator{
private:
    T* mpPtr;
public:
    iterator(T* ptr) : mpPtr(ptr){}; // init 

    // 重载运算符 * , 取value
    T& operator*(){
        return *mpPtr;  // 返回value
    };

    // 重载运算符 ++, 返回类型iterator
    iterator& operator++(){
        ++mpPtr;
        return *this; // 返回的事对象， 使用.直接调用。 mpPtr 是地址,使用->
    };

    bool operator!=(const iterator& other) const {
        return mpPtr != other.mpPtr;
    };


};

// 使用 typename, 实现类内类的函数
template<class T>
typename Vector<T>::iterator Vector<T>::begin(){ // 开始的指针
    return iterator(mpData); //iterator
}
// 不使用 typename
template<class T>
typename Vector<T>::iterator Vector<T>::end(){ //结束指针
    return iterator(mpData+mSize);
}

///////////////////////////////////////

int main(int argc, char** argv){
    
    cout << "############模板函数#########" << endl;
    printf("add<int>(1,2): %d\n", add<int>(1,2));
    printf("add<float>(1,2): %.3f\n", add<float>(1.0f,2.0f));
    
    cout << "############模板类#########" << endl;
    Student<string> s1("zhangsan", 18);
    s1.print();
    string chance_name = s1.chance_name("lisi");
    printf("chacnce_name: %s\n", chance_name.c_str());
    set_age(s1, 20);
    set_age_(&s1, 50);

    cout << "############迭代器案例#########" << endl;
    Vector<int> vec;
    for (int i=0; i<10; ++i){
        vec.push_back(i+1);
    }
    vec.info(); 

    printf("address of fist vec: %p\n", vec.begin());
    printf("value of fist vec: %d\n", *vec.begin());
    printf("address of fist ++vec: %p\n", ++vec.begin());
    printf("value of fist ++vec: %d\n", *++vec.begin());
    printf("address of last vec: %p\n", vec.end());
    printf("value of last vec: %d\n", *vec.end());

    for (auto it = vec.begin(); it != vec.end(); ++it)
        printf("%d ", *it);
    printf("\n");

    return 0;
}


#include <stdio.h>
#include <iostream>

class Person;
class kid;


class Person{

// 友元
friend void getAge(Person* pPerson);  // 函数做友元
friend class kid;  // 类做友元
// friend void kid::getAge(Person* pPerson);  // 类中的函数做友元,需要声明kid类


// 构造和析构函数
public:
    Person(); //构造函数, 使用常对象时，必须显示的实现
    ~Person(); //析构函数

//函数声明
public:
    void printClasses_(); //静态函数，只能访问静态变量
    void printInfo();
    void printAge(){ printf("value of m_age: %d\n", this->m_age);}; // this访问成员变量
    void printAge() const; // 函数重载，可以使常对象也可以访问函数
    // const修饰函数，只能用于读取成员变量，不能修改成员变量
    void printHeight() const;
    // static函数重载
    void getSkills(int c);
    void getSkills(float n);
    void getSkills(int a, int b);
    // 虚函数
    virtual void getm_heavy() { printf("value of Pserson::m_heavy: %d\n", this->m_heavy); };

//成员声明
public:
    static char mclasses_; //静态成员变量，必须函数外定义赋值
    int m_heavy;
    int m_age;
    int m_hight;

    
protected:
    int m_score;
private:
    int m_weight;
};


///////////////////////////////////////////////////////////////////////
////////////////////////这时Person类的实现///////////////////////////////
///////////////////////////////////////////////////////////////////////
// Person 类的实现
Person::Person(){
    m_score = 100;
    m_weight = 50;
    m_heavy = 50;
    m_age = 20;
    m_hight = 180;
}; // 构造函数
Person::~Person(){
    printf("Person::~Person()\n");
}; // 析构函数实现
char Person::mclasses_ = 'P'; //静态成员定义赋值
void Person::printClasses_(){
    printf("value of static member mclasses_ : %c\n", mclasses_);
};
void Person::printInfo(){
    printf("value of this: %p\n", this);
}

void Person::printAge() const { printf("value of m_age: %d\n", this->m_age);};

void Person::printHeight() const {
        // this->m_hight = 190;
        printf("value of m_hight: %d\n", this->m_hight);};
        
void Person::getSkills(int c){
    printf("Used getSkills(int c)\n");
};
void Person::getSkills(float n){
    printf("Used getSkills(float n)\n");

};
void Person::getSkills(int a, int b){
    printf("Used getSkills(int a, int b)\n");

};

///////////////////////////////////////////////////////////////////////
/////////////////////////这是其他类的实现///////////////////////////////

// 友元类
class kid{
public:
    void getAge(Person* pPerson){
        pPerson->m_age = 444;
        printf("value of m_age use func kid::getAge: %d\n", pPerson->m_age);
    };
};

// 继承的三种方式
class Student: public Person{ // public所有成员不改变原有属性
public:
    int m_age = 55;
    int m_score;
    static char mclasses_;

public:
    void getm_heavy() override { 
        printf("value of Student::m_heavy: %d\n", this->m_heavy); 
        };
};
char Student::mclasses_ = 'S';
class Teacher: protected Person{ // protected所有成员改变属性为protected
public:
    int m_salary;
};
class Boss: private Person{ // private所有成员改变属性为private
public:
    int m_bonus;
};

//纯虚函数，不能实例话
class Base{
public:
    Base(){printf("init Base::Base()\n");};
    virtual ~Base(){printf("Base::~Base()\n");}; // 这解决了子类继承，释放内存时，无法调用子类的析构方法
    virtual void getAge() = 0; // 纯虚函数
public:
    int m_age=10;
};

class Son : public Base{
public:
    Son(){
        m_age = 666;
        printf("init Son::Son()\n");
    };
    ~Son(){
        printf("Son::~Son()\n");
    };
    void getAge(){
        printf("value of m_age use func Son::getAge: %d\n", m_age);
    };
};

///////////////////////////////////////////////////////////////////////
/////////////////////////这是全局函数的实现///////////////////////////////
void getAge(Person* pPerson){
    pPerson->m_age = 555;
    printf("value of m_age use func getAge: %d\n", pPerson->m_age);
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


int main(int argc, char **argv){
    std::cout << "####静态成员变量###" << std::endl;
    Person p1;
    printf("p1.mclasses_ = %c\n", p1.mclasses_);
    p1.printClasses_();
    
    std::cout << "###### 指针 this ######" << std::endl;
    Person p2;
    printf("address of p2: %p\n", &p2);
    p2.printInfo();
    p2.printAge();

    std::cout << "###### 常函数const 修饰成员函数 限定 member 的只读属性，不能修改######" << std::endl;
    Person p3;
    p3.printHeight();

    std::cout << "###### 常对象 const 修饰声明对象， 其只能调用常函数######" << std::endl;
    const Person p4; // or-> const Person p4;
    p4.printAge(); // 重载后可以使用
    // p4.m_heavy = 60;  // 成员加入 mutable 可以更改
    p4.printHeight();

    std::cout << "############# 友元 friend 特殊的函数或类访问其他类的内容的方法##################3" << std::endl;
    getAge(&p3); // 函数
    kid k1;
    Person p5;
    k1.getAge(&p5);

    std::cout << "############# 继承 非静态成员都被继承，私有成员不能访问##################3" << std::endl;
    // 可以访问public和protected成员
    Student s1; // public 继承
    s1.m_score = 666; // 可以通过对象访问BaseClass中的public 和 protected
    printf("value of Student.m_age: %d\n", s1.m_age);
    printf("value of Person.m_age: %d\n", s1.Person::m_age);
    printf("value of Student.mclasses_: %c\n", s1.mclasses_);
    printf("value of Person.mclasses_: %c\n", s1.Person::mclasses_);
    Teacher t1;  // protected 继承
    // t1.m_age = 888; // 不能通过对象方式的访问BaseClass中的任何成员，可以通过类内函数访问
    Boss b1; // 不能通过对象的方式访问任何BaseClass成员
    
    std::cout << "############# 重载##################3" << std::endl;
    Person p6;
    p6.getSkills(1);
    p6.getSkills(1.1f);
    p6.getSkills(1,2);

    std::cout << "############# 虚函数 ##################3" << std::endl;
    // Base base1; // 纯虚函数不能实例化
    Son son1; // 必须重写父类中虚函数
    son1.getAge();
    
    Son* son2 = new Son();
    son2->getAge();
    delete son2;
    



    std::cout << "########################" << std::endl;
    return 0;
}
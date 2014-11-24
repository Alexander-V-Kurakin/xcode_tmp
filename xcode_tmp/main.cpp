//
//  main.cpp
//  xcode_tmp
//
//  Created by MUC-StarChild-Mercury on 10/10/14.
//  Copyright (c) 2014 MUC-StarChild-Mercury. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

#define TRACE(x) (std::cout << #x << " = " << x << std::endl)

struct D {
    D();
    std::string gets() const {return this->s;}
    std::string gets_p() const {return this->p;}
private:
    std::string s;
protected:
    std::string p;
};

D::D()
{
    this->s = "structure D";
    this->p = "protected d";
}


struct E {
    E(std::string, std::string);
    const std::string gets() const {return this->s;}
    std::string gets_p() const {return this->p;}
private:
    std::string s;
protected:
    std::string p;
};

E::E(std::string s, std::string p)
{
    this->s = s;
    this->p = p;
}


class C {
    std::string s = "class C";
    int c = 2;
public:
    int get() const {return this->c;}
    std::string gets() const {return this->s;}
};


class B {
    std::string s = "class B";
    int b = 1;
public:
    int get() const {return this->b;}
    std::string gets() const {return this->s;}
};


class A {
    std::string s;
    int a;
    const int b;
    static const int c = 100;
    const int h = 200;
    
    C cc;
public:
    A();
    A(std::string, int, int);
    
    B cb;
    
    int get() const {return a + b + c;}
    int get_h() const {return h;}
    std::string gets() const {return this->s;}
    std::string gets_C() const {return this->cc.gets();}
};

A::A() : b(10)
{
    this->s = "class A";
    this->a = 0;
}

A::A(std::string s, int a, int x = 0) : b(x)
{
    this->s = s;
    this->a = a;
}


class A1 : B, public A {
    const int h = 300;
    static int g;
    int f;
public:
    A1(std::string);
    
    static std::string a1[];    
    
    int get() const {return h;}
    int get_h() const {return A::get_h();}
    std::string gets_B() const {return this->B::gets();}
};

A1::A1(std::string s) : A(s, 11, 22)
{
    f = 0;
}

int A1::g = 22;

std::string A1::a1[] = {"one", "two", "three"};


int main(int argc, const char * argv[]) {
    // insert code here...    
    char *cp = const_cast<char*>("Hello, C++11 World!\n");
    std::cout << cp << std::endl;
    
    int any_value(4);
    
    static A a("class A", any_value, 11);
    A1 a1("inherited from A");
    B b;
    C c;
    
    std::cout << a.gets() << "\t" << b.gets() << "\t" << c.gets() << std::endl;
    std::cout << a1.A::gets() << std::endl;
    std::cout << a.get() << "\t" << b.get() << "\t" << c.get() << "\n\n";
    
    TRACE(a1.get());
    TRACE(a1.get_h());
    std::cout << std::endl;
    
    D d;
    E e("structure E", "protected e");
    E e1[2] = {E("structure E of e1[0]", "protected e1"),
               E("structure E of e1[1]", "protected e1")};
    
    std::cout << d.gets() << "\t" << d.gets_p() << std::endl;
    std::cout << e.gets() << "\t" << e.gets_p() << std::endl;
    
    std::cout << e1[0].gets() << "\t" << e1[0].gets_p() << std::endl;
    std::cout << e1[1].gets() << "\t" << e1[1].gets_p() << "\n\n";
    
    e = e1[1];
    
    std::cout << e.gets() << "\n\n";
    
    TRACE(any_value);
    TRACE(e.gets_p());
    std::cout << std::endl;;
    
    std::cout << "Embedded\t" << a.cb.gets() << "\t" << a.gets_C() << std::endl;
    TRACE(sizeof(A1));
    TRACE(sizeof(A));
    TRACE(a1.gets_B());
    
    return 0;
}

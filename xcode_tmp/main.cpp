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

struct D {
    D();
    std::string gets();
    std::string gets_p();
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

std::string D::gets()
{
    return s;
}

std::string D::gets_p()
{
    return p;
}


struct E {
    E(std::string, std::string);
    std::string gets();
    std::string gets_p();
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

std::string E::gets()
{
    return s;
}

std::string E::gets_p()
{
    return p;
}


class C {
    std::string s = "class C";
    int c = 2;
public:
    int get();
    std::string gets();
};

int C::get()
{
    return c;
}

std::string C::gets()
{
    return s;
}


class B {
    std::string s = "class B";
    int b = 1;
public:
    int get();
    std::string gets();
};

int B::get()
{
    return b;
}

std::string B::gets()
{
    return s;
}


class A {
    std::string s;
    int a;
public:
    A();
    A(std::string, int);
    
    int get();
    std::string gets();
};

A::A()
{
    this->a = 0;
}

A::A(std::string s, int a)
{
    this->a = a;
    this->s = s;
}

int A::get()
{
    return a;
}

std::string A::gets()
{
    return s;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    
    int any_value = 4;
    
    A a("class A", any_value);
    B b;
    C c;
    
    std::cout << a.gets() << "\t" << b.gets() << "\t" << c.gets() << std::endl;
    std::cout << a.get() << "\t" << b.get() << "\t" << c.get() << "\n\n";
    
    D d;
    E e("structure E", "protected e");
    E e1[2] = {E("structure E", "protected e1"), E("structure E", "protected e2")};
    
    std::cout << d.gets() << "\t" << d.gets_p() << std::endl;
    std::cout << e.gets() << "\t" << e.gets_p() << std::endl;
    
    std::cout << e1[0].gets() << "\t" << e1[0].gets_p() << std::endl;
    std::cout << e1[1].gets() << "\t" << e1[1].gets_p() << std::endl;
    
    return 0;
}

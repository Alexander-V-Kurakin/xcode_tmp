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
    std::string gets();
    std::string gets_p();
private:
    std::string s = "structure D";
protected:
    std::string p = "protected d";
};

std::string D::gets()
{
    return s;
}

std::string D::gets_p()
{
    return p;
}


struct E {
    std::string gets();
    std::string gets_p();
private:
    std::string s = "structure E";
protected:
    std::string p = "protected e";
};

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
    
    friend int B::get();
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
    
    A a("class A", 3);
    B b;
    C c;
    
    std::cout << a.gets() << "\t" << b.gets() << "\t" << c.gets() << std::endl;
    std::cout << a.get() << "\t" << b.get() << "\t" << c.get() << "\n\n";
    
    D d;
    E e;
    
    std::cout << d.gets() << "\t" << d.gets_p() << std::endl;
    std::cout << e.gets() << "\t" << e.gets_p() << std::endl;
    
    return 0;
}

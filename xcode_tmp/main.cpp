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
    std::string s = "structure D";
public:
    std::string gets();
    std::string gets_p();
protected:
    std::string d = "protected d";
};

std::string D::gets()
{
    return s;
}

std::string D::gets_p()
{
    return d;
}


struct E {
    std::string s = "structure E";
public:
    std::string gets();
    std::string gets_p();
protected:
    std::string e = "protected e";
};

std::string E::gets()
{
    return s;
}

std::string E::gets_p()
{
    return e;
}


class C {
    std::string s = "class C";
    int C = 2;
public:
    int get();
    std::string gets();
};

int C::get()
{
    return C;
}

std::string C::gets()
{
    return s;
}


class B {
    std::string s = "class B";
    int B = 1;
public:
    int get();
    std::string gets();
};

int B::get()
{
    return B;
}

std::string B::gets()
{
    return s;
}


class A {
    std::string s = "class A";
    int A = 0;
public:
    int get();
    std::string gets();
    
    friend int B::get();
};

int A::get()
{
    return A;
}

std::string A::gets()
{
    return s;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    
    A a;
    B b;
    C c;
    
    std::cout << a.gets() << "\t";
    std::cout << b.gets() << "\t";
    std::cout << c.gets() << std::endl;
    
    std::cout << a.get() << "\t";
    std::cout << b.get() << "\t";
    std::cout << c.get() << "\n\n";
    
    D d;
    E e;
    
    std::cout << d.gets() << "\t";
    std::cout << d.gets_p() << std::endl;
    std::cout << e.gets() << "\t";
    std::cout << e.gets_p() << std::endl;
    
    return 0;
}

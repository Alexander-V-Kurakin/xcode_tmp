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
    std::cout << "Hello, World!\n";
    
    A a;
    B b;
    C c;
    
    std::cout << a.gets() << " ";
    std::cout << b.gets() << " ";
    std::cout << c.gets() << std::endl;
    
    std::cout << a.get() << " ";
    std::cout << b.get() << " ";
    std::cout << c.get() << std::endl;
    
    std::cout << std::hex << a.get() << std::endl;
    
    return 0;
}

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


class Base1 {
public:
    virtual void what() const {std::cout << "class Base1" << std::endl;}
};

class Derived3 : public Base1 {
    int i = 44;
public:
    void what() const {std::cout << "class Derived3" << std::endl;}
    
    friend int ff(Derived3 &);
};

void f(){throw Derived3();}

int ff(Derived3 &d3){return d3.i;}


class Singleton {
    static Singleton s;
    Singleton(int x) : i(x){}
    Singleton(const Singleton&);
    int i;
    static int j;
public:
    static Singleton* instance(){ return &s; }
    static Singleton& GetHandle(){return s;}
    int GetValue() const {return i;}
    static int GetValue_j(){return j;}
    void SetValue(int x){i = x;}
};

Singleton Singleton::s(1);
int Singleton::j = 0;


int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, C++14 World!\n");
    std::cout << cp << std::endl;
    
    uint64_t a;
    std::string raw_string = R"(C:\A\B\C\D\file.txt())";
    
    std::cout << sizeof a << std::endl;
    std::cout << sizeof raw_string << "\t" << raw_string << std::endl;
    std::cout << std::endl;
    
    
    try {
        f();
    } catch (Base1 b) {
        b.what();
    }
    
    try {
        f();
    } catch (Base1& b) {
        b.what();
    }
    std::cout << std::endl;
    
    
    Singleton& s = Singleton::GetHandle();
    std::cout << s.GetValue() << "\t" << s.GetValue_j() << std::endl;
    
    Singleton& s2 = Singleton::GetHandle();
    s2.SetValue(2);
    std::cout << s.GetValue() << std::endl;
    std::cout << Singleton::instance()->GetValue() << std::endl;
    std::cout << std::endl;
    
    Derived3 d3;
    TRACE(ff(d3));
    std::cout << std::endl;
    
    return 0;
}

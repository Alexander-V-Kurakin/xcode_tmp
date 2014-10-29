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
public:
    A();
    A(std::string, int, int);
    
    int get() const {return a + b + c;}
    std::string gets() const {return this->s;}
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


int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, C++11 World!\n");
    std::cout << cp << std::endl;
    
    int any_value(4);
    
    A a("class A", any_value, 11);
    B b;
    C c;
    
    std::cout << a.gets() << "\t" << b.gets() << "\t" << c.gets() << std::endl;
    std::cout << a.get() << "\t" << b.get() << "\t" << c.get() << "\n\n";
    
    D d;
    E e("structure E", "protected e");
    E e1[2] = {E("structure E of e1[0]", "protected e1"),
               E("structure E of e1[1]", "protected e1")};
    
    std::cout << d.gets() << "\t" << d.gets_p() << std::endl;
    std::cout << e.gets() << "\t" << e.gets_p() << std::endl;
    
    std::cout << e1[0].gets() << "\t" << e1[0].gets_p() << std::endl;
    std::cout << e1[1].gets() << "\t" << e1[1].gets_p() << "\n\n";
    
    e = e1[1];
    
    std::cout << e.gets() << std::endl;
    
    return 0;
}

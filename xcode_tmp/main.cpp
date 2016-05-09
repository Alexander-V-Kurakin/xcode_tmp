//
//  main.cpp
//  xcode_tmp
//
//  Created by MUC-StarChild-Mercury on 10/10/14.
//  Copyright (c) 2014 MUC-StarChild-Mercury. All rights reserved.
//

//  C++ access modifiers/specifiers:
//
//              All users   Derived classes     Class' own users/members
//  Public          x               x                   x
//  Protected                       x                   x
//  Private                                             x

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
    
    int j = 3;
};

void f(){throw Derived3();}

int ff(Derived3 &d3)
{
    void (Derived3::*fptr)() const = &Derived3::what;
    (d3.*fptr)();
    
    int (Derived3::*vptr) = &Derived3::j;
    
    return d3.i + d3.*vptr;
}


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


class F {
    std::string s = "class F";
    int a;
public:
    F(){
        a = 0;
        std::cout << s << " constructor is called" << std::endl;
    }
    
    virtual void set_a(int n){
        a = n+111;
        std::cout << s << ": " << a << std::endl;
    }
    
    int get_a() const {return a;}
};


class G : public F {
    std::string s = "class G";
    int a;
    
public:
    G(){
        a = 4000;
        std::cout << s << " constructor is called" << std::endl;
    }
    
    void set_a(int n){
        a = n+222;
        std::cout << s << ": " << a << std::endl;
    }
    
    int get_a() const {return a;}
};


void f1(F& f){f.set_a(1000);}

int* i(int **p){ return *p; }


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
    
    F f;
    std::cout << std::endl;
    
    std::unique_ptr<std::string[]> ps(new std::string[2]);
    ps[1] = "unique_ptr is used";
    std::unique_ptr<int64_t[]> pi(new int64_t[2]);
    pi[1] = 100;
    
    G g;
    std::cout << std::endl;
    std::cout << ps[1] << "\t" << pi[1] << std::endl;
    std::cout << std::endl;
    
    f1(g);
    TRACE(f.get_a());
    TRACE(g.F::get_a());
    TRACE(g.get_a());
    std::cout << std::endl;
    
    int b = 5, c = 9;
    int *p1 = &b, *p2 = &c, **p3;
    
    p1 = p2;
    p3 = &p2;
    
    TRACE(*p1);
    TRACE(p1);
    TRACE(*p2);
    TRACE(p2);
    TRACE(*p3);
    TRACE(**p3);
    TRACE(p3);
    
    TRACE(i(&p1));
    TRACE(*(i(&p1)));
    
    return 0;
}

/*  Output:
 
 Hello, C++14 World!
 
 8
 24	C:\A\B\C\D\file.txt()
 
 class Base1
 class Derived3
 
 1	0
 2
 2
 
 ff(d3) = class Derived3
 47
 
 class F constructor is called
 
 class F constructor is called
 class G constructor is called
 
 unique_ptr is used	100
 
 class G: 1222
 f.get_a() = 0
 g.F::get_a() = 0
 g.get_a() = 1222
 
 *p1 = 9
 p1 = 0x7fff5fbff168
 *p2 = 9
 p2 = 0x7fff5fbff168
 *p3 = 0x7fff5fbff168
 **p3 = 9
 p3 = 0x7fff5fbff158
 i(&p1) = 0x7fff5fbff168
 *(i(&p1)) = 9
 Program ended with exit code: 0
*/
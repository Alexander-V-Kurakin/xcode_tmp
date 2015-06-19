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


template <typename T> void swap( T& x, T& y)
{
    T t = x; x = y; y = t;
}


template <typename T>
class I {
    T a;
public:
    I(T n): a(n){};
    T get_a() const;
};

template <typename T>
T I<T>::get_a() const
{
    return a;
}


class Base {
public:
    Base(int = 0){std::cout << "Base" << std::endl;}
    
    virtual ~Base(){};
    
    virtual std::string vf() const = 0;
};

class Derived1 : virtual public Base {
public:
    Derived1() : Base(1){}
    
    std::string vf() const throw() {return "Derived1";};
};

class Derived2 : virtual public Base {
public:
    Derived2() : Base(2){}
    
    std::string vf() const throw() {return "Derived2";};
};

class MI : public Derived1, public Derived2 {
public:
    MI(){}
    
    std::string vf() const throw() {return Derived1::vf();}
    
    void ef() throw (const char*) {throw "base class exception";}
};

class X : public MI {
public:
    X(){}
    
    std::string vf() const throw() {return Derived2::vf();}
    
    void ef(int n)
    {
        if (n < 2) throw "const char* exception";
        else
            throw n;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, C++14 World!\n");
    std::cout << cp << std::endl;
    
    MI mi;
    TRACE(mi.vf());
    X x;
    TRACE(x.vf());
    TRACE(x.MI::vf());
    std::cout << std::endl;
    
    for (int n = 0; n < 3; n++)
    {
        try {
            x.ef(n);
        } catch (const char* s) {
            std::cout << s << " caught\t" << n << std::endl;
        } catch (...) {
            std::cout << "any other exception caught\t" << n << std::endl;
        }
        
        try {
            x.MI::ef();
        } catch (const char* s) {
            std::cout << s << " caught\t" << n << std::endl;
        }
    }
    std::cout << std::endl;
    
    return 0;
}

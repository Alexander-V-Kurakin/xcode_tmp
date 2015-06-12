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
    virtual std::string vf() const = 0;
    virtual ~Base(){};
};

class Derived1 : virtual public Base {
public:
    std::string vf() const {return "Derived1";};
};

class Derived2 : virtual public Base {
public:
    std::string vf() const {return "Derived1";};
};

class MI : public Derived1, public Derived2 {
public:
    std::string vf() const {return Derived1::vf();}
};


int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, C++14 World!\n");
    std::cout << cp << std::endl;
    
    {
    int x = 1, y = 2;
    std::cout << "x = " << x << "\ty = " << y << std::endl;
    swap(x, y);
    std::cout << "x = " << x << "\ty = " << y << std::endl;
    }
    
    {
    float x = 1.1, y = 2.2;
    std::cout << "x = " << x << "\ty = " << y << std::endl;
    swap(x, y);
    std::cout << "x = " << x << "\ty = " << y << std::endl;
    }
    std::cout << std::endl;
    
    I<float> i(3.3);
    TRACE(i.get_a());
    I<int> j(4);
    TRACE(j.get_a());
    std::cout << std::endl;
    
    MI mi;
    TRACE(mi.vf());
    std::cout << std::endl;
    
    return 0;
}

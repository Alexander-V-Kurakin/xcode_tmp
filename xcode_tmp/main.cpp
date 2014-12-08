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


class F {
    std::string s = "class F";
    int a;
public:
    F(){
        a = 0;
        std::cout << s << " constructor is called\t" << a << std::endl;
    }
    
    virtual ~F() = 0;
    
    virtual void set_a(int n) = 0;
    
    int get_a() const {return a;}
};

F::~F()
{
    std::cout << s << " destructor is called\t" << std::endl;
}


class G : public F {
    std::string s = "class G";
    int a;
public:
    G(){
        a = 4000;
        std::cout << s << " constructor is called\t" << a << std::endl;
    }
    
    void set_a(int n){
        a = n+2;
        std::cout << s << ": " << a << std::endl;
    }
    
    int get_a() const {return a;}
};


class H : public G {
    std::string s = "class H";
    int a;
public:
    H(){
        a = 6000;
        std::cout << s << " constructor is called\t" << a << std::endl;
    }
    
    void set_a(int n){
        a = n+3;
        std::cout << s << ": " << a << std::endl;
    }
    
    int get_a() const {return a;}
};


void f1(F& f){f.set_a(1000);}


int main(int argc, const char * argv[]) {
    // insert code here...    
    char *cp = const_cast<char*>("Hello, C++11 World!\n");
    std::cout << cp << std::endl;
    
    G g;
    std::cout << std::endl;
    
    f1(g);
    TRACE(g.F::get_a());
    TRACE(g.get_a());
    std::cout << std::endl;
    
    H h;
    std::cout << std::endl;
    
    f1(h);
    TRACE(h.G::F::get_a());
    TRACE(h.G::get_a());
    TRACE(h.get_a());
    std::cout << "\n\n";
    
    F* f = new H;
    delete f;
    
    return 0;
}

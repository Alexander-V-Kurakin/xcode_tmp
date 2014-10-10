//
//  main.cpp
//  xcode_tmp
//
//  Created by MUC-StarChild-Mercury on 10/10/14.
//  Copyright (c) 2014 MUC-StarChild-Mercury. All rights reserved.
//

#include <iostream>

class B {
    int B = 1;
public:
    int get();
};

int B::get()
{
    return B;
}

class A {
    int A = 0;
public:
    int get();
};

int A::get()
{
    return A;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    A a;
    B b;
    
    std::cout << a.get() << "\n";
    std::cout << b.get() << "\n";
    
    return 0;
}

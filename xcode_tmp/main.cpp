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

using namespace std;

#define TRACE(x) (cout << #x << " = " << x << endl)

//volatile const unsigned int *v = (unsigned int *)(0x1234);                     // Succeeded
//volatile const unsigned int *v1 = reinterpret_cast<unsigned int *>(0x1234);    // Succeeded
//
//unsigned int f3()
//{
//    v1 = reinterpret_cast<unsigned int *>(0x5577);  // Just a variant, Succeeded
//    return *v + *v1;  // Succeeded
//}
//
//unsigned int f4()
//{
//    volatile static unsigned int *s = (unsigned int *)(0x1234);   // Succeeded
//
//    return *s;
//}

class Base1 {
public:
    virtual void what() const {cout << "class Base1" << endl;}
};

class Derived3 : public Base1 {
    int i = 44;
public:
    void what() const {cout << "class Derived3" << endl;}
    
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
    string s = "class F";
    int a;
public:
    F(){
        a = 0;
        cout << s << " constructor is called" << endl;
    }
    
    virtual void set_a(int n){
        a = n+111;
        cout << s << ": " << a << endl;
    }
    
    int get_a() const {return a;}
};


class G;

struct Y {
    string f(G*);
};

struct K {
    string f(G*);
};


class G : public F {
    string s = "class G", s1 = "Class G";
    int a;
    
public:
    G(){
        a = 4000;
        cout << s << " constructor is called" << endl;
    }
    
    void set_a(int n){
        a = n+222;
        cout << s << ": " << a << endl;
    }
    
    int get_a() const {return a;}
    string get_s1(){return s1;}
    string get_s(){return s;}
    
    friend string Y::f(G*);
    friend string f2(void);
    friend string f2(G*);
    friend struct K;
    
    struct L;           // The nested structure has to be declared first
    friend struct L;    // Then, it has to be declared as friend
    struct L {          // Then only the structure has to be defined
    private:
        G* g;
        string l = "Nested structure";
    public:
        string get_l(void){return l;};
        string get_sG(G* g){return g->get_s();};
        int get_aG(G* g);
    };
    
private:
    struct M;           // Declaration only, implementation is hidden
    M* smile;
    
public:
    int init(int x);
    string cleanup(void);
};


struct G::M             // Implementation
{
    int i = 0;
};

int G::init(int x)
{
    smile = new M;
    
    TRACE(smile->i);
    
    return smile->i = x;
}

string G::cleanup(void)
{
    delete smile;
    
    return "G::cleanup(void) is called";
}


int G::L::get_aG(G* g)
{
    return g->get_a();
}

string Y::f(G* g)
{
    return g->s1 = "friend Y::f(G*) is called";
}

string f2(void)
{
    G g;
    
    TRACE(g.get_s1());
    
    return g.s1 = "friend f2(void) is called";
}

string f2(G* g)
{
    return g->s1 = "friend f2(G* g) is called";
}

string K::f(G* g)
{
    return g->s1 = "friend K::f(G*) is called";
}


void f1(F& f){f.set_a(1000);}

int* i(int **p){ return *p; }


class Stack {
    enum { size = 100 };
    int stack[ size ];
    int top;
public:
    Stack() : top( 0 ) {}
    
    void push( int i ) { stack[ top++ ] = i; }
    int pop() { return stack[ --top ]; }
    
    class iterator;         // Nested iterator
    friend class iterator;
    class iterator {
        Stack& s;
        int index;
    public:
        iterator( Stack& is ) : s( is ), index( 0 ) {}
        
        int operator++() { return s.stack[ ++index ]; }         // Prefix
        int operator++( int ) { return s.stack[ index++ ]; }    // Postfix
        
        iterator& operator= ( iterator& rv ) {
            index = rv.index;
            return *this;
        }
        
        // To select the current element, the operator* can be used
        // instead of call to current(), which makes the iterator
        // look more like a pointer and is a common practice
        int operator*() const { return s.stack[index];}
        
        iterator& operator+= ( int rv ) {
            index += rv;
            return *this;
        }

        bool operator== ( const iterator& rv ) const {
            return index == rv.index;
        }

        bool operator!= ( const iterator& rv ) const {
            return index != rv.index;
        }

        iterator begin() { return iterator( *this ); }
        
        int current() const { return s.stack[ index ]; }
        void set( int i ) { index = i; };
        
        friend ostream& operator<< ( ostream& os, const iterator& it ) {
            return os << it.current();
//            return os << *it;         // see operator* definition
        }
    };
};

class H {
public:
    // There is one chunk of storage for a static data member, no matter how objects
    // of that class are created. All objects share the same static storage space for
    // that data member, so it's a way for them to 'communicate to each other'.
    
    int get() { static int static_val = 1; return static_val++; }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, World!\n");
        cout << cp << endl;
    // __cplusplus: This preprocessor macro provides a numeric value indicating
    // the C++ standard. However, it's not always reliable and might not reflect
    // the full capabilities of the compiler.
//    TRACE(__cplusplus);
//    TRACE(__clang_version__);
    std::cout << "__cplusplus\t\t\t" << __cplusplus << std::endl;
    std::cout << "__clang_version__\t" << __clang_version__ << std::endl << std::endl;
    
    H h1, h2, h3;
    TRACE(h1.get());
    TRACE(h2.get());
    TRACE(h3.get());
    cout << endl;
    
    
    {
        int a = 0, b = 1, c = 2, d = 3, e = 4;
        
        // static_cast<void> is used to suppress the warnings
        // original expression is a = (++a, ++b, ++c, ++d, ++e);
        
        a = (static_cast<void>(++a), static_cast<void>(++b), static_cast<void>(++c), static_cast<void>(++d), ++e);
        cout << a << " " << b << " " << c << " " << d << " " << e << endl;
        
        // static_cast<void> is used to suppress the warnings
        // original expression is a = ++a, ++b, ++c, ++d, ++e;
        // that will be evaluated to (a = ++a), ++b, ++c, ++d, ++e;
        
        a = 0;
        static_cast<void>(a = ++a), static_cast<void>(++b), static_cast<void>(++c), static_cast<void>(++d), ++e;
        cout << a << " " << b << " " << c << " " << d << " " << e << endl << endl;
    }
    
    uint64_t a;
    string raw_string = R"(C:\A\B\C\D\file.txt())";
    
    cout << sizeof a << endl;
    cout << sizeof raw_string << "\t" << raw_string << endl;
    cout << endl;
    
    
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
    cout << endl;
    
    
    Singleton& s = Singleton::GetHandle();
    cout << s.GetValue() << "\t" << s.GetValue_j() << endl;
    
    Singleton& s2 = Singleton::GetHandle();
    s2.SetValue(2);
    cout << s.GetValue() << endl;
    cout << Singleton::instance()->GetValue() << endl;
    cout << endl;
    
    Derived3 d3;
    TRACE(ff(d3));
    cout << endl;
    
    F f;
    cout << endl;
    
    unique_ptr<string[]> ps(new string[2]);
    ps[1] = "unique_ptr is used";
    unique_ptr<int64_t[]> pi(new int64_t[2]);
    pi[1] = 100;
    
    G g;
    cout << endl;
    cout << ps[1] << "\t" << pi[1] << endl;
    cout << endl;
    
    f1(g);
    TRACE(f.get_a());
    TRACE(g.F::get_a());
    TRACE(g.get_a());
    cout << endl;
    
    Y y;
    TRACE(g.get_s1());
    TRACE(y.f(&g));
    TRACE(g.get_s1());
    cout << endl;
    TRACE(f2());
    TRACE(f2(&g));
    cout << endl;
    K k;
    TRACE(k.f(&g));
    TRACE(g.get_s1());
    cout << endl;
    
    G::L l;                 // Nested structure is a separate object
    TRACE(l.get_sG(&g));
    TRACE(l.get_l());
    TRACE(l.get_aG(&g));
    cout << endl;
    
    TRACE(g.init(12345));
    TRACE(g.cleanup());
    cout << endl;
    
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
    cout << endl;
    
    int& rd = b;
    TRACE(&rd);
    TRACE(sizeof(long int));
    TRACE(sizeof(p1));
    TRACE(sizeof(&rd - p1));
    TRACE(*(&rd));
    TRACE(rd);
    TRACE(b);
    cout << endl;
    
    
    Stack stack;
    for( int i = 0; i < 100; i++ ) stack.push( i );
    Stack::iterator it = Stack::iterator( stack ).begin();
    for( int j = 0; j < 10; j++ ) cout << it++ << "\t";
    cout << endl;
    
    TRACE( it.current() );
    
    it += -10;
    for( int j = 0; j < 10; j++ ) cout << ++it << "\t";
    cout << endl;
    
    it += 5;
    for( int j = 0; j < 10; j++ ) cout << it++ << "\t";
    cout << endl;
    
    it.set( 40 );
    cout << "it.set( 40 )" << endl;
    for( int j = 0; j < 10; j++ ) cout << it++ << "\t";
    cout << endl;
    
    
    Stack::iterator start = Stack::iterator( stack ).begin();
    Stack::iterator end = Stack::iterator( stack ).begin();
    
    it.set( 0 );
    start += 50;
    end += 60;
    
    while ( start != end ) cout << start++ << "\t";
    cout << endl;
    
    start = end;
    while ( start != end ) cout << start++ << "\t";
    if ( start == end ) cout << "start = end";
    cout << endl;

    return 0;
}

/*  Output:
 
 Hello, World!

 __cplusplus            201703
 __clang_version__    12.0.0 (clang-1200.0.32.29)

 5 2 3 4 5
 1 3 4 5 6

 8
 24    C:\A\B\C\D\file.txt()

 class Base1
 class Derived3

 1    0
 2
 2

 ff(d3) = class Derived3
 47

 class F constructor is called

 class F constructor is called
 class G constructor is called

 unique_ptr is used    100

 class G: 1222
 f.get_a() = 0
 g.F::get_a() = 0
 g.get_a() = 1222

 g.get_s1() = Class G
 y.f(&g) = friend Y::f(G*) is called
 g.get_s1() = friend Y::f(G*) is called

 f2() = class F constructor is called
 class G constructor is called
 g.get_s1() = Class G
 friend f2(void) is called
 f2(&g) = friend f2(G* g) is called

 k.f(&g) = friend K::f(G*) is called
 g.get_s1() = friend K::f(G*) is called

 l.get_sG(&g) = class G
 l.get_l() = Nested structure
 l.get_aG(&g) = 1222

 g.init(12345) = smile->i = 0
 12345
 g.cleanup() = G::cleanup(void) is called

 *p1 = 9
 p1 = 0x7ffeefbff208
 *p2 = 9
 p2 = 0x7ffeefbff208
 *p3 = 0x7ffeefbff208
 **p3 = 9
 p3 = 0x7ffeefbff1f8
 i(&p1) = 0x7ffeefbff208
 *(i(&p1)) = 9

 &rd = 0x7ffeefbff20c
 sizeof(long int) = 8
 sizeof(p1) = 8
 sizeof(&rd - p1) = 8
 *(&rd) = 5
 rd = 5
 b = 5

 0    1    2    3    4    5    6    7    8    9
 it.current() = 10
 1    2    3    4    5    6    7    8    9    10
 15    16    17    18    19    20    21    22    23    24
 it.set( 40 )
 40    41    42    43    44    45    46    47    48    49
 50    51    52    53    54    55    56    57    58    59
 start = end
 Program ended with exit code: 0
*/

#include <iostream>

/*
    ? What is protected class members ?
    They are members that both the class and the class that is inheriting the first have access
    But outside those classes we don't have access to them 

*/

class A {
    private:
        int pr;
    protected:
        int pro;
    public:
        int pub;
        
        void f() {
            pub = 1;
            pr = 1;
            pro = 1;
        }
};

class B: public A {
    public:
        void g() {
            pub = 0;
            pro = 0;
            // pr = 0 -> No access
        }
};

int main() {
    A a;
    a.pub = 2;
    //a.pro = 2 -> No access
    //a.pr = 2 -> No access

    B b;
    b.pub = 2;
    //b.pro = 2 -> No access
    //b.pr = 2 -> No access
}
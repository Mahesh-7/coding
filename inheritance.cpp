#include<iostream>

using namespace std;

class A
{
    public:
    A(int a);
};

A::A(int a)
{
    cout<<a<<endl;
}

class B : public A
{
    public:
    B(int a,int b);
};

B::B(int a,int b) : A(a)
{
    cout<<a<<b<<endl;
}


int main()
{
    B b(1,2);  // derive constructor will call base constructor as well once obj created

    return 0;
}
#include<iostream>

using namespace std;

class shape  //base
{
    protected:
    int width,height;
    public:
    shape(int a,int b)
    {
        width = a;
        height = b;
    }

    virtual void area() //override //bypass
    {
        cout<< "base";
    }

};

class rectangle : public shape  //derive
{
    public:
    rectangle(int a,int b) : shape(a,b){} //dummy route to base to update values

    void area()
    {
        cout<< width * height;
    }
};

int main()
{
    shape *s;
    rectangle r(10,20);
    s=&r;
    r.area();
    s->area();
    return 0;
}
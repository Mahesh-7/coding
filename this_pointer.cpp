#include<iostream>

using namespace std;

class myClass
{
    private:
    int num1,num2;
    public:
    void setValue(int num1,int num2)
    {
        this->num1=num1;
        this->num2=num2;
    }
    void print()
    {
        cout<<num1+num2;
    }
};

int main()
{
    myClass obj;
    obj.setValue(10,20);
    obj.print();
    return 0;
}
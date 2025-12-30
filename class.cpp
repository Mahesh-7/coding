#include<iostream>

using namespace std;

class myClass
{
    private:
    int age;

    public:
    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
    void print()
    {
        cout<<age;
    }
    
};
int main()
{
    myClass obj;
    obj.setAge(10);
    cout<<obj.getAge()<<endl;
    obj.print();
    return 0;
}
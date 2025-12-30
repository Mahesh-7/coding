#include<iostream>

using namespace std;

class myconstructor
{
    public:
    myconstructor(int a, int b)
    {
        cout<<"constructor called "<<a<<b <<endl;
    }
    ~myconstructor()
    {
        cout<<"destructor called\n";
    }
};

int main()
{
    myconstructor obj(7,1);
    return 0;
}
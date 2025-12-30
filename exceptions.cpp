#include<iostream>
using namespace std;

int main()
{
    int age=18;
    try
    {
        if(age>=18)
        {
            cout<<"eligible";
        }
        else{
            throw(age);
        }
    }
    catch(...) //catch(int age)
    {
        cout<<"not eligible";
    }

    return 0;
}
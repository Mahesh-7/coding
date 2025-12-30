#include<iostream>

using namespace std;

int main()
{
    char n[]="hello";
    char * name = new char[10];
    name = n;
    cout<<name;
    return 0;
}
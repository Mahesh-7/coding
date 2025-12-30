#include<iostream>
#include<string>

using namespace std;

typedef struct 
{
    char name[10];
    int jersey_no;
}info_st;

int main()
{
    #if 0
        char name[10];
        int jersey_no;
        cout<<"enter name:";
        cin>>name;
        cout<<"enter jersey_no:";
        cin>>jersey_no;
        cout<<"hello c++ world\nwelcome " << name << " " << jersey_no; 
    #else
        info_st info;
        cout<<"enter name:";
        cin>>info.name;
        cout<<"enter jersey_no:";
        cin>>info.jersey_no;
        cout<<"hello c++ world\nwelcome " << info.name << " " << info.jersey_no; 
    #endif
    return 0;
}
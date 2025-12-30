#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    #if 0 //write
        ofstream file;
        file.open("doc.txt");
        file<<"hello mahesh";
    #else //read
        ifstream file;
        file.open("doc.txt");
        string outputTextfromfile;
        while(getline(file,outputTextfromfile))
        {
            cout<<outputTextfromfile;
        }
    #endif
        file.close();
        return 0;
}
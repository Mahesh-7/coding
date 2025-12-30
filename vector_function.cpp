#include<iostream>
#include<vector>
using namespace std;

vector<int> createArray(int n)
{
    vector<int> arr;
    for(int i=1;i<n;i++)
    {
        arr.push_back(i*10);
    }
    return arr;
}

int main()
{
    vector<int> arr= createArray(5);
    for(auto i=0;i<arr.size();i++) //auto will take care of type of i
    {
        cout<<arr[i]<<endl;
    }
}
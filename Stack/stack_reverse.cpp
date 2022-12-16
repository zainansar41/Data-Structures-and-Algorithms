#include<iostream>
#include <cstring>
#include<stack>
using namespace std;
void reverse(char c[],int n)
{
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    }

    for (int i = 0; i < n; i++)
    {
        c[i]=s.top();
        s.pop();
    } 
}

int main(){
    char c[51];
    cout<<"enter a word = ";
    cin>>c;
    reverse(c,strlen(c));
    cout<<c;
    return 0;
}
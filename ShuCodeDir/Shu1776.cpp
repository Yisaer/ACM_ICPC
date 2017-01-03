#include <cstdio>
#include <iostream>
using namespace std;
int F[50];
int main ()
{
    F[1]=1;
    F[2]=1;
    int n;
    for(int i=3;i<=45;i++)
        F[i]=F[i-1]+F[i-2];
    while(cin>>n)
        cout<<F[n]<<endl;
    
}

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int vis[105];


int main ()
{
    int   n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>vis[i];
        sort(vis,vis+n);
        for(int i=0;i<n;i++)
        {
            if(i)
                cout<<" ";
            cout<<vis[i];
            
        }
        cout<<endl;
        
    }
    
    
    
}

#include <cstdio>
#include <iostream>
using namespace std;
char  str1[105];
char  str2[105];
char  str3[105];

int main ()
{
    
    while(cin>>str1>>str2)
    {
        int num1[105];
        int num2[105];
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        long long l1=strlen(str1);
        long long l2=strlen(str2);
        char t1[105];
        char t2[105];
        long long j=l1-1;
        for(int i=0;i<l1;i++)
            t1[i]=str1[j--];
        j=l2-1;
        for(int i=0;i<l2;i++)
            t2[i]=str2[j--];
        
        
        
        for(int i=0;i<l1;i++)
            num1[i]=t1[i]-'0';
        for(int i=0;i<l2;i++)
            num2[i]=t2[i]-'0';
  
        int ans[105];
        memset(ans,0,sizeof(ans));
        long long  Max=max(l1,l2);
        for(int i=0;i<Max;i++)
        {
            ans[i]+=num1[i]+num2[i];
            if(ans[i]>=8)
            {
                ans[i]-=8;
                ans[i+1]++;
                
            }
            
        }
        if(ans[Max])
            Max++;
        int Ans[105];
        memset(Ans,0,sizeof(Ans));
       long long  A=Max-1;
        for(int i=0;i<Max;i++)
            Ans[i]=ans[A--];
        cout<<str1<<"+"<<str2<<"=";
        for(int i=0;i<Max;i++)
            cout<<Ans[i];
        cout<<endl;
        
        
        
    }
    
    
    
}

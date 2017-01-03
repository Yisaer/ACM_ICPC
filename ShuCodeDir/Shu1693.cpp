//  main.cpp
//  ANS
//
//  Created by 高松 on 15/10/13.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long
#include <cstring>
#include <algorithm>
#include <cctype>
#define ll long long
char str[9999];
char ans[999999];

int main ()
{
    int n;
    cin>>n;
    int cas=0;
    while(n--)
    {
        cas++;
        if(cas==1)
        char q=getchar();
        
        
        gets(str);
        ll len=strlen(str);
       // cout<<str<<endl;
        if(str[0]>='0'&&str[0]<='9')
        {
            int j=0;
            int num=0;
            for(ll i=len-1;i>=0;i--)
            {
                num=num*10+str[i]-'0';
                if(num<32)
                {
                    continue;
                }
                else
                {
                    char a;
                    
                    if(num>=32&&num<=63)
                    {
                        if(num==32)
                            a=' ';
                        if(num==44)
                            a=',';
                        if(num==46)
                            a='.';
                        if(num==58)
                            a=':';
                        if(num==59)
                            a=';';
                        if(num==63)
                            a='?';
                        if(num==33)
                            a='!';
                    }
                    else
                    {
                    a=char(num);
                    }
                    ans[j++]=a;
                    num=0;
                }
            }
            ans[j]='\0';
            cout<<ans<<endl;
        }
        else
        {
        int j=0;
        for(ll i=len-1;i>=0;i--)
        {
            int A=0;
            if(isalpha(str[i]))
            {
             A=int(str[i]);
            }
            else
            {
               if(str[i]=='!')
                   A=33;
                if(str[i]==',')
                    A=44;
                if(str[i]=='.')
                    A=46;
                if(str[i]==':')
                    A=58;
                if(str[i]==';')
                    A=59;
                if(str[i]=='?')
                    A=63;
                if(str[i]==' ')
                    A=32;
                
            }
           
            while(A)
            {
                char a=(A%10)+'0';
                ans[j++]=a;
                A/=10;
                
            }
            
        
            
        }
        ans[j]='\0';
            cout<<ans<<endl;
        }
        
    }

}

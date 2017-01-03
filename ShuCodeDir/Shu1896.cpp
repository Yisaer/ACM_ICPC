//  main.cpp
//  小6的梦话
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
char S[105];


int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--)
    {
        cin>>S;
        int len=strlen(S);
        char str[105];
        for(int i=0;i<len;i++)
        {
            str[i+1]=S[i];
            
        }
        str[len+1]='\0';
        str[0]='a';
        int ans=0;
        bool flag=true;
        for(int i=0;i<len;i++)
        {
            if(S[i]!='z')
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<len<<endl;
            
        }
        else
        {
            bool zflag=false;
        for(int i=1;i<=len;i++)
        {
            if(i!=1&&i!=len&&str[i]=='z'&&str[i-1]!='z'&&str[i+1]!='z')
                continue;
            else if(i==1&&str[i+1]=='z')
                ans++;
            else if(i==len&&str[i-1]=='z')
                ans++;
            else if(str[i]=='z'&&str[i+1]=='z'&&str[i-1]=='z')
                ans++;
            else if(str[i]=='z'&&str[i+1]!='z'&&zflag==false)
                zflag=true;
            else if(str[i]=='z'&&str[i-1]!='z'&&zflag==true)
            {
                ans++;
                zflag=false;
            }
        }
        
        cout<<ans<<endl;
        }
        
    }
    return 0;
}

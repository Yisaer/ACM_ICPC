//  main.cpp
//  1461 四种括号
//
//  Created by 高松 on 15/12/4.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <stack>
#include <cstring>
char str[300];
#define ll long long

int main(int argc, const char * argv[]) {
    
    while(cin>>str)
    {
        ll len=strlen(str);
        stack<char>s;
        for(int i=0;i<len;i++)
        {
            if(s.empty()){
                s.push(str[i]);
            }
            else{
                char ch=s.top();
                if(ch=='('){
                    if(str[i]==')')
                        s.pop();
                    else
                        s.push(str[i]);
                }else if(ch=='<'){
                    if(str[i]=='>')
                        s.pop();
                    else
                        s.push(str[i]);
                }else if(ch=='['){
                    if(str[i]==']')
                        s.pop();
                    else
                        s.push(str[i]);
                    
                }else if(ch=='{'){
                    if(str[i]=='}')
                        s.pop();
                    else
                        s.push(str[i]);
                }
                
            }
            
        }
        if(s.empty())
        {
            cout<<"YES"<<endl;
        }else
            cout<<"NO"<<endl;
        
    }
    
    return 0;
}

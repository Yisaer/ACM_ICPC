//
//  main.cpp
//  字典树
//
//  Created by 高松 on 16/1/9.
//  Copyright © 2016年 yisa. All rights reserved.
//


#include <iostream>
using namespace std;
#include <cstring>


int const Max = 26;


struct Node{
    Node *next [Max];
    int num;
};

Node* Creat(){
    Node* p =new Node();
    for(int i=0;i<Max;i++)
        p->next[i]=NULL;
    
    p->num=0;
    return p;
}



void Insert( char *str,Node* head){
    int len =strlen(str);
    Node *t,*p=head;
    for(int i=0;i<len;i++){
        int c = str[i]-'a';
        if(p->next[c]==NULL){
            t= Creat();
            p->next[c]=t;
            p->num++;
            p=p->next[c];
        }else
        {
            p->num++;
            p=p->next[c];
        }
    }
}

int Search(char* str, Node* head){
    Node *p =head;
    int len =strlen(str);
    int count = 0;
    for(int i=0;i<len;i++){
        int c = str[i]-'a';
        if(p->next[c]==NULL){
            cout<<"NonExisted"<<endl;
            count = 0 ;
            return 0;
        }
        else{
            p=p->next[c];
            count= p->num;
        }
    }
    return  count ;
}


int main (){
    
    Node*head = Creat();
    int m; char s[15][15];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
        Insert(s[i],head);
    }
    int q;
    cin>>q;
    while(q--){
        char tmp[15];
        cin>>tmp;
        int ans = Search(tmp,head);
        cout<<ans<<endl;
    }
    
}



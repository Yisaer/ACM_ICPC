
//
//  main.cpp
//  Test
//
//  Created by 高松 on 16/1/4.
//  Copyright © 2016年 yisa. All rights reserved.
//
// AC自动机 字符串多模式串匹配。 原理：字典树+KMP
//

//Demo:
//模式串：
//she
//he
//say
//shr
//her
//目标串：
//yasherhs
//
//返回：
//    目标串中含有模式串的数量

#include <iostream>
#include <cstring>
using namespace std;
int const   N =500010;
char str[1000010], keyword[51];
#include <queue>


struct Node{
    Node* fail;
    Node* next[26];
    int count ;
    Node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        count = 0;
        fail = NULL;
    }
}*q[N];
Node * root;
int head, tail;




void init(){
    head = tail = 0;
    root  =  new Node();
}

void Insert(char* str){
    int len;
    len = strlen(str);
    Node *p = root;
    for(int i=0;i<len;i++){
        int tmp = str[i]-'a';
        if(p->next[tmp] ==NULL){
            p->next[tmp]= new Node();
        }
        p=p->next[tmp];
    }
    p->count++;
}

void Build_ac( ){
    q[tail++] =root;
    while(head!=tail){
        Node* p = q[head++];
        Node* tmp = NULL;
        for(int i=0;i<26;i++){
            if(p->next[i]!=NULL){
                if(p==root){
                    p->next[i]->fail = root;
                }
                else{
                    tmp = p->fail;
                    while(tmp!=NULL){
                        if(tmp->next[i]!=NULL){
                            p->next[i]->fail = tmp->next[i];
                            break;
                        }
                        tmp=tmp->fail;
                    }
                    if(tmp==NULL){
                        p->next[i]->fail = root;
                    }
                }
                q[tail++]=p->next[i];
            }
        }
    }
}

int query(char* str){
    Node*p =root;
    int  res ,len;
    res= 0 ;
    len= strlen(str);
    for(int i=0;i<len;i++){
        int Index =str[i]-'a';
        while(p->next[Index]==NULL&&p!=root){
            p=p->fail;
        }
        p=p->next[Index];
        if(p==NULL)
            p=root;
        Node* tmp = p;
        while( tmp!=root && tmp->count !=-1){
            res+=tmp->count;
            tmp->count =-1;
            tmp= tmp->fail;
        }
        
    }
    return res;
}
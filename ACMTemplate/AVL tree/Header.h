//
//  Header.h
//  AVL tree
//
//  Created by 高松 on 16/5/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
using namespace std;

template<class Elemtype>
class Node{
private:
    Elemtype data;
    Node* lson;
    Node* rson;
    int Height;
    //定义空树的高度为-1，一个根节点的高度为0，
    int Balance_factor;
    Node* par;
    
public:
    Node():lson(NULL),rson(NULL),Height(0),
    Balance_factor(0),par(NULL){};
    Node(Node* Par):lson(NULL),rson(NULL),Height(0),
    Balance_factor(0),par(Par){};
};


template<class Elemtype>
class AVL_Tree{
    
private:
    Node<Elemtype> *root;
    
    //辅助函数
    int GetHeight(Node<Elemtype>* node);
    int max (int a , int b);
    //插入操作
    void insert (Node<Elemtype> Par,Node<Elemtype>* node,Elemtype data);
    
    
    //旋转
    
    //左左旋转
    void LL_Rotate(Node<Elemtype> * p);
public:
    AVL_Tree();
    Node<Elemtype>* GetRoot(AVL_Tree t);
};

//插入操作

template<class Elemtype>
void AVL_Tree<Elemtype>::insert(Node<Elemtype> Par,Node<Elemtype> * node,Elemtype Data){
    
    if(node==NULL){
        node = new Node<Elemtype>(Par);
        node->data=Data;
        return;
    }
    else if(node->data>Data)
    //如果x小于节点的值,就继续在节点的左子树中插入x
    {
        insert(node,node->lson,Data);
        int Minus = GetHeight(node->lson)-GetHeight(node->rson);
        if(Minus==2){
            if(Data<node->lson->data){
                LL_Rotate(node);
            }
            else{
                LR_Rotate(node);
            }
        }
    }
    else if(node->data<=Data)
    //如果x大于节点的值,就继续在节点的右子树中插入x
    {
        insert(node,node->rson,Data);
        int Minus = GetHeight(node->rson)-GetHeight(node->lson);
        if(Minus==2){
            if(Data>node->rson->data){
                RR_Rotete(node);
            }
            else{
                RL_Rotate(node);
            }
        }
    }
    node->height = max(node->lson->height,node->rson->height);
    
}


//左左旋转
//对于某个结点k2，他有左子树K1，右子树Z，K1的左子树X比右子树Y高2
//K1比Z高1
template<class Elemtype>
void AVL_Tree<Elemtype>::LL_Rotate(Node<Elemtype>* k2){
    
    Node<Elemtype>* Par = k2->par;
    int LorR = Par->lson==k2?1:0;
    Node<Elemtype>* k1  = k2->lson;
    Node<Elemtype>* Y   = k1->rson;
    
    k1->rson = k2;
    k2->lson = Y;
    
    k1->par = Par;
    if(LorR){
        Par->lson = k1;
    }
    else
        Par->rson = k2;
    
    k2 ->height = max(Y->height,k2->rson->height)+1;
    k1 ->hegiht = max(k1->lson->height,k2->height)+1;
}

//右右旋转
//对于某个结点K2 ，他有左子树Z，右子树K2， K2比Z高2
//对于结点K2，他有左子树Y，右子树X，X比Y高1














template<class Elemtype>
int AVL_Tree<Elemtype>::GetHeight(Node<Elemtype>* node){
    if(node!=NULL)
        return node->hgt;
    return -1;
}

template<class Elemtype>
int AVL_Tree<Elemtype>::max(int a,int b){
    return a>b?a:b;
}

template<class Elemtype>
Node<Elemtype>* AVL_Tree<Elemtype>::GetRoot(AVL_Tree t){
    return root;
}








#endif /* Header_h */

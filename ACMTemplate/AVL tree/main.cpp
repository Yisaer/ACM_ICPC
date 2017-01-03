//
//  main.cpp
//  AVL tree
//
//  Created by 高松 on 16/5/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <queue>


class Node{
private:
    Node* lson;
    Node* rson;
    int height;
    int data;
    Node* par;
    friend class AVL;
public:
    Node(int Data,Node* Par):
    lson(NULL),rson(NULL),data(Data),height(0)
    ,par(Par){};
};

class AVL{

private:
    Node* root;
    int GetHeight(Node* node);
    void Rotate_LL(Node* node);
    void Rotate_RR(Node* node);
    void Rotate_LR(Node* node);
    void Rotate_RL(Node* node);
    void insert(Node* &node,int Data,Node* Par);
    void trans(Node* node);
    void del(Node* &node,int data);
    bool isleft(Node* par);
public:
    Node* GetRoot(){
        return root;
    }
    AVL():root(NULL){};
    void Insert(int Data);
    void Trans();
    void CCTrans();
    void Delete(int Data);
};

bool AVL::isleft(Node* node){
    Node* Par = node->par;
    if(Par->lson==node)
        return true;
    else
        return false;
}

void AVL::CCTrans(){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* now = q.front();
        q.pop();
        cout<<"data="<<now->data<<" ";
        Node* l = now->lson;
        Node* r = now->rson;
        if(l!=NULL){
            cout<<"l="<<l->data<<" ";
            q.push(l);
        }
        if(r!=NULL){
            cout<<"r="<<r->data;
            q.push(r);
        }
        cout<<" height="<<now->height;
        cout<<endl;
    }
}

void AVL::trans(Node* node){
    if(node->lson!=NULL){
        trans(node->lson);
    }
    cout<<node->data<<" ";
    if(node->rson!=NULL){
        trans(node->rson);
    }
    
}

void AVL::Trans(){
    trans(root);
    cout<<endl;
}

void AVL::Insert(int Data){
    insert(root,Data,NULL);
}

void AVL::Rotate_LL(Node* k2){
    Node* Par= k2->par;
    Node* k1 = k2->lson;
    
    k2 ->lson = k1->rson;
    if(k1->rson!=NULL)
    k1 ->rson ->par = k2;
    
    
    k1->rson = k2;
    k2->par = k1;
    
    k1->par = Par;
    if(Par!=NULL){
    int Isleft =-1;
    if(Par->lson==k2){
        Isleft=1;
    }
    else
        Isleft=0;
    
    if(Isleft){
        Par->lson = k1;
    }
    else
        Par->rson = k1;
    }
    else{
        root = k1;
    }
    k2->height = max(GetHeight(k2->lson),GetHeight(k2->rson))+1;
    k1->height = max(GetHeight(k1->lson),GetHeight(k1->rson))+1;
}

void AVL::Rotate_RR(Node* k2){
    Node* Par =k2->par;
    Node* k1 = k2->rson;
    
    
    k2 ->rson = k1->lson;
    if(k1->lson!=NULL)
    k1->lson->par = k2;
    
    k1->lson = k2;
    k2->par = k1;
    
    k1->par = Par;
    
    int Isleft =-1;
    if(Par!=NULL)
    {
        if(Par->lson==k2){
            Isleft=1;
        }
        else
        Isleft=0;
    
        if(Isleft){
            Par->lson = k1;
        }
        else
            Par->rson = k1;
    }
    else{
        root = k1;
    }
    
    k2->height = max(GetHeight(k2->lson),GetHeight(k2->rson))+1;
    k1->height = max(GetHeight(k1->lson),GetHeight(k1->rson))+1;
}

void AVL::Rotate_LR(Node* node){
    Rotate_RR(node->lson);
    Rotate_LL(node);
}

void AVL::Rotate_RL(Node* node){
    Rotate_LL(node->rson);
    Rotate_RR(node);
}

void AVL::insert(Node* &node,int Data,Node* Par){
    
    if(node==NULL){
        node = new Node(Data,Par);
        return;
    }
    if(Data<node->data)
    //如果DATA小于节点的值,就继续在节点的左子树中插入DATA
    {
        insert(node->lson,Data,node);
        if(GetHeight(node->lson)-GetHeight(node->rson)==2){
            if(Data<node->lson->data){
                Rotate_LL(node);
            }
            else{
                Rotate_LR(node);
            }
        }
    }
    else
    //则DATA大于结点值，往结点的右子树插入DATA
    {
        insert(node->rson,Data,node);
        if(GetHeight(node->rson)-GetHeight(node->lson)==2){
            if(Data>node->rson->data){
                Rotate_RR(node);
            }
            else{
                Rotate_RL(node);
            }
        }
        
    }
    node->height = max(GetHeight(node->lson),GetHeight(node->rson))+1;
}



int AVL::GetHeight(Node* node){
    if(node!=NULL)
        return node->height;
    return -1;
}

void AVL::Delete(int Data){
    del(root,Data);
}

void AVL::del(Node* &node,int Data){
    if(node==NULL){
        return;
    }
    if(Data<node->data)
    //Data小于结点值，往左子树搜索
    {
        del(node->lson,Data);
        if(GetHeight(node->rson)-GetHeight(node->lson)==2){
            if(node->rson->lson!=NULL&&(GetHeight(node->rson->lson)>GetHeight(node->rson->rson)) )
                Rotate_RL(node);
            else
                Rotate_RR(node);
        }
    }
    else if(Data>node->data)
    //Data大于节点值，往右子树搜索
    {
        del(node->rson,Data);
        if(GetHeight(node->lson)-GetHeight(node->rson)==2){
            if(node->lson->rson!=NULL&& (GetHeight(node->lson->rson)>GetHeight(node->lson->lson) ))
                Rotate_LR(node);
            else
                Rotate_LL(node);
        }
    }
    else if(node->data==Data){
        
        if(node->lson!=NULL&&node->rson!=NULL)
        //左右子树都存在
        {
            Node* tmp = node->rson;
            Node* Par = node->par;
            int IsL = isleft(node);
            while(tmp->lson!=NULL) tmp =tmp->lson;
            node->data = tmp->data;
            if(Par!=NULL)
            {
            if(IsL)
                Par->lson = node;
            else
                Par->rson = node;
            }
            else{
                root = node;
            }
            del(node->rson,tmp->data);
            if(2==GetHeight(node->lson)-GetHeight(node->rson))
            {
                if(node->lson->rson!=NULL&& (GetHeight(node->lson->rson)>GetHeight(node->lson->lson) ))
                    Rotate_LR(node);
                else
                    Rotate_LL(node);
            }
        }
        else
        //只存在一个子树或不存在子树
        {
            Node* Par =node->par;
            Node* tmp =node;
            int IsL = -1;
            if(node->lson==NULL&&node->rson!=NULL){
                if(Par!=NULL){
                     IsL = isleft(node);
                }
                node = node->rson;
                node ->par = Par;
                if(Par!=NULL){
                    if(IsL)
                        Par->lson = node;
                    else
                        Par->rson = node;
                }
                else{
                    root = node;
                }
            }
            else if(node->lson!=NULL&&node->rson==NULL){
                if(Par!=NULL){
                    IsL = isleft(node);
                }
                node = node->lson;
                node ->par = Par;
                if(Par!=NULL){
                    if(IsL)
                        Par->lson = node;
                    else
                        Par->rson = node;
                }
                else{
                    root = node;
                }
            }
            else if(node->lson==NULL&&node->rson==NULL){
                if(Par!=NULL){
                    IsL = isleft(node);
                    if(IsL)
                        Par->lson=NULL;
                    else
                        Par->rson=NULL;
                }
                else{
                    root = NULL;
                }
            }
            delete(tmp);
        }
    }
    if(node==NULL) return;
    //递归得到当前结点树高
    node->height=max(GetHeight(node->lson),GetHeight(node->rson))+1;
    return;

}


int main (){
    AVL t;
    for(int i=1;i<=6;i++){
        int val;
        cin>>val;
        t.Insert(val);
    }
    t.CCTrans();
    t.Trans();
    int val;
    cin>>val;
    t.Delete(val);
    t.CCTrans();
    t.Trans();
    
}
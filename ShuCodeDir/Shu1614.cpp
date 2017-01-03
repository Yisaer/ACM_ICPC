#include <iostream>
using namespace std;
#include <cstdio>
#include <queue>
#include <vector>
#include <string>

int const Maxn = 101;

using namespace std;
struct Node{
    int val;
    int Index;
    Node *left;
    Node *right;
    int size;
    Node(int v,int s,int S):val(v),Index(s),size(S){left = NULL;right = NULL;}
};
struct cmp{
    bool operator()(Node *a,Node *b){
        if(a->val == b->val)return a->size<b->size;
        return a->val>b->val;
    }
};
string X [Maxn];

int F[Maxn];

priority_queue<Node* ,vector<Node*> ,cmp> pq;
int n;

Node* Build (){
    for(int i = 1;i<n;i++){
        Node *x = pq.top();
        pq.pop();
        Node *y = pq.top();
        pq.pop();
        Node *cur = new Node(x->val+y->val,-1,n+i);
        cur->left = y;
        cur->right = x;
        pq.push(cur);
    }
    Node *root = pq.top();
    pq.pop();
    return root;
}


void Str(Node* cur ,string str){
    if(cur  == NULL ){
        return ;
    }

    if( cur -> left ==NULL && cur->right == NULL){
        X[cur->Index] = str;

        return;

    }
    if(cur->left !=NULL)
        Str(cur->left,str+'0');
    if(cur -> right != NULL)
        Str(cur->right,str+'1');

}


int main (){

    int T;
    cin>>T;
    int cas = 0;
    while(T--){
        if(cas)
            cout<<endl;
        
        cas++;
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>F[i];
            Node* cur = new Node(F[i],i,i);
            pq.push(cur);
        }

        Node* root = Build();

        Str(root,"");
        cout<<"Case "<<cas<<endl;
        for(int i =1;i<=n;i++){
            cout<<F[i]<<" ";
            cout<<X[i]<<endl;
        }

    }
}




using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
int const Maxn=1e5+5;

struct X{
    int l,r;
    int val;
    int plus;
    int muti;
}Node[Maxn<<2];

void set_up(int rt){
    Node[rt].val=Node[rt*2].val+Node[rt*2+1].val;
}

void init(int L,int R,int rt){
    Node[rt].l=L;
    Node[rt].r=R;
    Node[rt].plus=0;
    Node[rt].muti=1;
    if(L==R){
        scanf("%d",&Node[rt].val);
        return;
    }
    int mid = (L+R)/2;
    init(L,mid,rt*2);
    init(mid+1,R,rt*2+1);
    set_up(rt);
}

void set_down(int rt){
    if(Node[rt].muti==1&&Node[rt].plus==0)
        return;
    int m= Node[rt].muti;
    int p= Node[rt].plus;
    Node[rt].muti=1;
    Node[rt].plus=0;
    Node[rt*2].muti*=m;
    Node[rt*2].plus=(Node[rt*2].plus*m+p);
    Node[rt*2].val=(Node[rt*2].val)*m+(Node[rt*2].r-Node[rt*2].l+1)*p;
    Node[rt*2+1].muti*=m;
    Node[rt*2+1].plus=(Node[rt*2+1].plus*m)+p;
    Node[rt*2+1].val=(Node[rt*2+1].val)*m+(Node[rt*2+1].r-Node[rt*2+1].l+1)*p;
    return;
}



void update(int L,int R,int rt,int k,int b){
    if(Node[rt].l==L&&Node[rt].r==R){
        Node[rt].val=(Node[rt].val)*k+(R-L+1)*b;
        Node[rt].muti*=k;
        Node[rt].plus=(Node[rt].plus*k)+b;
        return;
    }
    set_down(rt);
    int mid=(Node[rt].l+Node[rt].r)/2;
    if(R<=mid){
        update(L,R,rt*2,k,b);
    }
    else if(L>mid){
        update(L,R,rt*2+1,k,b);
    }
    else{
        update(L,mid,rt*2,k,b);
        update(mid+1,R,rt*2+1,k,b);
    }
    set_up(rt);
}

int query(int L,int R,int rt){
    if(L==Node[rt].l&&Node[rt].r==R){
        return Node[rt].val;
    }
    set_down(rt);
    int mid =( Node[rt].l+Node[rt].r)/2;
    if(R<=mid){
        return query(L,R,rt*2);
    }
    else if(L>mid){
        return query(L,R,rt*2+1);
    }
    else{
        return query(L,mid,rt*2)+query(mid+1,R,rt*2+1);
        
    }
}


int main (){
    int n,q;
    int k,b;
    while(scanf("%d%d",&n,&q)==2){
        init(1,n,1);
        while(q--){
            int Q,x,y;
            scanf("%d%d%d",&Q,&x,&y);
            if(Q==1){
                scanf("%d%d",&k,&b);
                update(x,y,1,k,b);
            }
            else
                printf("%d\n",query(x,y,1));
        }
        
    }

}

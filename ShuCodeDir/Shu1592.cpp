#include <cstdio>
#include <iostream>
using namespace std;
#include <vector>

const int maxn=1e5+5;
int STACK[maxn],top=0;
bool InStack[maxn];
int DFN[maxn];
int Low[maxn];
int ComponetNumber=0;
int Index=0;
vector <int> Edge[maxn];
vector <int> Component[maxn];
void Tarjan(int i)

{
      int j;
    DFN[i]=Low[i]=Index++;
    InStack[i]=true;
    STACK[++top]=i;
    for (int e=0;e<Edge[i].size();e++)
    {
        j=Edge[i][e];
        if (DFN[j]==-1)
        {
            Tarjan(j);
            Low[i]=min(Low[i],Low[j]);
        }
            
        else if (InStack[j])
        Low[i]=min(Low[i],DFN[j]);
        }
        if (DFN[i]==Low[i])
        {
            int cnt=0;
            do
            {
              cnt++;
              j=STACK[top--];
              InStack[j]=false;
              Component[ComponetNumber].push_back(j);
            }while (j!=i);
            if(cnt>1) ComponetNumber++;
            }
}
void init(){
    ComponetNumber=0;
    memset(STACK,-1,sizeof(STACK));
    memset(InStack,0,sizeof(InStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));
    memset(Edge,0,sizeof(Edge));
    memset(Component,0,sizeof(Component));
}
void solve(int n)
{
    for(int i=0;i<n;i++)
    if(DFN[i]==-1)
    Tarjan(i);
}

int main(){
    int n,e;
    while(~scanf("%d%d",&n,&e))
    {
        init();
        for(int i=0;i<e;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            Edge[x].push_back(y);
        }
        solve(n);
        cout<<ComponetNumber<<endl;
    }
    return 0;
}

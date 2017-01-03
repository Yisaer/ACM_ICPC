#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool isPrime[10005];
int  primelist[10005];


int S,E;

int sum(int a,int b,int c,int d)
{
    return a*1000+b*100+c*10+d;
}



int bfs()
{
    int  vis[9999];
    int  cnt[9999];
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    vis[S]=1;
    int In[10];
    queue<int >q;
    q.push(S);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        In[0]=x/1000;
        In[1]=(x/100)%10;
        In[2]=(x%100)/10;
        In[3]=x%10;
        //cout<<"x="<<x<<endl;
        
        for(int i=0;i<4;i++)
        {
            int num=In[i];
            int j;
            for( j=0;j<10;j++)
            {
                if(j==0&&i==0)
                    continue;
                if(j==num)
                    continue;
                In[i]=j;
                int Sum=sum(In[0],In[1],In[2],In[3]);
                if(isPrime[Sum]&&vis[Sum]==0)
                {
                    cnt[Sum]=cnt[x]+1;
                    q.push(Sum);
                    vis[Sum]=1;
                    
                }
                if(Sum==E)
                    return cnt[E];
                
            }
            In[i]=num;
        }
        
        
        if(x==E) return 0;
    }
    
    return -1;
}


int main ()
{
    
    int n;
    n = 9999;
    for(int i=1;i<=n;i++){
        isPrime [i]= true;
    }
    int count = 0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            count++;
            primelist[count]=i;
        }
        for(int j=1;j<=count;j++){
            if(i * primelist[j] > n )
                break;
            isPrime[ i*primelist[j] ] =false;
            if(i % primelist[j] == 0)
                break;
        }
    }
    int T;
    cin>>T;
    while(T--)
    {
        queue<int >q;
        
        
        cin>>S>>E;
        
        int ans;
        ans=bfs();
        cout<<ans<<endl;
        
    }
    
    
    
}

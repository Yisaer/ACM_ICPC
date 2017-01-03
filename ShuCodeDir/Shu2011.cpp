#include <iostream>
#include <cstring>
using namespace std;
int map[15][15];
int n;
int used[15],step,flag;
int DFS(int s)
{
    int i;
    if( flag ) return 1;
    if( step == n+1 && s == 0 )
    {
        flag = 1;
        return 1;
    }
    for(i=0; i<=n; i++)
        if( !used[i] && map[s][i] )
        {
            step++;
            used[i] = 1;
            DFS(i);
            used[i] = 0;
            step--;
        }
    return 0;
}
int main()
{
    int ind = 1,len;
    char str[50];
    int to,i,k,ans;
    while( scanf("%d",&n) != EOF && n )
    {
        getchar();
        memset(map,0,sizeof(map));
        for(i=1; i<=n; i++)
        {
            gets(str);
            len = strlen(str);
            for(k=0; k<len; k++)
                if( isdigit(str[k] ) )
                {
                    to = str[k]-'0';
                    map[i][to] = map[to][i] = 1;
                }
        }
        memset(used,0,sizeof(used));
        flag = step = 0;
        DFS(0);
        ans = flag;
        printf("Case %d: ",ind++);  
        if( ans )
            printf("Granny can make the circuit.\n");
        else
            printf("Granny can not make the circuit.\n");
    }
return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int MOD;


struct matrix
{
    int mat[31][31];
    matrix(){memset(mat,0,sizeof(mat));}
};


matrix mul(matrix A,matrix B)
{
    int i,j,k;
    matrix C;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                C.mat[i][j]=((C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%MOD+MOD)%MOD;
            }
        }
    }
    return C;
}


matrix powmul(matrix A,int k)
{
    matrix B;
    for(int i=1;i<=n;i++)B.mat[i][i]=1;
    while(k)
    {
        if(k&1)B=mul(B,A);
        A=mul(A,A);
        k>>=1;
    }
    return B;
}

int main (){
    int T;
    cin>>T;
    int cas = 0;
    while(T--){
        cas++;
        printf("Case %d:\n",cas);
        int x;
        cin>>x>>MOD;
        n=2;
        matrix A;
        cin>>A.mat[1][1]>>A.mat[1][2]>>A.mat[2][1]>>A.mat[2][2];
        matrix B = powmul(A,x);
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                if(j-1)cout<<" ";
                cout<<B.mat[i][j];
            }
            cout<<endl;
        }
        
    }
}

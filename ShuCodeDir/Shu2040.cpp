using namespace std;
int Cnt(int a){
    int res = 0;
    while(a){
        a/=10;
        res++;
    }
    return res;
}

int Yu (int C){
    int res = 1;
    for(int i=0;i<C;i++){
        res *=10;
    }
    return res;
}

int main (){
    
    int n;
    int cas = 0;
    while(cin>>n){
        cas++;
        printf("Case %d: ",cas);
        int C = Cnt(n);
        long long S = n*n;
        cout<<n<<", ";
        if(n==(S%Yu(C))){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        
    }

}


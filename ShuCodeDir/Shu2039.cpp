using namespace std;


int main (){
    
    int n,a;
    int cas = 0;
    while(cin>>a>>n){
        cas++;
        printf("Case %d: ",cas);
        long long ans = 0;
        int num = a;
        for(int i = 0;i<n;i++){
            ans += num;
            num = num*10+a;
        }
        cout<<ans<<endl;
    }

}


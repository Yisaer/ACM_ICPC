using namespace std;


int main (){
    
    double n;
    int cas = 0;
    double tmp;
    while(cin>>n){
        tmp = n;
        n/=1000;
        cas++;
        printf("Case %d: ",cas);
        int ans = 0;
        while(n<=8844.43){
            n*=2;
            ans++;
        }
        cout<<tmp<<", "<<ans<<", ";
        printf("%.1lf\n",n);
    }

}


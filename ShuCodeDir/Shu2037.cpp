using namespace std;


int main (){
    
    int n;
    int cas = 0;
    while(cin>>n){
        cas++;
        printf("Case %d: ",cas);
        if(n<=0){
            cout<<n<<", -1"<<endl;
            continue;
        }
        int tmp = n;
        int cnt = 0;
        while(n!=1){
            cnt++;
            if(n&1){
                n = 3*n+1;
                
            }
            else{
                n /= 2;
            }
        }
        cout<<tmp<<", "<<cnt<<endl;
        
    }

}

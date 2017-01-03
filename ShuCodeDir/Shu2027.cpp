using namespace std;
#define ll long long
#include <cmath>
#include <algorithm>
int n;
int A[100001];


int main(){
    int n;
    while(cin>>n){
    int sum = 0;
        for(int i=0;i<n;i++){
            cin>>A[i];
            sum+=A[i];
        }
        sort(A,A+n);
        int p = n-sum%n;
        int arv = sum/n;
        int cnt = 0;
        for(int i=0;i<p;i++){
            cnt += abs(A[i]-arv);
        }
        arv = (sum+n-1)/n;
        for(int i=p;i<n;i++){
            cnt+=abs(A[i]-arv);
        }
        cout<<cnt/2<<endl;
        
        
    }
}

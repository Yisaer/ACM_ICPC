#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#define ll long long
ll  mod=1071017;
int const P=1071017;




int Euler(int n){

	int res = n,i;
	for(i=2;i * i <= n;i++)
	if(n%i == 0){
		n /=i ;
		res = res - res/i;
		while(n % i ==0)
			n/=i;
	}

	if (n > 1)   
        res = res - res/n; 
  
   	return res;
}


ll Pow(ll n, ll m, ll MOD) {
    ll ret = 1;
    while (m) {
        if (m & 1) ret = (ret * n) % MOD;
        m >>= 1;
        n = (n * n) % MOD;
    } return ret;
}

int fun( int n,int mod)
{
	if(n==0)
	return 1;
	return Pow(3,fun(n-1,Euler(mod)),mod);
	
}

int main ()
{
	
	int T;
	cin>>T;
	int ans;
	while(T--)
	{
		int n;
		cin>>n;
		int ans;
		ans=fun(n,mod);
		cout<<ans<<endl;
	}
	
	return 0;	
}

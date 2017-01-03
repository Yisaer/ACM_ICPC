#include <iostream>
using namespace std;

int main (){
	int T;
	cin>>T;
	while(T--){
		int A,B;
		cin>>A>>B;
		int ans = 0;
		if(A<=B){
		cout<<ans<<endl;
		continue;
		}
		while(A>B){
			ans++;
			A=A/2+1;	
		}
		cout<<ans<<endl;
	}
}

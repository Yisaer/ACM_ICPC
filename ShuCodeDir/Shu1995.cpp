#include <cstring>
#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
int F[1005];
bool cmp(int a,int b){
	return a>b;	
}

int main (){
	
	int T;
	cin>>T;
	while(T--){
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>F[i];	
		}
		for(int i=0;i<n;i++){
			F[i]-=i;	
		}
		sort(F,F+n,cmp);
		for(int i=0;i<n;i++){
			F[i]+=i;	
		}
		bool flag  =true;
		F[n]=-999;
		for(int i=0;i<n;i++){
			if(F[i]>=F[i+1]&&F[i]>=0){
				continue;
			}
			else{
			 flag = false  ;break;	
			}
		}
		
		if(flag){
			for(int i=0;i<n;i++){
				if(i) cout<<" ";
				cout<<F[i];
			}
			cout<<endl;
		}
		else{
			cout<<"Impossible"<<endl;
		}
		
		
	}
	
}

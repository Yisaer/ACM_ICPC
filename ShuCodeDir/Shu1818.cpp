#include <cstdio>
#include <iostream>
#include <cctype> 
using namespace std;
char str[65540];
char T[65540];

int main ()
{
	/*
	int T;
	cin>>T;
	int t=T;
	char q;
	q=getchar();
	*/
	int cas=0;
	while(gets(str))
	{
	
	
		cas++;
	
		int len=strlen(str);
		
		for(int i=0;i<len;i++)
		if(str[i]>='a'&&str[i]<='z')
		str[i]=str[i]+'A'-'a';
		
	//	puts(str);
			for(int i=0;i<len+1;i++){
			str[len-i]=str[len-i-1];
		}
		str[0]=' ';
		for(int i=0;i<len;i++){
			if(str[i]==' '&&str[i+1]=='T'&&str[i+2]=='H'&&str[i+3]=='E'&&str[i+4]==' '){
				str[i]=str[i+1]=str[i+2]=str[i+3]=str[i+4]=' ';
			}
			if(str[i]==' '&&str[i+1]=='O'&&str[i+2]=='F'&&str[i+3]==' '){
				str[i]=str[i+1]=str[i+2]=str[i+3]=' ';
			}
			if(str[i]==' '&&str[i+1]=='A'&&str[i+2]=='N'&&str[i+3]=='D'&&str[i+4]==' '){
				str[i]=str[i+1]=str[i+2]=str[i+3]=str[i+4]=' ';
			}
			if(str[i]==' '&&str[i+1]=='F'&&str[i+2]=='O'&&str[i+3]=='R'&&str[i+4]==' '){
				str[i]=str[i+1]=str[i+2]=str[i+3]=str[i+4]=' ';
			}
			if(str[i]==' '&&str[i+1]=='A'&&str[i+2]=='N'&&str[i+3]==' '){
				str[i]=str[i+1]=str[i+2]=str[i+3]=' ';
			}
			if(str[i]==' '&&str[i+1]=='A'&&str[i+2]==' '){
				str[i]=str[i+1]=str[i+2]=' ';
			}
		}
		printf("Case %d: ",cas);
			for(int i=0;i<len;i++){
			if(i==0&&str[0]!=' '){
				cout<<str[0];
			}
			if((str[i]==' '||str[i]=='-')&&str[i+1]!=' '){
				cout<<str[i+1];
			}
		}
		cout<<endl;
		
		

	}
	

}

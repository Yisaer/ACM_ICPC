#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char str1[100000],str2[100000];
  int a=0;
  while(gets(str1))
  {
  gets(str2);
  int n=0;
  int  l1=strlen(str1),l2=strlen(str2);
 
  for(int j=0;j<l2;j++)
   {
	 int b=0;
	if(str2[j]==str1[0])
	{
	 int flag=1;
//	cout<<"Find j="<<j<<endl;
    for(int i=j+1;i<j+l1;i++)
      if(str2[i]!=str1[++b]){flag=0;break;}
     
      if(flag==1)n++;	
	}
	
   }
   a++;
   printf("Case %d: ",a);
   cout<<n<<endl;
  }
}

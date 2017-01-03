#include <iostream>
using namespace std;

bool Isleap(int n)
{
	if((n%4==0&&n%100!=0)||(n%400==0))
	return true;
	return false;	
	
	
}


int main ()
{
	int n;
	while(cin>>n)
	{
		if(Isleap(n))
		{
			cout<<"The year "<<n<<" is a leap year."<<endl;
				
		}
		else 
		{
			cout<<"The year "<<n<<" is not a leap year."<<endl;	
		}
	
	}
	
	
	
}


#include<cmath>

using namespace std;



int main()

{

	int n;

	while(cin>>n,n)

	{


		cout<<n<<endl;

		cout<<"Times:"<< (int)ceil(log((double)n)/log(3.0))<<endl;

	}

	return 0;

}

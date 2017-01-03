#include <math.h>

int main()   
{   
	long long n;
	long long x;
		long long sum;
	while(scanf("%lld",&n)==1)
	{
		sum=0;
		for(x=1;x<n;x++)
		{
			if(n%x==0)
			sum+=x;
		}
		if(sum==n)
		printf("%lld YES\n",n);
		else printf("%lld NO\n",n);
	}

    return 0;   
    }   

#define _Shuoj1955_

#include<iostream>
#include<cmath>
#include <cstring>
#include <cstdio> 

using namespace std;

typedef long long ll;



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ll N;
		cin >> N;
		ll X;
		X = (1 + sqrt(1 + 8 * (N - 1))) / 2;
		if (((X - 1)*X / 2 + 1) == N)cout << 2 << endl;
		else cout << 3 << endl;
	}
	return 0;
}

#endif//_Shuoj1955_

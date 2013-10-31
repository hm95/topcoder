#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaximumPoints( int A, int B, int C, int N )
{
	int sum = 0;

	for( int i = 0; i < N; i++ )
	{
		if( A >= B && A >= C )
		{
			sum += A;
			if( A >= 1 ) A--;
		}
		else if( B > A && B > C )
		{
			sum += B;
			if( B >= 1 ) B--;
		}
		else if( C > A && C >= B )
		{
			sum += C;
			if( C >= 1 ) C--;
		}
	}

	return sum;
}

int main()
{
	int n = getMaximumPoints( 3, 5, 48, 40 );
	cout << "The maximum is " << n << endl;

	return 0;
}

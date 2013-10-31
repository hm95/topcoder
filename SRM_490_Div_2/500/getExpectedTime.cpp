#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOOPCONST 1000000

double getExpectedTime( int N, int M )
{
	vector <long double> expected_times;
	int j;
	double mind = 0;
	long double avg = 0;

	if( N == M )
	{
		return 0.0;
	}

	for( int i = 0; i < LOOPCONST; i++ )
	{
		j = i;
		while( mind < M*i && i > 0 )
		{
			mind += N;
		}
		if( mind == M*i )
		{
			expected_times.push_back(0.0);
		}
		else
		{
			expected_times.push_back( mind - M*i );
		}	
	}

	for( int k = 0; k < LOOPCONST; k++ )
	{
		avg += expected_times[k];
	}
	avg /= LOOPCONST;

	return double( avg );
}

int main()
{
	double a = getExpectedTime( 12345, 2345 );
	cout << a << endl;

	return 0;
}

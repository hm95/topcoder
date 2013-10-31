#include <iostream>
#include <cmath>
using namespace std;

double cycleRange( double R )
{
	double X = 0.25;
	double mi = 1000;
	double ma = -1000;

	for( int i = 0; i < 200000; i++ )
	{
		X = X*R*(1-X);
	}

	for( int i = 0; i < 1000; i++ )
	{
		X = X*R*(1-X);
		if( X < mi )
		{
			mi = min( mi, X );
		}
		if( X > ma )
		{
			ma = max( ma, X );
		}
	}
	return ma - mi;
}

int main()
{
	double R = 3.55;
	double cycle = cycleRange( R );
	cout << cycle << endl;

	return 0;
}

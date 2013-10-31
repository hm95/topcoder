#include <iostream>
#include <math.h>
using namespace std;

int sum_of_digits( long long i )
{
	int sum_digits = 0;

	while( i > 0 )
	{
		if( i % 10 == 0 )
		{
		}
		else
		{
			sum_digits += i % 10;
		}
		i /= 10;
	}
	return sum_digits;
}

int theCount( int low, int high )
{
	int sum = 0;
	for( long i = low; i < high + 1; i++ )
	{
		if( sum_of_digits(i*i) == sum_of_digits(i)*sum_of_digits(i) )
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	int low = 1000000;
	int high = 1000000;

	int num_rabbit = theCount( low, high );
	cout << "There are " << num_rabbit << " rabbit numbers between " << high << " and " << low << endl;

	return 0;
}

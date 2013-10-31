#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector <int> distance;
	vector <int> height;
	vector <double> slope;

	distance.push_back( 173 );
	distance.push_back( 36 );
	distance.push_back( 668 );
	distance.push_back( 79 );
	distance.push_back( 26 );
	distance.push_back( 544 );

	height.push_back( 448 );
	height.push_back( 743 );
	height.push_back( 203 );
	height.push_back( 446 );
	height.push_back( 444 );
	height.push_back( 91 );
	height.push_back( 453 );

	for( int i = 0; i < distance.size(); i++ )
	{
		slope.push_back( (  double( height[ i + 1 ] - height[i] ) / distance[i] ) );
	}

	for( int i = 0; i < distance.size(); i++ )
	{
		cout << slope[i] << endl;
	}

	sort( height.begin(), height.end() );
	
	for( int i = 0; i < height.size(); i++ )
	{
		cout << height[i] << endl;
	}


	return 0;
}

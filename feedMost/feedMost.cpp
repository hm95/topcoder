#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int feedMost( vector <int> hunger, vector <int> greed, int totalFood )
{
	//vector< vector<int> > costs( hunger.size(), vector<int>( hunger.size() ) );
	int costs[hunger.size()][hunger.size()];

	/* calculate the cost of feeding badger i, if there are j badgers */
	for( int i = 0; i < hunger.size(); i++ )
	{
		for( int j = 0; j < hunger.size(); j++ )
		{
			costs[j][i] = hunger[i] + greed[i]*(j);
		}
		sort( costs[i][j], costs[i][j] );
	}

	/* sort costs */
	/*
	for( int i = 0; i < hunger.size(); i++ )
	{
		for( int z = 0; z < hunger.size(); z++ )
		{
			for( int j = 1; j < hunger.size(); j++ )
			{
				if( costs[i][j-1] > costs[i][j] )
				{
					swap( costs[i][j-1], costs[i][j] ); 
				}
			}
		}
	}
	*/

	/* display all costs */
	/*for( int i = 0; i < hunger.size(); i++ )
	{
		for( int j = 0; j < hunger.size(); j++ )
		{
			cout << costs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	int sum = 0;
	for( int i = hunger.size() - 1; i >= 0; i-- )
	{
		for( int j = 0; j < i + 1; j++ )
		{
			sum += costs[i][j];
		}
		if( sum <= totalFood )
		{
			return i + 1;
		}
		else
		{
			sum = 0;
		}
	}
	return 0;
}

int main()
{
	vector <int> hunger;
	vector <int> greed;
	int totalFood = 50;

	hunger.push_back(3);
	hunger.push_back(3);
	hunger.push_back(5);
	hunger.push_back(1);
	hunger.push_back(9);
	
	greed.push_back(4);
	greed.push_back(8);
	greed.push_back(89);
	greed.push_back(2);
	greed.push_back(3);

	int num_bad = feedMost( hunger, greed, totalFood );
	cout << "The total amount of food is " << totalFood << endl;
	cout << "The most number of badgers he can take is " << num_bad << endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find_max( int sum, vector <int> assets )
{
	bool startf = false;
	int count = 0;

	int tsum = 0;
	for( int l = 0; l < assets.size(); l++ )
	{
		tsum += assets[l];
	}
	if( tsum - assets[0] == 2*assets[0] )
	{
		return assets[0];
	}

	int asum = 0;
	if( sum == 0 )
	{
 		startf = true;
		for( int i = 0; i < assets.size(); i++ )
		{
			if( asum + assets[i] < floor( tsum / 3 ) )
			{
				asum += assets[i];
				count++;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for( int i = sum - 1; i > 0; i-- )
		{
			if( asum + assets[i] < floor( tsum / 3 ) )
			{
				asum += assets[i];
				count++;
			}
			else
			{
				break;
			}
		}
	}
	
	int rsum = tsum - asum;

	int bsum = 0;
	if( startf )
	{
		for( int j = count; j < assets.size(); j++ )	
		{
			if( bsum + assets[j] < floor( rsum / 2 ) )
			{
				bsum += assets[j];
			}
		}
	}
	else
	{
		for( int j = count; j > 0; j-- )	
		{
			if( bsum + assets[j] < floor( rsum / 2 ) )
			{
				bsum += assets[j];
			}
		}
	}

	int csum = tsum - bsum - asum;
	int mi = min( csum, bsum );

	return min( mi, asum );
}

int albertsShare( vector <int> assets )
{
	// from back
	int asumf = assets.size();
	asumf = find_max( asumf, assets );

	// from front
	int asumb = 0;
	asumb = find_max( asumb, assets );

	return max( asumf, asumb );
}

int main()
{
	vector <int> assets;
	assets.push_back( 2 );
	assets.push_back( 1 );
	assets.push_back( 3 );
	int albertsAssets = albertsShare( assets );
	cout << "Albert gets " << albertsAssets << endl;

	return 0;
}

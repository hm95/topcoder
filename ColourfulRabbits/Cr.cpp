#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
typedef map<int, int> int_map;

int getMinimum( vector <int> replies )
{
	int sum = 0;
	int_map map;

	for( int i = 0; i < replies.size(); i++ )
	{
		if( replies[i] == 0 )
		{
			sum += 1;
			continue;
		}
		if( map[replies[i]] == 0 )
		{
			map[replies[i]] = 1;
		}
		else if ( map[replies[i]] == replies[i] )
		{
			map[replies[i]] = 0;
			sum += replies[i] + 1;
		}
		else
		{
			map[replies[i]]++;
		}
	}

	for( int i = 0; i < replies.size(); i++ )
	{
		if( map[replies[i]] != 0 )
		{
			sum += replies[i] + 1;
			map[replies[i]] = 0;
		}
	}

	return sum;
}

int main()
{
	vector <int> replies;
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	replies.push_back(0);
	int num = getMinimum( replies );
	cout << num << endl;

	return 0;
}

#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string justifyLine( vector <string> words, int width )
{
	int tc = accumulate( words.begin(), words.end(), string()).size();
	int num_spaces = width - tc;
	int num_spots = words.size() - 1;
	int normal_space = num_spaces / num_spots;
	int larger_space = normal_space + 1;
	int num_larger_spaces = num_spaces % num_spots;
	int num_normal_spaces = num_spaces - num_larger_spaces;

	string s = words[0];

	for( int i = 1; i < words.size(); i++ )
	{
		if( words[i][0] < '_' && num_normal_spaces > 0 || num_larger_spaces == 0 )
		{
			s += string( normal_space, '_' );
			num_normal_spaces--;
		}
		else
		{
			s += string( larger_space, '_' );
			num_larger_spaces--;
		}
		s += words[i];
	}
	return s;
}

int main()
{
	return 0;
}

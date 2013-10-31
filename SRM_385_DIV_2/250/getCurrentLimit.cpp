#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int getCurrentLimit( vector <string> signs )
{
	int def = 60;
	int cur = 60;

	string last = signs[ signs.size() - 1 ];

	if( last == "default" || last == "city" )
	{
		for( int i = 0; i < signs.size(); i++ )
		{
			if( signs[i] == "default" ) cur = def;
			if( signs[i] == "city" )
			{
				if( def == 60 ) def = 90;
				else def = 60;
				cur = def;
			}
		}
		return cur;
	}
	else return atoi( last.c_str() );
}

int main()
{
	vector <string> signs;
	signs.push_back("40");
	signs.push_back("80");
	signs.push_back("city");

	int cur = getCurrentLimit( signs );
	cout << cur << endl;

	return 0;
}

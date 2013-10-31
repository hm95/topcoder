#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> smap;

int getMaximum( vector <string> front, vector <int> back )
{
	smap imap;
	int sum = 0;
	string tmp;
	smap::iterator it = imap.begin();
	smap::iterator jt = imap.begin();

	for( int i = 0; i < front.size(); i++ )
	{
		it = imap.find( front[i] );
		tmp = front[i];
		reverse( tmp.begin(), tmp.end() );
		jt = imap.find( tmp );
		if( jt == imap.end() )
		{
			if( it == imap.end() || it->second == 0 )
			{
				imap.insert( pair<string, int> ( tmp, back[i] ) );
			}
			it = imap.find( front[i] );
			else
			{
				sum += it->second;
				sum += back[i];
				(it->second) = 0;
			}
		}
		else
		{
		}
		

	}
	
	return sum;
}

int main()
{
	vector <string> front;
	vector <int> back;

	front.push_back("abc");
	front.push_back("cja");
	front.push_back("abc");
	front.push_back("cba");
	front.push_back("cba");

	back.push_back(7);
	back.push_back(5);
	back.push_back(3);
	back.push_back(3);
	back.push_back(3);
	
	int max = getMaximum( front, back );
	cout << "The max is " << max << endl;

	return 0;
}

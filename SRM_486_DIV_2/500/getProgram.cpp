#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool get_to( int s, int t, string ret )
{
	if( t == s*s )
	{
		ret += '*';
		return true;
	}
	if( t == 2*s )
	{
		ret += '+';
		return true;
	}
	
	if( get_to( s, sqrt(t), ret ) )
	{
		ret += '*';
	}

	if( get_to( s, t/2, ret ) )
	{
		ret += '+';
	}

	return false;
}

string getProgram( int s, int t )
{
	string ret = "";
	if( s == t ) return "";
	
	if( get_to(  s, sqrt(t), ret ) )
	{
		ret += '*';
	}

	if( get_to( s, t/2, ret ) )
	{
		ret += '+';
	}

	return ret;
}

int main()
{
	int s = 7, t = 392;
	string p = getProgram( s, t );
	cout << p << endl;

	return 0;
}

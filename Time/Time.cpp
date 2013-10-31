#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string whatTime( int seconds )
{
	string str;
	int h = seconds / 3600;
	seconds %= 3600;
	int m = seconds / 60;
	seconds %= 60;
	char buf[64];
	sprintf( buf, "%d:%d:%d", h, m, seconds );
	str = buf;
	return str;
}

int main()
{
	string s = whatTime( 3661 );
	cout << s << std::endl;

	return 0;
}

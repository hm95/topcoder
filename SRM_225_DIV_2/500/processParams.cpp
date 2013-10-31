#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string processParams( string code, vector <string> params )
{
	string ret = "";
	int x, y, p, i, j;

	for( i = 0; i < code.length(); i++ )
	{
		if( code[i] != '$' || code[i+1] == '0' || i == code.length() - 1 )
		{
			ret += code[i];
			continue;
		}
		x = y = 0;
		for( j = i+1; j < code.size(); j++ )
		{
			if( !isdigit( code[j] ) ) break;
			y = x*10 + code[j] - '0';
			if( y > params.size() ) break;
			x = y;
		}

		if( x == 0 )
		{
			ret += code[i];
			continue;
		}
		else
		{
			i = j - 1;
			ret += params[ x - 1 ];
		}
	}

	return ret;
}

int main()
{
	string c = "if( $1 == $2 ) $3;";
	vector <string> params;
	params.push_back("12");
	params.push_back("12");
	params.push_back("doWhatIwant();");

	string s = processParams( c, params );
	cout << s << endl;

	return 0;
}

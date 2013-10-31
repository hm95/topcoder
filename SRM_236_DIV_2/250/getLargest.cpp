#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

string getLargest( string numberA, string numberB )
{
	int A, b, C, d;
	sscanf( numberA.c_str(), "%d^%d", &A, &b );
	sscanf( numberB.c_str(), "%d^%d", &C, &d );
	if( b*log(A) > d*log(C) ) return numberA;
	else return numberB;
}

int main()
{
	string a = "3^100";
	string b = "6^87";
	string s = getLargest( a, b );
	cout << s << endl;

	return 0;
}

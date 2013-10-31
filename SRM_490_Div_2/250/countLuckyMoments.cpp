#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLucky( string s )
{
	// AB:BA
	if( s.at(0) == s.at(4) && s.at(1) == s.at(3) ) return true;
	// AA:BB
	else if( s.at(0) == s.at(1) && s.at(3) == s.at(4) ) return true;
	// AB:AB
	else if( s.at(0) == s.at(3) && s.at(1) == s.at(4) ) return true;
	else return false;
}

int countLuckyMoments( vector <string> moments )
{
	int count = 0;
	for( int i = 0; i < moments.size(); i++ )
	{
		if( isLucky( moments[i] ) ) count++;
	}
	return count;
}

int main()
{
	vector <string> moments;
	moments.push_back("00:00");
	moments.push_back("00:59");
	moments.push_back("23:00");
	int count = countLuckyMoments( moments );
	cout << count << endl;

	return 0;
}

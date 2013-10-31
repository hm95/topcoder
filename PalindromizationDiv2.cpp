#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;


class PalindromizationDiv2 {
public:
	bool all_nines( string beg )
	{
		for( int i = 0; i < beg.size(); i++ )
			if( beg[i] != '9' ) return false;
		return true;
	}
	bool is_palindrome( int X )
	{
		stringstream ss;
		ss << X;

		for( int i = 0; i < ss.str().length(); i++ )
			if( ss.str()[i] != ss.str()[ss.str().length() - 1 - i] ) return false;

		return true;
	}
	int getMinimumCost(int X)
	{
		if( is_palindrome( X) ) return 0;

		stringstream ss;
		ss << X;

		int hl = ss.str().length()/2;
		string beg = "", nd = "";

		for( int i = 0; i < hl; i++ )
		{
			beg += ss.str()[i];
			nd += ss.str()[ ss.str().length() - 1 - i ];
		}

		if( atoi( nd.c_str() ) == 0 && all_nines( beg ) ) return 1;

		reverse( beg.begin(), beg.end() );
		reverse( nd.begin(), nd.end() );
		int rd = atoi( beg.c_str() ) - atoi( nd.c_str() );

		return abs( rd );
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	PalindromizationDiv2 *obj;
	int answer;
	obj = new PalindromizationDiv2();
	clock_t startTime = clock();
	answer = obj->getMinimumCost(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = 25;
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 12321;
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 40;
	p1 = 4;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2011;
	p1 = 9;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 0;
	p1 = 0;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
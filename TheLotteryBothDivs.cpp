#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <list>
#include <iterator>
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

using namespace std;


class TheLotteryBothDivs {
public:
	bool is_suffix_of(const string& a, const string& b)
	{
		if ( b.size() <= a.size() ) return false;
		return ( b.substr( b.length() - a.length() ) == a );
	}

	double num( string s )
	{
		int num_digits = s.size();
		return pow( 10.0, 9 - num_digits );
	}

	double find(vector <string> goodSuffixes)
	{
		double good = 0.0;
		
		bool removed[ goodSuffixes.size() ];
		fill( removed, removed + goodSuffixes.size(), false );

		// find all good suffixes
		for( int i = 0; i < goodSuffixes.size(); i++ )
		{
			for( int j = 0; j < i; j++ )
				if( goodSuffixes[i] == goodSuffixes[j] )
					removed[i] = true;

			for( int j = 0; j < goodSuffixes.size(); j++ )
				if( is_suffix_of( goodSuffixes[j], goodSuffixes[i] ) )
					removed[i] = true;
		}

		for( int i = 0; i < goodSuffixes.size(); i++ )
			if( !removed[i] )
				good += pow( 10.0, 9.0 - goodSuffixes[i].length() );
	
		return good / 1e9;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TheLotteryBothDivs *obj;
	double answer;
	obj = new TheLotteryBothDivs();
	clock_t startTime = clock();
	answer = obj->find(p0);
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
		res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	
	vector <string> p0;
	double p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"4","7"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"47","47"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.01;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"47","58","4747","502"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.021;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"8542861","1954","6","523","000000000","5426","8"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.201100101;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{	
	// ----- test 5-----
	string t0[] = {"99555", "76", "259775455", "84455", "26", "455", "6055", "3", "8", "3", "1", "55", "17398755", "6155", "60455", "47", "8", "55", "050146755", "6269355", "37", "55", "7", "155", "443494955", "9", "5435455", "88169055", "434955", "8714155", "0111255", "7", "859155", "5266755", "16755", "5", "93", "4555", "77", "17655", "305755", "1", "55", "441046055", "555", "2", "040635555", "45", "55", "255"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.7211;
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

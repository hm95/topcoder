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

using namespace std;


class TheNewHouseDivTwo {
public:
	bool e( int x, int y, vector <int> xs, vector <int> ys, set <pair<int,int> > houses )
	{
		cout << "e" << endl;
		cout << (houses.end() != houses.find( make_pair( x + 2, y ) ) )<< endl << (houses.end() != houses.find( make_pair(x + 1, y + 1 ))) << endl << (houses.end() != houses.find(make_pair( x+1, y-1 ) )) << endl << endl;
		if( houses.end() != houses.find( make_pair( x + 2, y ) ) && houses.end() != houses.find( make_pair(x + 1, y + 1 )) && houses.end() != houses.find(make_pair( x+1, y-1 ) )) return true;
		else return false;
	}

	bool w( int x, int y, vector <int> xs, vector <int> ys, set <pair<int,int> > houses )
	{
		cout << "w" << endl;
		cout << (houses.end() != houses.find( make_pair( x - 2, y ) ) )<< endl << (houses.end() != houses.find( make_pair(x - 1, y + 1 ))) << endl << (houses.end() != houses.find(make_pair( x-1, y-1 ) )) << endl << endl;
		if( houses.end() != houses.find( make_pair( x - 2, y ) ) && houses.end() != houses.find( make_pair( x - 1, y + 1 )) && houses.end() != houses.find(make_pair (x-1, y-1 )) ) return true;
		else return false;
	}

	bool n( int x, int y, vector <int> xs, vector <int> ys, set <pair<int,int> > houses )
	{
		cout << "n" << endl;
		cout << (houses.end() != houses.find( make_pair( x, y+2 ) ) )<< endl << (houses.end() != houses.find( make_pair(x + 1, y + 1 ))) << endl << (houses.end() != houses.find(make_pair( x-1, y+1 ) )) << endl << endl;
		if( houses.end() != houses.find( make_pair( x, y+2 ) ) && houses.end() != houses.find(make_pair (x+1, y + 1 )) && houses.end() != houses.find(make_pair( x-1, y+1 )) ) return true;
		else return false;
	}

	bool s( int x, int y, vector <int> xs, vector <int> ys, set <pair<int,int> > houses )
	{
		cout << "s" << endl;
		cout << (houses.end() != houses.find( make_pair( x, y-2 ) ) )<< endl << (houses.end() != houses.find( make_pair(x + 1, y - 1 ))) << endl << (houses.end() != houses.find(make_pair( x-1, y-1 ) )) << endl << endl;
		if( houses.end() != houses.find( make_pair( x, y-2 ) ) && houses.end() != houses.find(make_pair( x+1, y - 1 )) && houses.end() != houses.find( make_pair(x-1, y-1 )) ) return true;
		else return false;
	}

	int count(vector <int> x, vector <int> y)
	{
		set < pair<int, int> > houses;
		set <pair<int,int> > u;

		for( int i = 0; i < x.size(); i++ )
			houses.insert( make_pair( x[i], y[i] ) );

		int ni= 0;
		for( int i = 0; i < x.size(); i++ )
		{
			if( e( x[i], y[i], x, y, houses) && (u.end() == u.find( make_pair( x[i], y[i]))))
			{
				ni++;
				u.insert( make_pair( x[i] + 1, y[i] ) );
			}
			if( w( x[i], y[i], x, y, houses) && (u.end() == u.find( make_pair( x[i], y[i]))))
			{
				ni++;
				u.insert( make_pair( x[i]-1, y[i] ) );
			}
			if( n( x[i], y[i], x, y, houses) && (u.end() == u.find( make_pair( x[i], y[i]))))
			{
				ni++;
				u.insert( make_pair( x[i], y[i]+1 ) );
			}
			if( s( x[i], y[i], x, y, houses) && (u.end() == u.find( make_pair( x[i], y[i]))))
			{
				ni++;
				u.insert( make_pair( x[i], y[i] -1) );
			}
		}

		return ni;	
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheNewHouseDivTwo *obj;
	int answer;
	obj = new TheNewHouseDivTwo();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {-1,1,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,-1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {4,5,0,8,-3,5,4,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9,-4,2,1,1,11,0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {4,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,7,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,7,3,4,9,3,7,1,1,6,1,6,1,9,7,9,4,9,1,4,7,1,2,5,3,8,7,7,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,2,8,9,4,3,4,1,4,1,7,8,1,1,1,4,7,1,9,4,9,1,4,1,1,1,2,4,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
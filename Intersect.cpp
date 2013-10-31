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


class Intersect {
public:
	int area( vector <int> x, vector <int> y )
	{
		int minx = min( x[0], x[1] );
		int maxx = max( x[0], x[1] );
		int miny = min( y[0], y[1] );
		int maxy = max( y[0], y[1] );
		
		for( int i = 2; i < x.size(); i += 2 )
		{
			minx = max( minx, min( x[i], x[i+1] ) );
			maxx = min( maxx, max( x[i], x[i+1] ) );
			miny = max( miny, min( y[i], y[i+1] ) );
			maxy = min( maxy, min( y[i], y[i+1] ) );
		}
		
		if( minx < maxx && miny < maxy ) return ( maxx - minx )*( maxy - miny );
		else return 0;
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
	Intersect *obj;
	int answer;
	obj = new Intersect();
	clock_t startTime = clock();
	answer = obj->area(p0, p1);
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
	int t0[] = {0,2,3,-4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {17,1000,18,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {10000,-10000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-10000,10000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 400000000;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {3,8,6,12,10,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,17,7,17,7,17};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,0,0,0,0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,5,5,5,5,5,5,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {2,100,5,32,1000,-20,47,12};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {29,-1000,-800,-200,-900,300,-600,-650};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1000;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {1,7,12,3,16,8,3,12};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-90,-60,-70,3,-60,-90,-80,-100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
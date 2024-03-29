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


class MafiaGame {
public:
	double probabilityToLose(int N, vector <int> decisions)
	{
		int votes[N];
		memset( votes, 0, sizeof( votes ) );
		int maxv = -1;
		double num_vul = 0;

		for( int i = 0; i < decisions.size(); i++ )
		{
			votes[ decisions[i] ]++;
			maxv = max( maxv, votes[ decisions[i] ] );
		}

		for( int i = 0; i < N; i++ )
			if( votes[i] == maxv )
				num_vul++;

		if( num_vul == decisions.size() ) return 0.0;
		
		int c = num_vul;
		while( true )
		{
			if( c == 0 ) return 0.0;
			if( c == 1 ) return 1.0 / num_vul;
			c = N % c;
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	MafiaGame *obj;
	double answer;
	obj = new MafiaGame();
	clock_t startTime = clock();
	answer = obj->probabilityToLose(p0, p1);
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
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	vector <int> p1;
	double p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	int t1[] = {1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	int t1[] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,18,19,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 23;
	int t1[] = {17,10,3,14,22,5,11,10,22,3,14,5,11,17};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0.14285714285714285;
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

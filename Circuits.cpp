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

#define NO_PATH -9e8;

class Circuits {
public:
	int howLong(vector <string> connects, vector <string> costs)
	{		
		/* Initializing adjacency matrix. */
		int path[connects.size()][connects.size()];
		
		for( int i = 0; i < connects.size(); i++ )
			for( int j = 0; j < connects.size(); j++ )
				path[i][j] = NO_PATH;
		
		
		/* Initial adjacency matrix costs for visiting each node. */
		int to, cost_to;
		
		for( int i = 0; i < costs.size(); i++ )
		{			
			istringstream iss( connects[i], istringstream::in );
			istringstream bss( costs[i], istringstream::in );
			
			while( iss >> to && bss >> cost_to )
				path[i][to] = cost_to;
		}
		
		
		/* Computing longest path. */
		int m = 0;
		
		for( int k = 0; k < connects.size(); k++ )
			for( int i = 0; i < connects.size(); i++ )
				for( int j = 0; j < connects.size(); j++ )
				{
					path[i][j] = max( path[i][j], path[i][k] + path[k][j] );
					m = max( m, path[i][j] );
				}

		return m;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Circuits *obj;
	int answer;
	obj = new Circuits();
	clock_t startTime = clock();
	answer = obj->howLong(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"1 2","2",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"5 3","7",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 12;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1","2","3","","5","6","7",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"2","2","2","","3","3","3",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"","2 3 5","4 5","5 6","7","7 8","8 9","10","10 11 12","11","12","12",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"","3 2 9","2 4","6 9","3","1 2","1 2","5","5 6 9","2","5","3",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 22;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"","2 3","3 4 5","4 6","5 6","7","5 7",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"","30 50","19 6 40","12 10","35 23","8","11 20",""};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 105;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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

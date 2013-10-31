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


class GardenHose {
public:
	int countDead(int n, int rowDist, int colDist, int hoseDist)
	{
		int d_top[n];
		int d_left[n];
		int d_right[n];
		int d_bot[n];

		bool ok[n][n];
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				ok[i][j] = false;

		for( int i = 0; i < n; i++ )
		{
			d_top[i] = colDist * ( i + 1 );
			d_bot[i] = colDist * ( n - i );
			d_left[i] = rowDist * ( i + 1 );
			d_right[i] = rowDist * ( n - i );
		}
		
		for( int i = 0; i < n; i++ )
		{
			if( hoseDist >= d_top[i] )
				for( int j = 0; j < n; j++ )
					ok[i][j] = true;

			if( hoseDist >= d_bot[n - i - 1] )
				for( int j = 0; j < n; j++ )
					ok[n - i - 1][j] = true;

			if( hoseDist >= d_left[i] )
				for( int j = 0; j < n; j++ )
					ok[j][i] = true;

			if( hoseDist >= d_right[n - i - 1] )
				for( int j = 0; j < n; j++ )
					ok[j][n - i - 1] = true;
		}

		int count = 0;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				if( !ok[i][j] ) count++;

		return count;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	GardenHose *obj;
	int answer;
	obj = new GardenHose();
	clock_t startTime = clock();
	answer = obj->countDead(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p2;
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 1;
	p3 = 2;
	p4 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 1;
	p3 = 1;
	p4 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = 2;
	p2 = 5;
	p3 = 5;
	p4 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 2;
	p2 = 5;
	p3 = 3;
	p4 = 24;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 50;
	p1 = 50;
	p2 = 50;
	p3 = 49;
	p4 = 2500;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
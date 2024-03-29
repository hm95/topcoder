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


class LeaguePicks {
public:
	vector <int> returnPicks(int position, int friends, int picks)
	{
		vector <int> a;
		int count = 0;
		while(1)
		{
			for( int i = 1; i <= friends; i++ )
			{
				count++;
				if( i == position )
					a.push_back(count);

				if( count == picks )
					return a;

			} 
			for( int i = friends; i > 0; i-- )
			{
				count++;
				if( i == position )
				a.push_back(count);
				
				if( count == picks )
					return a;
			}
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, vector <int> p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	LeaguePicks *obj;
	vector <int> answer;
	obj = new LeaguePicks();
	clock_t startTime = clock();
	answer = obj->returnPicks(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p3;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 6;
	p2 = 15;
	int t3[] = {3,10,15};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2 = 10;
	int t3[] = {1,2,3,4,5,6,7,8,9,10};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 2;
	p2 = 39;
	int t3[] = {1,4,5,8,9,12,13,16,17,20,21,24,25,28,29,32,33,36,37};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 11;
	p2 = 100;
	int t3[] = {5,18,27,40,49,62,71,84,93};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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

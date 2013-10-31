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


class HammingNumbers {
public:
	int getNumber(vector <int> factors, int n)
	{
		map <int, int> mmap;
		sort( factors.begin(), factors.end() );
		mmap[1] = 1;
		
		int tmp, cnt;
		for( int i = 0; i < factors.size(); i++ )
		{
			tmp = factors[i];
			cnt = 0;
			while( cnt < n )
			{
				mmap[tmp] = 1;
				tmp += factors[i];
				cnt++;
			}
		}
		
		map <int, int>::iterator it = mmap.begin();
		int nu = 0;
		
		while( it != mmap.end() && nu < n )
		{
			cout << it->first << endl;
			if( it->second != 0 ) nu++;
			it++;
		}
		
		return it->first;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	HammingNumbers *obj;
	int answer;
	obj = new HammingNumbers();
	clock_t startTime = clock();
	answer = obj->getNumber(p0, p1);
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
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {2,3,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
	p2 = 24;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,2,2,4,4,4,8,8,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 11;
	p2 = 1024;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {7,9,14,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 52;
	p2 = 4802;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {4,11,15,21,29,28};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2841;
	p2 = 2146636800;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100000;
	p2 = 532287;
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

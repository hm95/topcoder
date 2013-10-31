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


class MinCostPalindrome {
public:
	int getMinimum(string s, int oCost, int xCost) {
    int cur_cost = 0;
    for( int i = 0; i < s.size() / 2; i++ )
      if( s[i] == '?' && s[s.size() - 1 - i] != '?' )
      {
        s[i] = s[s.size() - 1 - i];
        if( s[i] == 'o' )
          cur_cost += oCost;
        else
          cur_cost += xCost;
      }

    for( int i = 0; i < s.size() / 2; i++ )
      if( s[i] != '?' && s[s.size() - 1 - i] == '?' )
      {
        s[s.size() - 1 - i] = s[i];
        if( s[i] == 'o' )
          cur_cost += oCost;
        else
          cur_cost += xCost;
      }


    string sorted = s;
    reverse( sorted.begin(), sorted.end() );
    if( s != sorted ) return -1;

    int num_ = 0;
    for( int i = 0; i < s.size(); i++ )
      if( s[i] == '?' )
        num_++;

    return num_ * min(oCost, xCost) + cur_cost;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	MinCostPalindrome *obj;
	int answer;
	obj = new MinCostPalindrome();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	string p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = "oxo?xox?";
	p1 = 3;
	p2 = 5;
	p3 = 8;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "x?" "?x";
	p1 = 9;
	p2 = 4;
	p3 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ooooxxxx";
	p1 = 12;
	p2 = 34;
	p3 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "oxoxooxxxxooxoxo";
	p1 = 7;
	p2 = 4;
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "?o";
	p1 = 6;
	p2 = 2;
	p3 = 6;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?";
	p1 = 50;
	p2 = 49;
	p3 = 980;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "o?" "?oxxo?xoox?ox?" "?x?" "?";
	p1 = 3;
	p2 = 10;
	p3 = 38;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
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

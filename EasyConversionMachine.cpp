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


class EasyConversionMachine {
public:
	string isItPossible(string originalWord, string finalWord, int k) {
        int diff = 0;
        for( int i = 0; i < originalWord.size(); i++ )
            if( originalWord[i] != finalWord[i] )
                diff++;
        if( diff > k ) return "IMPOSSIBLE";
        if( (k - diff) % 2 == 0 ) return "POSSIBLE";
        return "IMPOSSIBLE";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, int p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"" << "," << p2;
	cout << "]" << endl;
	EasyConversionMachine *obj;
	string answer;
	obj = new EasyConversionMachine();
	clock_t startTime = clock();
	answer = obj->isItPossible(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	int p2;
	string p3;
	
	{
	// ----- test 0 -----
	p0 = "aababba";
	p1 = "bbbbbbb";
	p2 = 2;
	p3 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "aabb";
	p1 = "aabb";
	p2 = 1;
	p3 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "aaaaabaa";
	p1 = "bbbbbabb";
	p2 = 8;
	p3 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "aaa";
	p1 = "bab";
	p2 = 4;
	p3 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "aababbabaa";
	p1 = "abbbbaabab";
	p2 = 9;
	p3 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
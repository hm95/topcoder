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


class SuperRot {
public:

	string decoder(string message)
	{

		for( int i = 0; i < message.length(); i++ )
		{
			if( message[i] == ' ' ) continue;
			
			if( int( message[i] ) >= 65 && int( message[i] ) <= 77 )
			{
				message[i] = message[i] + 13;
				continue;
			}
			
			if( int( message[i] ) >= 78 && int( message[i] ) <= 90 )
			{
				message[i] = message[i] - 13;
								continue;
			}
			
			if( int( message[i] ) >= 97 && int( message[i] ) <= 109 )
			{
				message[i] = message[i] + 13;
								continue;
			}
			
			if( int( message[i] ) >= 110 && int( message[i] ) <= 122 )
			{
				message[i] = message[i] - 13;
								continue;
			}
			
			if( int( message[i] ) >= 48 && int( message[i] ) <= 52 )
			{
				message[i] = message[i] + 5;
								continue;
			}
			
			if( int( message[i] ) >= 53 && int( message[i] ) <= 57 )
			{
				message[i] = message[i] - 5;
								continue;
			}
		}	
	
		return message;
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	SuperRot *obj;
	string answer;
	obj = new SuperRot();
	clock_t startTime = clock();
	answer = obj->decoder(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	{
	// ----- test 0 -----
	p0 = "Uryyb 28";
	p1 = "Hello 73";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "GbcPbqre";
	p1 = "TopCoder";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "";
	p1 = "";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "5678901234";
	p1 = "0123456789";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "NnOoPpQqRr AaBbCcDdEe";
	p1 = "AaBbCcDdEe NnOoPpQqRr";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ";
	p1 = "Time is 09 26 PM on July 9th of the year 2003 AD";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "Gur dhvpx oebja sbk whzcf bire n ynml qbt";
	p1 = "The quick brown fox jumps over a lazy dog";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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

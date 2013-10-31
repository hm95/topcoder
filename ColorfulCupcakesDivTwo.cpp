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


class ColorfulCupcakesDivTwo {
public:
    int num_diff( map <char, int> freq, char not_this, char not_that )
    {
         int count = 0;

        map <char, int>::iterator it = freq.begin();
        while( it != freq.end() )
        {
            if( it->first != not_this && it->first != not_that && it->second != 0 )
                count++;
            it++;
        }

        return count;
    }

    int num_diff( map <char, int> freq, char not_this )
    {
        int count = 0;

        map <char, int>::iterator it = freq.begin();
        while( it != freq.end() )
        {
            if( it->first != not_this && it->second != 0 )
                count++;
            it++;
        }

        return count;
    }

	int countArrangements(string cupcakes)
    {
        map <char, int> freq;
        for( int i = 0; i < cupcakes.size(); i++ )
            freq[cupcakes[i]]++;

        int size = freq.size();

        int ret = size;

        cupcakes[i] = 'A';

        for( int i = 1; i < cupcakes.size(); i++ )
        {
            if( i == cupcakes.size() - 1 ) ret *= num_diff( freq, cupcakes[i - 1], cupcakes[0] );
            else ret *= num_diff( freq, cupcakes[i - 1] );
        }

        return ret % 1000000007;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	ColorfulCupcakesDivTwo *obj;
	int answer;
	obj = new ColorfulCupcakesDivTwo();
	clock_t startTime = clock();
	answer = obj->countArrangements(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "ABAB";
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ABABA";
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ABC";
	p1 = 6;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "ABABABABABABABABABABABABABABABABABABABABABABABABAB";
	p1 = 2;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA";
	p1 = 741380640;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
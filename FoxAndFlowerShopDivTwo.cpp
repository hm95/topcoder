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


class FoxAndFlowerShopDivTwo {
public:
    int get( vector <string> flowers, int sr, int er, int sc, int ec )
    {
        //cout << "sr " << sr << "er " << er << "sc " << sc << "ec " << ec << endl;
        int sum = 0;
        if( sr >= 0 && er <= flowers.size() && sc >= 0 && ec <= flowers[0].size() )
        {
            for( int i = sr; i <= er; i++ )
                for( int j = sc; j <= ec; j++ )
                    if( flowers[i][j] == 'F' )
                        sum++;
        }

        //cout << "has " << sum << endl << endl;

        return sum;
    }

    int get_max( vector <string> flowers, int r, int c, string type )
    {
        int sr = 0, er = flowers.size() - 1, sc = 0, ec = flowers[0].size() - 1;
        if( type == "top" )
            er = r - 1;
        else if( type == "right" )
            sc = c + 1;
        else if( type == "left" )
            ec = c - 1;
        else
            sr = r + 1;

        return get( flowers, sr, er, sc, ec );
    }

	int theMaxFlowers(vector <string> flowers, int r, int c) {
        int top = get_max( flowers, r, c, "top" );
        int right = get_max( flowers, r, c, "right" );
        int left = get_max( flowers, r, c, "left" );
        int bot = get_max( flowers, r, c, "bot" );

        return max( max( top, right ), max( left, bot ) );
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	FoxAndFlowerShopDivTwo *obj;
	int answer;
	obj = new FoxAndFlowerShopDivTwo();
	clock_t startTime = clock();
	answer = obj->theMaxFlowers(p0, p1, p2);
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
	
	vector <string> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"F.F",".F.",".F."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 1;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"F..","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {".FF.F.F","FF...F.","..FF.FF"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 2;
	p3 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"F",".","F","F","F",".","F","F"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 0;
	p3 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {".FFF..F...","FFF...FF.F","..F.F.F.FF","FF..F.FFF.","..FFFFF...","F....FF...",".FF.FF..FF","..F.F.FFF.",".FF..F.F.F","F.FFF.FF.F"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 3;
	p3 = 32;
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

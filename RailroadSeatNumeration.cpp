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


class RailroadSeatNumeration {
public:
    string convert( vector <int> tickets, string type )
    {
        vector <int> domestic;
        for( int i = 1; i <= 36; i++ )
            domestic.insert( i );

        vector <int> international;
        for( int i = 1; i <= 9; i++ )
            for( int j = 1; j <= 4; j++ )
                international.insert( atoi( itoa( i ) + itoa( j ) ) );

       map <int, string> mapping;
       for( int i = 0; i < domestic.size(); i++ )
            mapping[domestic[i]] = international[i];

       string str = "";

       if( type == "INTERNATIONAL" )
       {
            for( int i = 0; i < tickets.size(); i++ )
            {
                str += itoa(tickets[i]);
                if( i != tickets.size() - 1 ) str += ' ';
            }
       }
       else
       {
            for( int i = 0; i < tickets.size(); i++ )
            {
                str += mapping[tickets[i]];
                if( i != tickets.size() - 1 ) str += ' ';
            }
       }

       return str;
    }

	string getInternational(vector <int> tickets) {
        set <string> domestic;
        stringstream out;
        for( int i = 1; i <= 36; i++ )
        {
           out << i;
           domestic.insert( out.str() );
        }

        set <string> international;
        for( int i = 1; i <= 9; i++ )
            for( int j = 1; j <= 4; j++ )
            {
                out << i;
                string first = out.str();
                out << j;
                string second = out.str();
                international.insert( first + second );
            }

        bool allDomestic = true, allInternational = true;
        for( int i = 0; i < tickets.size(); i++ )
        {
            if( international.find( itoa(tickets[i]) ) == international.end() &&
                domestic.find( itoa(tickets[i]) ) == domestic.end() ) return "BAD DATA";
            

            if( international.find( itoa(tickets[i]) ) == international.end() )
                allInternational = false;
er
            if( domestic.find( itoa(tickets[i]) ) == domestic.end() )
                allDomestic = false;
        }

        if( allDomestic && allInternational ) return "AMBIGUOUS";
        if( allDomestic ) return convert( tickets, "DOMESTIC" );
        return convert( tickets, "INTERNATIONAL" );
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	RailroadSeatNumeration *obj;
	string answer;
	obj = new RailroadSeatNumeration();
	clock_t startTime = clock();
	answer = obj->getInternational(p0);
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "11";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "AMBIGUOUS";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {45};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "BAD DATA";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {5,7,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "21 24 23";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {21,24,23};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "AMBIGUOUS";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {8,28};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "26 76";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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

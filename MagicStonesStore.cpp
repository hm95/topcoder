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


class MagicStonesStore {
public:
  vector <int> get_first( int n )
  {
    vector <bool> prime( 9e4 + 1, true );
    int num_primes = 0;

    for( int i = 2; i <= sqrt(9e4); i++ )
    {
      if( num_primes > 9e4 ) break;
      if( !prime[i] ) continue;
      num_primes++;
      for( int j = 2 * i; j <= 9e4; j += i )
        prime[j] = false;
    }

    vector <int> list_primes;
    for( int i = 2; i <= 9e4; i++ )
      if( prime[i] && num_primes > 0 )
      {
        num_primes--;
        list_primes.push_back(i);
      }

    for( int i = 2; i <= list_primes.size(); i++ )
      cout << list_primes[i] << " ";
    cout << endl;

    return list_primes[list_primes.size() - 1];

    return list_primes;
  }

	string ableToDivide(int n) {
    vector <int> primes = get_first(n);
    for( int i = 0; i < primes.size(); i++ )
      for( int j = 0; j < primes.size(); j++ )
        if( primes[i] + primes[j] == 2 * n )
          return "YES";

    return "NO";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	MagicStonesStore *obj;
	string answer;
	obj = new MagicStonesStore();
	clock_t startTime = clock();
	answer = obj->ableToDivide(p0);
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
	
	int p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = "NO";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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

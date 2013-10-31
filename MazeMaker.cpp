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
#include <string.h>
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


class MazeMaker {
public:
	struct pos
	{
		int row, col;
		int steps;
	};

	bool is_ok( int row, int col, vector <string> maze )
	{
		if( row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() ) return true;
		return false;
	}

	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)
	{
		int visited[maze.size()][maze[0].size()];
		memset( visited, -1, sizeof( visited ) );
		visited[startRow][startCol] = 0;

		pos start;
		start.row = startRow;
		start.col = startCol;
		start.steps = 0;

		queue <pos> q;
		q.push( start );

		while( !q.empty() )
		{
			pos cur = q.front();
			q.pop();

			for( int i = 0; i < moveRow.size(); i++ )
			{
				pos tmp;
				tmp.row = cur.row + moveRow[i];
				tmp.col = cur.col + moveCol[i];
				tmp.steps = cur.steps + 1;

				if( is_ok( tmp.row, tmp.col, maze ) )
				{
					if( maze[tmp.row][tmp.col] == '.' )
					{
						if( visited[tmp.row][tmp.col] == -1 )
						{
							q.push( tmp );
							visited[tmp.row][tmp.col] = tmp.steps;
						}
						else visited[tmp.row][tmp.col] = min( tmp.steps, visited[tmp.row][tmp.col] );
					}
				}
			}
		}

		int max_steps = 0;
		for( int i = 0; i < maze.size(); i++ )
		{
			for( int j = 0; j < maze[0].size(); j++ )
			{
				if( maze[i][j] == '.' && visited[i][j] == -1 ) return -1;
				max_steps = max( max_steps, visited[i][j] );
			}
		}

		return max_steps;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p4[i];
	}
	cout << "}";
	cout << "]" << endl;
	MazeMaker *obj;
	int answer;
	obj = new MazeMaker();
	clock_t startTime = clock();
	answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	vector <int> p3;
	vector <int> p4;
	int p5;
	
	{
	// ----- test 0 -----
	string t0[] = {"...","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"...","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0,1,1,-1,-1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1,1,-1,1,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"X.X","...","XXX","X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".......","X.X.X..","XXX...X","....X..","X....X.","......."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	p2 = 0;
	int t3[] = {1,0,-1,0,-2,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,-1,0,1,3,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 7;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"......."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	int t3[] = {1,0,1,0,1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,1,0,1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 6;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..X.X.X.X.X.X."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	int t3[] = {2,0,-2,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,2,0,-2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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
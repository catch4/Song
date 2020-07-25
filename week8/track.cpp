/*
Catch study 8주차
프로그래머스_경주로 건설
https://programmers.co.kr/learn/courses/30/lessons/67259
*/
/*-------------------------
풀이
(23 * 2 + 2) * 500 =  24000
25*25*100 = 62500
최대값 = 86500 -> long long 안해두댐

분류는 잘 모르겠다.
다익스트라 같기는 한데
최소값부터 시작하는게 아니라 최대 비용부터 갱신했다.
최소비용 부터 갱신하면 test 14가 실패로 뜬다.
아마도
...  2800	  ... 2800     ...   2800
2400      -> 2400 2500 ->  2400  2500    원래는 3000
                                 3100
이런 상황 때문에 그런 것 같음
---------------------------*/

#include <iostream>
#include <vector>
#include <queue>
#define vec2d std::vector<std::vector<int>>
#define INF 2147000000
int n, dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
using namespace std;

struct Path {
	int y, x,c;
	bool d;
	Path(){}
	Path(const int& t_y, const int& t_x, const int& t_c, const bool& t_d)  {
		y = t_y; x = t_x; c = t_c; d = t_d;
	}
	bool operator<(const Path& bb)const {
		return c < bb.c;
	}
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	std::priority_queue<Path> Q;
	vec2d cost(n, std::vector<int>(n, INF));
	cost[0][0] = 0;
	Q.push(Path(0, 0, 0, 0));
	Q.push(Path(0, 0, 0, 1));
	while (!Q.empty()) {
		Path now = Q.top();
		Q.pop();
		for (int k = 0; k < 4; k++)
		{
			int n_y = now.y + dy[k], n_x = now.x + dx[k],n_c;
			if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= n||board[n_y][n_x]) continue;
			if (k / 2 == now.d) n_c = now.c + 100;
			else n_c = now.c + 600;
			if (cost[n_y][n_x] >= n_c) {
				cost[n_y][n_x] = n_c;
				Q.push(Path(n_y, n_x, n_c, k / 2));
			}
		}
	}
	answer = cost[n - 1][n - 1];
	return answer;
}


int main() {
	int n; std::cin >> n;
	std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin>> board[i][j];
		}
	std::cout << solution(board) << '\n';
}



/*
3
0 0 0
0 0 0
0 0 0
answer = 900

8
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 1
0 0 1 0 0 0 1 0
0 1 0 0 0 1 0 0
1 0 0 0 0 0 0 0
answer = 3800

4
0 0 1 0
0 0 0 0
0 1 0 1
1 0 0 0
answer = 2100
600+2000
6
0 0 0 0 0 0
0 1 1 1 1 0
0 0 1 0 0 0
1 0 0 1 0 1
0 1 0 0 0 1
0 0 0 0 0 0
answer = 3200
*/
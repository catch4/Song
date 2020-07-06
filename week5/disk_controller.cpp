/*
Catch study 5주차
프로그래머스_디스크 컨트롤러
https://programmers.co.kr/learn/courses/30/lessons/42627
*/
/*---------------------------
풀이
우선순위 큐로 풀이

case 1. 현재 시간에 처리 안한 작업이 있는 경우 
	요청된 작업중 가장 작업 속도가 빠른 작업부터 처리
case 2. 현재 요청된 작업이 없을 경우
    먼저온 것 처리

case 1.
1. 요청들어온 시점 - 작업 속도 순으로 오름차순으로 정렬
2. 현재 작업이 끝난 시점전에 들어온 작업들 
   작업 속도 - 요청들어온 시점 순으로 오름차순으로 정렬
3. 작업 처리 시간 = (이전 작업 끝난시점-요청된 시점) + 작업 소요시간
   새로운 작업 끝난 시점 = 이전 작업 끝난 시점 + 작업 소요시간
4. 나머지는 다시 queue로

case 2.
1. [3,1],[3,5] 여도 맨처음 입력 될때 같은 시간대 중에
   가장 빠른게 앞에 있도록 정렬했으므로 바로 처리
   작업 처리시간 = 이 작업의 소요 시간
   새로운 작업 끝난 시점 = 작업 요청받은 시간 + 작업 소요 시간
---------------------------*/

#include <iostream>

#include <vector>
#include <queue>
using namespace std;

struct Request {
	int start,time;
	bool flag;
	Request(const int& t_start, const int& t_time, const bool& t_flag = true) {
		start = t_start; time = t_time; flag = t_flag;
	}
	bool operator <(const Request& bb)
	const {
		if (flag) { // case1-1.
			if (start == bb.start) return time > bb.time;
			else return start > bb.start;
		}
		else // case1-2.
			if (time == bb.time) return start > bb.start;
			else return time > bb.time;
	}
};

#define heap std::priority_queue<Request>

int solution(vector<vector<int>> jobs) {
	
	int answer = 0, len = jobs.size(),end=0;
	heap Q;
	// case1-1
	for (int i = 0; i < len; i++) Q.push(Request( jobs[i][0], jobs[i][1] ));
	while (!Q.empty())
	{
		heap tmp;
		// case1-2
		while (!Q.empty() && Q.top().start <= end) {
			tmp.push(Request(Q.top().start, Q.top().time, false));
			Q.pop();
		}
		if (tmp.size()) // case1
		{
			// case1-3.
			answer += tmp.top().time + end-tmp.top().start;
			end += tmp.top().time;
			tmp.pop();
			while (!tmp.empty()){
				// case1-4.
				Q.push(Request(tmp.top().start, tmp.top().time ));
				tmp.pop();
			}
		}
		else { // case2
			answer += Q.top().time;
			end = Q.top().start + Q.top().time;
			Q.pop();
		}
	}
	return answer/len;
}


/*
test cast

4
0 10
4 10
5 11
15 2
result = 15

3
0 3
1 9
2 6
result = 9

3
0 3
4 3
10 3
result = 3
*/

int main() {
	int n; std::cin >> n;
	vecs jobs(n, std::vector<int>(2));
	for (int i = 0; i < n; i++)
		std::cin >> jobs[i][0] >> jobs[i][1];

	std::cout << solution(jobs) << std::endl;
	
}
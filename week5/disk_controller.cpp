/*
Catch study 5����
���α׷��ӽ�_��ũ ��Ʈ�ѷ�
https://programmers.co.kr/learn/courses/30/lessons/42627
*/
/*---------------------------
Ǯ��
�켱���� ť�� Ǯ��

case 1. ���� �ð��� ó�� ���� �۾��� �ִ� ��� 
	��û�� �۾��� ���� �۾� �ӵ��� ���� �۾����� ó��
case 2. ���� ��û�� �۾��� ���� ���
    ������ �� ó��

case 1.
1. ��û���� ���� - �۾� �ӵ� ������ ������������ ����
2. ���� �۾��� ���� �������� ���� �۾��� 
   �۾� �ӵ� - ��û���� ���� ������ ������������ ����
3. �۾� ó�� �ð� = (���� �۾� ��������-��û�� ����) + �۾� �ҿ�ð�
   ���ο� �۾� ���� ���� = ���� �۾� ���� ���� + �۾� �ҿ�ð�
4. �������� �ٽ� queue��

case 2.
1. [3,1],[3,5] ���� ��ó�� �Է� �ɶ� ���� �ð��� �߿�
   ���� ������ �տ� �ֵ��� ���������Ƿ� �ٷ� ó��
   �۾� ó���ð� = �� �۾��� �ҿ� �ð�
   ���ο� �۾� ���� ���� = �۾� ��û���� �ð� + �۾� �ҿ� �ð�
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
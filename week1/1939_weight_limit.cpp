/*
Catch study 1주차
백준_1939 중량제한
https://www.acmicpc.net/problem/1939
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pi std::pair<int,int>
#define vecs std::vector<pi>

int n, m;
vecs vec[100000];
bool ck[100000];
bool dfs(const int& start,const int& dst,const int& dst_weight)
{
	int len = vec[start].size();
	ck[start] = 1; // 현재 노드 방문 체크
	for (int i = 0; i < len; i++)
	{
		if (ck[vec[start][i].first]) continue;
		if (vec[start][i].first==dst)
		{
			// 목적지며 목표 weight 이상일 경우
			if (vec[start][i].second >= dst_weight) return true;
		}
		else
		{
			// 거쳐가는 지점이 목표 weight 보다 낮으면 볼 필요 없음
			if (vec[start][i].second >= dst_weight) {
				// 재귀 내에서 true를 리턴으로 받았다면 바로 true 리턴
				if (dfs(vec[start][i].first, dst, dst_weight)) return true;
			}
		}
	}
	// 목표 weight를 버틸 수 있는 지점이 존재하지 않음
	return false;
}

int main() {
	 std::cin >> n>>m;
	 int y, x, c,start,dst,max_weight=0;
	 for (int i = 0; i < m; i++)
	 {
		 std::cin >> y >> x >> c;
		 vec[y - 1].push_back({ x-1, c });
		 vec[x - 1].push_back({ y-1,c });
		 if (max_weight < c) max_weight = c;
	 }
	 std::cin >> start >> dst;
	 int l = 0, h = max_weight,mid;
	 while (l <= h)
	 {
		 memset(ck, false, sizeof(ck)); //체크 초기화
		 mid = (h + l) / 2;
		 if (dfs(start - 1, dst - 1, mid)) l = mid + 1; //현재 무게 버틸 수 있을 때
		 else h = mid - 1;
	 }
	
	 std::cout << h<<std::endl;
	 return 0;
}
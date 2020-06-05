/*
Catch study 1����
����_1939 �߷�����
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
	ck[start] = 1; // ���� ��� �湮 üũ
	for (int i = 0; i < len; i++)
	{
		if (ck[vec[start][i].first]) continue;
		if (vec[start][i].first==dst)
		{
			// �������� ��ǥ weight �̻��� ���
			if (vec[start][i].second >= dst_weight) return true;
		}
		else
		{
			// ���İ��� ������ ��ǥ weight ���� ������ �� �ʿ� ����
			if (vec[start][i].second >= dst_weight) {
				// ��� ������ true�� �������� �޾Ҵٸ� �ٷ� true ����
				if (dfs(vec[start][i].first, dst, dst_weight)) return true;
			}
		}
	}
	// ��ǥ weight�� ��ƿ �� �ִ� ������ �������� ����
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
		 memset(ck, false, sizeof(ck)); //üũ �ʱ�ȭ
		 mid = (h + l) / 2;
		 if (dfs(start - 1, dst - 1, mid)) l = mid + 1; //���� ���� ��ƿ �� ���� ��
		 else h = mid - 1;
	 }
	
	 std::cout << h<<std::endl;
	 return 0;
}
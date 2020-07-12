/*
Catch study 6����
����_1029 �׸���ȯ
https://www.acmicpc.net/problem/1029
*/
/*
Ʋ��
����κ��� dy�� ���� ������ �س´µ�
��Ʈ����ŷ���� �ٸ���� �ȶ��ö� ã�ƺ�

���� ������ �׸��� �ǳ׹��� ���, ���� �ݾ�, �ش� ����϶�
�̹� ���� �����ϸ� �װ� return �ϴ� ������� dynamic
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define vec3d std::vector<std::vector<std::vector<int>>>
#define vec2d std::vector<std::vector<int>>
int max = 1, n;
int dfs(vec3d& ck,vec2d& vec, const int& pre,const int& idx,const int& cost) {
	int ret = 1,now=pre|(1<<idx);
	if (now < ((1 << n)-1)) {
		int max = 0,result=0;
		for (int i = 0; i < n; i++) {
			if (now & (1 << i) || vec[idx][i] < cost) continue;
			result = ck[now][i][cost];
			if (!result) {
				result = dfs(ck, vec, now, i, vec[idx][i]);
			}
			max = std::max(result, max);
		}
		ret += max;
	}
	return ck[pre][idx][cost] = ret;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	vec3d ck(1<<n,std::vector<std::vector<int>> (n,std::vector<int> (10,0)));
	vec2d vec(n, std::vector<int> (n,0));
	for (int i = 0; i < n; i++) {
		char ch;
		for (int j = 0; j < n; j++) {
			std::cin >> ch;
			vec[i][j] = ch - '0';
		}

	}
	std::cout << dfs(ck,vec,1,0,0)<< '\n';
}
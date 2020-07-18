/*
Catch study 7����
����_3430 ���̻��
https://www.acmicpc.net/problem/3430
*/
/*
�� ó���� ������ ���� �����ϴ� �� �˾Ҵµ�
������ �� �� �ϳ��� ����ϴ� �ſ���
�������
2 4
0 0 0 1
������
YES
1 0 0
YES
0 1 0
YES
0 0 1
�� ������.

Ʋ��
�޸��ʰ��� ���Ʋ���� ��α� �� ���� ������
�ڿ��� ���� ä��� ������� �ߴµ�
�տ��� ���� ä���� ����

1. �� �� ���³� set�� �߰�
2. �� ���³��� ��� ���� ���� �� �ȿ³��� ȣ�� ����
   t���� ��°� üũ
   (���Ŀ� ������ ȣ���� �񰡿��� �̳� ���Ŀ� �� �ȿ��³� ���ž���)
3. ���ų��� set���� ����
*/
#include <iostream>
#include <vector>
#include <set>
int n, m, t;
bool Is_OK(std::vector<int>& ck, std::vector<int>& ret) {
	std::set<int> s;
	for (int i = 0; i < m; i++) {
		std::cin >> t;
		if (t == 0) {
			s.insert(i);
			ret[i] = 0;
		}
		else {
			auto iter = s.upper_bound(ck[t - 1]);
			if (iter == s.end())
			{
				while (++i < m) {
					std::cin >> t;
				}
				return false;
			}
			// 2.
			ret[*iter] = t;
			ck[t - 1] = i;
			
			// 3.
			s.erase(iter); 
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int z; std::cin >> z;
	while (z--) {
		std::cin >> n >> m;
		std::vector<int> ck(n, -1),ret(m,-1);
		if (Is_OK(ck, ret)) {
			std::cout << "YES\n";
			for (int i = 0; i < m; i++) if (ret[i] != -1) std::cout << ret[i] << " ";
			std::cout << '\n';
		}
		else std::cout << "NO\n";
	}
	return 0;
}
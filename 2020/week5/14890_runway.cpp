/*
Catch study 5����
����_14890 ����
https://www.acmicpc.net/problem/14890
*/
/*---------------------------
Ǯ��
��,�� ���� idx�� ū ���, ���� ��� ������ ����

1. true�� ��� �� �࿡ ���� Ȯ��, false�� ��� �� ���� ����
2. ���� idx�� ū ��� 
   l��ŭ ���� idx���� ���� idx�� �������� Ȯ�� �� üũ
3. ���� idx�� ���� ���
   l��ŭ ���� idx���� ���� idx�� �������� Ȯ�� ��
   �̹� üũ �Ǿ� �ִ� ��� ���θ� ���� ���ϹǷ� false return
4. true ���� �� ��,���� ���� ī��Ʈ
---------------------------*/
#include <iostream>
#include <vector>
#define vecs std::vector<std::vector<int>>
int n, l;

bool slope(vecs& map, int& idx, bool flag) {
	std::vector<bool> ck(n);
	if (flag)
	{
		for (int i = 1; i < n; i++) {
			if (map[idx][i] == map[idx][i - 1]) continue;
			else if (map[idx][i]==map[idx][i - 1]+1) {
				if (i - 1 < l - 1) return false;
				for (int j = i - 1; j >= i - l; j--)
					if (map[idx][i - 1] != map[idx][j] || ck[j]) return false;
					else ck[j] = 1;
			}
			else if (map[idx][i]+1 == map[idx][i - 1]) {
				if (n - i < l) return false;
				for (int j = i; j < i + l; j++)
					if (map[idx][i] != map[idx][j]) return false;
					else ck[j] = 1;
				i = i + l-1;
			}
			else return false;
		}
	}
	else {
		for (int i = 1; i < n; i++) {
			if (map[i][idx] == map[i-1][idx]) continue;
			else if (map[i][idx] == map[i-1][idx] + 1) {
				if (i - 1 < l - 1) return false;
				for (int j = i - 1; j >= i - l; j--)
					if (map[i-1][idx] != map[j][idx] || ck[j]) return false;
					else ck[j] = 1;
			}
			else if (map[i][idx] + 1 == map[i-1][idx]) {
				if (n - i < l) return false;
				for (int j = i; j < i + l; j++)
					if (map[i][idx] != map[j][idx]) return false;
					else ck[j] = 1;
				i = i + l - 1;
			}
			else return false;
		}
	}
	return true;
}

int main() {
	std::cin >> n >> l;
	int cnt = 0;
	vecs map(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
		}
	for (int i = 0; i < n; i++) if (slope(map, i, true)) cnt++;
	for (int i = 0; i < n; i++) if (slope(map, i, false)) cnt++;
	std::cout << cnt << std::endl;
}
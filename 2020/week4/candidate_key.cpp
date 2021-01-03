/*
Catch study 4����
���α׷��ӽ�_�ĺ�Ű
https://programmers.co.kr/learn/courses/30/lessons/42890
*/

/*
��ǰ �̤�,���� �߾� �ڵ� ������
�� �ڵ� ���������� �ִ� ���� �ĺ�Ű ���ϴ� �� �˾Ҵ�.
������ ����� �о�߰ڴ�. test case�� �� �Ʒ��� �ּ����� ǥ���ߴ�.

�Ʒ��� 1�� 3�� �ٽ��� �� ����.

1. index�� ���������� ����ȭ �� �� bool������ �Ǻ�
ex) 5�� ��� 101 -> 1�� index�� 3�� index ����
2. set�� �Ź� Ȯ������ �ʰ� size�� Ȯ���Ѵ�.(�ߺ��Ǹ� n�̸��� ũ�Ⱑ ����)
3. �κ������� �ĺ�Ű������ Ȯ���Ѵ�. �̺κе� ����ȭ�� ����Ѵ�.
ex) 7�� ��� 1101 -> 1,3,4 �� index ����, ���� 5(101)�� �ĺ�Ű���ٸ�
	7&5 = 5�� true�� false�� return
4. ���� �ڵ�� now+=relation[j][k];�ε� �������� ���� case �÷��� �����ߴ�.
5. ���������� �ĺ�Ű�� ������ ���� return �Ѵ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool possi(vector<int> &vec, int now) {
	for (int i = 0; i<vec.size(); i++)
		if ((vec[i] & now) == vec[i])return false; // 3.
	return true;
}
int solution(vector<vector<string>> relation) {
	int n = relation.size();
	int m = relation[0].size();
	vector<int> ans;
	for (int i = 1; i<(1 << m); i++) {
		set<string> s;
		for (int j = 0; j<n; j++) {
			string now = "";
			for (int k = 0; k<m; k++) {
				// 1.
				if (i&(1 << k))now += relation[j][k]+ " "; // 4.
			}
			s.insert(now);
		}
		if (s.size() == n&&possi(ans, i))ans.push_back(i); // 2.
	}
	return ans.size();
}

int main() {
	int n, m; std::cin >> n >> m;
	vector<vector<string>> relation(n, vector<string>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> relation[i][j];
	std::cout << solution(relation) << std::endl;
}

/*
����.
4 2
ab
c
a
bc
a
x
x
c

6 4
100
ryan
music
2
200
apeach
math
2
300
tube
computer
3
400
con
computer
4
500
muzi
music
3
600
apeach
music
2
*/
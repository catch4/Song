/*
Catch study 13����
����_7575 ���̷���
https://www.acmicpc.net/problem/7575
*/
/*-----------------
Ǯ��
1. ù��°�� �ι�° ���α׷����� ���̷��� �ĺ��� ��� ����
2. ������ ���α׷����� �Ǵ��� Ȯ���Ѵ�. ��, n=2�� ��� ���̷��� �ĺ��� �ִٸ� �ٷ� yes
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#define vecs std::vector<std::vector<int>>
#define pi std::pair<int,int>
#define p first
#define id second
int n, k;
vecs virus, prog;

bool check(const int& i, const int& j,const int& idx,int step) {
	if ((step == 1 && prog[j].size() - idx < k) || // make �Լ� �ʹݺζ� ������
		(step == -1 && idx < k - 1))
		return false;
	
	for (int z = 0; abs(z) < k; z += step)
		if (virus[i][abs(z)] != prog[j][idx + z])
			return false;
	return true;
}

bool check_virus() {
	for (int i = 0; i < virus.size(); i++) // ������� ���̷��� �ĺ��� �� Ȯ��
	{
		bool i_check = true;
		for (int j = 2; j < n; j++) { // 0,1 idx�� ���̷��� Ȯ�������� ����
			bool j_check = false;
			for (int idx = 0; idx < prog[j].size(); idx++)
				if (virus[i][0] == prog[j][idx])
					if (check(i, j, idx, 1) || check(i, j, idx, -1)) {
						j_check = true; // ���̷����� �Ǵ� ���
						continue;
					}
			if (!j_check) // ���̷��� ���� �ѹ��� ������ ���
			{
				i_check = false; 
				break;
			}
		}
		if (i_check) // ��� ���α׷��� ���̷��� �ĺ��� �����ϹǷ� ����
			return true;
	} 
	return false; // ��� ���α׷����� ����� ���̷��� �ĺ��� ����
}

bool make(const pi& p1, const pi& p2,const int& step) //  step 1�� ���� p2 ������, -1�� ���� ������, p1�� �׻� ������
{
	bool flag = true;
	if ((step == 1 && prog[p2.p].size() - p2.id < k) || //p2�� Ȯ���ؾ� �ϴµ� ���� �ε����� k ������� ���
		(step == -1 && p2.id < k - 1))
		return false;

	for (int i = 0; abs(i) < k; i+=step)
	{
		if (prog[p1.p][p1.id+abs(i)]!=prog[p2.p][p2.id+i])
		{
			flag = false; // Ʋ��
			break;
		}
	}
	if (flag) { // ���� �� �ִ� ���
		std::vector<int> ret(k, 0);
		for (int i = 0; abs(i) < k; i+=step)
			ret[abs(i)] = prog[p2.p][p2.id + i];
		virus.push_back(ret); // ���̷��� �ĺ� ����
	}
	return flag;
}

void make_virus() {
	for (int i = 0; i <= prog[0].size() - k; i++)
		for (int j = 0; j < prog[1].size(); j++)
			if (prog[0][i] == prog[1][j]) // ������ ���� ã�� ���� Ȯ��
				if (!make({ 0,i }, { 1, j }, 1) && !make({ 0,i }, { 1,j }, -1)) // ������, ������ Ȯ��
					continue;
				else 
					break;
				
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> k;
	prog.resize(n);
	
	for (int i = 0; i < n; i++) {
		int m; std::cin >> m;
		for (int j = 0; j < m; j++) {
			int num; std::cin >> num;
			prog[i].push_back(num);
		}
	}
	
	make_virus(); // 1.
	
	if (virus.size() && (n == 2 || check_virus())) // 2.
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}


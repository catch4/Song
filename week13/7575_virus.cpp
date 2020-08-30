/*
Catch study 13주차
백준_7575 바이러스
https://www.acmicpc.net/problem/7575
*/
/*-----------------
풀이
1. 첫번째와 두번째 프로그램에서 바이러스 후보를 모두 생성
2. 나머지 프로그램에서 되는지 확인한다. 단, n=2인 경우 바이러스 후보가 있다면 바로 yes
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
	if ((step == 1 && prog[j].size() - idx < k) || // make 함수 초반부랑 동일함
		(step == -1 && idx < k - 1))
		return false;
	
	for (int z = 0; abs(z) < k; z += step)
		if (virus[i][abs(z)] != prog[j][idx + z])
			return false;
	return true;
}

bool check_virus() {
	for (int i = 0; i < virus.size(); i++) // 만들어진 바이러스 후보군 다 확인
	{
		bool i_check = true;
		for (int j = 2; j < n; j++) { // 0,1 idx는 바이러스 확인했으니 안함
			bool j_check = false;
			for (int idx = 0; idx < prog[j].size(); idx++)
				if (virus[i][0] == prog[j][idx])
					if (check(i, j, idx, 1) || check(i, j, idx, -1)) {
						j_check = true; // 바이러스가 되는 경우
						continue;
					}
			if (!j_check) // 바이러스 판정 한번도 못받은 경우
			{
				i_check = false; 
				break;
			}
		}
		if (i_check) // 모든 프로그램이 바이러스 후보가 적합하므로 정답
			return true;
	} 
	return false; // 모든 프로그램에서 공통된 바이러스 후보가 없음
}

bool make(const pi& p1, const pi& p2,const int& step) //  step 1일 때는 p2 정방향, -1일 때는 역방향, p1은 항상 정방향
{
	bool flag = true;
	if ((step == 1 && prog[p2.p].size() - p2.id < k) || //p2를 확인해야 하는데 남은 인덱스로 k 못만드는 경우
		(step == -1 && p2.id < k - 1))
		return false;

	for (int i = 0; abs(i) < k; i+=step)
	{
		if (prog[p1.p][p1.id+abs(i)]!=prog[p2.p][p2.id+i])
		{
			flag = false; // 틀림
			break;
		}
	}
	if (flag) { // 만들 수 있는 경우
		std::vector<int> ret(k, 0);
		for (int i = 0; abs(i) < k; i+=step)
			ret[abs(i)] = prog[p2.p][p2.id + i];
		virus.push_back(ret); // 바이러스 후보 생성
	}
	return flag;
}

void make_virus() {
	for (int i = 0; i <= prog[0].size() - k; i++)
		for (int j = 0; j < prog[1].size(); j++)
			if (prog[0][i] == prog[1][j]) // 동일한 숫자 찾을 때만 확인
				if (!make({ 0,i }, { 1, j }, 1) && !make({ 0,i }, { 1,j }, -1)) // 역방향, 정방향 확인
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


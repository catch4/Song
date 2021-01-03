/*
Catch study 6주차
백준_10159 저울
https://www.acmicpc.net/problem/10159
*/
/*
틀렸던 이유 - 상위의 상위 또는 하위의 하위를 최신화 안함.

TODO:
1. 입력 밑에 for문을 만들었는데 이 부분 Push 함수로 넣는게
   더 깔끔할 거 같다.
2. 다풀고 나서 알고리즘 분류 보니까 플로이드 와샬이다.
플로이드 와샬 공부하고 다시 풀어봐야 겠다.


------풀이---------------
시간초과 날줄 알았는데 안나서 놀람.

1. 찾는 시간 줄일려고 ck 배열도 같이 선언했다.
1-2. num은 알 수 없는 관계의 숫자
     자기 자신은 포함하지 않으므로 n-1

2. 입력 받을 때 low high로 오는 경우
   high 값 보다 큰 값들은 반드시 low보다 크다.
   low 값 보다 작은 값들은 반드시 high보다 작다.

3. 작은 값, 혹은 큰 값을 vector에 push_back 할 때
   알수없는 관계 -1
*/

#include <iostream>
#include <vector>
int n, m;

struct Goods {
	int num = 0;
	std::vector<bool> h; // 1.
	std::vector<bool> l; // 1.
	std::vector<int> l_idx;
	std::vector<int> h_idx;
	Goods() {}
	Goods(const int& t_num) {
		num = t_num - 1;
		h.resize(t_num, 0);
		l.resize(t_num, 0);
	}
};

void Push(std::vector<Goods>& items, const int& high, const int& low)
{
	if (!items[high].l[low])
	{
		items[high].l[low] = 1;
		items[high].l_idx.push_back(low);
		items[high].num -= 1;
	}
	if (!items[low].h[high])
	{
		items[low].h[high] = 1;
		items[low].h_idx.push_back(high);
		items[low].num -= 1;
	}
}
void heavy(std::vector<Goods>& items,
	const int& idx,const int& num) {
	std::vector<int>& h_vec = items[idx].h_idx;
	for (int i = 0; i < h_vec.size(); i++)
	{
		if (items[h_vec[i]].l[num]) continue;
		heavy(items, h_vec[i], num);
	}
	Push(items, idx, num);
}
void light(std::vector<Goods>& items,
	const int& idx,const int& num) {
	std::vector<int>& l_vec = items[idx].l_idx;
	for (int i = 0; i < l_vec.size(); i++)
	{
		if (items[l_vec[i]].h[num]) continue;
		light(items, l_vec[i],num);
	}
	Push(items, num, idx);
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	int l, h;
	std::vector<Goods> items(n,Goods(n));
	for (int i = 0; i < m; i++) {
		std::cin >> l >> h;
		if (l == h || items[l - 1].l[h - 1] || items[h - 1].h[l - 1]) continue;
		for (int j = 0; j < items[h - 1].h_idx.size(); j++)
			light(items, l - 1, items[h - 1].h_idx[j]);
		light(items, l - 1, h - 1);
		for (int j = 0; j < items[l - 1].l_idx.size(); j++)
			heavy(items, h - 1, items[l - 1].l_idx[j]);
		heavy(items, h - 1, l - 1);
	}
	for (int i = 0; i < n; i++) {
		std::cout << items[i].num << '\n';
	}
	return 0;
}

/*--------------------------------
풀이
플로이드와샬

코드는 이해를 했는데 123~126 라인에서
j는 항상 가운데에 있어야 하는 이유를 모르겠다.
--------------------------------*/
#include <iostream>
#include <vector>

int main() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<bool>> heavy(n, std::vector<bool>(n, 0));
	for (int i = 0; i < m; i++)
	{
		int a, b; std::cin >> a >> b;
		heavy[a - 1][b - 1] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (heavy[j][i] && heavy[i][k]) heavy[j][k] = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (!heavy[i][j] && !heavy[j][i]) cnt++;
		std::cout << cnt - 1 << '\n';
	}
	return 0;
}
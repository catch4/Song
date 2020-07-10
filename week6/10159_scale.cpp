/*
Catch study 6����
����_10159 ����
https://www.acmicpc.net/problem/10159
*/
/*
Ʋ�ȴ� ���� - ������ ���� �Ǵ� ������ ������ �ֽ�ȭ ����.

TODO:
1. �Է� �ؿ� for���� ������µ� �� �κ� Push �Լ��� �ִ°�
   �� ����� �� ����.
2. ��Ǯ�� ���� �˰��� �з� ���ϱ� �÷��̵� �ͼ��̴�.
�÷��̵� �ͼ� �����ϰ� �ٽ� Ǯ����� �ڴ�.


------Ǯ��---------------
�ð��ʰ� ���� �˾Ҵµ� �ȳ��� ���.

1. ã�� �ð� ���Ϸ��� ck �迭�� ���� �����ߴ�.
1-2. num�� �� �� ���� ������ ����
     �ڱ� �ڽ��� �������� �����Ƿ� n-1

2. �Է� ���� �� low high�� ���� ���
   high �� ���� ū ������ �ݵ�� low���� ũ��.
   low �� ���� ���� ������ �ݵ�� high���� �۴�.

3. ���� ��, Ȥ�� ū ���� vector�� push_back �� ��
   �˼����� ���� -1
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
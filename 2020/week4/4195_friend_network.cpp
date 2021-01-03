/*
Catch study 4����
����_4195 ģ�� ��Ʈ��ũ
https://www.acmicpc.net/problem/4195
*/
/*
�����ֿ� �ؽ��� ã�Ҵ��� ��������
unordered map���� ���� ���� �̸����� ã��
�׳� �ֻ��� �ϳ� ã�´ٴ� �������� ������

�ѹ� �ð��ʰ� �����µ� ��ũ false �ϴϱ� �ٷ� �����

1. �ؽ����� ���� ���� ���� �̸��� 0���� �ϱ� ����
   ����ִ� ����ü�� ����.

2. �ؽ����� out�� 0�� ���� index �� �ο�.

3. �θ� ã���鼭 num, parent �ֽ�ȭ

4. �θ� ������ ��� �ٷ� return

5. �θ� �ٸ� ��� �� �θ��� number ��ġ��
   �θ���� ����
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define map std::unordered_map<std::string, int>

struct People {
	std::string name,parent;
	int num = 1;
	People() {
		name = "", parent = "";
	}
	People(const std::string& str)
	{
		name = parent = str;
	}
};

// 3.
People search(map& mp, std::vector<People>& vec, std::string& str) 
{
	People& now = vec[mp[str]];
	if (now.name == now.parent)
		return now;
	else
	{
		People p = search(mp, vec, now.parent);
		now.parent = p.parent;
		now.num = p.num;
		return now;
	}
}

int check(map& mp, std::vector<People>& vec, std::string& a, std::string& b)
{
	int cur_a = mp[a], cur_b = mp[b];
	// 2.
	if (!cur_a) { 
		mp[a] = cur_a = vec.size();
		vec.push_back(People(a));
	}
	if (!cur_b) 
	{
		mp[b] = cur_b= vec.size();
		vec.push_back(People(b));
	}
	People per_a = search(mp,vec,vec[cur_a].parent); // 3.
	People per_b = search(mp, vec, vec[cur_b].parent);
	if (per_a.parent == per_b.parent) return per_a.num; // 4.

	// 5.
	int idx_a = mp[per_a.parent],idx_b = mp[per_b.parent];
	vec[idx_a].num += vec[idx_b].num;
	vec[idx_b].num = vec[idx_a].num;
	vec[idx_b].parent = vec[idx_a].name;
	return vec[idx_a].num;
}
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while (t--)
	{
		map mp;
		int n; std::cin >> n;
		std::vector<People> vec; 
		vec.push_back(People()); // 1.
		for (int i = 0; i < n; i++)
		{
			std::string a, b;
			std::cin >> a >> b;
			std::cout << check(mp,vec,a,b)<< '\n';
		}
	}
	return 0;
}
/*
Catch study 4주차
백준_4195 친구 네트워크
https://www.acmicpc.net/problem/4195
*/
/*
저번주에 해쉬로 찾았던거 생각나서
unordered map으로 현재 받은 이름인지 찾음
그냥 최상위 하나 찾는다는 생각으로 구현함

한번 시간초과 났었는데 싱크 false 하니까 바로 통과됨

1. 해쉬에서 아직 받지 않은 이름은 0으로 하기 위해
   비어있는 구조체를 넣음.

2. 해쉬에서 out이 0인 값에 index 값 부여.

3. 부모 찾으면서 num, parent 최신화

4. 부모가 동일한 경우 바로 return

5. 부모가 다른 경우 두 부모의 number 합치고
   부모관계 설정
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
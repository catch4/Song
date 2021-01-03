/*
Catch study 10����
���α׷��ӽ�_����Ʈ�ٹ�
https://programmers.co.kr/learn/courses/30/lessons/42579?language=cpp
*/
/*-----------------
Ǯ��
��������������������������������������������������������������������

1. hash�� string�� ���� index�߰�
2. sums���� �� �帣�� �� �÷��� Ÿ�Ӱ� idx ����
3. musics�� �� ���� �帣�� idx, ���� playŸ�Ӱ� ���� idx
4. sums�� musics �����ϰ� 2�����Ϸ� ��´�.
-----------------*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define pi std::pair<int,int>
using namespace std;
struct Album {
	int play=0, idx=0;
	Album() {}
	Album(const int& t_p,const int& t_id)
	{
		play = t_p, idx = t_id;
	}
	bool operator<(const Album& bb)const {
		if (play == bb.play)
			return idx < bb.idx;
		else {
			return play > bb.play;
		}
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	std::unordered_map<string, int> mp;
	std::vector<Album> sums;
	std::vector<std::vector<Album>> musics;
	int cur = 0;
	for (int i = 0; i < genres.size(); i++) {
		if (mp.find(genres[i]) != mp.end()) {
			sums[mp[genres[i]]].play += plays[i];
			musics[mp[genres[i]]].push_back(Album( plays[i],i ));
		}
		else {
			mp[genres[i]] = cur; // 1.
			cur++;
			sums.push_back({ plays[i],cur-1}); // 2.
			std::vector<Album> m;
			m.push_back(Album(plays[i], i)); 
			musics.push_back(m); // 3.
		}
	}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < sums.size(); i++) {
		int idx = sums[i].idx;
		sort(musics[idx].begin(), musics[idx].end());
		answer.push_back(musics[idx][0].idx); // 4.
		if(musics[idx].size()>1)
			answer.push_back(musics[idx][1].idx); // 4.
	}
	return answer;
}


int main() {
	vector<string> geners;
	vector<int> plays;
	
	geners.push_back("classic");
	geners.push_back("pop");
	geners.push_back("classic");
	geners.push_back("classic");
	geners.push_back("pop");

	plays.push_back(500);
	plays.push_back(600);
	plays.push_back(150);
	plays.push_back(800);
	plays.push_back(2500);

	vector<int> answer = solution(geners, plays);
	for (int i = 0; i < answer.size(); i++)
		std::cout << answer[i] << " ";
}
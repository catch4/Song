/*
Catch study 10주차
프로그래머스_베스트앨범
https://programmers.co.kr/learn/courses/30/lessons/42579?language=cpp
*/
/*-----------------
풀이
정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬정렬

1. hash에 string에 대한 index추가
2. sums에는 각 장르당 총 플레이 타임과 idx 저장
3. musics의 각 행은 장르의 idx, 열은 play타임과 고유 idx
4. sums랑 musics 정렬하고 2개이하로 담는다.
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
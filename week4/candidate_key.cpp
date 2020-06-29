/*
Catch study 4주차
프로그래머스_후보키
https://programmers.co.kr/learn/courses/30/lessons/42890
*/

/*
못품 ㅜㅜ,제일 잘쓴 코드 공부함
이 코드 보기전에는 최대 길이 후보키 구하는 줄 알았다.
문제좀 제대로 읽어야겠다. test case는 맨 아래에 주석으로 표시했다.

아래의 1과 3이 핵심인 것 같다.

1. index의 선택유무를 이진화 한 후 bool값으로 판별
ex) 5의 경우 101 -> 1번 index와 3번 index 선택
2. set을 매번 확인하지 않고 size를 확인한다.(중복되면 n미만의 크기가 나옴)
3. 부분집합이 후보키였는지 확인한다. 이부분도 이진화를 사용한다.
ex) 7의 경우 1101 -> 1,3,4 번 index 선택, 만약 5(101)이 후보키였다면
	7&5 = 5로 true라서 false를 return
4. 원래 코드는 now+=relation[j][k];인데 누군가가 예외 case 올려서 수정했다.
5. 마지막으로 후보키로 선정된 양을 return 한다.
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
예외.
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
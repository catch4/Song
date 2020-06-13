/*
Catch study 2주차
프로그래머스_파일명 정렬
https://programmers.co.kr/learn/courses/30/lessons/17686
*/

/*
풀이

최대 vector<string>의 사이즈가 1000이기 때문에
head/number로 나눈 이후 sorting해도 많이 안걸릴거라고 생각함.


조건
- TAIL은 영향을 주지 않는다. 우선순위는  HEAD->NUMBER->들어온 순서

0. TAIL은 영향을 주지 않기 때문에 number까지 받으면 더 이상 나누지 않는다.
1. 들어온 string array에서 각각 head,number,index,원래 파일명을 나눈다(return asnwer용).
	1_1. head에는 숫자가 포함되지 않으며 대문자 혹은 소문자로 맞춰야 한다.
	1_2. number는 숫자로 이루어 지며 01과 1은 동일하다. 따라서 숫자범위를 만나기 전까지 num=num*10+now_num을 하면 된다.
	1_3. 초기화 시 할당.
2. 문자열은 string 배열에서 사전순으로 대소 구분하기 때문에 조건을 따르도록 operator를 overloading 한다. 
3. asnwer에 sorting된 순서대로 할당하고 retrun 한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File_DB {
	std::string head = "";
	std::string file_name = "";
	int num = 0;
	int idx = 0;

	// 1. 
	void segment() {
		int cur = 0;
		for (int i = 0; i < file_name.size(); i++)
		{
			if ((file_name[i] >= '0'&&file_name[i] <= '9')||file_name[i]=='.')
			{
				cur = i;
				break;
			}
			// 1-1.
			else if (file_name[i] >= 'A'&&file_name[i] <= 'Z')
				head += (file_name[i] + ('a' - 'A'));
			else
				head += file_name[i];
			// 1-1.
		}
		// 1-2.
		for (int i = cur; i < file_name.size(); i++) {
			if (file_name[i] >= '0'&&file_name[i] <= '9')
				num = num * 10 + (file_name[i] - '0');
			else // 0
				break;
			// 0.
		}
		// 1-2.
	}
	// 1.

	// 1-3.
	File_DB(std::string name,const int& t_idx) {
		file_name = name;
		idx = t_idx;
		segment();
	}
	// 1-3.

	// 2.
	bool operator < (const File_DB& bb)const{
		if (head == bb.head&&num == bb.num)
			return idx < bb.idx;
		else if (head == bb.head)
			return num < bb.num;
		else
			return head < bb.head;
	}
	// 2.
};

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<File_DB> db;
	int len = files.size();
	for (int i = 0; i < len; i++)
		db.push_back(File_DB(files[i], i));
	// 2.
	sort(db.begin(), db.end());

	// 3.
	for (int i = 0; i < len; i++)
		answer.push_back(db[i].file_name);
	return answer;
}

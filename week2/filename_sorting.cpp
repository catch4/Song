/*
Catch study 2����
���α׷��ӽ�_���ϸ� ����
https://programmers.co.kr/learn/courses/30/lessons/17686
*/

/*
Ǯ��

�ִ� vector<string>�� ����� 1000�̱� ������
head/number�� ���� ���� sorting�ص� ���� �Ȱɸ��Ŷ�� ������.


����
- TAIL�� ������ ���� �ʴ´�. �켱������  HEAD->NUMBER->���� ����

0. TAIL�� ������ ���� �ʱ� ������ number���� ������ �� �̻� ������ �ʴ´�.
1. ���� string array���� ���� head,number,index,���� ���ϸ��� ������(return asnwer��).
	1_1. head���� ���ڰ� ���Ե��� ������ �빮�� Ȥ�� �ҹ��ڷ� ����� �Ѵ�.
	1_2. number�� ���ڷ� �̷�� ���� 01�� 1�� �����ϴ�. ���� ���ڹ����� ������ ������ num=num*10+now_num�� �ϸ� �ȴ�.
	1_3. �ʱ�ȭ �� �Ҵ�.
2. ���ڿ��� string �迭���� ���������� ��� �����ϱ� ������ ������ �������� operator�� overloading �Ѵ�. 
3. asnwer�� sorting�� ������� �Ҵ��ϰ� retrun �Ѵ�.
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

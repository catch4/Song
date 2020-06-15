/*
Catch study 3����
���α׷��ӽ�_N���� ����
https://programmers.co.kr/learn/courses/30/lessons/17687
*/

#include <string>
#include <vector>
#include <stack>
using namespace std;

// n������ ǥ������ ���� ���ڿ� ��ȯ
string make_num(int num, int n) { 

	if (num == 0) return "0";
	string a = "";
	stack<char> str;
	int tmp_num = num;
	while (tmp_num > 0) {
		int mod = tmp_num % n;
		if (mod >= 0 && mod <= 9)
			str.push(mod + '0');
		else if (mod >= 10)
			str.push((mod % 10) + 'A');
		tmp_num /= n;
	}
	while (!str.empty()) {
		a += str.top();
		str.pop();
	}
	return a;
}


string solution(int n, int t, int m, int p) {
	string answer = "";
	string str = "";
	int cnt = 0;
	// t*m�̻� ���̰� �� ������ ���ڿ� ����
	while (str.size() < t*m) {
		str += make_num(cnt, n);
		cnt++;
	}
	cnt = 0;
	for (int i = p - 1; cnt < t; i += m)
	{
		answer += str[i];
		cnt++;
	}

	return answer;
}


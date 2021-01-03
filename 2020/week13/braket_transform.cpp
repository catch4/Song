#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int countbra(std::string& sub) {
	int o = 0, c = 0;
	for (int i = 0; i < sub.size(); i++)
	{
		if (o&&c&&o == c)
			return i;
		if (sub[i] == '(')
			o++;
		else
			c++;
	}
}

int check(std::string& sub) {
	std::stack<char> stk;
	for (int i = 0; i < sub.size(); i++) {
		if (sub[i] == '(')
			stk.push(sub[i]);
		else {
			if (!stk.size())
				return countbra(sub);
			else stk.pop();
		}
	}
	return -1; // �ùٸ� ��ȣ¦ �ɽ� -1
}

std::string corstr(std::string& str) {
	int ret = check(str);
	if (ret == -1)
		return str; // �ùٸ��Ƿ� �ٷ� return
	else {
		std::string u, v;
		if (ret % 2)
			ret += 1;  // �̰� ���� �ɵ�

		u = str.substr(0, ret);
		v = str.substr(ret, str.size() - ret);

		if (check(u) == -1) {
			if (v.size())
				return u + corstr(v);
			else
				return u;
		}
		else {
			if (2 < u.size()) {
				u = u.substr(1, u.size() - 2);
				// ���ڿ� ��ü�� �����°� �ƴ� ��ȣ ��ȯ
				for (int z = 0; z<u.size(); z++)
					if (u[z] == '(')
						u[z] = ')';
					else
						u[z] = '(';
			}
			else
				u = "";

			if (v.size())
				return "(" + corstr(v) + ")" + u;
			else
				return "()" + u;
		}
	}
}
string solution(string p) {
	return corstr(p);
}
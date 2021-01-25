/*
Catch study 21/jan/4week
����_20120 ȣ�ݿ�� �������
https://www.acmicpc.net/problem/20120

for���� ���� �Ʒ� 3���� ����
�޺� 0�� ��� �ִ밪 -> �� ��° ���� ù ��° �� ��Ȳ���� �޺��� 1 �̻� �� ���� ū ���� ��
�޺� 1�� ��� �ִ밪 -> �� ��° ���� �� ��° �� ��Ȳ���� �޺��� 1 �̻� �� ���� ū ���� �� + ���� ��
�޺� 2 �̻��� ��� �ִ밪 -> ���� ���� �޺��� 1�̻��� �� + ���� �� * �޺�
*/
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n; std::cin >> n;
	long long n2_max = 0,n1_max=0, answer = 0;
	std::vector<long long> vec(n);
	std::cin >> vec[0];
	
	for (int i = 1; i < n; i++) {
		int num; std::cin >> num;
		long long now_max = -10000001;
		for (int j = i-1; j>=0 ; j--) {
			now_max = std::max(vec[j], now_max); 
			vec[j + 1] = vec[j] + (j + 2)*num;
		}
		vec[0] = std::max(n2_max, n1_max)+num; // ���� �޺� 1 �� ��� �ִ� ��, ���� n2_max�� ����° �� �޺��� 1 �̻� �� ���� ū ������
		n2_max = n1_max; // n-2�� ���� �Ǿ��� �� �ִ밪
		n1_max = now_max; // n-1�� ���� �Ǿ��� �� �ִ밪
	}
	answer = std::max(answer, std::max(n2_max, n1_max)); // ���� �޺� 0 �� ��� �ִ� ��
	for (int i = 0; i < n; i++) // �޺� 1 �̻� �� ���� �ִ밪
		answer = std::max(vec[i], answer); 
	std::cout << answer;
}
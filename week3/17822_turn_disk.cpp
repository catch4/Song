/*
Catch study 3����
����_17822 ���� ������
https://www.acmicpc.net/problem/17822
*/
/*
ȸ���� Ƚ���� �� ���Ǹ��� ����ϰ�
���ÿ��� ȸ���� idx ��ȯ
���� ��ó���� ����ϰ� ���� ���� �ɶ�
�׸�ŭ ���� �������� ����

0. ��ó�� �Է� ���� ������ ��
1. �� ���� �� ȸ�� Ƚ�� ����
2-0. ���� disk ����
2-1. ȸ�� ���� index return
2-2. �������� ������ ��� ����
2-3. 2-2�� �ѹ��� ���Ͼ ��� ó��
*/
#include <iostream>
#include <vector>

#define vecs std::vector<std::vector<int>>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m,t,sum=0,del_cnt=0;

int rotated_num(std::vector<int>& rot, // 2-1.
	const int& y, const int& x)
{
	int n_x = rot[y] + x;
	if (n_x < 0)
		n_x = (m - (abs(n_x) % m))%m;
	else if (n_x >= m)
		n_x = (abs(n_x) % m);
	return n_x;
}

void rotation(std::vector<int>& rot)
{
	int xi, di, ki;	std::cin >> xi >> di >> ki;
	for (int i = xi; i <= n; i += xi)
		if (di) rot[i-1] += ki;
		else rot[i - 1] -= ki;
}

bool zero_event(vecs& disk) // 2-3.
{
	if (n*m == del_cnt) return false;
	double pivot = sum / ((double)n*m - del_cnt);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (disk[i][j]) {
				if (disk[i][j] > pivot) {
					disk[i][j]-=1;
					sum-=1;
				}
				else if (disk[i][j] < pivot) {
					disk[i][j]+=1;
					sum+=1;
				}
			}
	return true;
}

bool del(vecs& disk, std::vector<int>& rot)
{
	vecs tmp = disk; // 2-0.
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int rx = rotated_num(rot, i, j); // 2-1.
			if (!tmp[i][rx]) continue;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				if (ny < 0 || ny >= n) continue;
				int nx = j + dx[k];
				if (nx < 0) nx = m - 1;
				else if (nx == m) nx = 0;
				nx = rotated_num(rot, ny, nx); // 2-1.
				if (tmp[ny][nx] == tmp[i][rx]) { // 2-2.
					if (disk[ny][nx])
					{
						sum = sum- disk[ny][nx];
						disk[ny][nx] = 0;
						del_cnt+=1;
					}
					if (disk[i][rx])
					{
						sum = sum- disk[i][rx];
						disk[i][rx] = 0;
						del_cnt+=1;
					}
					flag = true;
				}
			}
		}
	}
	if (!flag) // 2-3.
		return zero_event(disk);
	return true;
}

void sum_disk(vecs& disk) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += disk[i][j];
}

int main() {
	std::cin >> n >> m>>t;
	vecs disk(n, std::vector<int> (m,0));
	std::vector<int> rot(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> disk[i][j];
	sum_disk(disk); // 0.
	while (t--) {
		rotation(rot);
		if(!del(disk,rot)) break;
	}
	std::cout << sum;
	return 0;
}


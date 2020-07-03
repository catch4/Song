/*
Catch study 5����
����_16398 �༺ ����
https://www.acmicpc.net/problem/16398
*/
/*
ó������ ���ͽ�Ʈ��� Ǯ���ֳ� ����ϴٰ�
���� �ȶ��ö� MST(minimum spanning tree) ������
return �� long long���� ���ؼ� 10�� ���

Ǯ��

1) Kruskal
- ����� ���� ������ ������ �ϰ� union, find�� �����
  ���� ���� Ʈ���� �����.

  1. input�� ���� �� �ߺ��Ǵ� ������ ���� �ʾƵ� �ȴ�.
  2. �θ��带 ã��(Find) �θ��尡 ���� ���� ��� Union
  3. 2�� �ش��� ��� ����� ���Ѵ�.

2) Prim
- �� vertex�� ��߷� �����ϰ� �ٸ� ������ ����� �ּ�ȭ �Ѵ�.
  �켱���� ť�� ����Ѵ�.

  1. 0��° idx���� ���, ������ 0��° ���� ��� ���Ѵ�� ����
  2. ���� idx���� �������� ���� �����
     ���� ������ ���� ���� ��� ť�� ����
  3. ���� ������ �ּҰ��̹Ƿ� ����� ����
  4. �湮�� ���� �̹� �ּҰ��̹Ƿ� �н�
  5. 4�� ������ �湮 Ƚ���� n�� �� ��� �ּҰ�
*/

//---------------------------------------Kruskal--------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
int n;
struct Node {
	int start, end,cost;
	Node(const int& i, const int& j,const int& n_cost)
	{
		start = i; end = j; cost = n_cost;
	}
	bool operator<(const Node& bb) {
		return cost < bb.cost;
	}
};

int Find(std::vector<int>& parent, const int& node)
{
	if (node == parent[node]) return node;
	else return parent[node] = Find(parent, parent[node]);
}

void Union(std::vector<int>& parent, const int& n1, const int& n2)
{
	if(n1<n2) parent[n2] = n1;
	else parent[n1] = n2;
}

long long kruskal()
{	
	int cost;
	std::vector<Node> nodes;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> cost;
			if (i < j) nodes.push_back(Node(i, j, cost)); // 1.
		}

	sort(nodes.begin(), nodes.end());
	std::vector<int> parent(n, 0);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	long long sum = 0;
	for (int i = 0; i <nodes.size(); i++)
	{
		int p1 = Find(parent,nodes[i].start), p2 = Find(parent,nodes[i].end); 
		if (p1 != p2) // 2.
		{
			Union(parent, p1, p2);
			sum += nodes[i].cost; // 3.
		}
	}
	return sum;
}
//----------------------------------------------------------------------------

//-----------------------------------Prim-------------------------------------
#include <queue>
#define vecs std::vector<std::vector<int>>
#define INF 2147000000
#define pli std::pair<long long,int>
long long prim() {
	int cnt = 0;
	long long sum = 0;
	vecs nodes(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> nodes[i][j];
	std::vector<long long> dist(n, INF); // 1.
	std::vector<bool> ck(n);
	dist[0] = 0; // 1.
	std::priority_queue<pli> Q;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		pli now= Q.top();
		Q.pop();
		if (ck[now.second]) continue; // 4.
		ck[now.second] = 1;
		sum += dist[now.second]; // 3.
		if (++cnt == n) break; // 5.
		for (int i = 0; i < n; i++)
			if (dist[i] > nodes[now.second][i]) { // 2.
				dist[i] = nodes[now.second][i];
				Q.push({ -nodes[now.second][i], i });
			}
	}
	return sum;
}
//-----------------------------------------------------------------------------
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	//std::cout << kruskal() << std::endl;
	std::cout << prim() << std::endl;
}
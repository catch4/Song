/*
Catch study 5주차
백준_16398 행성 연결
https://www.acmicpc.net/problem/16398
*/
/*
처음에는 다익스트라로 풀수있나 고민하다가
뭔가 안떠올라서 MST(minimum spanning tree) 공부함
return 값 long long으로 안해서 10분 헤맴

풀이

1) Kruskal
- 비용이 낮은 순으로 정렬을 하고 union, find를 사용해
  전부 동일 트리로 만든다.

  1. input을 받을 때 중복되는 영역은 받지 않아도 된다.
  2. 부모노드를 찾고(Find) 부모노드가 같지 않을 경우 Union
  3. 2에 해당할 경우 비용을 더한다.

2) Prim
- 한 vertex를 출발로 지정하고 다른 극점의 비용을 최소화 한다.
  우선순위 큐를 사용한다.

  1. 0번째 idx에서 출발, 극점은 0번째 빼고 모두 무한대로 설정
  2. 현재 idx에서 극점까지 가는 비용이
     현재 극점값 보다 작을 경우 큐에 삽입
  3. 현재 극점이 최소값이므로 결과에 덧셈
  4. 방문한 곳은 이미 최소값이므로 패스
  5. 4의 이유로 방문 횟수가 n일 때 모두 최소값
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
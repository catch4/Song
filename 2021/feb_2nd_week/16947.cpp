#include <iostream>
#include <vector>
#include <queue>
#define vec2d std::vector<std::vector<int>>
#define pi std::pair<int,int>
int n;

bool make_cycle(vec2d& graph, std::vector<bool>& ck,const int& start, const int& now,int cnt) {
	if (start == now && cnt > 1) return true;
	ck[now] = 1;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!ck[next])
		{
			if(make_cycle(graph, ck, start, next, cnt + 1)) return true;
		}
		else if (next == start && cnt > 1) return true;
	}
	return false;
}

struct Info {
	int node, cnt = 0;
	Info() {}
	Info(const int& nn, const int& cc) { node = nn; cnt = cc; }
	bool operator < (const Info& bb)const { return cnt > bb.cnt; }
};

void bfs(vec2d& graph,std::vector<bool>& is_cycle,std::vector<int>& dist) {
	std::priority_queue<Info> Q;
	for(int i=0;i<n;i++)
		if (is_cycle[i]) {
			Q.push(Info(i, 0));
			dist[i] = 0;
		}
	while (!Q.empty()) {
		Info now = Q.top();
		Q.pop();
		for (int i = 0; i < graph[now.node].size(); i++) {
			int next = graph[now.node][i];
			if (dist[next] <= now.cnt+1) continue;
			dist[next] = now.cnt + 1;
			Q.push({ next,now.cnt + 1 });
		}
	}
	
}

int main() {
	std::cin >> n;
	vec2d graph(n);
	std::vector<bool> is_cycle(n, 0);
	std::vector<int> dist(n, 2147000000);
	for (int i = 0; i < n; i++)
	{
		int s, e; std::cin >> s >> e;
		graph[s - 1].push_back(e - 1);
		graph[e - 1].push_back(s - 1);
	}
	for (int i = 0; i < n; i++) {
		std::vector<bool> ck(n);
		is_cycle[i] = make_cycle(graph, ck, i, i, 0);
	}
	bfs(graph, is_cycle, dist);
	for (int i = 0; i < n; i++) std::cout << dist[i] << " ";
	return 0;
}

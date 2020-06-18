///*
//Catch study 3주차
//백준_4485 녹색 옷 입은 애가 젤다지?
//https://www.acmicpc.net/problem/4485
//*/
///*
//처음에는 큐로 했을 때 통과하기는 했는데 172ms나옴.
//그래서 우선순위 큐로 바꿈. 8ms로 바뀜.
//
//다익스트라.
//0. INF 설정 최악이 (125+124)*9 = 2241인데 넉넉하게 10^5로 설정함
//1. y,x,cost를 저장할 수 있는 구조체 선언 및 operator 오버로딩
//2. 현재값이랑 저장되어 있는 값 비교 후 교체시 queue에 할당.
//3. 현재값이 이미 저장되어 있는 값보다 작을 경우 다음 queue
//*/
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#define vecs std::vector<std::vector<int>>
//#define INF 100000 // 0.
//struct cost { // 1.
//	int y, x, c;
//	cost(const int& ty,const int& tx, const int& tc)
//	{
//		y = ty; x = tx; c = tc;
//	}
//	bool operator<(const cost& bb)const { return c > bb.c; }
//};
//int n, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
//
//int dijkstra(vecs& cave){
//	vecs min_cost(n, std::vector<int>(n, INF));
//	std::priority_queue<cost> Q;
//	Q.push(cost(0, 0, cave[0][0]));
//	min_cost[0][0] = cave[0][0];
//	while (!Q.empty())
//	{
//		cost now = Q.top();
//		Q.pop();
//		if (now.c > min_cost[now.y][now.x]) continue; // 3. 
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.x + dx[i];
//			int ny = now.y + dy[i];
//			if (nx >= 0 && nx < n&&ny<n&&ny >= 0 &&
//				min_cost[ny][nx]>cave[ny][nx] + now.c)
//			{
//				Q.push(cost(ny, nx, cave[ny][nx] + now.c)); // 2.
//				min_cost[ny][nx] = cave[ny][nx] + now.c;
//			}
//		}
//	}
//	return min_cost[n - 1][n - 1];
//}
//
//int main() {
//	int t = 1;
//	while (1)
//	{
//		std::cin >> n;	if (!n) break;
//		vecs cave(n, std::vector<int>(n, 0));
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				std::cin >> cave[i][j];
//		std::cout << "Problem "<<t<<": "<<dijkstra(cave)<<'\n';
//		t++;
//	}
//	return 0;
//}
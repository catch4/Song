#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main() {
	int src, dst; std::cin >> src >> dst;
	
	if (src > dst) {
		std::cout << src-dst << '\n';
		return 0;
	}
	else {
		std::vector<int> vec((dst+1)*2,2147000000);
		vec[src] = 0;
		std::queue<int> Q;
		Q.push(src);
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			if (now - 1 >= 0 && vec[now - 1] > vec[now] + 1)
			{
				vec[now - 1] = vec[now] + 1;
				Q.push(now - 1);
			}
			if(now+1<vec.size() && vec[now+1]>vec[now]+1)
			{
				vec[now + 1] = vec[now] + 1;
				Q.push(now +1);
			}
			if(now*2<vec.size() && vec[now*2]>vec[now])
			{
				vec[now *2] = vec[now];
				Q.push(now *2);
			}
		}
		/*for (int i = 0; i <= dst; i++)
			std::cout << vec[i] << " ";
		std::cout << '\n';*/
		std::cout << vec[dst] << '\n';
	}
}
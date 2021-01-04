#include <iostream>
#include <queue>
#include <functional>

int main() {
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::priority_queue<int,std::vector<int>,std::greater<int>> b;
		std::priority_queue<int> s;
		for (int i = 0; i < n; i++) {
			int num; std::cin >> num;
			if (i == 0) {
				b.push(num);
				std::cout << num<<" ";
			}
			else{
				int mid = num;
				if (!s.size()) {
					if (mid > b.top())
					{
						b.push(mid);
						mid = b.top();
						b.pop();
					}
				}
				else {
					while (mid < s.top() || mid > b.top()) {
						if (mid > b.top())
						{
							b.push(mid);
							mid = b.top();
							b.pop();
						}
						else {
							s.push(mid);
							mid = s.top();
							s.pop();
						}
					}
				}
				if(i%2==0)
					std::cout << mid << " ";
				if (b.size() == s.size()) b.push(mid);
				else s.push(mid);
			}
			
		}
		std::cout << '\n';
	}
}
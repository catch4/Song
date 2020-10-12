//#include <iostream>
//
//bool ck[100][100];
//
//int main() {
//	int n,cnt=0; std::cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a, b; std::cin >> a >> b;
//		for (int h = b - 1; h < b + 9; h++)
//			for (int w = a - 1; w < a + 9; w++)
//				ck[h][w] = 1;
//			
//	}
//	for (int i = 0; i < 100; i++)
//		for (int j = 0; j < 100; j++)
//			if (ck[i][j])
//				cnt++;
//			
//	std::cout << cnt << '\n';
//}
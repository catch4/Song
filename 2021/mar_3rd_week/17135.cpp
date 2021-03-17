#include <iostream>
#include <vector>
#define vec2d std::vector<std::vector<bool>>

int answer,n, m, dis,num;

void age(vec2d& tmp, int& enemy) {
	for (int i = n - 1; i>0; i--)
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1 && tmp[i][j])
				enemy -= 1;
			
			tmp[i][j] = tmp[i - 1][j];
		}
	for (int j = 0; j < m; j++)
		tmp[0][j] = 0;
}

void simul(vec2d& mp, std::vector<bool>& ar) {
	vec2d tmp = mp;
	int enemy = num, kill = 0;
	while (enemy) {
		int p = 0;
		std::pair<int, int> pos[3];
		bool find[3];
		for (int a = 0; a < ar.size(); a++) {
			if (!ar[a]) continue;
			std::cout << "a=" << a << '\n';
			find[p] = false;
			for (int d = 0; d < dis; d++)
			{
				for (int l = 0; l < d + 1; l++)
				{
					int x = l - d + a, y = -1 - l + n;
					if (x<0 || x >= m || y < 0 || y >= n) continue;
					if (tmp[y][x])
					{
						find[p] = true;
						pos[p].first = y, pos[p].second = x;
						break;
					}
				}
				if (find[p]) break;
				for (int r = 0; r < d; r++)
				{
					int x = r + 1 + a, y = -d + r + n;
					if (x<0||x >= m || y < 0||y>=n) continue;
					if (tmp[y][x])
					{
						find[p] = true;
						pos[p].first = y, pos[p].second = x;
						break;
					}
				}
				if (find[p]) break;
			}
			p += 1;
			
		}
		for (int i = 0; i < 3; i++)
		{
			if (find[i] && tmp[pos[i].first][pos[i].second]) {
				tmp[pos[i].first][pos[i].second] = 0;
				enemy -= 1;
				kill += 1;
			}
		}
		/*std::cout << "pre_age" << '\n';
		for (int ti = 0; ti < n; ti++) {
			for (int tj = 0; tj < m; tj++)
				std::cout << tmp[ti][tj] << " ";
			std::cout << '\n';
		}*/
		if (enemy) age(tmp, enemy);

		/*std::cout << "post_age" << '\n';
		for (int ti = 0; ti < n; ti++) {
			for (int tj = 0; tj < m; tj++)
				std::cout << tmp[ti][tj] << " ";
			std::cout << '\n';
		}
		std::cout << enemy<<'\n';*/
	
	}
	std::cout << kill << '\n';
	if (answer < kill) answer = kill;
}

void dfs(vec2d& mp,std::vector<bool>& ar,const int& pre,const int& sum) {
	for (int i = pre+1; i < m; i++) {
		ar[i] = 1;
		if (sum == 2)
			simul(mp, ar);
		else
			dfs(mp, ar, i, sum + 1);
		ar[i] = 0;
	}
}

int main() {
	std::cin >> n >> m >> dis;
	vec2d mp(n, std::vector<bool>(m, 0));
	std::vector<bool> ar(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;	std::cin >> c;
			if (c == '1') num+=1;
			mp[i][j]=c-'0';
		}
	dfs(mp, ar, -1, 0);
	std::cout << answer << '\n';

	return 0;
}
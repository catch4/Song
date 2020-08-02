


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#define hash std::unordered_map<std::string,int>
#define vec2d std::vector<std::vector<bool>>
int n,m,dy[] = { -1,-1,-1,0,0,1,1,1 }, dx[] = { -1,0,1,-1,1,-1,0,1 }, score_box[] = { 0,0,0,1,1,2,3,5,11 };
char board[4][4];
struct Dict {
	int score;
	std::string str;
	void cin() {
		std::cin >> str;
		score = score_box[str.size()];
	}
};

struct Ret {
	int score = 0,cnt=0,max_len=0;
	std::string str="";
	void add(Dict& dict) {
		score += dict.score;
		cnt++;
		if (dict.str.size()>max_len || (dict.str.size()==max_len&&dict.str<str)){
			str = dict.str;
			max_len = dict.str.size();
		}
	}
	void init() {
		score = 0; cnt = 0; max_len = 0;
	}
};

void cin_board() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> board[i][j];
}

void dfs(hash& mp,const int& i,const int& j,vec2d& ck,std::string str) {
	str += board[i][j];
	mp[str] = 1;
	if (str.size() == 8) return;
	for (int k = 0; k < 8; k++) {
		int n_y = i + dy[k], n_x = j + dx[k];
		if (n_y < 0 || n_y >= 4 || n_x < 0 || n_x >= 4 || ck[n_y][n_x]) continue;
		ck[n_y][n_x] = 1;
		dfs(mp, n_y, n_x, ck, str);
		ck[n_y][n_x] = 0;
	}
}


void make_hash(hash& mp) {
	vec2d ck(4, std::vector<bool>(4, 0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			ck[i][j] = 1;
			dfs(mp, i, j, ck, "");
			ck[i][j] = 0;
		}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	std::vector<Dict> dicts(n);
	for (int i = 0; i < n; i++) dicts[i].cin();
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		cin_board();
		Ret ret;
		hash mp;
		make_hash(mp);

		for (int j = 0; j < n; j++) {
			if (mp.find(dicts[j].str) != mp.end()) {
				ret.add(dicts[j]);
			}
		}
		std::cout << ret.score << " " << ret.str << " " << ret.cnt << '\n';
	}
}

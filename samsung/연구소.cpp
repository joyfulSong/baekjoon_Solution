#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[8][8], n, m, ret = 0;
const int dj[4] = { 0, 0, -1, 1 }; // j는 열(가로) i는 행(세로), 상하좌우
const int di[4] = { -1, 1, 0, 0 };

struct Loc {
	int r, c;
	Loc(int a, int b) {
		r = a; c = b;
	}
};

queue<Loc> virus;

void bfs() {
	queue<Loc> virus_tmp = virus; //for문 안돌아도, 큐는 이렇게 복사할 수 있다. 

	//현재 선택된 벽들에 대해 방문 체크용. 매 bfs마다 필요해서 여기에 만듬. 전에 방문한적이 있다면 그 방은 선택안하도록. 
	int visited[8][8] = { 0, }; //초기화 방식.
	// 강의서는 바이러스 위치도 방문 체크하는데, 벽에대해서만 필요하잖아? 아래 if문도 그렇고

	//원래의 맵은 훼손하지 않고 새로 만든 맵으로 쓰려고. (조합 dfs에서 map이 바뀜.)
	int back_up[8][8];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			back_up[i][j] = map[i][j];
		}
	}

	while (!virus_tmp.empty()) {
		Loc vi_loc = virus_tmp.front();
		virus_tmp.pop();

		int row = vi_loc.r;
		int col = vi_loc.c;
		back_up[row][col] = 2;

		for (int i = 0; i < 4; ++i) {
			int n_r = row + di[i];
			int n_c = col + dj[i];
			
			if (n_r < 0 || n_r >= n || n_c < 0 || n_c >= m) continue;
			
			else {
				if (back_up[n_r][n_c] == 0 && visited[n_r][n_c] == 0) {
					// 여기선 큐에 넣기만 하니깐 2라고 아직 체크 안하지. 
					visited[n_r][n_c] = 1;
					virus_tmp.push(Loc(n_r, n_c));
				}
			}
		}

	}

	int candi = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(back_up[i][j] == 0) ++candi;
		}
	}

	if (ret < candi) ret = candi;
}

void select_wall(int cnt, int si, int sj) {
	if (cnt == 3) {
		bfs();
		return;
	}
	else {
		for (int i = si; i < n; ++i) {
			for (int j = sj; j < m; ++j) {
				if (map[i][j] == 0) { // 벽을 세워야만 bfs 로 넘어가야하는데, 안세워도 다음 재귀로 넘어가게 짜놧엇음;
					map[i][j] = 1;
					select_wall(cnt + 1, i, j);
					map[i][j] = 0;
				}
			}
			sj = 0; // 행이 바뀌었는데 여전히 같은 열을 가리키고 있으면 다음 행의 첫열에서 시작안함.
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push(Loc(i, j)); //원래는 위치를 어떤 벡터에 저장해두고 꺼내서 큐에 넣엇는데, 바로 큐로 사용하면 된다.
			}
		}
	}

	select_wall(0, 0, 0); // count, si, sj

	cout << ret;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, M = -2147000000;
char tmp[21];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

char map[21][21];
bool ch1[26]; //시간초과 방지위해 알파벳 대문자 아스키코드: 65~90
// bool ch2[20][20];
//queue<Loc> q; bfs로 풀려니깐 체크배열을 해제하기 위해 for문을 돌려야함.

void DFS(int x, int y, int cnt) {

	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];

		if (xx >= 0 && xx < C && yy >= 0 && yy < R) { //넘겨주기에도 그렇고, 그 자리를 지났는지를 확인하는 용도는 어차피 아래서 알파벳이 겹치는지 확인하기에 ch2배열이 필요없음

			if (ch1[map[yy][xx]-65] == 1) {
				if (cnt > M) M = cnt;
				continue;
			}
			/*bool flag = 0;

			for (int l = 0; l < ch1.size(); l++) {
				if (map[yy][xx] == ch1[l])
				{
					flag = 1;
					break;
				}
			}*/

			else {
				ch1[map[yy][xx] - 65] = 1;
				DFS(xx, yy, cnt + 1);
				ch1[map[yy][xx] - 65] = 0;
			}


		}

		//vector.clear() --> leaving the container with a size of 0.

	}

}

//bfs는 큐에 기준 좌표를 넣고 주변을 탐색해, 가능한 주변을 다 돌고나면 큐가 비어서 새로운 좌표이동이 되어야 해 for문을 돌아야하지만
//dfs로는 큐가 빈다는것이 없이 어떤 좌표에 대해 주변을 다 탐색하되, 새로운 알파벳을 만나면 그 좌표로 바로 이동해 스택을 쌓아 거기서 또 주변을 탐색하다가 더이상 없으면 내려와 다시 탐색하는 식으로 전체를 다 돈다.
int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
		}
	}

	ch1[map[0][0] - 65] = 1;
	M = 1;
	DFS(0, 0, 1);


	cout << M;

}
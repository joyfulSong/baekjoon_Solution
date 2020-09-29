#include <iostream>
using namespace std;

int map[31][11]; // 1행 1열부터 시작
int n, m, h, ret = 4;

bool check() {
	bool ret = true;

	for (int i = 1; i <= n; ++i) { // 모든 라인에 대해서 테스트
		int pos = i; // 1라인에서 시작해서 사다리 선 만나면 pos 이동
		for (int j = 1; j <= h; ++j) {//세로선 따라 내려감
			if (map[j][pos] == 1) ++pos;
			else if (map[j][pos - 1] == 1) --pos; // 한 열 이전에 1이 놓여있다는 건, 현재 위치가 이동한 이후의 위치라는 것. 그러면 가리키는 위치는 한칸 왼쪽으로 가야함.
		}
		if (pos != i) return ret = false; // 한번이라도 일치하지 않으면 바로 false 리턴.
	}

	return ret;
}

void dfs(int count, int r, int c) {// r,c부터 돌면됨.그 앞선 위치에는 앞선 경우에 조합으로 그어봤음
	if (count >= ret) return; // 이미 ret보다 커졌다면, 더 스택을 쌓을것도 없다.
	if (check()) { //가로선을 추가해서 올라온 스택에서 전체 사다리 구조를 확인해보니, 모두 i=i다, ret의 값 변경
		ret = count;
		return;
	}
	if (count == 3) return; // 3일때 check통과해서 ret에 담았거나, 혹은 통과못해서 못담앗거나, 최대값이 3이기에 더 스택쌓을 필요 없음. 
	else {
		for (int i = r; i <= h; ++i) {
			for (int j = c; j < n; ++j) { //이동가능한 시작점에 담았기 때문에 n-1까지 돔
				if (map[i][j] == 0 && map[i][j - 1] != 1 && map[i][j + 1] != 1) {
					map[i][j] = 1;
					dfs(count + 1, i, j);
					map[i][j] = 0;
				}
			}
			c = 1; //다음 행에서 다시 맨 처음 열부터 돌아야하니깐.
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	dfs(0, 1, 1);

	if (ret == 4) {
		cout << "-1"; return 0;
	}//최대 3개까지 추가 가능하므로. 또한 도중에 갱신되지 못해서 초기값이랑 동일하다면.
	
	cout << ret;

	return 0;

}
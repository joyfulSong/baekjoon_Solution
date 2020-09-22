#include <iostream>
using namespace std;

int n, res = 0;
int map[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	int l;
	cin >> n >> l;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	//모든 행
	for (int i = 0; i < n; ++i) {
		int a = map[i][0], ac = 1, bc = 0;
		bool flag = 0;
		for (int j = 1; j < n; ++j) {
			if (map[i][j] == a + 1) {
				// 기준 수보다 큰 수는 이전에 카운트 했던 걸로 사용
				if (ac < l) {
					flag = 1;
					break; // 이 행은 이미 길 안됨.
				}
				else if (ac >= l) {
					a = map[i][j]; ac = 1;
				}
			}
			else if (map[i][j] == a) {
				ac += 1;
			}
			else if (map[i][j] == a - 1) {
				bc += 1; // 기준 수보다 작은 수는 만난 이후로 카운트 해야함. 
				if (bc >= l) {
					if ((l > 1 && map[i][j - 1] == map[i][j]) || l == 1) {
						a = map[i][j]; bc = 0;
						ac = 0;
						flag = 0;
					}
					
				}
				else {
					flag = 1;
				}
				
			}
			else {
				flag = 1;
				break; // 갑자기 숫자가 1칸 넘게 바뀌면 그 행은 길이 못됨
			}

		}
		if (flag == 0) res += 1;

		//cout << res << endl;
	}

	//모든 열
	for (int i = 0; i < n; ++i) {
		int a = map[0][i], ac = 1, bc = 0;
		bool flag = 0;
		for (int j = 1; j < n; ++j) {
			if (map[j][i] == a + 1) {
				// 기준 수보다 큰 수는 이전에 카운트 했던 걸로 사용
				if (ac < l) {
					flag = 1;
					break; // 이 행은 이미 길 안됨.
				}
				else if (ac >= l) {
					a = map[j][i]; ac = 1; // 비교 대상 바꾸고 다시 1부터 카운트 (이전에 1, 지금이 2라면, 이 칸부터가 1: 다음칸이 하나 큰수인데, l==1이면 경사로 놓을 수 있으므로.)
				}
			}
			else if (map[j][i] == a) {
				ac += 1;
			}
			else if (map[j][i] == a - 1) {
				bc += 1; // 기준 수보다 작은 수는 만난 이후로 카운트 해야함. 
				if (bc >= l) {
					if ((l > 1 && map[i-1][j] == map[i][j]) || l == 1) {
						a = map[j][i]; bc = 0;
						ac = 0; // 현재칸까지 경사로로서 사용됏으니, ac 는 0으로 초기화되어야.
						flag = 0;
					}
				}
				else {
					flag = 1;
				}
			}
			else {
				flag = 1;
				break; // 갑자기 숫자가 1칸 넘게 바뀌면 그 행은 길이 못됨
			}
		}
		if (flag == 0) res += 1;
		//cout << res << endl;
	}

	cout << res;
}
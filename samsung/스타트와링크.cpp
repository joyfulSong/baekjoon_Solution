#include <iostream>
#include <algorithm>
using namespace std;

int s[21][21]; //0번인덱스 사용 x
int a[11], b[11]; //ch는 숫자를 안쓴거 확인하기 위해서
int n, minimum = 2000;

void dfs(int l, int c) {
	if (l == (n / 2) + 1) {
		int ch[21] = { 0, };
		for (int i = 1; i < (n / 2) + 1; ++i) {
			ch[a[i]] = 1;
		}

		int j = 1;
		for (int i = 1; i < n + 1; ++i) {
			if (ch[i] == 0) {
				b[j] = i;
				++j;
			}
		}
		int start = 0, link = 0;
		for (int i = 1; i < (n / 2); ++i) {
			int ai = a[i]; int bi = b[i];
			for (int j = i + 1; j < (n / 2) + 1; ++j) {
				int aj = a[j]; int bj = b[j];
				start += s[ai][aj] + s[aj][ai];
				link += s[bi][bj] + s[bj][bi];
			}
		}
 		if (abs(start - link) < minimum) 
			minimum = abs(start - link);
		//cout << abs(start - link) << minimum << '\n';
	}
	else {
		for (int i = c; i < n + 1; ++i) {
			a[l] = i;
			dfs(l + 1, i + 1); // c+1을 넣엇었음. c는 dfs로 넘어온 값이고, 레벨이 안차면 i 포문이 돌아서 i값이바뀌니깐 i를 넘겨줘야하는거지. c넘겨주면 이전에 c 썼는데 또 c를 사용하게되지.
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			cin >> s[i][j];
		}
	}


	dfs(1,1);

	cout << minimum;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, L;
int ch[15];
char arr[15];

void DFS(int l, int v, int mo, int ja) {
	if (l == L) {
		if (mo < 1 || ja < 2) return;
		for (int i = 0; i < C; i++) {
			if (ch[i] == 1) {
				cout << arr[i];
			}
		}cout << '\n';


	}

	for (int i = v; i < C; i++) {
		if (ch[i] == 0) {
			ch[i] = 1;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			{
				DFS(l + 1, i + 1, mo + 1, ja);
			}
			else DFS(l + 1, i + 1, mo, ja + 1);
			ch[i] = 0;
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	char a;

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);

	DFS(0, 0, 0, 0);

	return 0;
}
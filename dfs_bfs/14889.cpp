#include <iostream>

using namespace std;

int S[21][21], ch_comb1[11], ch_comb2[11], ch_num[11], ch_score[3];
int N, tot = 0, min = 214760000;


// 만든 N/2개의 숫자들 또한 2개씩 짝을 이루는 조합을 만들어야 한다.
// bool이 1이면 DFS로 체크된 숫자들에 대해서, bool이 2이면 체크 안되서 새로 만들어준 ch_comb에 대해서.
void dfs(bool f, int s, int L) {
	if (L == 3) {
		int a = ch_score[1];
		int b = ch_score[2];
		tot += S[a][b] + S[b][a];
	}
	else {
		if (f == 1) {
			for (int i = s; i <= N / 2; i++) {
				ch_score[L] = ch_comb1[i]; // ch_comb에는 조합에 대한 숫자가 저장되어 있으니, 점수계산용으로 저장.
				dfs(1, i + 1, L + 1);
			}
		}
		
		else {
			for (int i = s; i <= N / 2; i++) {
				ch_score[L] = ch_comb2[i]; 
				dfs(0, i + 1, L + 1);
			}
		}
	}
}

void DFS(int s, int L) {
	if (L == N / 2 + 1) {
		tot = 0;
		dfs(1, 1, 1); // 숫자조합을 다 만들었으면, 이 조합에 대한 능력치를 계산한다.
		int tmp = tot; // 나머지 수에 대해서 dfs함수를 또 써야해서 tot값을 따로 뺴둔다.

		// 나머지 수에 대해서 조합을 저장해둔다.
		int cnt = 1;
		for (int i = 1; i <= N; i++) {
			if (ch_num[i] == 0) {
				ch_comb2[cnt++] = i;
			}
		}

		tot = 0;
		dfs(0, 1, 1); // 나머지 수에 대해서 능력치 계산.
		if (min > abs(tot - tmp)) min = abs(tot - tmp);
	}

	else {
		for (int i = s; i <= N; i++) {
			ch_comb1[L] = i; // 반 나누는 조합을 만들기 위해 하나씩 저장한다.
			ch_num[i] = 1; // 어떤 숫자를 썼는지 알기 위해. 체크하지 않은 숫자는 따로 또 점수 계산해야하므로. 
			DFS(i + 1, L + 1);
			ch_num[i] = 0; // 이전 스택에서 2를 사용햇지만, 스택을 빼고 새 스택에서는 새로운 숫자를 사용하게 되니. 
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	DFS(1, 1);

	cout << min;

	return 0;
}

// 스택은 1부터 쌓이고, 레벨 끝까지 차서 다시 이전 스택으로 돌아가 칸을 ㅐ우면 자동으로 칸을 재사용하므로, 칸을 초기화할 필요없음.
// 카톡에 조합 dfs 그림 캡쳐본 있음.
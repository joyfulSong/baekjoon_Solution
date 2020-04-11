#include <iostream>
#include <vector>
using namespace std;

int Dp[11]; //입력 N < 11

int Dynamic(int a) {
	if (Dp[a] == 0) {
		for (int i = 4; i < a+1; i++)
			Dp[i] = Dp[i - 1] + Dp[i - 2] + Dp[i - 3];
	}
	return Dp[a];
}

int main()
{
	int T, N, ans;
	cin >> T;
	
	Dp[1] = 1;
	Dp[2] = 2;
	Dp[3] = 4;

	for (int i = 0; i < T; i++) {
		cin >> N;

		if (Dp[N] == 0) {
			ans = Dynamic(N);
			}
		}
		ans = Dp[N]; // Dp[0] == 0일때도. 
		cout << ans << "\n";
		}
	}

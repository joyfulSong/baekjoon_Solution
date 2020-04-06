#include <iostream>

using namespace std;

int Dp[1001];

int main()
{
	int N;
	cin >> N;

	if (Dp[N] == 0) {

		Dp[1] = 1;
		Dp[2] = 2;

		for (int i = 3; i < N + 1; i++) {
			Dp[i] = Dp[i - 1] + Dp[i - 2];
		}
	}

	cout << Dp[N] % 10007 << "\n";
}
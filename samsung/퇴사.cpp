#include <iostream>
#include <vector>

using namespace std;

int n, maximum = -2147000000;
vector<int> T(n + 1), P(n + 1);

void DFS(int date, int sum) {
	if (date == n + 1) {
		if (maximum < sum) {
			maximum = sum;
		}
	}
	else {
		if (T[date] + date <= n + 1) DFS(T[date] + date, sum + P[date]);
		DFS(date + 1, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	int t, p;
	T[0] = 0;
	P[0] = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}

	for (int i = 1; i <= n; ++i) {
		cout << T[i] << P[i] << endl;
	}
	DFS(1, 0);

	cout << maximum;
}
#include <iostream>

using namespace std;

int main()
{
	int N; // 찍어야 할 별 개수, 출력할 갯수 늘리는 용

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
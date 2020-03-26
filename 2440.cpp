#include <iostream>

using namespace std;

int main()
{
	int N; // 찍어야 할 별 개수, 출력할 갯수 늘리는 용

	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
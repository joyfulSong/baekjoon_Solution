#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N; 

	for (int i = 1; i < N+1; i++) {
		for (int k = (N - i); k > 0; k--) {
			cout << " ";
		}
		for (int j = 1; j < i+1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < (i + 1); j++) {
			cout << " ";
		}
		for (int k = N; k > i; k--) {
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
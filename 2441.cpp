#include <iostream>

using namespace std;

int main()
{
	int N; 

	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int k = 0; k < (N - i); k++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
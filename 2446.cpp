#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N; 
	int tot = 2 * N - 1;

	for (int i = 0; i < tot; i++) {
		
		if ((tot - 2 * i) > 1) {
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			for (int j = 0; j < tot - 2 * i; j++) {
				cout << "*";
			}
			cout << "\n";
		}

		 if ((tot - 2 * i) == 1) {
			 for (int j = 0; j < (tot-1)/2; j++) {
				 cout << " ";
			 }
			 cout << "*";
			 cout << "\n";
		 }

		 
		 if ((tot - 2 * i) < 1) {
			 {
				 for (int j = 0; j < (tot-i)-1; j++) { // i가 0에서 시작해서 1을 빼줌
					 cout << " ";
				 }
				 for (int j = 0; j < (2*(i+1) - tot); j++) {
					 cout << "*";
				 }
				 cout << "\n";
			 }
		 }
	}
	
	return 0;
}
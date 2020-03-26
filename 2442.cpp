#include <iostream>

using namespace std;

int main()
{
	int N, tot1, tot2; //줄의 개수, 차지하는 요소의 개수, 각줄에서의 별개수

	cin >> N; 
	tot1 = 2 * N - 1;

	for (int i = 1; i <= N; i++) { //개수 따져야하므로 1부터 시작
		tot2 = 2 * i - 1;
		
		if (tot1 != tot2) {
			for (int k = 0; k < (tot1 - tot2) / 2; k++) {
				cout << " ";
			}
		}
			for (int j = 0; j < tot2; j++) {
				cout << "*";
			}
			cout << "\n";
		}
	return 0;
}
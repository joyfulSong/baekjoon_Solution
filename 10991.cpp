#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N; 

	for (int i = 1; i <= N; i++) {
		
		if ((N - i) != 0) { // 0이 되면 마지막 줄임
			for (int j = 0; j < (N - i); j++) { //마지막 줄 전까지는 앞에 공백이 N-i개 존재
				cout << " ";
			}
		}
		for (int j = 0; j < (i-1); j++) { //i번째 줄은 *와 공백 한셋트가 i-1번 출력
			cout << "*" << " ";
		}

		cout << "*" << "\n";
	}

	return 0;

}
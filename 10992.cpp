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
			cout << "*"; // 앞 공백 출력 끝나면 별찍기
			
			if (i == 1) { cout << "\n"; }

			if (i != 1) { //첫줄이 아니면 공통 적용

			    //사이공백 갯수: 각줄 전체 출력갯수 N+(i-1) - 앞 공백 갯수(N-i) - 별 두개 2
				for (int j = 0; j < (2 * i - 3); j++) {
					cout << " ";
				}
				cout << "*" << "\n";
			}
			
		}

		else {
			for (int j = 0; j < N + i - 1; j++) {
				cout << "*";
			}
			cout << "\n";
		}
	}

	return 0;

}
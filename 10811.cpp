#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, a, b; // 바구니 개수, 역순으로 만들 횟수, 범위

	cin >> N >> M; 

	vector<int> my_vector(N);

	for (int i = 0; i < N; i++) {
		my_vector[i] = i+1;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		if (a != b) {
			int num = (b-a+1); //빼내야 하는 원소 수
			vector<int> temp_vector(num); //기존의 배열을 잠시 저장해두는 용도
			
			for (int j = 0; j < num; j++) {
				temp_vector[j] = my_vector[(a-1)+j];
			}

			// 기존의 벡터를 새롭게 갱신
			int count = 0;
			for (int j = num-1; j >= 0 ; j--) {
				my_vector[(a-1) + count] = temp_vector[j];
				count++;
			}

			//확인 출력용
			for (int i = 0; i < N; i++) {
				cout << my_vector[i] << " ";
			}
			cout << '\n';	
		}
	}
	for (int i = 0; i < N; i++) {
		cout << my_vector[i] << " ";
	}

}

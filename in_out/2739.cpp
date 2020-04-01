#include <iostream>
using namespace std;

int main()
{
	int N;

	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i < 10; i++) {
		cout << N << " * " << i << " = "<< N*i << '\n';
	}
	return 0;
}

// endl이 매우 느리다는 정보를 얻음(개행후 출력 버퍼를 비우기에) 차라리 \을 쓰라고.
// cin은 cout과 한셋트로, cin을 할때마다 cout의 버퍼를 먼저 비우는걸 의미. 
// 여러 케이스에 대해 입출력을 반복해야 할때는 cin.tie(NULL)을 써주는게 좋음.
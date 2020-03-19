#include <iostream>
#include <string>

using namespace std;

int main()
{
	string txt;

	cin >> txt;  // 도중에 공백이 들어있다면 getline(cin, txt) 사용해야함. 
	//앞서 받은 변수가 있다면 개행문자 지워주기: cin.ignore(256, '\n')

	int i = 0;
	while (i < txt.size()+1){
		cout << txt.substr(i, 10) << endl;
		i += 10;
	}
}
// 나는 일정 구간을 출력해주는 stl 함수를 사용함. 
// txt[i]로도 접근이 가능함. 그리고 10개가 될때마다 줄바꿈을 출력해주는 방법도 있음
// 2007년이라고 명시되어 있어서 이전 달까지의 날수를 모두 계산할 필요 없음
// 요일을 알아내는 법은 나누기 7을 했을 때 나머지에 따라서 요일이 결정됨. 
// 31, 28, 30일인 날들이 섞여있어도, 날수를 모두 더해주기에 2월은 32일부터가 되는 것이라 나머지 연산을 똑같이 사용 가능
// case나 조건문을 사용할까 했으나, array에 저장하고 접근함. 

#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
	int x, y, day = 0, ans;

	cin.tie(NULL);
	cin >> x >> y;

	//1월 1일부터 이전 달까지의 날짜 수를 계산
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < x - 1; i++) {
		day += month[i];
	}
	day += y; // 현재 달의 날수를 더함

	ans = day % 7;

	string days[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	cout << days[ans] << "\n";
	
	return 0;
}


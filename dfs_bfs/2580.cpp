#include <iostream>
#include <vector>

using namespace std;

struct Loc {
    int x, y;
    Loc() {}
    Loc(int a, int b) {
        x = a; y = b;
    }
};

int map[9][9];
Loc zero_list[90];
int cnt = 0;

//모든 행요소(세로줄)
bool check_rows(int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (map[i][y] == n) return false;
    }
    return true;
}

//모든 열요소(가로줄)
bool check_cols(int x, int n) {
    for (int i = 0; i < 9; i++) {
        if (map[x][i] == n) return false;
    }
    return true;
}

bool check_box(int x, int y, int n) {
    // 3의 배수 만큼씩 칸의 구역이 나뉘므로. 
    x = x / 3;
    y = y / 3;
    for (int i = x * 3; i < x * 3 + 3; i++) { // 배열이 0부터 시작해서.
        for (int j = y * 3; j < y * 3 + 3; j++) {
            if (map[i][j] == n) return false;
        }
    }
    return true;
}

bool check(int x, int y, int n) {
    return (check_rows(y, n) && check_cols(x, n) && check_box(x, y, n)) ? true : false;
}

void DFS(int l) {
    if (l == cnt) {
        // 처음에 0으로 저장되었던 모든 곳에 값을 넣고나면 출력한다.
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0); // 종료
    }

    // 속해있는 행, 열, 영역에 대해 존재하지 않는 숫자를 찾아서 집어넣는다. 
    for (int i = 1; i <= 9; i++) {
        // DFS로 새 스택으로 올라가면 또 다시 1부터 9까지 검사한다.
        // 0인 리스트에서 x,y값을 꺼내둔다.
        int x = zero_list[l].x;
        int y = zero_list[l].y;

        if (check(x, y, i)) {
            map[x][y] = i;
            DFS(l + 1);
            map[x][y] = 0; // 앞서 값을 채워왔는데, 만약 그중에 뒤에서 필요한 수를 먼저 사용한 경우, 현재 루프에서 답을 가질 수가 없어서 1부터 9까지 검사했는데 답을 구하지 못한다. 
            // 그경우, 이전 스택으로 내려가 저장했던 값을 다시 0으로 만들고 이전에 검사했던 수 다음 수부터 검사한다.
        }
    }
}
int main() {
    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp;
            map[i][j] = tmp;

            if (tmp == 0) {
                zero_list[cnt] = Loc(i,j); // 0 저장
                cnt++; //cnt에는 0부터 저장되므로 cnt-1이 진짜 갯수. 
            }

        }
        
    }

    DFS(0);
}
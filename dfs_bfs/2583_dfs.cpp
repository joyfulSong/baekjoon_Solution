#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int island[100][100], dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int N, M, k, cnt(0);
bool marked[100][100];
vector<int> result;

struct Loc
{
	int x, y;
	Loc(int a, int b)
	{
		x = a; y = b;
	}
};

void DFS(int y, int x)
{
	marked[y][x] = true; // 방문완료
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (xn >= 0 && xn < N && yn >= 0 && yn < M)
		{
			if (island[yn][xn] == 0 && !marked[yn][xn])
			{
				DFS(yn, xn);
			}
		}
	}
}

int main()
{
	int x1, y1, x2, y2;
	cin >> M >> N >> k;

	//섬 개수만큼 좌표받아서 1로 마킹
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int r = x1; r < x2; r++)
			{
				// 섬위치는 1로 마킹
				if (island[j][r] == 0) island[j][r] = 1;
			}
		}
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (island[j][i] == 0 && !marked[j][i])
			{
				//0인 지점 발견, 여기서부터 DFS시작.
				cnt = 0;
				DFS(j, i); //한 지점에서 들어가서 돌만큼 돌고 나왔다는건 더이상 돌 수 있는 곳이 없다(0인 상하좌우 모두 마킹)
				result.push_back(cnt); // 그때의 cnt가 섬의 면적
			}

		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end()); //오름차순 정렬
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
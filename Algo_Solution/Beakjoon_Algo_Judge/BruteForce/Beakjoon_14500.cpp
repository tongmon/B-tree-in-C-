#include <bits/stdc++.h>
using namespace std;

/*
https://www.acmicpc.net/problem/14500
다른 사람의 풀이들을 보니 내 풀이와 접근방식이 좀 달랐다...
나는 테트리스 게임을 만든 기억을 더듬으면서 구현을 하여 그런지
회전을 기준으로 작성을 하였다.
다른 사람들의 풀이는 어짜피 4칸 도형이니 시작점을 잡고 DFS 4번을 돌리자! 근데 ㅗ 이 모양은 따로 해주고!
이런 느낌이고 내 풀이는 9칸을 잡고 회전을 시킬 건데 
회전을 할 이유가 없는 ㅁ 모양과 모양이 9칸안에 다 안들어가는 | 모양을 제외하고 따로 만들어준다.
회전은 어떤 방식으로 되냐면 중심점을 제외한 점들의 인덱스에 2를 더하고 8로 나누어주면 90도 회전한 블록의 인덱스를 가지게 된다.
이는 일일이 블록 회전하면서 노트에 그려보면 알 수가 있다.
이러한 방식으로 얻어진 배열에 중심점으로 부터 얼마나 떨어져있는지에 대한 정보가 적혀있고
이를 더해주어 정답을 도출했다.
내 방식이 생각하기 약간 까다로워도 숏코딩에 유리하지 않나 생각이 든다.
이 문제를 통해 완전탐색, 구현 문제에 대한 풀이 속도를 늘려간다.
*/

int N, M, Map[501][501], Max, Sum, X, Y;
short Brick[9][2] =
{
	{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {0, 0}
},
Dir[8][4] =
{
	{-1,0}, {-1,1}, {-1,2}, {7, 0, 1, 2}, {0, 1, 2, 3}, {0, 7, 8, 5}, {2, 3, 8, 5}, {1, 7, 8, 3}
},
Sub[3][4][2] =
{
	{{0, -1}, {0, 0}, {0, 1}, {0, 2}}, {{-1, 0}, {0, 0}, {1, 0}, {2, 0}}, {{0, 0}, {1, 0}, {1, 1}, {0, 1}}
};

void GetMax(int k, int i, int j, int y) {
	Sum = 0;
	for (int z = 0; z < 4; z++) {
		if (y > -1) {
			int Ind = Dir[k][z];
			if (Ind < 8)
				Ind = (Ind + 2 * y) % 8;
			X = j + Brick[Ind][0], Y = i + Brick[Ind][1];
		}
		else {
			X = j + Sub[Dir[k][1]][z][0], Y = i + Sub[Dir[k][1]][z][1];
		}
		if (0 <= X && X < M && 0 <= Y && Y < N)
			Sum += Map[Y][X];
		else
			break;
	}
	Max = max(Sum, Max);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 8; k++) {
				for (int y = 0; y < 4 && Dir[k][0] > -1; y++) {
					GetMax(k, i, j, y);
				}
				if (Dir[k][0] < 0) {
					GetMax(k, i, j, -1);
				}
			}
		}
	}
	cout << Max;
}
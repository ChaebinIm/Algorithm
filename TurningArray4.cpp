#include <iostream>
using namespace std;
int N, M, K;
int map[51][51], map_copy[51][51], map_init[51][51];
int oper[6][3];
bool visited[6];
int arr[6];
int _min = 99999999;
// 시계방향으로 회전시키는 함수.
void rotate(int r1, int c1, int r2, int c2) {
	// 1. 바깥쪽부터 안쪽으로..
	for (int i = 0; i < (r2 - r1) / 2; i++) {
		// 윗변
		for (int j = c1 + i; j < c2 - i; j++) {
			map[r1 + i][j + 1] = map_copy[r1+i][j];
		}
		// 오른변
		for (int j = r1 + i; j < r2 - i; j++) {
			map[j + 1][c2 - i] = map_copy[j][c2-i];
		}
		// 아랫변
		for (int j = c2 - 1 - i; j >= c1 + i; j--) {
			map[r2-i][j] = map_copy[r2-i][j+1];
		}
		// 왼변
		for (int j = r2 - 1 - i; j >= r1 + i; j--) {
			map[j][c1 + i] = map_copy[j+1][c1+i];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map_copy[i][j] = map[i][j];
		}
	}
}
 
 
void dp(int cnt) {
	if (cnt == K) {
		for (int i = 0; i < K; i++) {
			int r, c, s;
			r = oper[arr[i]][0];
			c = oper[arr[i]][1];
			s = oper[arr[i]][2];
			rotate(r - s, c - s, r + s, c + s);
		}
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += map[i][j];
			}
			if (sum < _min) {
				_min = sum;
			}
		}
		for (int i = 0; i <= N; i++){
			for (int j = 0; j <= M; j++){
				map[i][j] = map_init[i][j];
				map_copy[i][j] = map_init[i][j];
			}	
		}
	}
	else {
		for (int i = 0; i < K; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[cnt] = i;
				dp(cnt + 1);
				visited[i] = false;
			}
		}
	}
}
 
 
 
 
 
 
 
int main()
{
	// input
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			map_copy[i][j] = map[i][j];
			map_init[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int input1, input2, input3;
		cin >> input1 >> input2 >> input3;
		oper[i][0] = input1;
		oper[i][1] = input2;
		oper[i][2] = input3;
	}
	// 연산 순서 결정하기.
	dp(0);
	cout << _min << "\n";
	while (1);
}

// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int map[10][10];
int paper_count[6] = { 0, 5, 5, 5, 5, 5 };
int _min = 99999999;
bool visited[10][10];


// check함수는 size(1,2,3,4,5)의 변을 가진 정사각형으로 덮을 수 있는지 여부를 체크.
bool check(int r, int c, int size) {
	bool res = false;
	if (r + size <= 10 && c + size <= 10) {
		res = true;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (map[r + i][c + j] == 0) {
					res = false;
					break;
				}
			}
			if (!res) {
				break;
			}
		}
	}
	return res;
}


void simulation(int now, int cnt, vector<pair<int, int>> v) {
	// 만약, 전체가 색종이로 덮였다면, 끝
	if (now == 101 || v.size() == 0) {
		if (cnt < _min) {
			_min = cnt;
		}
		return;
	}
	else {
		// 이번에 방문할 방문지를 결정.
		int r = v[now].first;
		int c = v[now].second;
		// 방문한 적이 없던 곳이라면,
		if (!visited[r][c]) {
			// 1*1, 2*2, 3*3, 4*4, 5*5 각각으로 덮을 수 있는지 체크한 후, 덮을 수 있다면 덮고 계속 진행.
			// 다섯가지 다 쓸수 없다면, 실패로 간주.
			int _cnt = 0;
			for (int i = 5; i >= 1; i--) {
				if (paper_count[i] > 0) {
					bool flag = check(r, c, i);
					// 덮을 수 있다면,
					if (flag) {
						// 덮는다.
						for (int j = 0; j < i; j++) {
							for (int k = 0; k < i; k++) {
								map[r + j][c + k] = 0;
								visited[r + j][c + k] = true;
							}
						}
						paper_count[i]--;
						// 다음 방문위치 찾아주기.
						int next = 101;
						for (int j = 0; j < v.size(); j++) {
							if (map[v[j].first][v[j].second] == 1) {
								next = j;
								break;
							}
						}
						simulation(next, cnt + 1, v);
						// 덮은 것을 해제한다.
						paper_count[i]++;
						for (int j = 0; j < i; j++) {
							for (int k = 0; k < i; k++) {
								map[r + j][c + k] = 1;
								visited[r + j][c + k] = false;
							}
						}
						_cnt++;
					}
				}
			}
			if (_cnt == 0) {
				return;
			}
		}

	}




}


int main()
{
	vector<pair<int, int>> v;
	// input
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
			}
			else {
				visited[i][j] = true;
			}
		}
	}

	simulation(0, 0, v);

	if (_min == 99999999) {
		cout << -1 << "\n";
	}
	else {
		cout << _min << "\n";
	}
	while (1);
}

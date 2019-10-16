
#include <iostream>
#include <vector>
using namespace std;
int N, M; // N은 세로, M은 가로.
int map[8][8], map_init[8][8];
class cctv;
vector<cctv> v; //1~5번 cctv
int arr[8];
int _min = 64;

class cctv {
public:
	int r;
	int c;
	int type;
	int dir;
	cctv(int _r, int _c, int _type, int _dir) :r(_r), c(_c), type(_type), dir(_dir) {}
	void setDir(int _dir){
		dir = _dir;
	}
};

void up(int r, int c) {
	int nr = r;
	int nc = c;
	while (nr >= 0) {
		if (map[nr][nc] == 0) {
			map[nr][nc] = '#';
		}
		else if (map[nr][nc] == 6) {
			break;
		}
		else {
			nr--;
			continue;
		}
	}
}

void down(int r, int c) {
	int nr = r;
	int nc = c;
	while (nr < N) {
		if (map[nr][nc] == 0) {
			map[nr][nc] = '#';
		}
		else if (map[nr][nc] == 6) {
			break;
		}
		else {
			nr++;
			continue;
		}
	}
}

void right(int r, int c) {
	int nr = r;
	int nc = c;
	while (nc < M) {
		if (map[nr][nc] == 0) {
			map[nr][nc] = '#';
		}
		else if (map[nr][nc] == 6) {
			break;
		}
		else {
			nc++;
			continue;
		}
	}
}

void left(int r, int c) {
	int nr = r;
	int nc = c;
	while (nc >= 0) {
		if (map[nr][nc] == 0) {
			map[nr][nc] = '#';
		}
		else if (map[nr][nc] == 6) {
			break;
		}
		else {
			nc--;
			continue;
		}
	}
}
void type_one(int r, int c, int dir) {
	if (dir == 0) {
		up(r, c);
	}
	else if (dir == 1) {
		right(r, c);
	}
	else if (dir == 2) {
		down(r, c);
	}
	else if (dir == 3) {
		left(r, c);
	}
}

void type_two(int r, int c, int dir) {
	if (dir % 2 == 0) {
		up(r, c);
		down(r, c);
	}
	else {
		right(r, c);
		left (r, c);
	}
}

void type_three(int r, int c, int dir) {
	if (dir == 0) {
		up(r, c);
		right(r, c);
	}
	else if (dir == 1) {
		right(r, c);
		down(r, c);
	}
	else if (dir == 2) {
		down(r, c);
		left(r, c);
	}
	else if (dir == 3) {
		left(r, c);
		up(r, c);
	}
}

void type_four(int r, int c, int dir) {
	if (dir == 0) {
		left(r, c);
		up(r, c);
		right(r, c);
	}
	else if (dir == 1) {
		up(r, c);
		right(r, c);
		down(r, c);
	}
	else if (dir == 2) {
		right(r, c);
		down(r, c);
		left(r, c);
	}
	else if (dir == 3) {
		down(r, c);
		left(r, c);
		up(r, c);
	}
}

void type_five(int r, int c, int dir) {
	up(r, c);
	right(r, c);
	down(r, c);
	left(r, c);
}

void seeing(int r, int c, int type, int dir) {
	if (type == 1) {
		type_one(r, c, dir);
	}
	else if (type == 2) {
		type_two(r, c, dir);
	}
	else if (type == 3) {
		type_three(r, c, dir);
	}
	else if (type == 4) {
		type_four(r, c, dir);
	}
	else if (type == 5) {
		type_five(r, c, dir);
	}
}


void simulation() {
	for (int i = 0; i < v.size(); i++) {
		int r = v[i].r;
		int c = v[i].c;
		int type = v[i].type;
		int dir = v[i].dir;
		seeing(r, c, type, dir);
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				res++;
			}
		}
	}
	if (res < _min) {
		_min = res;
	}
}


void dp(int cnt) {
	if (cnt == v.size()) {
		// 방향 설정. 0은 북, 1은 오른쪽, 2는 남쪽, 3은 왼쪽을 의미.
		for (int i = 0; i < v.size(); i++) {
			v[i].setDir(arr[i]);
		}
		// 시뮬레이션
		simulation();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = map_init[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			arr[cnt] = i;
			dp(cnt + 1);
		}
	}

}






int main()
{
	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			map_init[i][j] = input;
			if (input >= 1 && input <= 5) {
				v.push_back(cctv(i, j, input, 0));
			}
		}
	}
	// 전체 경우의 수를 고려하기 위한 장치.
	dp(0);

	cout << _min << "\n";

	while (1);
	return 0;
}

// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
bool visited[101][101];
vector<pair<int, int>> v;

pair<int, int> rotation(pair<int,int> p) {
	int r = p.first;
	int c = p.second;
	int res_r = 0;
	int res_c = 0;
	if (r == 0 && c == 1) {
		res_r = -1;
		res_c = 0;
	}else if (r == 1 && c == 0) {
		res_r = 0;
		res_c = 1;
	}
	else if (r == 0 && c == -1) {
		res_r = 1;
		res_c = 0;
	}
	else if (r == -1 && c == 0) {
		res_r = 0;
		res_c = -1;
	}

	return {res_r, res_c};
}


void check(int gene, int now) {
	
	if (now == gene) {
		return;
	}
	else {
		for (int i = v.size()-1; i >= 0; i--) {
			v.push_back(rotation(v[i]));
		}
		check(gene, now + 1);
	}

}





int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, r, dir, gene;
		cin >> c >> r >> dir >> gene;
		if (dir == 0) {
			v.push_back({0, 1});
		}
		else if (dir == 1) {
			v.push_back({ -1, 0 });
		}
		else if (dir == 2) {
			v.push_back({ 0, -1 });
		}
		else if (dir == 3) {
			v.push_back({ 1, 0 });
		}
		check(gene, 0);
		int nr = r;
		int nc = c;
		visited[nr][nc] = true;
		for (int j = 0; j < v.size(); j++) {
			nr = nr + v[j].first;
			nc = nc + v[j].second;
			visited[nr][nc] = true;
		}
		v.clear();
	}

	int res = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			bool flag = true;
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					if (!visited[i + a][j + b]) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					break;
				}
			}
			if (flag) {
				res++;
			}
		}
	}

	cout << res << "\n";


	while (1);
}

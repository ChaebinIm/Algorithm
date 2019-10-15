#include <iostream>
using namespace std;
int N;
int pred[50][9];
int now = 0;
int res = 0;
int _max = 0;
int _now = 0;
bool one, two, three; 
int arr[8];
bool visited[9];
int order[9]; 
void now_change() {
	if (_now == 8) {
		_now = 0;
		now = order[0];
	}
	else {
		_now++;
		now = order[_now];
	}
}

void simulation(int ining){
	int score = 0;
	bool flag = true;
	int out = 0;
	while (flag) {
		int shot = pred[ining][now];
		if (shot == 1) {
			if (three) {
				three = false;
				score++;
			}
			if (two) {
				two = false;
				three = true;
			}
			if (one) {
				one = false;
				two = true;
			}
			one = true;
		}
		else if (shot == 2) {
			if (three) {
				three = false;
				score++;
			}
			if (two) {
				two = false;
				score++;
			}
			if (one) {
				one = false;
				three = true;
			}
			two = true;
		}
		else if (shot == 3) {
			if (three) {
				three = false;
				score++;
			}
			if (two) {
				two = false;
				score++;
			}
			if (one) {
				one = false;
				score++;
			}
			three = true;
		}
		else if (shot == 4) {
			if (three) {
				three = false;
				score++;
			}
			if (two) {
				two = false;
				score++;
			}
			if (one) {
				one = false;
				score++;
			}
			score++;
		}
		else if (shot == 0) {
			out++;
		}
		now_change();
		if (out == 3) {
			flag = false;
		}
	}
	res += score;
}

void dp(int cnt) {

	if (cnt == 8) {
		order[0] = arr[0];
		order[1] = arr[1];
		order[2] = arr[2];
		order[3] = 0;
		order[4] = arr[3];
		order[5] = arr[4];
		order[6] = arr[5];
		order[7] = arr[6];
		order[8] = arr[7];

		res = 0;
		_now = 0;
		now = order[0];
		for (int i = 0; i < N; i++) {
			one = false;
			two = false;
			three = false;
			simulation(i);
		}
		if (_max < res) {
			_max = res;
		}
	}
	else {
		for (int i = 1; i < 9; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[cnt] = i;
				dp(cnt+1);
				visited[i] = false;
			}
		}
	}
}





int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++)
		{
			cin >> pred[i][j];
		}
	}

	dp(0);

	cout << _max << "\n";
	return 0;
}


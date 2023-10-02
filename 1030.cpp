
#include <iostream>
#include <cmath>

using namespace std;

int S, N, K;
int R1, C1, R2, C2; // (C1,R1) ~ (C2,R2) 계산하기

int MAX;
int outSizeY, outSizeX;

//출력 값
bool board[51][51];

//처음에 제대로 접근하는 것이 더 중요하다

void Recursive(int Nsize, int t, int X, int Y) {

	//Nsize 현재 체크하고 있는 나누려고 하는 박스의 크기
	//t 현재 시간
	//X, Y 해당 박스가 시작하는 왼쪽 위에 코드

	cout << Nsize << " " << t << " " << X << " " << Y << "탐색중" << endl;

	//Ksize 정사각형의 중간 값의 크기를 scale에 따라서 계산하기
	int Ksize = K * pow(N, S - t);

	//가운데 계산 =>  해당 Nsize의 정사각형 기준 중간 값의 위, 아래 값 계산
	int middleL = (Nsize - Ksize) / 2; // 작은
	int middleR = (Nsize + Ksize) / 2; // 큰

	//cout << Ksize << " " << middleL << " " << middleR << endl;

	//내가 출력하는 부분이
	//가운데에 해당하는 칸이 해당 칸에 해당하는지 확인.
	for (int i = middleL + Y; i < middleR + Y; i++) {
		if (R1 > i || R2 < i) continue;

		for (int j = middleL + X; j < middleR + X; j++) {
			if (C1 > j || C2 < j) continue;

			//범위에 해당한다면 색칠하기
			board[i - R1][j - C1] = true;
		}
	}


	//세분화 종료 시, return 0
	if (S == t) return;

	//인덱스 세분화 후에, 분할 정복하기
	//왼쪽 위
	
	int NsizeDiv = Nsize/N;
	
	//위쪽 라인 탐색
	
	if(C1 < X + Nsize && R1 < Y ){
	    for (int i = Y; i < Y + middleL; i+= NsizeDiv) {
		    for (int j = X; j < X + Nsize ; j+= NsizeDiv)
			    Recursive(Nsize / N, t + 1, j, i);
		}
	
	}
	
	
	
	

	//가운데 탐색
	for (int i = Y + middleL; i < Y + middleR; i+= NsizeDiv) {

		//왼쪽 탐색
		for (int j = X; j < X + middleL; j += NsizeDiv ) {
			Recursive(Nsize / N, t + 1, j, i);
		}

		//오른쪽 탐색
		for (int j = X + middleR; j < X + Nsize; j+= NsizeDiv) {
			Recursive(Nsize / N, t + 1, j, i);
		}
	}

	//아래쪽 라인 탐색
	for (int i = Y + middleR; i < Y + Nsize; i+= NsizeDiv) {
		for (int j = X; j < X + Nsize; j+= NsizeDiv) {
			Recursive(Nsize / N, t + 1, j, i);
		}
	}
}

int main() {

	//input
	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	outSizeY = R2 - R1 + 1;
	outSizeX = C2 - C1 + 1;
	MAX = pow(N, S);

	//Recursive
	Recursive(MAX, 1, 0, 0);

	//output
	for (int i = 0; i < outSizeY; i++) {
		for (int j = 0; j < outSizeX; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}

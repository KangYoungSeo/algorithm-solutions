

#include <iostream>
#include <cmath>

using namespace std;

int N;

long long board[100001][2][2];
//N번째, 왼/오른쪽, 있는지 없는지

int main() {

	//input
	cin >> N;
	
	//1번째 왼쪽 사자 없을 때
	board[0][0][0] = 2;
	
	//1번째 오른쪽 사자 없을때
	board[0][1][0] = 2;
	
	//1번째 왼쪽 사자 있을 때
	board[0][0][1] = 1;
	
	//1번째 오른쪽 사자 있을 때
	board[0][1][1] = 1;
	
	//DP 탐색
	//i번째의
	for(int i = 1; i < N; i++){
	    
	    //왼쪽 사자 있을 때 
	    // 1. X O     2. X X    1. X O == ? O == board[i-1][1][1] * 1
	    //    O X        O X    2. X X == ? X - O X == (board[i-1][1][0] - board[i-1][0][1]) * 2
	    board[i][0][1] = board[i-1][0][0] % 9901;
	    
	    //2 * (board[i-1][1][0] - board[i-1][0][1]) + board[i-1][1][1];
	    
	    //왼쪽 사자 없을 때
	    //1.  X X  2. O X  => ? X   3. X X  4. O X  => ? X  5. X O  => ? O
	    //    X O     X O              X X     X X             X X
	    board[i][0][0] = (2 * board[i-1][1][0] + board[i-1][1][1]) % 9901;
	    
	    //오른쪽 사자 있을 때
	    // 1.  O X    2. X X   1. O X == O ? == board[i-1][0][1] * 1
	    //     X O       X O   2. X X == ? X - O X == 
	    board[i][1][1] = board[i-1][1][0] % 9901;
	    
	    //2 * board[i-1][1][0] - board[i-1][0][1];
	    
	    //오른쪽 사자 없을 때
	    //1.  X X  2. X O  => X ?   3. X X  4. X O  => X ?  5. O X  => O ?
	    //    O X     O X              X X     X X             X X
	    board[i][1][0] = (2 * board[i-1][0][0] + board[i-1][0][1])% 9901;
	    
	    
	    //cout << i + 1 << "번째  : " 
	    //<< board[i][0][0] << " " << board[i][0][1] << " " << board[i][1][0] << " " << board[i][1][1] << endl;
	   
	}
	
	//사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력
	cout << (board[N-1][1][1] + board[N-1][1][0]) % 9901 << endl;

	return 0;
}

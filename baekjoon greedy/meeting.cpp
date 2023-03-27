#include <iostream>
using namespace std;
int MIN;
int K;
int* coin;
int Cnt;
int foundOut;

void getCoin(int idx, int rest) {

	int & ret = coin[idx];
	//기저 : 코인을 사용하여 원하는 값에 도달.	
	if (rest == 0 ) {
		
		if (MIN > Cnt) MIN = Cnt;
		foundOut = true;
	}
	else {
		if (idx == -1) return;
		if (rest >= ret) {					//해당 인덱스의 코인의 가치가 남아있는 값보다 작아야 지불 가능하겠죠?
			int maxCoin = rest / ret;		//먼저 최대 인덱스의 값을 저장해 놓습니다!

			for (int i = maxCoin; i >= 0; i++) {	//해당 인덱스 코인 값은 꼭 다 쓸필요 없고 혹시 다른 코인으로도 안된다면 코인을 1개 덜써서 확인가능
				Cnt += i;
				getCoin(idx - 1, rest - ret * i);
				if (foundOut == true) {
					break;
					foundOut = false;
				}
				Cnt -= i;

			}
		}
		else
			getCoin(idx - 1, rest);
	}

}

int main() {

	int N; cin >> N; cin >> K;
	coin = new int[N];
	for (int i = 0; i < N; i++) cin >> coin[i];
	MIN = 1234567890;
	Cnt = 0;
	foundOut = false;
	getCoin(N -1, K);


	cout << MIN << endl;			//결과 출력
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void basic(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	basic();

    //동전 N종류
	int N; cin >> N;
    //가치의 합을 K로
    int K; cin >> K;
    
	vector<int> coin;

	for(int i = 0; i< N; i++){
		int temp; cin >> temp;
		coin.push_back(temp);
	}

	//long long result = 0;
	//long long cnt[1001];

	//먼저 내림차순으로 정리를 한다. 이때 사용하는 함수는?
	sort(coin.begin(), coin.end());

	// 큰 숫자를 기준으로 사용을 해보자 -> greedy

	// 동전 갯수 계산하기
	int cnt = 0;

	//남은 값
	int rest = K;

	//동전 최대 수
	int min = -1;

	for(int i = N-2; i >= 0; i--){
		
		// 현재 처리해야할 돈이 끝일 경우
		if(rest == 0) break;

		//내가 가진 코인이 넘칠 경우는 그 다음으로 스킵
		if(rest < coin[i]) continue;
		
		// 현재 처리해야하는 값에서 이 코인이 해결할 수 있는 정도
		int maxCnt = rest / coin[i];

		// 그동안 썼던 코인 수 추가하기
		cnt += maxCnt;

		// 이번 코인으로 처리한 수를 rest에서 깎기
		rest -= (maxCnt * coin[i]);

	}

	//최솟값 계산
	cout << cnt << endl;

	return 0;
}
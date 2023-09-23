#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	if (k >= n) {
		cout << 0;
	}
	else {
		int answer = 0;

		while (1) {
			int cnt = 0;
			int temp = n;
			while (temp > 0) {
				if (temp % 2 == 0) {
					temp /= 2;
				}
				else {
					temp /= 2;
					cnt++;
				}

			}
			//cnt가 k보다 작거나 같아지면 종료
			if (k >= cnt) {
				break;
			}

			n++;
			answer++;
		}
		cout << answer;
	}
	
	return 0;
}


/*
#include <iostream>

using namespace std;

int N, K;

int divide(){
    
    int multiply = 1; 
    int cnt = 0;
    int Div = N;
    bool found = false;
    
    while(Div > 1){
        
        cnt *= 2;
        
        //짝수 일 경우,
        if(Div % 2 == 0){
            
            //표현 가능할 경우 (K가 Div/2 ~ Div사이에 있다면 무조건 표현 가능)
            if(Div/2 <= K){
                found = true;
                break;
            }
            //표현할 수 없는 경우
            else{
                
                multiply *= 2; //배수 증가  ===>의미 없음!!
                
                Div /= 2; // 나누고 (컵 두 쌍을 합치고 그 다음 묶음에서 여부 확인)
            }
        }
        
        //홀수 일 경우,
        else if(Div % 2 == 1){
            
            //표현 가능할 경우 (K가 Div/2 + 1 ~ Div사이에 있다면 무조건 표현 가능)
            if((Div + 1) / 2 < K){
                found = true;
                break;
            }
            
            //표현할 수 없는 경우            
            else{
                
                cnt++; //컵 추가
                
                multiply *= 2; //배수 증가 ===> 의미 없음!!
                
                Div++;  //현재 묶음 값에 묶음 추가 
                
                Div /= 2; // 나누고 (컵 두 쌍을 합치고 그 다음 묶음에서 여부 확인)
                
            }
        }
        
        
        cout << cnt << endl;
    }
    if(Div == 1) return cnt;
    
    if(!found) return -1;
    
    return cnt;
    
}


int main()
{
    cin >> N >> K;
    
    cout << divide() << endl;
    
    return 0;
}


*/
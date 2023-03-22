#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

bool prime(ll n) { // 소수 판별
    if(n < 2) return false;
       
  
  //하나씩 확인
  //sqrt : 제곱근 함수 활용
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}
//k진수로 변환단계.
//먼저 k로 n을 나눈 나머지를 string에 추가
string convert_num(int n, int k) { // k진수로 변환
    string ret = "";
    
    while(n) {
        ret += to_string(n % k);
        n /= k;
    }
    
  //역방향 반복자 사용
    return string(ret.rbegin(), ret.rend());
}

int get_answer(string num) { // 0을 기준으로 parsing하여 소수이면 count
    string tmp = "";
    int ret = 0;
    
    for(int i=0; i<num.length(); ++i) {
        if(num[i] == '0' && !tmp.empty()) {
            ll n = stoll(tmp);
            if(prime(n)) ret++;
            tmp = "";
        }
        else tmp += num[i];
    }
    
    if(!tmp.empty()) {
        ll n = stoll(tmp);
        if(prime(n)) ret++;
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
  //숫자를 변환
    string num = convert_num(n, k);
  // 답 반환
    return get_answer(num);
}

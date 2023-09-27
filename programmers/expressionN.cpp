#include <string>
#include <vector>

using namespace std;

int n;
int dp[32001] ={0,};//2,3,4,5,1,

int recursive(int number){
    
    if(dp[number] > 0) return dp[number];
    if(number <= 5) return dp[number];
    
    int cnt = 0;
    
    if(number >= 11111){
        
        int quo = (number / 11111);
        
        cnt += quo * 5;
        cnt += recursive(number-quo*5);
        
    }
    else if(number >= 1111){
        
        int quo = (number / 1111);
        
        cnt += quo * 4;
        cnt += recursive(number-quo*4);
        
    }
    else if(number >- 111){
        int quo = (number / 111);
        
        cnt += quo * 3;
        cnt += recursive(number-quo*3);
        
    }
    else if(number >= 11){
        
        int quo = (number / 11);
        
        cnt += quo * 2;
        cnt += recursive(number-quo*2);
    
    }
    else if(number > 5){
        
        int quo = number / 5;
        
        cnt += quo;
        cnt += dp[number - quo * 5];
        
    }
    
    dp[number] = cnt + 1;
    
    return dp[number];
}

int solution(int N, int number) {
    
    int cnt = 0;
    n = N;
    
    //if(N <= 1000) cout <<"done"<< endl;
    
    //recursive(number);
    
    //8보다 크면 -1 출력
}


/*과거 코드

    if(N == 1) return number; //예외
    
    int answer = 0;
    dp[0] = 1; dp[1] = 2; //dp[2] = 4; dp[3] = 6;
    M = N;

    answer = totalN(number);
    if(answer == 0) return -1;
    return answer;
    


int totalN(int num){
    
    if(num > 30000) return 0;
    //cout << num << "검사 : " << endl;
    
    //0이 나올 경우 리턴
    if(num < 2) return num * 2;
    
    //계산한 적 있을 경우 리턴
    else if(dp[num] != 0) return dp[num];
    
    //1111... 일 경우
    int cont = num;
    int Cnt = 0;
    
    while(cont > 0){
        if(cont % 10 == 1){
            cont /= 10;
            Cnt++;
        }
        else break;
        
    }
    if(cont == 0){
        //cout << "연속 11"<< Cnt + 1 << endl;
        dp[num] = Cnt + 1;
        return Cnt +1;
    }
    
    
    
    
    // 비교
    // 가장 가까운 1111이랑 유사한 얘 + 나머지 추가
    
    int conti = 1;
    int ten = 10;
    int cnt = -1;
    
    while(conti < num){
        conti += ten;
        ten *= 10;
        cnt++;
    }
    
    //콘티랑 num 값 확인하기
    conti /= 10;
    
    int min = totalN(conti) + totalN(num-conti);
    
    min -= cnt;
    
    
    //실제로 더하기로 구해보기
    int min2;
    if( num >= M ) {
        min2 = num / M + totalN(num % M);
    }
    else min2 = num * 2;
    
   
    //cout << min << " " << min2 << endl;
    
    //총 세개의 값 중에 가장 작은 값 확인
    min = min < min2 ? min : min2;
    
    //그 작은 값을 return하기
    dp[num] = min;
    //cout << dp[num] << endl;
    
    return min;
    
}
*/

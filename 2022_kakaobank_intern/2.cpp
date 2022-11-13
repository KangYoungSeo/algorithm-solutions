#include <string>
#include <vector>
//#include <iostream>
using namespace std;
int solution(int money, int minratio, int maxratio, int ranksize, int threshold, int months) {
    
    int maxtax = threshold + (maxratio - minratio) * ranksize;
    int remainder;
    
    //2.월별 세금 징수
    while(months-->0){
        //1. 반올림 값 저장 후 무시하고 계산 진행
        remainder = money %100;
        money -= remainder;
        //2-1. threshold보다 적을 시 징수 종료
        if(money < threshold) {
            money += remainder;
            break;
        }
        //2-2. 징수 대상일 경우
        int userratio;
        
        if(money > maxtax) //세율이 max보다 클 경우
            userratio = maxratio;
        else //세율 
            userratio = minratio + (money - threshold)/ ranksize;

        //현재 금액에서 ratio만큼 세금 징수
        money -= money / 100 * userratio ;
        //백 단위 미만 나머지 값 최종 추가
        money += remainder;
    }
    return money;
}

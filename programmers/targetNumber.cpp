#include <string>
#include <vector>

using namespace std;

vector<int> num;
int numsize;
int answer;
int goal;

void DFS(int idx, int result){
    
    if(idx == numsize){
        if(goal == result) answer++;
        return;
    }
    
    DFS(idx+1, result - num[idx]);
    DFS(idx+1, result + num[idx]);
    
}

int solution(vector<int> numbers, int target) {
    
    answer = 0;
    
    goal = target;
    numsize = numbers.size();
    num = numbers;
    
    //재귀, 백트래킹
    DFS(1,numbers[0]);
    DFS(1,-numbers[0]);
    
    return answer;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;


//node 구현
struct node{
    
    int before;
    int after;
    
};

int N, M;


//!!!!!!!!연결 리스트 같은데 확인해보자... 자료구조 이렇게 하는 것이 맞는 가?
node train[500001];

void print(){
    
    //연결리스트 debug
    for(int i = 0; i < 500001; i++){
        if(train[i].before == 0) continue;
        
        cout << i << "번째 : " <<train[i].before << " " << train[i].after << endl;
    }
}


//BN i j : 고유 번호 i를 가진 역의 다음 역의 고유 번호를 출력, 고유 번호 j인 역을 설립
void constructBN(int i, int j){
    
    //먼저 i의 원래 그 다음 인덱스를 저장
    int next = train[i].after;
    
    //그다음 인덱스는 j가 앞임을 선택
    train[next].before = j;
    
    //i의 인덱스 후를 확인.
    train[i].after = j;
    
    //출력
    cout << next << endl;
    
    //j 노드 생성
    
    train[j] = {i, next};
    
}

//BP i j : 고유 번호 i를 가진 역의 이전 역의 고유 번호를 출력, 고유 번호 j인 역을 설립
void constructBP(int i, int j){
    
    //먼저 i의 원래 그 전의 인덱스를 저장
    int before = train[i].before;
    
    //그다음 인덱스는 j가 앞임을 선택
    train[before].after = j;
    
    //i의 인덱스 후를 확인.
    train[i].before = j;
    
    //출력
    cout << before << endl;
    
    //j 노드 생성
    
    train[j] = {before, i};
    
}


//CN i : 고유 번호 i를 가진 역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력
void constructCN(int i){
    
    //i의 다음 역, 즉 삭제할 당사자가누군지 저장
    int toDelete = train[i].after;
    
    cout << toDelete << endl;
    
    //삭제역 다음 역 저장
    int next = train[toDelete].after;
    
    //다음역의 이전 역으로 i로 변경
    train[next].before = i;
    
    //i의 다음역 변경
    train[i].after = next;
    
    //역 초기화
    train[toDelete] = {0,0};
}

//CP i : 고유 번호 i를 가진 역의 이전 역을 폐쇄하고 그 역의 고유 번호를 출력
void constructCP(int i){
    
    //i의 이전 역
    int toDelete = train[i].before;
    
    cout << toDelete << endl;
    
    //삭제역 이전 역 저장
    int before = train[toDelete].before;
    
    //이전역의 다음 역으로 i로 변경
    train[before].after = i;
    
    //i의 이전역 변경
    train[i].before = before;
    
    //역 초기화
    train[toDelete] = {0,0};
}


int main()
{
    //4 4
    cin >> N;
    // N개의 역이 원형으로 연결, 각 역은 고유 번호가 할당돼 있으며 역들의 고유 번호는 서로 다름
    // 특정 역의 다음 역은 시계 방향으로 인접한 역을 의미하고, 이전 역은 반시계 방향으로 인접한 역
    
    cin >> M;
    // M번의 공사
    // 공사 4가지
    // 1. 고유 번호 i를 가진 역의 다음 역의 고유 번호를 출력, 그 사이에 고유 번호 j인 역을 설립
    // 2. 고유 번호 i를 가진 역의 이전 역의 고유 번호를 출력, 그 사이에 고유 번호 j인 역을 설립
    // 3. 고유 번호 i를 가진 역의 다음 역을 폐쇄, 그 역의 고유 번호를 출력
    // 4. 고유 번호 i를 가진 역의 이전 역을 폐쇄, 그 역의 고유 번호를 출력
    
    //이미 설립한 역은 다시 설립하지 X,  폐쇄한 역은 다시 설립될 수 있음
    //폐쇄 작업은 현재 설립된 역이 2개 이상일 때만 들어옴
    
    int temp;
    int before = 0;
    int after = 0;
    
    //연결리스트의 첫 노드가 누구인지 저장
    int front, back;
    
    //첫 노드 추가
    cin >> temp; front = temp;
    train[temp] = {0, 0};
    before = temp;
    
    //2 7 3 5
    // N 역 값 입력 => 연결리스트 만들기
    for(int i = 1; i < N; i++){
        
        cin >> temp;
        
        //이전 node의 다음 값을 본인을 추가
        train[before].after = temp;
        
        //본인 node 생성 
        train[temp] = { before, 0};
        
        //그다음 노드를 위해 본인 노드정보 저장하기
        before = temp;
        
        //연결리스트의 마지막 노드일 경우 저장하기
        if(i == N -1) back = temp;
        
    }
    
    
    //맨 앞 친구의 앞 node를 맨 뒤 node의 값으로 선정
    train[front].before = back;
    
    //맨 뒤 친구의 뒤 node를 맨 앞 node의 값으로 선정
    train[back].after = front;
    

    
    
    // 공사 시작
    string construct;
    int i, j;
    
    for(int k = 0; k < M; k++){
        
        cin >> construct;
        cin >> i;
        
        //BN i j : 고유 번호 i를 가진 역의 다음 역의 고유 번호를 출력, 고유 번호 j인 역을 설립
        if(construct == "BN"){
            cin >> j;
            
            constructBN(i,j);
        }
        //BP i j : 고유 번호 i를 가진 역의 이전 역의 고유 번호를 출력, 고유 번호 j인 역을 설립
        else if(construct == "BP"){
            cin >> j;
            
            constructBP(i,j);
            
        }
        //CN i : 고유 번호 i를 가진 역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력
        else if(construct == "CN"){
            
            constructCN(i);
        }
        //CP i : 고유 번호 i를 가진 역의 이전 역을 폐쇄하고 그 역의 고유 번호를 출력
        else if(construct == "CP"){
        
            constructCP(i);
        }
        
        //print();
    }
    
    
    //BN 5 11 => 2 7 3 5 11       2
    //BP 3 6 => 2 7 6 3 5 11      7
    //CP 2 =>  2 7 6 3 5          11
    //CN 7 => 2 7 3 5             6

    return 0;
}

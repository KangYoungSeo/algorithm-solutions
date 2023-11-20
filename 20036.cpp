#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int N, K, R;

struct snow { int idx1; int idx2; int sum; };

bool cmp(const snow& a, const snow& b) {
	return a.sum < b.sum; // 눈사람 키 별로 정렬
}

int main(){
    
    vector<int> H;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp; cin >> temp;
        H.push_back(temp);
    }
    
    vector<snow> snowman;
    
    for(int i = 0; i < N -1; i++){
        for(int j = i + 1; j < N; j++){
            snowman.push_back({i,j,H[i] + H[j]});
        }
    }
    
    sort(snowman.begin(), snowman.end(), cmp);       //정렬
    

    int answer = 1000000001;
    
    for(int i = 0; i < snowman.size(); i++){
        
        snow choose1 = snowman[i];
        
        for (int j = i + 1; j < snowman.size(); j++) {
            
			snow choose2 = snowman[j];
			
			if (choose2.idx1 != choose1.idx1 && choose2.idx1 != choose1.idx2 && choose2.idx2 != choose1.idx1 && choose2.idx2 != choose1.idx2) {
				answer = min(answer, choose2.sum - choose1.sum);
				break;
			}
        }
    }
    
    cout << answer << endl;

    return 0;
}

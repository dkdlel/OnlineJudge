//
//  14501(퇴사).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/02.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int main(){
    
    int T[16], P[16], cache[16] = {0}; // T,P : input, cache : 이전 상담 돈들의 누적 값
    int N, ans = 0; fcin >> N;
    for(int i = 0 ; i < N ; i++) fcin >> T[i] >> P[i];
    
    for(int i = 0 ; i < N ; i++){
        if(i + T[i] < N + 1) // 상담이 끝나도 퇴사 날짜를 넘지 않을때
            cache[i + T[i]] = cache[i + T[i]] < P[i] + cache[i] ? P[i] + cache[i] : cache[i + T[i]]; // 기존의 돈의 값과 현재 돈의 최댓값(현재 돈 + 이전의 누적된 돈) 비교
        cache[i+1] = cache[i] < cache[i+1] ? cache[i+1] : cache[i]; // 누적값 최대 갱신
        ans = ans < cache[i+1] ? cache[i+1] : ans;
    }
    
    cout << ans << '\n';
    
    return 0;
}

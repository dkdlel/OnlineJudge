//
//  13458(시험 감독).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/15.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int main(){
    
    int arr[1000001];
    int N; fcin >> N;
    for(int i = 0 ; i < N ; i++) fcin >> arr[i];
    int main, sub; fcin >> main >> sub; // main : 주 감독, sub: 보조 감독
    long long ans = 0;
    
    for(int i = 0 ; i < N ; i++){
        ans++;
        arr[i] -= main;
        
        if(arr[i] <= 0) continue; // 총감독관 한명으로 해결
        if(arr[i] % sub) ans += arr[i] / sub + 1; // 나머지가 있으면 몫 +1
        else ans += arr[i] / sub; // 나머지 없으면 몫
    }
    cout << ans << '\n';
    return 0;
}

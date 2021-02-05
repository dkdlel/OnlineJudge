//
//  12865(평범한 베낭).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/03.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[101][2], cache[101][100001];

int main(){
    
    int N, K; fcin >> N >> K;
    for(int i = 1 ; i <= N ; i++) fcin >> arr[i][0] >> arr[i][1];
    
    for(int i = 1 ; i <= N ; i++){
        int weight = arr[i][0], value = arr[i][1];
        for(int j = 1 ; j <= K ; j++)
            cache[i][j] = weight <= j ? max(cache[i-1][j], value + cache[i-1][j-weight]) : cache[i-1][j];
        // 현재 무게를 넣을수 있으면 물건을 넣지않을때(i-1)과 물건을 넣을때(value + [i-1][j-weight])의 최대값 => 넣을때는 현재 무게를 빼고 계산
        // 현재 무게를 넣을수 없으면 직전의 무게
    }
    
    cout << cache[N][K] << '\n';
    
    return 0;
}

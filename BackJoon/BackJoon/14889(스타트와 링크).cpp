//
//  14889(스타트와 링크).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/11.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int N, halfN, idx = 0, ans = 987654321;
int arr[21][21], visited[21]; // input
deque<int> start, link; // team

void dfs(int cnt, int idx){
    
    if(cnt == halfN){ // 절반을 채웠으면
        int startSum = 0, linkSum = 0;
        link.clear();
        for(int i = 0 ; i < N ; i++){ // link 팀 구성
            if(!visited[i]) link.push_back(i);
        }
        
        for(int i = 0 ; i < halfN -1 ; i++){ // 선택된 팀의 합들 구하기
            int x, y;
            for(int j = i + 1 ; j < halfN ; j++){
                x = start[i]; y = start[j];
                startSum += arr[x][y] + arr[y][x];
                x = link[i]; y = link[j];
                linkSum += arr[x][y] + arr[y][x];
            }
        }
        
        ans = min(ans, abs(startSum - linkSum));
        
        return;
    }
    
    for(int i = idx ; i < N ; i++){
        if(!visited[i]){
            visited[i] = 1; // start 팀 구성
            start.push_back(i);
            dfs(cnt+1, i);
            start.pop_back(); // 원상복귀
            visited[i] = 0;
        }
    }
}

int main(){
    
    fcin >> N; halfN = N/2;
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < N ; j++) fcin >> arr[i][j];
    
    dfs(0,0);
    cout << ans << '\n';
    return 0;
}

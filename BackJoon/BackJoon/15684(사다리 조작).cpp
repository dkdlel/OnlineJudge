//
//  15684(사다리 조작).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/25.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define INF 987654321

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int N, M, H, ans = INF;
int arr[50][50], visited[50][50]; // [11][31]해서 틀려서 50으로 함

void Init(){
    fcin >> N >> M >> H;
    for(int i = 0 ; i < M ; i++){
        int a,b;
        fcin >> a >> b;
        visited[a-1][b-1] = 1; // 문제는 1부터 시작, 풀이는 0부터 시작
    }
}

int isPossible(){
    for(int i = 0 ; i < N ; i++){ // 시작점, 도착점
        int col = i;
        for(int j = 0 ; j < H ; j++){
            if(visited[j][col]) col++; // 내위치에 사다리가 있으면 오른쪽으로
            else if(visited[j][col-1]) col--; // 내위치 전위치에 사다리가 있으면 왼쪽으로
        }
        if(col != i) return 0; // 같은 row아님
    }
    return 1; // 같은 row
}

void dfs(int idx, int cnt){
    if(cnt > 3) return;
    if(isPossible()){
        ans = ans > cnt ? cnt : ans;
        return;
    }
    for(int i = idx ; i < H ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visited[i][j] || visited[i][j+1] || visited[i][j-1]) continue; // 사다리 연결돼있으면
            visited[i][j] = 1;
            dfs(i, cnt+1);
            visited[i][j] = 0;
        }
    }
}

int main(){
    
    Init();
    dfs(0,0);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}

//
//  14500(테트로미노).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/23.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[501][501], visited[501][501];
int dx[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dy[4] = { 0 , 0 , -1, 1};
int ex[4][4] = {{0,0,0,1},{0,1,1,2},{-1,0,0,0},{-1,0,0,1}}; // exception X(ㅗ)
int ey[4][4] = {{0,1,2,1},{0,0,1,0},{1,0,1,2},{1,0,1,1}}; // exception Y(ㅗ)
int N, M, ans = 0;

void dfs(int x, int y, int sum, int cnt){
    if(cnt == 4){ // ㅗ 제외한 나머지 모양 완성
        ans = ans < sum ? sum : ans;
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){
        int nextX = x + dx[i]; int nextY = y + dy[i];
        if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY]){ // 배열 범위를 초과하지 않고 방문하지 않은 위치
            visited[nextX][nextY] = 1; // 방문 처리하고
            dfs(nextX, nextY, sum + arr[nextX][nextY], cnt+1);
            visited[nextX][nextY] = 0; // 계산 끝이니 미방문 처리
        }
    }
}

void Exception(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        int sum = 0, cnt = 0;
        for(int j = 0 ; j < 4 ; j++){
            int nextX = x + ex[i][j]; int nextY = y + ey[i][j];
            if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M) { // 배열 범위 확인
                sum += arr[nextX][nextY];
                cnt++;
            }
            else break; // 배열 초과하면 도형 안만들어짐
        }
        if(cnt == 4) ans = ans < sum ? sum : ans; // 도형이 만들어졌을때 최대값 확인
    }
}

int main(){
    fcin >> N >> M;
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) fcin >> arr[i][j];
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            visited[i][j] = 1;
            dfs(i, j, arr[i][j], 1);
            visited[i][j] = 0;
            Exception(i, j); // 예외 확인
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}

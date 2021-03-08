//
//  14888(연산자 끼워넣기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/08.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define INF 987654321
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

vector<int> vec, oper, visited;
int N, maxAns = -INF, minAns = INF;

void Init(){
    fcin >> N;
    visited.resize(N-1, 0);
    for(int i = 0 ; i < N ; i++) {
        int num; fcin >> num;
        vec.push_back(num);
    }
    for(int i = 0 ; i < 4 ; i++){
        int num; fcin >> num;
        for(int j = 0 ; j < num ; j++) {
            oper.push_back(i);
        }
    }
}

int Calc(int type, int idx, int ans){
    
    switch(type){
        case PLUS:
            ans += vec[idx];
            break;
        case MINUS:
            ans -= vec[idx];
            break;
        case MUL:
            ans *= vec[idx];
            break;
        case DIV:
            if(ans < 0){
                ans *= -1;
                ans /= vec[idx];
                ans *= -1;
            }else{
                ans /= vec[idx];
            }
            break;
    }
    
    return ans;
}

void dfs(int idx, int cnt, int ans){ // idx : vec 현재의 index, cnt : 계산갯수, ans : 답
    int result = 0; // 이전의 값을 위한 변수
    if(cnt == N-1) {
        maxAns = ans < maxAns ? maxAns : ans;
        minAns = ans > minAns ? minAns : ans;
        return;
    }
    
    for(int i = 0 ; i < N-1 ; i++){
        if(!visited[i]){
            result = Calc(oper[i], idx, ans); // 수식 계산
            visited[i] = 1;
            dfs(idx+1, cnt+1, result);
            visited[i] = 0;
        }
    }
}

int main(){
    
    Init();
    
    dfs(1, 0, vec[0]);
    cout << maxAns << '\n' << minAns << '\n';
    
    return 0;
}

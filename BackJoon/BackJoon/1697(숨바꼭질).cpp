//
//  1697(숨바꼭질).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/28.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define MAX 100001

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int N, M;
int ans[MAX];
queue<int> q;

int BFS(){
    q.push(N);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == M) return ans[M];
        
        if(cur - 1 >= 0 && !ans[cur - 1]){ // 0이 아닐때
            ans[cur-1] = ans[cur] + 1;
            q.push(cur-1);
        }
        if(cur + 1 < MAX && !ans[cur + 1]){ // 경계값
            ans[cur+1] = ans[cur] + 1;
            q.push(cur+1);
        }
        if(cur * 2 < MAX && !ans[cur * 2]){
            ans[cur*2] = ans[cur] + 1;
            q.push(cur*2);
        }
    }
    return 0;
}

int main(){
    
    fcin >> N >> M;
    cout << BFS() << '\n';
    return 0;
}

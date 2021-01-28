//
//  1707(이분 그래프).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/28.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define RED 1
#define BLUE 2

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

vector< vector<int> > vec;
vector<int> visited;
int V, E;

void Init(){
    fcin >> V >> E;
    vec.clear(); vec.resize(V+1);
    visited.clear(); visited.resize(V+1);
    for(int i = 0 ; i < E ; i++){
        int v1, v2; fcin >> v1 >> v2;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    int color = RED; visited[root] = RED; // default
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if(visited[cur] == RED) color = BLUE;
        else if(visited[cur] == BLUE) color = RED;
        
        for(int i = 0 ; i < vec[cur].size() ; i++){
            if(!visited[vec[cur][i]]){
                visited[vec[cur][i]] = color;
                q.push(vec[cur][i]);
            }
        }
    }
}

int isBipartite(){
    for(int i = 1 ; i <= V; i++){
        for(int j = 0 ; j < vec[i].size() ; j++){
            if(visited[i] == visited[vec[i][j]]) return 0;
        }
    }
    return 1;
}

int main(){
    
    int testcase; fcin >> testcase;
    while(testcase--){
        Init();
        for(int i = 1 ; i <= V ; i++){
            if(!visited[i]) BFS(i);
        }
        isBipartite() ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}

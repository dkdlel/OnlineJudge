//
//  14499(주사위굴리기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/22.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int N, M, diceX, diceY, K;
int arr[21][21], order[1001], dice[7];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 , 0 };

void Init(){
    fcin >> N >> M >> diceX >> diceY >> K;
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) fcin >> arr[i][j];
    for(int i = 0 ; i < K ; i++) fcin >> order[i];
}

void Move(int dir){
    if(dir == EAST){
        int tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = tmp;
    } else if(dir == WEST){
        int tmp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = tmp;
    } else if(dir == NORTH){
        int tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = tmp;
    } else{
        int tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = tmp;
    }
}

void Copy(int dir){
    diceX += dx[dir]; diceY += dy[dir];
    
    if(0 <= diceX && diceX < N && 0 <= diceY && diceY < M) {
        Move(dir+1);
        if(arr[diceX][diceY]){ // 현재 자리에 숫자 있음
            dice[6] = arr[diceX][diceY];
            arr[diceX][diceY] = 0;
        }else{ // 현재 자리가 0
            arr[diceX][diceY] = dice[6];
        }
        cout << dice[1] << '\n';
    }
    else{
        diceX -= dx[dir];
        diceY -= dy[dir];
    }
}

void Sol(){
    for(int i = 0 ; i < K ; i++){
        if(order[i] == EAST) Copy(0);
        else if(order[i] == WEST) Copy(1);
        else if(order[i] == NORTH) Copy(2);
        else Copy(3);
    }
}

int main(){
    
    Init();
    Sol();
    return 0;
}

//
//  1015.cpp
//  BackJoon
//
//  Created by  JeJn on 2020/06/29.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

vector<int> A,P;

int main(){

    int N; cin >> N;
    for(int i = 0 ; i < N ; i++){
        int num; cin >> num;
        A.push_back(num);
    }
    P.assign(N, -1);
    for(int i = 0 ; i < N ; i++){
        P[i] = 0;
        for(int j = 0 ; j < N ; j++){ // 작은 숫자의 갯수 찾기
            if(A[i] > A[j]) P[i]++;
        }

        while (1) { // 중복수 예외 찾기
            bool flag = false;
            for (int k = 0; k < N; k++) {
                if (i != k && P[i] == P[k]) {
                    P[i]++;
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }

    for(int i = 0 ; i < N ; i++)
        cout << P[i] << " ";
    
    cout << "\n";
    return 0;
}

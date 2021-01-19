//
//  2005(파스칼삼각형).cpp
//  SWExpert
//
//  Created by  JeJn on 2021/01/19.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 11

ifstream fcin("/Users/jejn/Desktop/SWExpert/input.txt");
ofstream fcout("/Users/jejn/Desktop/SWExpert/output.txt");

int main(){

    int arr[MAX][MAX];
    int testcase = 0; fcin >> testcase;

    for(int t = 1 ; t <= testcase ; t++){
        cout << '#' << t << '\n';
        int num; fcin >> num;
        for(int i = 0 ; i <= num ; i++) for(int j = 0 ; j <= num ; j++) arr[i][j] = 0;
        arr[1][1] = 1; cout << "1\n";
        for(int i = 2 ; i <= num ; i++){
            for(int j = 1 ; j <= i ; j++){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

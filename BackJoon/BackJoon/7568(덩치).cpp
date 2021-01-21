//
//  7568(덩치).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/21.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct info {
    int x, y, rank=1;
}info;

bool compare(info a, info b) { return a.x < b.x; }
int main() {

    int T;
    cin >> T;
    vector <info> V;
    vector <info> tmp;
    V.resize(T); tmp.resize(T);

    for (int i = 0; i < T; i++) cin >> V[i].x >> V[i].y;


    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (V[i].x < V[j].x && V[i].y < V[j].y) V[i].rank++;
        }
    }

    for (int i = 0; i < T; i++) cout << V[i].rank << " ";
    
    cout << "\n";
    return 0;
}

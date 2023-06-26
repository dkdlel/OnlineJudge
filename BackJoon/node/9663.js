const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [N] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);
const chess = [];
let ans = 0;

function isPossible(row){
    for(let i = 0 ; i < row ; i++){
        const cur_chess = chess[row];
        const prev_chess = chess[i];
        if(cur_chess === prev_chess || (row - i === Math.abs(cur_chess - prev_chess))){
            return false;
        }
    }
    return true;
}

function Sol(row){

    if(row >= N){
        ans++;
        return;
    }

    for(let col = 0 ; col < N ; col++){
        chess[row] = col;
        if(isPossible(row)){
            Sol(row + 1);
        }
    }
}

Sol(0);
console.log(ans);
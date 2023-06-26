const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);
let arr = [];
let ans = '';

function Sol(){

    if(arr.length === M){
        ans += arr.join(' ') + '\n';
        return;
    }

    for(let i = 1 ; i <= N ; i++){
        arr.push(i);
        Sol(i);
        arr.pop();
    }

}

Sol();

console.log(ans.trim());
const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);
const visited = new Array(M + 1).fill(false);
let arr = [];
let ans = '';

function Sol(start){

    if(arr.length === M){
        ans += arr.join(' ') + '\n';
    }

    for(let i = start ; i <= N ; i++){
        if(!visited[i]){
            visited[i] = true;
            arr.push(i);
            Sol(i);
            arr.pop();
            visited[i] = false;
        }
    }

}

Sol(1);

console.log(ans.trim());
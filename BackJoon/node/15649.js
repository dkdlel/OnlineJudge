const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const visited = new Array(N+1).fill(false);
const arr = [];
let ans = '';

function Sol(){

    if(arr.length === M){
        ans += arr.join(' ') + '\n';
        return;
    }

    for(let i = 1 ; i <= N ; i++){
        if(!visited[i]){
            visited[i] = true;
            arr.push(i);
            Sol();
            arr.pop();
            visited[i] = false;
        }
    }
}

Sol();
console.log(ans);
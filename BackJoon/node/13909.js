const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [num] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

let ans = 0;

for(let i = 1 ; i * i <= num ; i++){
    ans++;
}

console.log(ans);
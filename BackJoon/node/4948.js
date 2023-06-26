const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const max_num = Math.max(...f_input);
let arr = new Array(max_num * 2).fill(0);
arr[0] = arr[1] = 1;

for(let i = 2; i <= 2 * max_num; i++){

    if(arr[i] === 1) continue;

    for(let j = i * 2 ; j <= 2 * max_num ; j += i){
        arr[j] = 1;
    }
}

f_input.forEach((input) => {

    if(input === 0) return false;

    let ans = 0;
    for(let i = input + 1 ; i <= 2 * input ; i++){
        if(arr[i] === 0){
            ans++;
        }
    }
    console.log(ans);
});
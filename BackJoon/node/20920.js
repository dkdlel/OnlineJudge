const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/);

const mapping = new Map();
M = parseInt(M);

f_input.filter(ele => ele.length >= M).forEach((input) => {
    if(mapping.has(input)){
        let tmp = mapping.get(input);
        mapping.set(input, ++tmp);
    }else{
        mapping.set(input, 0);
    }
});

const arr = [...mapping];

arr.sort((a,b) => {
    if(a[1] === b[1]){
        if(a[0].length === b[0].length){
            return a[0] < b[0] ? -1 : 1;
        }
        return b[0].length - a[0].length;
    }
    return b[1] - a[1];
});

let ans = '';
arr.forEach((ele) => ans += ele[0] + '\n');
console.log(ans);
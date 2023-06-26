const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);
let zeros = [];
let arr = [];
let flag = false;

for(let i = 0 ; i < 81 ; i++){
    if(f_input[i] === 0){
        zeros.push(i);
    }
}

solution();

function solution(){

    if(arr.length === zeros.length){
        let row = '';
        for(let i = 0 ; i < 81 ; i++){
            row += f_input[i] + ' ';
            if(i % 9 === 8){
                console.log(row);
                row = '';
            }
        }
        flag = true;
        return;
    }

    const idx = arr.length;
    for(let i = 1 ; i <= 9 ; i++){
        const zero_idx = zeros[idx];
        // if(!flag && Row(zero_idx, i) && Col(zero_idx, i) && Block(zero_idx, i)){
        if(!flag && RowCol(zero_idx, i) && Block(zero_idx, i)){
            f_input[zero_idx] = i;
            arr.push(i);
            solution();
            arr.pop();
            f_input[zero_idx] = 0;
        }
    }
}

function RowCol(idx, cur){
    let row = parseInt(idx / 9) * 9;
    let col = parseInt(idx % 9);

    for(let i = 0 ; i < 9 ; i++){
        let row_idx = row + i;
        let col_idx = i * 9 + col;
        if(cur === f_input[row_idx] || cur === f_input[col_idx]){
            return false;
        }
    }

    return true;
}

function Block(idx, cur){
    let x = parseInt((idx / 27)) * 27;
    let y = parseInt((idx % 9) / 3) * 3;
    let start = x + y;

    for(let i = start ; i < start + 27 ; i += 9){
        for(let j = i ; j < i + 3 ; j++){
            if(cur === f_input[j]){
                return false;
            }
        }
    }

    return true;
}

// function Row(idx, cur){
//     let start = parseInt(idx / 9) * 9;
    
//     for(let i = start ; i < start + 9 ; i++){
//         if(cur === f_input[i]) {
//             return false;
//         }
//     }

//     return true;
// }

// function Col(idx, cur){
//     let start = parseInt(idx % 9);

//     for(let i = start ; i < 81 ; i += 9){
//         if(cur === f_input[i]) {
//             return false;
//         }
//     }

//     return true;
// }
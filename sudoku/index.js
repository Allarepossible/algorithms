var puzzle = [
      [5,3,0,0,7,0,0,0,0],
      [6,0,0,1,9,5,0,0,0],
      [0,9,8,0,0,0,0,6,0],
      [8,0,0,0,6,0,0,0,3],
      [4,0,0,8,0,3,0,0,1],
      [7,0,0,0,2,0,0,0,6],
      [0,6,0,0,0,0,2,8,0],
      [0,0,0,4,1,9,0,0,5],
      [0,0,0,0,8,0,0,7,9]];

    var solution = [
      [5,3,4,6,7,8,9,1,2],
      [6,7,2,1,9,5,3,4,8],
      [1,9,8,3,4,2,5,6,7],
      [8,5,9,7,6,1,4,2,3],
      [4,2,6,8,5,3,7,9,1],
      [7,1,3,9,2,4,8,5,6],
      [9,6,1,5,3,7,2,8,4],
      [2,8,7,4,1,9,6,3,5],
      [3,4,5,2,8,6,1,7,9]];

const inRow = (x, y, puzzle) => puzzle[x].filter(i => i !== 0);
const inColumn = (x, y, puzzle) => puzzle.map(row => row[y]).filter(i => i !== 0);
const inCube = (x, y, puzzle) => {
  let res = [];
  let xC = Math.floor(x/3) * 3 + 1;
  let yC = Math.floor(y/3) * 3 + 1;
  for (let i = -1; i < 2; i++){
    for (let j = -1; j < 2; j++){
        let num = puzzle[xC+i][yC+j];
        if (num) {
          res.push(num);
        }
    }
  }
  return res;
}
const findRest = arr => {
  let set = new Set(arr);
  let all = new Set([...Array(10).keys()].slice(1));
  for (let i of set) {
    if (all.has(i)) {
      all.delete(i)
    }
  }
  return [...all]
}
const isPuzzleResolved = p => p.filter(r => r.reduce((a,i)=>a+i,0)===45).length === 9;
    
function sudoku(puzzle) {
  let p = puzzle;
  for (let i = 0; i < 9; i++){
    for (let j = 0; j < 9; j++){
      if (!p[i][j]) {
        let possibleVariants = findRest([...inRow(i,j,p), ...inColumn(i,j,p), ...inCube(i,j,p)]); 
        
        if (possibleVariants.length === 1) {
          p[i][j] = possibleVariants[0];
        }
      }
    }
  }
  if (isPuzzleResolved(p)) {
    return p;
  } else {
    return sudoku(p);
  }
}

console.log(sudoku(puzzle))

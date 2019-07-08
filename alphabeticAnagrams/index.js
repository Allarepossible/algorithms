const fact = n => {
  let res = 1;
  let i = 1;
  while (i <= n) {
    res *= i;
    i++;
  }
  return res;
};

const stringToMap = str => str.split('').reduce((acc,i) => {
  acc[i] = acc[i] ? acc[i] + 1 : 1;
  return acc;
}, {});

const countOfRepeat = arr => arr.reduce((acc, i) => (i < 3 ? acc * i : acc * fact(i)), 1);

const listPosition = word => {
  let sorted = [];
  let res = 0;
  let set = new Set(word.split(''))
  
  if (set.size === word.length) {
    sorted = word.split('').sort();
    for (let i = 0; i < word.length; i++) {
      let index = sorted.indexOf(word[i])
    
      res += index * fact(set.size - 1 - i)
      sorted = [...sorted.slice(0, index), ...sorted.slice(index+1)];
    }
  
    return res + 1;
  } else {
    let w = word;
    for (let i = 0; i < word.length; i++) {
      let map = stringToMap(w);
      sorted = Object.keys(map).sort();
      let index = sorted.indexOf(w[i])
      let rest = [...sorted.slice(0, index), ...sorted.slice(index+1)].map(i => map[i]);
      console.log([word[i], index,sorted, map, rest])
//       if (map[word[i]] === 1) {
//         delete map[word[i]];
//       } else {
//         map[word[i]]--;
//       }
//       res += index * fact(sorted.length - 1 - i) / rest;
//       console.log([countOfRepeat(Object.values(map)), res])
      w = w.slice(1, w.length);
    }
    
    return res
  }
  
}






//'QUESTION' : 24572
//'BOOKKEEPER' : 10743


console.log(listPosition('BOOKKEEPER'))




console.log(listPosition('BOOKKEEPER'))

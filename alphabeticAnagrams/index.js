const mem = fn => {
  const cache = {};
  return n => {
    if (!cache[n]) {
      cache[n] = fn(n);
    }
  
    return cache[n];
  }
}
const fact = mem(n => !n ? 1 : n * fact(n-1));

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
    let map = stringToMap(word);
    
    for (let i = 0; i < word.length; i++) {
      sorted = Object.keys(map).sort();
      let index = sorted.indexOf(word[i])
      let rest = fact(map[word[i]]);
      if (map[word[i]] === 1) {
        delete map[word[i]];
      } else {
        map[word[i]]--;
      }
      res += index * fact(sorted.length - 1 - i) / rest;
    }
    
    return res
  }
  
}

const stringToMap = str => str.split('').reduce((acc,i) => {
  acc[i] = acc[i] ? acc[i] + 1 : 1;
  return acc;
}, {})

const countOfRepeat = arr => arr.reduce((acc, i) => (i < 3 ? acc * i : acc * fact(i)), 1)



//'QUESTION' : 24572
//'BOOKKEEPER' : 10743


console.log(listPosition('BOOKKEEPER'))

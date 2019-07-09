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
  let w = word;
  
  while (w.length > 0) {
    let map = stringToMap(w);
    sorted = Object.keys(map).sort();
    let index = sorted.indexOf(w[0])
    let rest = sorted.map(i => map[i]);

    for (var j = 0; j < index; j++) {
      res += fact(w.length - 1) * rest[j] / countOfRepeat(rest);
    }

    w = w.slice(1, w.length);
  }

  return res + 1;
  
}


//'QUESTION' : 24572
//'BOOKKEEPER' : 10743

console.log(listPosition('QUESTION'))
console.log(listPosition('BOOKKEEPER'))

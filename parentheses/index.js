const good = '()[()]{()()[]}';
const bad = '[(]{})';

const all = ['{}', '[]', '()'];

const hasOneBracket = (str, a) => a.some(br => str.indexOf(br) > 0);
const isGoodSequence = str => {
  let result = "It's a bad sequence"
  if (str.length % 2 === 1) {
    return result;
  };
  
  let newStr = str;
  for (let i of all) {
    let posOfBracket = newStr.indexOf(i);
    while (posOfBracket > -1) {
      newStr = newStr.slice(0, posOfBracket) + newStr.slice(posOfBracket + 2);

      posOfBracket = newStr.indexOf(i);
    } 
  }
  if (newStr.length > 0) {
    if (hasOneBracket(str, all)) {
      return isGoodSequence(newStr)
    }
  } else {
    result = "It's a good sequence";
  }
  return result;
}



console.log(isGoodSequence(good))
console.log(isGoodSequence(bad))

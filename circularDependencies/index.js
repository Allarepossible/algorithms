const Dependencies = {
    '0': ['1', '2', '3', '4'],
    '1': ['5', '6'],
    '5': ['s','7'],
    '3': ['6', '2'],
    '6': [], 
    '7': ['8', '4'],
    '4': ['9'],
    '9': ['5', '7']
}


// Вводим понятие цепочки. Идем по дереву вниз и добавляем в нее связанные узлы, 
// если в цепочке один и тот же элемент встречается дважды - у нас зацикленность!
const notCircularDependencies = (deps) => {
  let chain = [];
  for (let item in deps) {
      chain.push(item);

      const result = buildChain(chain, deps[item], deps);

      if (result) {
        return 'circular dependensies'
      }
  }
  return 'no'
};

const buildChain = (chain, array, deps) => {
  let end;
    while (array.length > 0) {
      let elem = array.shift();
      
      if (chain.indexOf(elem) > -1) {
        return true;
      } else {
        
        chain.push(elem);
        
        if (deps[elem]) {
          end = buildChain(chain, deps[elem], deps);
        } else {
          chain.pop();
        }
      }
    }
  if (end === true) {
    return end;
  } 
  
  chain.pop();
}


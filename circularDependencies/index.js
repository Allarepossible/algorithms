const Dependencies = {
    'index.js': ['foo.js', 'bar.js', 'firts.js', 'style.css'],
    'foo.js': ['bar1.js'],
    'bar.js': ['index', 's','foo3.js'],
    'bar1.js': ['first.js'],
    'first.js': ['second.js', 'bar.js', 'index.js'],
    'second.js': [], 
}


// Вводим понятие цепочки. Идем по дереву вниз и добавляем в нее связанные узлы, 
// если в цепочке один и тот же элемент встречается дважды - у нас зацикленность!
const notCircularDependencies = (deps) => {
  let chain = [];
  for (let item in deps) {
      chain.push(item);
    
      return buildChain(chain, deps[item], deps);
  }
  
};

const buildChain = (chain, array, deps) => {
    while (array.length > 0) {
      let elem = array.shift();
      
      if (chain.indexOf(elem) > -1) {
        return false;
      } else {
        chain.push(elem);
        if (deps[elem] && deps[elem].length > 0) {
          return buildChain(chain, deps[elem], deps);
        } else {
          chain.pop();
        }
      }
    }
  chain.pop();
}

console.log(notCircularDependencies(Dependencies))

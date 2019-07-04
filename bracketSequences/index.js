const sequences = (current, open, close, n) => {
  if (current.length === 2 * n) {
    if (open === close) {
      console.log(current);
    }
    return;
  }
  if (open <= n) {
    sequences(current + '(', open + 1, close, n);
  }
  if (close < open) {
    sequences(current + ')', open, close + 1, n);
  }
  
}


const findSequences = n => sequences('', 0, 0, n);

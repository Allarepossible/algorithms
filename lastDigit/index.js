const findLastInPow = (s1, s2) => +s2 === 0 ? 1: Math.pow(+s1.slice(-1), +s2.slice(-2)%4 + 4);

const lastDigit = (as) => {
    as = as.map(i=>String(i));
    if (as.length === 0) return 1;
    if (as.length === 1) return as[0] % 10;
    if (as.length === 2) {
        return findLastInPow(as[0], as[1]) % 10;
    } else {
        let res = as.splice(-2);
        let p = +res[0] + +res[1] < 10 ? Math.pow(+res[0], +res[1]) : findLastInPow(res[0],res[1])+20;
        let pow = res[1] === '0' || res[0] === '1' ? 1 : p;
        as.push(String(pow%100))
        return lastDigit(as);
    }
}

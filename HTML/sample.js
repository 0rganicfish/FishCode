var fact = (x) => (x ? x * fact(x - 1) : 1);

console.log(fact(5));

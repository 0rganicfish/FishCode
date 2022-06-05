function hello(str: string): void {
  if (!str) return;
  console.log('hello', str);
}

const mie = 'miemie',
  strs = [mie, 'mie', '233'];

strs.forEach((ele) => {
  hello(ele);
});

interface UserInfo {
  id: string;
  name: string;
  age?: number;
  friends?: UserInfo[];
}

const fish: UserInfo = {
  id: '233',
  name: 'fish',
  //   age: 23,
  friends: [
    {
      id: '232',
      name: 'fish1',
    },
    {
      id: '234',
      name: 'fish2',
    },
  ],
};

function sum(a: number, b: number, f?: boolean) {
  if (!f) return;
  return a + b;
}
console.log(sum(1, 2, false));

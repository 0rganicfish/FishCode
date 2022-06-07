const mie = {
    name: "mie",
    money: 12,
    getMoney(num = 0) {
      this.money += num;
    },
  },
  fish = {
    name: "fish",
    money: 10,
  };

mie.getMoney.call(fish, 100);
console.log(fish.money);

const data = [
  { id: "01", value: 123 },
  { id: "02", value: 234 },
];

const tmp = (data) =>
  `<table>${data
    .map(
      (addr) => `
  <tr><td>${addr.id}</td><td>${addr.value}</td></tr>`
    )
    .join("")}
</table>`;

console.log(tmp(data));

const os = require("os"),
  ips = Object.values(os.networkInterfaces())[0];
let ans = ips.find((ele) => ele.family === "IPv4").address;

console.log(ans);

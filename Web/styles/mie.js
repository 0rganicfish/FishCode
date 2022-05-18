// const http = require("http");

// const hostname = "127.0.0.1";
// const port = 3000;

// const server = http.createServer((req, res) => {
//   res.statusCode = 200;
//   res.setHeader("Content-Type", "text/plain");
//   res.end("Hello World\n");
// });

// server.listen(port, hostname, () => {
//   console.log(`Server running at http://${hostname}:${port}/`);
// });

const fuzzyFind = (str, list) => {
  const reg = new RegExp("(.*)(" + str.split("").join(")(.*)(") + ")(.*)");
  let ans = [];
  list.forEach((ele) => {
    if (reg.test(ele)) ans.push(ele);
  });
  return ans;
};

const obj = {
  course: { id: ["21123"], name: [], type: [] },
  stuInfo: {
    id: [
      "fishroot",
      "teacheroot",
      "2114100106",
      "2114100114",
      "2114100128",
      "2114100306",
      "2114100314",
      "2114100328",
    ],
    major: [],
    name: [],
    sex: ["男", "女"],
  },
};

let ans = [],
  inp = "21141003";

for (const ele of Object.values(obj)) {
  for (const value of Object.values(ele)) {
    ans = ans.concat(fuzzyFind(inp, value));
  }
}

console.log(ans);

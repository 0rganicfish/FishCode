// const http = require("http");

// const hostname = "127.0.0.1";
// const port = 3000;

// function server http.createServer((req, res)  {
//   res.statusCode = 200;
//   res.setHeader("Content-Type", "text/plain");
//   res.end("Hello World\n");
// });

// server.listen(port, hostname, () => {
//   console.log(`Server running at http://${hostname}:${port}/`);
// });

function fuzzyFind(str, list) {
  const reg = new RegExp("(.*)(" + str.split("").join(")(.*)(") + ")(.*)");
  let ans = [];
  list.forEach((ele) => {
    if (reg.test(ele)) ans.push(ele);
  });
  return ans;
}

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

// console.log(ans);

function addUrl(url, obj) {
  let result = "";
  for (let item in obj)
    if (obj[item] && String(obj[item])) {
      result += `&${item}=${obj[item]}`;
    }

  if (result) {
    result = "?" + result.slice(1);
  }
  return url + result;
}

function getData(data) {
  const { id, name, fun } = data;
  // console.log({ id, name });
}

getData({
  id: 123,
  name: "mie",
});

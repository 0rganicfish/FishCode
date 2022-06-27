/*
const axios = require("axios");

const ajax = axios.create({
  baseURL: "http://localhost:1026/api/",
  timeout: 2333,
});

 // const Url = "https://api.bilibili.com/x/space/acc/info?mid=" + uid;

ajax
  .get("getUser")
  .then((res) => {
    const data = res.data;
    console.log(data);
  })
  .catch(function (error) {
    if (error.response) {
      // 请求成功发出且服务器也响应了状态码，但状态代码超出了 2xx 的范围
      console.log(error.response.data);
      console.log(error.response.status);
      console.log(error.response.headers);
    } else if (error.request) {
      // 请求已经成功发起，但没有收到响应
      // `error.request` 在浏览器中是 XMLHttpRequest 的实例，
      // 而在node.js中是 http.ClientRequest 的实例
      console.log(error.request);
    } else {
      // 发送请求时出了点问题
      console.log("Error", error.message);
    }
    console.log(error.config);
  });
*/

/*
const express = require("express");
const user = require("./static/fishData.json");

const app = express(),
  port = 3000;

app.get("/api/user", (req, res) => {
  res.json(user);
});

app.listen(port, () => {
  console.log(`http://localhost:${port}/fish)`);
});
*/

/*
const ajax = axios.create({
  baseURL: "http://localhost:1023/api/",
  timeout: 2333,
});
ajax.post("/users", { id: 233 });
*/

const axios = require("axios");

function getList(url) {
  const ans = [];

  axios.get(url).then((res) => {
    const regex =
      /http:\/\/www\.huizhou\.gov\.cn\/zwzt\/fkyq\/zxyq\/content\/post_\d+.html/gm;

    res.data.match(regex).forEach((ele) => {
      axios.get(ele).then((res1) => {
        if (!res1.data.match(/惠州市无新增新冠肺炎确诊病例和无症状感染者。/g))
          ans.push(res1.data.match(/(?<=发布时间：)\d{4}-\d{2}-\d{2}/gm)[0]);
      });
    });
  });

  return new Promise((resolve, rejects) => {
    setTimeout(() => {
      resolve(ans);
    }, 2000);
  });
}

let ans = [],
  len = 4,
  url = "http://www.huizhou.gov.cn/zwzt/fkyq/zxyq/index";

for (let i = 1; i <= len; ++i) {
  getList(url + (i > 1 ? `_${i}` : "") + ".html").then((res) => {
    ans = [...ans, ...res];
  });
}

setTimeout(() => {
  ans.sort((a, b) => Date.parse(a) - Date.parse(b));

  console.log(
    `最近 ${len * 20}天 内有 ${
      len * 20 - ans.length
    }天 报告为 “惠州市无新增新冠肺炎确诊病例和无症状感染者。”`
  );
  console.log(ans);
}, len * 2000);

// const dates = [];
// for (let i = 0; i < 20 * 4; ++i) {
//   const time = new Date(new Date() - i * 24 * 3600 * 1000);
//   dates.push(time.toJSON().slice(0, 10));
// }

// const arr = dates.filter((ele) => {
//   return !ans.includes(ele);
// });

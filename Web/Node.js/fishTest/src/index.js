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

const hh = require("./api/mie");

console.log(hh.hh);

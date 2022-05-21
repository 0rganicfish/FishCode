function userInfo(uid, files) {
  const https = require("https"),
    fs = require("fs"),
    Url = "https://api.bilibili.com/x/space/acc/info?mid=" + uid;

  https
    .get(Url, (res) => {
      let data = "";

      res.on("data", (chunk) => {
        data += chunk;
      });

      res.on("end", () => {
        fs.writeFile(files, data, (err) => {
          if (err) throw err;
          console.log("JSON data is saved.");
        });
        // let json = JSON.parse(data);
        // console.log(json);
      });
    })
    .on("error", () => console.log("获取数据出错!"));
}

// userInfo("259486090", "Web/user.json");

function weiboHot() {
  const url = "https://weibo.com/ajax/side/hotSearch",
    fs = require("fs"),
    https = require("https");

  https
    .get(url, (res) => {
      let data = "";
      res.on("data", (t) => {
        data += t;
      });

      res.on("end", () => {
        const json = JSON.parse(data).data.realtime,
          ans = [];
        json.forEach((ele) => {
          ans.push(ele.word);
        });
        console.log(ans);
      });
    })
    .on("error", (e) => console.log(e));
}

weiboHot();

import { get } from "https";
import { writeFile } from "fs";

export function userInfo(uid, files) {
  const Url = "https://api.bilibili.com/x/space/acc/info?mid=" + uid;

  get(Url, (res) => {
    let data = "";

    res.on("data", (chunk) => {
      data += chunk;
    });

    res.on("end", () => {
      writeFile(files, data, (err) => {
        if (err) throw err;
        console.log("JSON data is saved.");
      });
      console.log(JSON.parse(data));
    });
  }).on("error", () => console.log("获取数据出错!"));
}

userInfo("259486090", "Web/user.json");

export function weiboHot() {
  const url = "https://weibo.com/ajax/side/hotSearch";

  get(url, (res) => {
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
  }).on("error", (e) => console.log(e));
}

// weiboHot();

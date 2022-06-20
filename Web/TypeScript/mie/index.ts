import { get } from "https";

function weiboHot() {
  const url = "https://weibo.com/ajax/side/hotSearch";

  interface hotWord {
    word: string;
  }

  get(url, (res) => {
    let data = "";
    res.on("data", (t) => {
      data += t;
    });

    res.on("end", () => {
      const json: [] = JSON.parse(data).data.realtime,
        ans: string[] = [];
      json.forEach((ele: hotWord) => {
        ans.push(ele.word);
      });
      console.log(ans);
    });
  }).on("error", (e) => console.log(e));
}

weiboHot();

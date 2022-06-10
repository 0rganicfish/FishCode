const os = require("os"),
  ips = Object.values(os.networkInterfaces())[0];
let ans = ips.find((ele) => ele.family === "IPv4").address;
// console.log(ans);

{
  const http = require("https"),
    fs = require("fs"),
    url = "https://innei.ren/feed",
    files = "Web/rss.xml";

  http
    .get(url, (res) => {
      let data = "";

      res.on("data", (chunk) => {
        data += chunk;
      });

      res.on("end", () => {
        fs.writeFile(files, data, (err) => {
          if (err) throw err;
          console.log("RSS data is saved.");
        });
      });
    })
    .on("error", (e) => console.log(e));
}

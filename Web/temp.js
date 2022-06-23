const { rejects } = require("assert");
/*
* 
{
  const os = require("os"),
    ips = Object.values(os.networkInterfaces())[0];
  let ans = ips.find((ele) => ele.family === "IPv4").address;
  console.log(`http://${ans}:2333/web`);
} 
*/

/*
* 
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
*/

/*
 * 
{
  function getApi(success, delay = 1000) {
    const mes = {
      suc: "success",
      fail: "fail",
    };
    return new Promise((resolve, rejects) => {
      console.log("getting getApi");
      setTimeout(() => {
        success ? resolve(mes.suc) : rejects(mes.fail);
      }, delay);
    });
  }

  async function action() {
    try {
      const mes = await getApi(true);
      console.log("async got!", mes);
    } catch (e) {
      console.log("async ??", e);
    }
  }

  getApi(true)
    .then((mes) => {
      console.log("then got!", mes);
    })
    .catch((mes) => {
      console.log("catch ??", mes);
    });
  action();

  (async () => {
    const a = await getApi(1, 2000); //运行后2秒得到a
    console.log(a);
    const b = await getApi(22, 5000); //在得到a的5秒后才得到b
    console.log(b);

    setTimeout(() => {
      console.log(a + b); //得到b的1秒后才有a+b
    }, 1000);
  })();
}
 */

/*
 *  */
{
  const path = require("path");
  const dbPath = path.join(__dirname, "../db.json");

  console.log(dbPath);
}

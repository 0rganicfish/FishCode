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
  const str = [
    `2022-6-25广东省新冠肺炎疫情情况
发布时间：2022-06-25 17:17:30 来源：惠州市卫生健康局

浏览字号：大｜中｜小

　　6-240-24时，全省新增本土确诊病例5例（其中1例为无症状感染者转确诊）和本土无症状感染者2例，均为深圳报告。全省新增出院1例（为境外输入），目前在院86例（境外输入79例）；新增解除医学观察无症状感染者26例（均为境外输入），尚在医学观察无症状感染者191例（境外输入179例）。

　　全省新增境外输入确诊病例9例（其中2例为无症状感染者转确诊），广州报告6例，2例来自泰国，其余4例分别来自加拿大、澳大利亚、新加坡和孟加拉国；珠海报告3例，均来自中国澳门。新增境外输入无症状感染者23例，广州报告14例，6例来自泰国，3例来自本，其余5例分别来自加拿大、澳大利亚、新加坡、孟加拉国和埃塞俄比亚；深圳报告2例，分别来自菲律宾和刚果（金）；佛山报告4例，3例来自柬埔寨，1例来自韩国；东莞报告3例，分别来自塞尔维亚、印度和新加坡。

　　截至6-2424时，全省累计报告新冠肺炎阳性感染者15834例（境外输入10349例），其中确诊病例7417例（境外输入4015例），无症状感染者8417例（境外输入6334例）。

　　惠州市无新增新冠肺炎确诊病例和无症状感染者。`,
    `2022-6-22广东省新冠肺炎疫情情况
发布时间：2022-06-25 17:17:30 来源：惠州市卫生健康局

浏览字号：大｜中｜小

　　6-240-24时，全省新增本土确诊病例5例（其中1例为无症状感染者转确诊）和本土无症状感染者2例，均为深圳报告。全省新增出院1例（为境外输入），目前在院86例（境外输入79例）；新增解除医学观察无症状感染者26例（均为境外输入），尚在医学观察无症状感染者191例（境外输入179例）。

　　全省新增境外输入确诊病例9例（其中2例为无症状感染者转确诊），广州报告6例，2例来自泰国，其余4例分别来自加拿大、澳大利亚、新加坡和孟加拉国；珠海报告3例，均来自中国澳门。新增境外输入无症状感染者23例，广州报告14例，6例来自泰国，3例来自本，其余5例分别来自加拿大、澳大利亚、新加坡、孟加拉国和埃塞俄比亚；深圳报告2例，分别来自菲律宾和刚果（金）；佛山报告4例，3例来自柬埔寨，1例来自韩国；东莞报告3例，分别来自塞尔维亚、印度和新加坡。

　　截至6-2424时，全省累计报告新冠肺炎阳性感染者15834例（境外输入10349例），其中确诊病例7417例（境外输入4015例），无症状感染者8417例（境外输入6334例）。

　　惠州市无新增新冠肺炎确诊病例和无症状感染者。`,
  ];

  const ans = [];

  function f(ele) {
    if (ele.match(/惠州市无新增新冠肺炎确诊病例和无症状感染者。/g)) {
      ans.push(ele.match(/2022-\d-\d+/g)[0]);
    }
  }

  // str.forEach((ele) => {
  //   setTimeout(f);
  // });

  // console.log(ans);
}

{
  const arr = [
    "2022-06-10",
    "2022-06-11",
    "2022-06-12",
    "2022-06-13",
    "2022-06-14",
    "2022-06-15",
    "2022-06-16",
  ];

  const dates = [];
  for (let i = 0; i < 20; ++i) {
    const time = new Date(new Date() - i * 24 * 3600 * 1000);
    dates.push(time.toJSON().slice(0, 10));
  }

  const ans = dates.filter((ele) => {
    return !arr.includes(ele);
  });
  console.log( ans);
}

const http = require("http"),
  c = require("child_process");

/**
 * Get ip(v4) address
 * @return {String} the ipv4 address or 'localhost'
 */
function getIPV4() {
  const os = require("os"),
    ips = os.networkInterfaces().WLAN;
  return ips[3].address || "localhost";
}
const ivp4 = getIPV4();

function run() {
  http
    .createServer(function (req, res) {
      res.writeHead(200, { "Content-Type": "text/plain" });
      // console.log(req);
      res.end("mie!\n"); //
    })
    .listen(80);

  console.log("Server running at http://" + ivp4 + "/mie");
  // 使用默认浏览器打开
  c.exec("start http://" + ivp4 + "/mie");
}

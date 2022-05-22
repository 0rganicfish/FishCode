const http = require("http"),
  c = require("child_process"),
  os = require("os");

/**
 * Get ip(v4) address
 * @return {String} the ipv4 address or 'localhost'
 */
let getIPAddress = function () {
  let ifaces = os.networkInterfaces(),
    ip = "";

  for (let dev in ifaces) {
    ifaces[dev].forEach(function (details) {
      if (ip === "" && details.family === "IPv4" && !details.internal) {
        ip = details.address;
        return;
      }
    });
  }
  return ip || "127.0.0.1";
};
const ivp4 = getIPAddress();

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

const request = require("./index");

module.exports = function getQRKey(params: object) {
  return request({
    url: "/login/qr/key",
    method: "get",
    params,
  });
};

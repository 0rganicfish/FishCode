function username() {
  var upname = document.getElementsByClassName("user-name"),
    len = upname.length - 1;
  console.log("共有", len, "位 up 主。分别是：");
  for (var i = 0; i < len; ++i) {
    console.log(upname[i].innerText);
  }
}
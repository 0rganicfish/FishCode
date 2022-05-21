// 切换表格
function changeTable() {
  let btn = document.querySelectorAll('input[name="options"]'),
    tables = document.querySelector(".tables"),
    titles = document.querySelector(".titles");

  function sendData(d) {
    new Ajax().main({
      url: "database/dataStu.php",
      data: { type: d },
      success: (res) => {
        tables.innerHTML = res; //插入表格
      },
    });
  }
  sendData("score");

  changeBtn(btn, (tar) => {
    sendData(tar.value);
    setTimeout(() => sortTable(".right "), 300);

    if (tar.value === "score") {
      titles.innerHTML = "惠州学院学生成绩明细（有效）";
    } else if (tar.value === "source") {
      titles.innerHTML = "我的课程信息";
    }
  });
}

function copyQQ() {
  const qq = document.querySelector(".qqmail");
  qq.addEventListener("click", () => {
    Copy("notfound405@qq.com", qq);
    alert("复制成功");
  });
}

window.onload = () => {
  changeTable();
  copyQQ();
  // console.log(navigator.userAgent);

  setTimeout(() => {
    sortTable(".right ");
    divPage(".right ");
    stuInfo();
  }, 300); //等表格出来再说
};

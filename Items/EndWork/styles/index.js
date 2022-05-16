// 切换表格
const changeTable = () => {
  let btn = document.querySelectorAll('input[name="options"]'),
    tables = document.querySelector(".tables");

  const sendData = (d) => {
    new Ajax().main({
      url: "database/dataStu.php",
      data: { type: d },
      success: (res) => {
        tables.innerHTML = res; //插入表格
      },
    });
  };
  sendData("score");

  changeBtn(btn, (tar) => {
    sendData(tar.value);
    setTimeout(() => sortTable(), 300);
  });
};

const copyQQ = () => {
  const qq = document.querySelector(".qqmail");
  qq.addEventListener("click", () => {
    Copy("notfound405@qq.com", qq);
    alert("复制成功");
  });
};

// 学生信息写入
const stuInfo = () => {
  let stuClass = document.getElementById("class"),
    gpa = document.getElementById("gpa"),
    stuId = document.getElementById("id"),
    stuName = document.getElementById("name");

  new Ajax().main({
    url: "database/stu.json",
    success: (res) => {
      let ans = JSON.parse(res).data.stuInfo;
      stuClass.innerText = ans.class;
      gpa.innerText = ans.gpa;
      stuId.innerText = ans.id;
      stuName.innerText = ans.name;
    },
  });
};

window.onload = () => {
  changeTable();
  copyQQ();
  // console.log(navigator.userAgent);

  setTimeout(() => {
    sortTable();
    divPage();
    stuInfo();
  }, 300); //等表格出来再说
};

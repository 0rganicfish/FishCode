//切换表格
const changeTable = () => {
  let btn = document.querySelectorAll('input[name="options"]'),
    tables = document.querySelector(".tables");

  changeBtn(btn, (tar) => {});
};

// 选择框
const select = () => {
  const selBox = document.querySelectorAll("tbody .checkbox input"),
    allBox = document.querySelector("thead .checkbox input");

  allBox.addEventListener("click", () => {
    selBox.forEach((ele) => {
      if (!ele.checked && allBox.checked) {
        ele.checked = true;
      }
      if (!allBox.checked) {
        ele.checked = false;
      }
    });
  });
};

// 弹窗......打开！
const showWin = () => {
  const btn1 = document.querySelectorAll('td input[name="info"]'),
    btn2 = document.querySelectorAll('td input[name="edit"]'),
    mes = document.querySelector(".mesMain"),
    editBtn = document.querySelector('.mes input[name="editSave"]'),
    btnText = document.querySelector(".mes label span");

  [btn1, btn2].forEach((eles) => {
    eles.forEach((ele) => {
      ele.addEventListener("click", (e) => {
        const stuid =
          e.target.parentElement.parentElement.children[3].innerHTML;
        // 发送当前点击学生的学号
        new Ajax().main({
          url: "database/dataStu.php",
          data: { uid: stuid },
          success: () => {
            stuInfo();
          },
        });

        if (e.target.name === "info") {
          btnText.innerHTML = "修改";
        } else {
          editBtn.parentElement.style.display = "";
          btnText.innerHTML = "保存";
          setTimeout(() => {
            editInfo(e.target.parentElement);
          }, 200);
        }
        mes.style.display = "";
      });
    });
  });

  editBtn.addEventListener("click", () => {
    if (btnText.innerHTML === "修改") {
      btnText.innerHTML = "保存";
      setTimeout(() => {
        editInfo();
      }, 300);
    }
  });

  closeWin();
};

// 弹窗......关闭！
const closeWin = () => {
  const back = document.querySelector(".mask"),
    close = document.querySelector(".close"),
    mes = document.querySelector(".mesMain");

  [back, close].forEach((ele) => {
    ele.addEventListener("click", () => {
      mes.style.display = "none";
      returns();
    });
  });
};

/*
 * 编辑信息...... */
const editInfo = () => {
  let info = [],
    changeInfo = [],
    tableTd = document.querySelectorAll(".mes td"),
    editBtn = document.querySelector('.mes input[name="editSave"]'),
    btnText = document.querySelector(".mes label span");

  document.querySelectorAll(".info span").forEach((ele) => {
    if (ele.attributes["id"]) info.push(ele);
  });

  [info, tableTd].forEach((item) => {
    item.forEach((ele) => {
      ele.addEventListener("click", (e) => {
        const tar = e.target;
        if (tar.tagName === "SPAN") {
          let input = document.createElement("input");

          input.setAttribute("type", "text");
          input.setAttribute("class", "editable");
          input.value = tar.innerHTML;
          // input.setAttribute("name", tar)

          tar.innerHTML = "";
          tar.append(input);
          changeInfo.push(tar);

          // console.log(changeInfo);
          console.log(tar.innerHTML);
        }
      });
    });
  });

  editBtn.addEventListener("click", (e) => {
    if (btnText.innerHTML === "保存") {
      saveInfo(changeInfo);
    }
  });
  // returns(changeInfo);
};

/*
 * 保存......信息 */
const saveInfo = (changeInfo) => {
  const saveBtn = document.querySelector('.mes input[name="editSave"]');

  // new Ajax().main({
  //   url: "database/dataRoot.php",
  //   method: "POST",
  //   data: { uid: stuid },
  //   success: () => {},
  // });

  // console.log(changeInfo);
  returns(changeInfo);
  saveBtn.parentElement.style.display = "none";
};

/*
 * 还原~ */
const returns = (changeInfo) => {
  let info = [];
  document.querySelectorAll(".info span").forEach((ele) => {
    if (ele.attributes["id"]) info.push(ele);
  });
  let tableTd = document.querySelectorAll(".mes td");

  // console.log(changeInfo);
  //修改了才用
  if (changeInfo) {
    changeInfo.forEach((ele) => {
      let t = ele.childNodes[0].value;
      ele.removeChild(ele.childNodes[0]);
      ele.innerHTML = t;
    });
  }
};

window.onload = () => {
  changeTable();
  showWin();

  setTimeout(() => {
    divPage();
    sortTable();
    select();
  }, 200);
};

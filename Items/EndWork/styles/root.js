//切换表格
const changeTable = () => {
  let btn = document.querySelectorAll('input[name="options"]'),
    tables = document.querySelector(".right .tables");

  const sendData = (d) => {
    new Ajax().main({
      url: "database/dataRoot.php",
      data: { type: d },
      success: (res) => {
        tables.innerHTML = res; //插入表格
      },
    });
  };

  sendData("students");
  changeBtn(btn, (tar) => {
    sendData(tar.value);
    setTimeout(() => sortTable(".right "), 300);
  });
};

// 选择框
const select = () => {
  const selBox = document.querySelectorAll(".right tbody .checkbox input"),
    allBox = document.querySelector(".right thead .checkbox input");

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
    saveBtn = document.querySelector('.mes input[name="save"]'),
    tables = document.querySelector(".win .tables");

  [btn1, btn2].forEach((eles) => {
    eles.forEach((ele) => {
      ele.addEventListener("click", (e) => {
        const stuid =
          e.target.parentElement.parentElement.children[3].innerHTML;
        // 发送当前点击学生的学号
        new Ajax().main({
          url: "database/dataStu.php",
          data: { uid: stuid, type: "score" },
          success: (res) => {
            tables.innerHTML = res; //表格成绩信息
            stuInfo(); //学生信息
          },
        });

        mes.style.display = "";
        if (e.target.name === "info") {
          saveBtn.parentElement.style.display = "none";
        } else {
          saveBtn.parentElement.style.display = "";
          setTimeout(() => editInfo(), 300);
        }

        setTimeout(() => {
          closeWin();
          sortTable(".win ", false);
        }, 200);
        //
      });
    });
  });
  //
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
    changeInfo = new Set(),
    tableTd = document.querySelectorAll(".mes tbody td"),
    saveBtn = document.querySelector('.mes input[name="save"]'),
    stuId = document.querySelector(".win #stuId").innerText;

  document.querySelectorAll(".info span").forEach((ele) => {
    if (ele.attributes["id"]) info.push(ele);
  });

  const adding = (ele, callback) => {
    console.log(ele);
    changeInfo.add(ele);
    callback();
  };

  [info, tableTd].forEach((item) => {
    item.forEach((ele) => {
      ele.addEventListener("click", (e) => {
        const tar = e.target;

        if (tar.childNodes[0].nodeName === "#text") {
          adding(tar, () => {
            let input = document.createElement("input");
            input.setAttribute("type", "text");
            input.setAttribute("class", "editable");
            input.value = tar.innerHTML;
            tar.removeChild(tar.childNodes[0]);
            tar.append(input);
          });
        }
      });
    });
  });

  saveBtn.addEventListener("click", () => {
    saveInfo(changeInfo, stuId);
  });
};

/*
 * 保存......信息 */
const saveInfo = (changeInfo, stuId) => {
  const saveBtn = document.querySelector('.mes input[name="save"]');
  let editData = { info: [], table: [] };

  changeInfo.forEach((item) => {
    if (item.tagName === "TD") {
      editData.table.push({
        id: item.id,
        course: item.parentElement.children[1].innerText,
        value: item.innerText,
      });
    } else {
      console.log(item);
      editData.info.push({
        id: item.id,
        value: item.innerText,
      });
    }
  });
  console.log(editData, stuId);

  new Ajax().main({
    url: "database/dataRoot.php",
    method: "POST",
    data: editData,
    success: () => {
      saveBtn.parentElement.style.display = "none";
      returns(changeInfo);
    },
  });
};

/*
 * 还原~ */ //毕竟....display:none 挖的坑
const returns = (changeInfo) => {
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

  setTimeout(() => {
    divPage(".right ");
    sortTable(".right ");
    select(); //选择框
    showWin(); //弹窗
  }, 200);
};

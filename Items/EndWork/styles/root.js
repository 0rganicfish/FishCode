//切换表格
function changeTable() {
  const btn = document.querySelectorAll('input[name="options"]'),
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
}

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
function showWin() {
  const btn1 = document.querySelectorAll('td input[name="info"]'),
    btn2 = document.querySelectorAll('td input[name="edit"]'),
    win = document.querySelector(".mes"),
    back = document.querySelector(".mask"),
    close = document.querySelector(".close"),
    saveBtn = document.querySelector(".mes .edit"),
    tables = document.querySelector(".win .tables");

  function show(tar) {
    win.style.display = "";
    if (tar.name === "info") {
      saveBtn.style.display = "none";
    } else {
      saveBtn.style.display = "";
      editInfo(); //点击编辑
    }

    // 弹窗......关闭！
    [back, close].forEach((ele) => {
      ele.onclick = () => (win.style.display = "none");
    });

    sortTable(".win ", false);
  }

  //
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
            setTimeout(() => show(e.target), 300);
          },
        });
        //
      });
    });
  });
}

/*
 * 编辑信息...... */
function editInfo() {
  let tableTd = document.querySelectorAll(".mes tbody td"),
    saveBtn = document.querySelector('.mes input[name="save"]'),
    stuId = document.querySelector(".win #stuId").innerText,
    info = [...document.querySelectorAll(".win .info span")].filter((ele) => {
      return ele.attributes["id"];
    });

  function pushInput(node) {
    let input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("class", "editable");
    input.setAttribute("id", node.innerHTML);
    input.value = node.innerHTML;
    node.innerHTML = "";
    node.appendChild(input);
  }

  [info, tableTd].forEach((item) => {
    item.forEach((ele) => {
      ele.addEventListener("click", () => {
        if (ele.innerHTML[0] !== "<") pushInput(ele);
      });
    });
  });

  saveBtn.onclick = () => {
    saveInfo(stuId);
  };
}

/*
 * 验证输入 */
function checkIn(input) {
  // console.log(input);
  if (!input.length) return false;
  
  

  return true;
}

/*
 * 保存......信息 */
function saveInfo(stuId) {
  const saveBtn = document.querySelector(".mes .edit"),
    input = document.querySelectorAll(".win input.editable"),
    editData = { stuId: stuId, info: [], table: [] };

  if (!checkIn(input)) return false;

  //
  input.forEach((ele) => {
    const par = ele.parentElement;
    if (par.nodeName === "SPAN") {
      editData.info.push({
        key: par.id,
        value: encodeURIComponent(ele.value),
      });
    } else {
      editData.table.push({
        key: par.id,
        value: encodeURIComponent(ele.value),
        course: encodeURIComponent(par.parentElement.id),
      });
    }
  });

  // 恢复
  input.forEach((ele) => {
    ele.parentElement.innerHTML = ele.value;
  });

  //
  new Ajax().main({
    url: "database/dataRoot.php",
    method: "POST",
    data: JSON.stringify(editData) + "&type=update",
    success: (res) => {
      console.log(res);
      saveBtn.style.display = "none";
    },
  });
}

//
window.onload = () => {
  changeTable();

  setTimeout(() => {
    divPage(".right ");
    sortTable(".right ");
    select(); //选择框
    showWin(); //弹窗
  }, 300);
};

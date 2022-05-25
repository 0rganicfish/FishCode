function autoFun(type = "students") {
  setTimeout(() => {
    divPage(".right ");
    sortTable(".right ");
    select(); //选择框

    //删除
    deleteInfo(type);
    //添加
    addInfo(type);

    // qq Fun
    const qq = document.querySelector(".qqmail");
    qq.addEventListener("click", () => {
      Copy("notfound405@qq.com", qq);
      alert("复制成功");
    });
  }, 200);
}

/*
 * 切换表格 */

function sendData(d) {
  const tables = document.querySelector(".right .tables");
  new Ajax().main({
    url: "database/dataRoot.php",
    data: { type: d },
    success: (res) => {
      //  console.log(res);
      tables.innerHTML = res;
      autoFun(d);
      if (d === "students") {
        setTimeout(() => showWin(), 200);
      }
    },
  });
}

function changeTable() {
  const btn = document.querySelectorAll('input[name="options"]');
  sendData("students");

  changeBtn(btn, (tar) => {
    if (tar.value === "course") {
      setTimeout(() => editCourse(), 200);
    }
    sendData(tar.value);
  });
}

/*
 * 选择框 */
function select() {
  const selBox = document.querySelectorAll('.right tbody input[name="check"]'),
    allBox = document.querySelector('.right thead input[name="check"]');

  allBox.addEventListener("click", () => {
    selBox.forEach((ele) => {
      if (!ele.checked && allBox.checked) {
        ele.checked = true;
      }
      if (!allBox.checked) ele.checked = false;
    });
  });
}

/*
 * 点击编辑 */

function pushInput(node) {
  let input = document.createElement("input");
  input.setAttribute("type", "text");
  input.setAttribute("class", "editable");
  input.setAttribute("id", node.innerHTML);
  input.value = node.innerHTML;
  node.innerHTML = "";
  node.appendChild(input);
}

/*
 * 学生界面 */

/*
 * 请求学生成绩信息 */
function getInfo(stuid) {
  const tables = document.querySelector(".win .tables"),
    stuClass = document.querySelector(".win #class"),
    gpa = document.querySelector(".win #gpa"),
    stuId = document.querySelector(".win #stuId"),
    stuName = document.querySelector(".win #stuName");

  new Ajax().main({
    url: "database/dataStu.php",
    data: { uid: stuid, type: "score" },
    success: (res) => {
      const regex = /{.+}/gm,
        stu = JSON.parse(res.match(regex)),
        ans = res.replace(regex, "");

      tables.innerHTML = ans; //插入表格
      stuClass.innerText = stu.class;
      gpa.innerText = stu.gpa;
      stuId.innerText = stu.id;
      stuName.innerText = stu.name;
    },
  });
}

/*
 * 弹窗......打开！ */

function showWin() {
  const btn1 = document.querySelectorAll('td input[name="info"]'),
    btn2 = document.querySelectorAll('td input[name="edit"]'),
    win = document.querySelector(".mes"),
    back = document.querySelector(".mask"),
    close = document.querySelector(".close"),
    saveBtn = document.querySelector(".mes .edit"),
    tables = document.querySelector(".win .tables");

  function show(tar, uid) {
    win.style.display = "";
    if (tar.name === "info") {
      saveBtn.style.display = "none";
    } else {
      saveBtn.style.display = "";
      editStu(uid); //点击编辑
    }
    sortTable(".win ", false);
  }

  //
  [btn1, btn2].forEach((eles) => {
    eles.forEach((ele) => {
      ele.addEventListener("click", () => {
        const stuid = ele.parentElement.parentElement.children[2].innerHTML;
        // 发送当前点击学生的学号
        getInfo(stuid);
        setTimeout(() => show(ele, stuid), 150);
      });
    });
  });

  // 弹窗......关闭！
  [back, close].forEach((ele) => {
    ele.onclick = () => {
      win.style.display = "none";
      tables.innerHTML = "";
    };
  });
}

/*
 * 编辑信息...... */

function editStu(uid) {
  const saveBtn = document.querySelector('.mes input[name="save"]'),
    stuId = document.querySelector(".win #stuId"), //只能改学号和姓名
    stuName = document.querySelector(".win  #stuName"),
    tableTd = [...document.querySelectorAll(".mes tbody td")].filter((ele) => {
      const ids = ele.attributes;
      return ids.length && ids.id.value !== "gradePoint";
    });

  [[stuId, stuName], tableTd].forEach((item) => {
    item.forEach((ele) => {
      ele.addEventListener("click", () => {
        if (ele.innerHTML[0] !== "<") pushInput(ele);
      });
    });
  });

  saveBtn.onclick = () => {
    saveStu(uid);
  };
}

/*
 * 验证输入 */ //懒了......
function checkIn(input) {
  // console.log(input);
  if (!input.length) return false;

  return true;
}

/*
 * 保存......信息 */
function saveStu(uid) {
  const saveBtn = document.querySelector(".mes .edit"),
    input = document.querySelectorAll(".win input.editable"),
    editData = { stuId: uid, info: [], table: [] };

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

  //
  new Ajax().main({
    url: "database/dataRoot.php",
    method: "POST",
    data: JSON.stringify(editData) + "&type=update",
    success: (res) => {
      // console.log(res);

      // 恢复
      saveBtn.style.display = "none";
      let id = editData.info.find((ele) => ele.key === "stuId");
      id = id ? id.value : uid;
      getInfo(id);
    },
  });
  //5-24 几乎的一星期......
}

//

/*
 * 课程修改 */
function editCourse() {
  const btn = document.querySelectorAll('.right input[name="edit"]'),
    saveBtn = document.querySelector('.editInfo input[name="save"]');
  let courseId = "";

  btn.forEach((eles) => {
    eles.onclick = (e) => {
      const node = e.target.parentElement.parentElement.children;
      saveBtn.parentElement.style.display = "";

      courseId = node[2].innerHTML;
      [...node].forEach((ele, index) => {
        if (![0, 1, 7].includes(index)) {
          ele.style.padding = "";
          pushInput(ele);
        }
      });
    };
  });

  saveBtn.onclick = () => saveCourse(courseId);
}

/*
 * 保存课程 */
function saveCourse(id) {
  const edited = [...document.querySelectorAll(".right td .editable")],
    saveBtn = document.querySelector(".editInfo .saveBtn");
  let editData = { courseId: id, data: [] };

  edited.forEach((ele) => {
    const par = ele.parentElement;
    if (ele.id !== ele.value)
      //只发送修改过的
      editData.data.push({
        key: par.id,
        value: encodeURIComponent(ele.value),
      });
  });

  //
  new Ajax().main({
    url: "database/dataRoot.php",
    method: "POST",
    data: JSON.stringify(editData) + "&type=course",
    success: () => {
      saveBtn.style.display = "none";
      edited.forEach((ele) => (ele.parentElement.innerHTML = ele.value));
    },
  });
}

/*
 * 删除信息...... */
function deleteInfo(type) {
  let deleteData = { type: type, data: [] };

  //单个删除
  if (type !== "score") {
    const btn = document.querySelectorAll('.right input[name="delete"]');
    btn.forEach((ele) => {
      ele.onclick = () => {
        if (confirm("确认删除？ 删除后不可恢复")) {
          const id = ele.parentElement.parentElement.children[2].innerHTML;
          deleteData.data.push(id);
          new Ajax().main({
            url: "database/dataRoot.php",
            method: "POST",
            data: JSON.stringify(deleteData) + "&type=delete",
            success: () => {
              sendData(type);
            },
          });
        }
      };
      //
    });
  }

  const deleteAll = document.querySelector('.right input[name="deleteAll"]'),
    checkbox = document.querySelectorAll('td input[name="check"]');

  deleteAll.onclick = () => {
    checkbox.forEach((ele) => {
      if (ele.checked) {
        const par = ele.parentElement.parentElement.children;
        if (type === "score") {
          deleteData.data.push({
            stuId: par[2].innerHTML,
            courseId: par[4].innerHTML,
          });
        } else deleteData.data.push(par[2].innerHTML);
      }
    });

    if (confirm("确认删除？ 删除后不可恢复"))
      new Ajax().main({
        url: "database/dataRoot.php",
        method: "POST",
        data: JSON.stringify(deleteData) + "&type=delete",
        success: () => {
          sendData(type);
        },
      });
  };
}

/*
 * 添加信息 */
function addInfo() {}

//
window.onload = () => {
  changeTable();
  autoFun();
};

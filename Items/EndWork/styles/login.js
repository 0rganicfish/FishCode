/*
 * 二维码 */
let QRcode = () => {
  const icon = document.querySelectorAll(".other-login span"),
    qr = document.querySelector(".QRCode");

  icon.forEach((ele) => {
    ele.addEventListener("mouseover", () => {
      setTimeout(() => {
        qr.style.visibility = "visible";
      }, 300);
    });
    ele.addEventListener("mouseout", () => {
      qr.style.visibility = "hidden";
    });
  });
};

/*
 * 登录检查 */

let Login_check = () => {
  const uid = document.getElementById("uid"),
    password = document.getElementById("password"),
    tips = document.querySelectorAll(".tips"),
    check = document.querySelector(".checkbox"),
    form = document.querySelector("form");
  uid.value = password.value = "";

  /*
   * 合法的输入 */

  uid.addEventListener("blur", (e) => {
    const tar = e.target;
    if (tar.value === "" || tar.value.length !== 10 || isNaN(tar.value)) {
      tips[0].style.color = "red";
    } else {
      tips[0].style.color = "grey";
    }
  });
  uid.addEventListener("focus", () => {
    tips[0].style.color = "grey";
  });

  password.addEventListener("blur", (e) => {
    const tar = e.target;
    if (tar.value === "" || tar.value.length < 8 || tar.value.length > 16) {
      tips[1].style.color = "red";
    } else {
      tips[1].style.color = "grey";
    }
  });
  password.addEventListener("focus", () => {
    tips[1].style.color = "grey";
  });

  /*
   * 真的有这个人？ */

  let ajax = new Ajax(),
    flag = true;

  ajax.main({
    url: "database/stu.json",
    method: "POST",
    success: (res) => {
      const stuid = JSON.parse(res).uid;
      uid.addEventListener("blur", (e) => {
        if (stuid.indexOf(e.target.value) === -1) {
          tips[0].style.color = "red";
          flag = false;
        } else {
          flag = true;
        }
      });
    },
  });

  /*
   * 记住吗？*/

  check.addEventListener("click", () => {
    const box = document.getElementById("check");
    if (!box.checked) box.checked = true;
    else box.checked = false;
  });
  check.onmousedown = () => {
    return false;
  };

  /*
   * 提交检测并拦截 */

  form.onsubmit = () => {
    if (uid.value === "") {
      tips[0].style.color = "red";
    }
    if (password.value === "") {
      tips[1].style.color = "red";
    }
    if (uid.value && password.value && flag) {
      form.method = "POST";
      form.action = "login.php";
      form.submit();
    }
    return false;
  };
};

/*
 * 复制 */

let Copy = (copyString, copy) => {
  let textArea = document.createElement("textarea");
  textArea.value = copyString;
  copy.appendChild(textArea);
  textArea.focus(), textArea.select();
  document.execCommand("copy");
  textArea.style.visibility = "hidden";
  copy.removeChild(textArea);
};
let Copy_qq = () => {
  let qq = document.querySelector(".qqmail");
  qq.addEventListener("click", () => {
    Copy("notfound405@qq.com", qq);
    alert("复制成功");
  });
};

window.onload = () => {
  QRcode();
  Login_check();
  Copy_qq();

  // 一些杂项
  (() => {
    document.querySelector(".forget").onmousedown = () => {
      return false;
    };
    window.history.replaceState(null, null, window.location.href); //表单缓存..刷新
  })();
};

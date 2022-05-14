let divPage = () => {
  const table = document.querySelector("tbody"),
    perPages = document.getElementById("perPage"), // Rows per Page
    prePage = document.querySelector(".prePage"), // 上一页
    nextPage = document.querySelector(".nextPage"), // 下一页
    pageNum = document.getElementById("pageNum"), //页码
    tpPage = document.querySelector('input[name="tpPage"]'); // 跳页

  let totalRow = table.rows.length,
    perPage = 5, //一页的行数
    begin = 0,
    end = perPage,
    totalPage = Math.ceil(totalRow / perPage),
    curPage = 1; //目前在第几页

  const display = () => {
      for (let row of table.rows) {
        row.style.display = "none";
      }
      for (let i = begin; i < end; ++i) {
        table.rows[i].style.display = "";
      }
      pageNum.innerText = curPage;
    },
    // 开头末尾的禁用按钮
    check = () => {
      prePage.disabled = curPage === 1;
      nextPage.disabled = curPage >= totalPage;
    },
    //总页数
    printPage = () => {
      document.getElementById("total").innerText = totalPage;
    };

  (() => {
    check();
    display();
    printPage();

    // 前后页
    prePage.addEventListener("click", () => {
      --curPage;
      check();
      end = begin;
      begin = prePage.disabled ? 0 : begin - perPage;
      display();
    });
    nextPage.addEventListener("click", () => {
      ++curPage;
      check();
      begin = end;
      end = nextPage.disabled ? totalRow : Number(perPage) + Number(end);
      display();
    });

    //一页要展示的行数
    perPages.addEventListener("change", (e) => {
      if (e.target.value === "all") {
        end = perPage = totalRow;
      } else {
        end = perPage = Number(e.target.value);
      }
      begin = 0;
      curPage = 1;
      totalPage = Math.ceil(totalRow / perPage);
      check();
      display();
      printPage();
    });

    //跳页
    tpPage.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        let val = Number(e.target.value);
        if (val >= 1 && val <= totalPage) {
          curPage = val;
          check();
          begin = (val - 1) * perPage;
          end = nextPage.disabled ? totalRow : val * perPage;
        } else if (val > totalPage) {
          curPage = totalPage;
          begin = (totalPage - 1) * perPage;
          end = totalRow;
        } else {
          curPage = 1;
          begin = 0;
          end = perPage;
        }
        check();
        display();
      }
    });

    //EndOf
  })();
};

const sort_table = () => {
  const thead = document.querySelector("thead"),
    tbody = document.querySelector("tbody"),
    sortIco = document.querySelectorAll(".sort_ico");
  let rows_array = Array.from(tbody.rows),
    sortDire = [],
    preIndex = 0;

  for (let i = 0; i < rows_array[0].children.length; ++i) {
    sortDire[i] = true; //默认第一次为升序
  }

  const cmp = (col) => {
    return (rowA, rowB) => {
      let a = rowA.cells[col].innerHTML,
        b = rowB.cells[col].innerHTML,
        A = Number(rowA.cells[0].innerHTML), //相同则按第一列排序
        B = Number(rowB.cells[0].innerHTML);

      if (!isNaN(a)) {
        a = Number(a);
        b = Number(b);
        return a === b ? A - B : a - b; //数字
      } else {
        return a === b ? A - B : a > b; //字符串
      }
    };
  };

  thead.addEventListener("click", (e) => {
    if (e.target.tagName === "TH") {
      let index = e.target.cellIndex;

      if (sortDire[index]) {
        rows_array.sort(cmp(index));
      } else {
        rows_array.reverse();
      }
      tbody.append(...rows_array);

      // 排序的图标
      if (sortDire[index]) {
        let item = sortIco[index];
        item.style.background = "url(img/sort_up.png) center no-repeat";
        item.style.backgroundSize = "100%";
        item.style.top = "14px";
      } else {
        let item = sortIco[index];
        item.style.background = "url(img/sort_down.png) center no-repeat";
        item.style.backgroundSize = "100%";
        item.style.top = "22px";
      }
      if (preIndex != index) {
        let item = sortIco[preIndex];
        item.style.background = "url(img/sort.png) center no-repeat";
        item.style.backgroundSize = "100%";
        item.style.top = "18.5px";
      }

      preIndex = index;
      sortDire[index] = !sortDire[index]; //升降序
    }
  });
};

window.onload = () => {
  sort_table();
  divPage();
};

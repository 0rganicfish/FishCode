function Ajax(str) {
  let xhr = new XMLHttpRequest();
  xhr.onreadystatechange = () => {
    if (xhr.readyState === 4 && xhr.status === 200)
      document.getElementById("app").lastElementChild.innerHTML =
        xhr.responseText;
  };
  let url = "ajax.php?" + str;
  xhr.open("GET", url, true);
  xhr.send();
}

function sort_table() {
  console.log("jme");
  document.getElementById("table").addEventListener("click", (e) => {
    console.log(e);
    if (e.target.tagName == "TH") {
      sorting(e.target.cellIndex, e.target.type);
    }
  });

  function sorting(col_num, type) {
    console.log(col_num, type);
    let tbody = document.getElementById("table").querySelector("tbody"),
      rows_array = Array.from(tbody.rows),
      compare;

    switch (type) {
      case "number":
        compare = function (rowA, rowB) {
          return rowA.cells[col_num].innerHTML - rowB.cells[col_num].innerHTML;
        };
        break;
      case "string":
        compare = function (rowA, rowB) {
          return rowA.cells[col_num].innerHTML > rowB.cells[col_num].innerHTML;
        };
        break;
    }

    rows_array.sort(compare);
    tbody.append(...rows_array);
  }
}

window.onload = () => {
  document.getElementById("play").addEventListener("click", () => {
    Ajax("sel=play");
  });
  document.getElementById("close").addEventListener("click", () => {
    Ajax("sel=close");
  });
};

let obj = {
  name: "fish",
  handleEvent: function () {
    console.log(this.name);
  },
};

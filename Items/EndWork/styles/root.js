//切换表格
const changeTable = () => {
  let btn = document.querySelectorAll('input[name="options"]'),
    tables = document.querySelector(".tables");

  changeBtn(btn, (tar) => {});
};

window.onload = () => {
  changeTable();

  setTimeout(() => {
    divPage();
    sortTable();
  }, 200);
};

function f() {
  console.log("CJS");
}

function ff() {
  console.log("ff()");
}

const data = {
  name: "fish",
  id: "2114",
};

module.exports = {
  f,
  ff,
  data,
};

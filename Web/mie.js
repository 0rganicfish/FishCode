const on = (el, evt, fn, opts = {}) => {
  const delegatorFn = (e) =>
    e.target.matches(opts.target) && fn.call(e.target, e);
  el.addEventListener(
    evt,
    opts.target ? delegatorFn : fn,
    opts.options || false
  );
  if (opts.target) return delegatorFn;
};

const fn = () => console.log("mie!"),
  user = document.getElementById("user");
on(user, "click", fn, { target: "img" });

let obj = {
  handleEvent: f,
  
};

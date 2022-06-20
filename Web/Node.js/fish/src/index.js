// const { data: cjs } = require('./moduleCJS.cjs');
// console.log(cjs);

import { data, mie as mieF } from "./moduleESM.mjs";

console.log(data);
mieF();

import md5 from "md5";

const before = "Hello World";
const after = md5(before);
console.log({ before, after });

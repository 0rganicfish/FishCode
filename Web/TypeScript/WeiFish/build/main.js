import { db } from "./db";
db.query("select * from users", "", (res) => {
    console.log(res);
});

import { db } from "./db";

db.query("select * from users", "", (res: any) => {
  console.log(res);
});

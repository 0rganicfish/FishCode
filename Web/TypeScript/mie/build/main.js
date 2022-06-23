import express from "express";
import { routers } from "./router/user";
const app = express();
app.use(express.json()).use(express.urlencoded());
app.use("/api", routers);
app.listen("1023", () => {
    console.log("api server running on http://localhost:1023/api");
});

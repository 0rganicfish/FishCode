import { app } from "./router";
app
    .all("/mie", (req, res) => {
    res.send(req.headers);
})
    .listen("1023", () => {
    console.log("http://localhost:1023/mie");
});

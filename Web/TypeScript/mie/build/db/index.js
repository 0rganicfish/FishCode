import url from "url";
import fs from "fs";
import path from "path";
import { promisify } from "util";
const readFile = promisify(fs.readFile), writeFile = promisify(fs.writeFile), dirname = path.dirname(url.fileURLToPath(import.meta.url));
const dbPath = path.join(dirname, "../../static/fishData.json");
export const getDb = async () => {
    const data = await readFile(dbPath);
    return JSON.parse(data.toString());
};
export const addDb = async (db) => {
    const data = JSON.stringify(db, null, " ");
    await writeFile(dbPath, data);
};

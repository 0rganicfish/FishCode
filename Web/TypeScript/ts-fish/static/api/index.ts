const axios = require("axios");

exports.request = axios.create({
  baseURL: "https://ping-music-api.vercel.app/",
  timeout: 10000,
  withCredentials: true,
});

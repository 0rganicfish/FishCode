module.exports = {
  productionSourceMap: false,
  publicPath: "./",
  outputDir: "dist",
  assetsDir: "assets",
  devServer: {
    port: 1026,
    https: false,
    open: true,
  },
  chainWebpack: (config) => {
    config.resolve.extensions.add("ts").add("tsx");
  },
};

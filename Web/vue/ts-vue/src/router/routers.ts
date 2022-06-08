import { createRouter, createWebHashHistory, RouteRecordRaw } from "vue-router";

// 路由树的配置
const routes: Array<RouteRecordRaw> = [
  {
    path: "/",
    name: "index",
    alias: "/index",
    component: () => import("../views/index.vue"),
  },
  {
    path: "/home",
    name: "home",
    component: () => import(/* webpackChunkName: "home" */ "../views/home.vue"),
    meta: {
      title: "home",
    },
  },
  {
    path: "/:pathMatch(.*)*",
    name: "404",
    component: () => import(/* webpackChunkName: "404" */ "../views/404.vue"),
  },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;

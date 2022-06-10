import { createRouter, createWebHashHistory, RouteRecordRaw } from "vue-router";

// 路由树的配置
const routes: Array<RouteRecordRaw> = [
  {
    path: "/home",
    name: "home",
    meta: {
      title: "home",
    },
    component: () => import("@/views/home.vue"),
  },
  {
    path: "/fish",
    name: "fish",
    component: () => import("@/views/fish.vue"),
  },

  {
    path: "/404",
    name: "404",
    component: () => import(/* webpackChunkName: "404" */ "@/views/404.vue"),
  },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;

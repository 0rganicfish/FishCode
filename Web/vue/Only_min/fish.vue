<template>
  <div>
    <h1>Vue3生命周期钩子函数</h1>
    <h2>响应式拦截数据data的值是：{{ msg }}</h2>
    <p><button @click="changeMsg">点击改变msg</button></p>
  </div>
</template>

<script>
import { reactive, onUnmounted, onUpdated, onMounted, toRefs } from 'vue'; // 引入需要的
export default {
  setup() {
    // 初始化项目工作都放在setup中
    console.log('当前应用程序被安装了');
    const state = reactive({
      // 定义状态
      msg: '学而时习之', // 定义变量
      changeMsg: () => {
        // 定义方法
        state.msg = '不亦说乎';
      },
    });
    let timer = 0;
    let count = 0;
    onMounted(() => {
      console.log('页面挂载完成，触发了onMounted钩子函数');
      timer = setInterval(() => {
        console.log('定时器正在运行中', count++);
      }, 1000);
    });
    onUpdated(() => {
      console.log('数据发生了更新，触发了onUpdated钩子函数');
    });
    onUnmounted(() => {
      console.log('页面/组件退出，触发了onUnmounted钩子函数');
      // 如果不清楚，这些异步的行为就会常驻在内存中，一定程度上会造成常驻内存的不必要消耗，造成内存泄露
      clearInterval(timer);
    });
    return {
      ...toRefs(state),
    };
  },
};
</script>

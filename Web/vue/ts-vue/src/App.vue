<template>
  <ul class="user-info">
    <li v-for="(value, key, index) in userInfoRefs" :key="index" :class="key">
      {{ key }} :{{ value }}
    </li>
  </ul>
</template>

<script lang="ts">
import { defineComponent, reactive, toRefs } from "vue";

export default defineComponent({
  setup() {
    // 定义一个reactive对象
    const userInfo = reactive({
      id: 1,
      name: "Petter",
      age: 18,
      gender: "male",
    });

    // 定义一个新的对象，它本身不具备响应性，但是它的字段全部是ref变量
    const userInfoRefs = toRefs(userInfo);

    // 2s后更新userInfo
    setTimeout(() => {
      userInfo.id = 2;
      userInfo.name = "Tom";
      userInfo.age = 20;
      // alert("updated");
    }, 3000);

    // 在这里结构toRefs对象才能继续保持响应式
    return {
      userInfoRefs,
    };
  },
});
</script>

<style>
#app {
  font-family: 微软雅黑, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
  margin-top: 60px;
}
</style>

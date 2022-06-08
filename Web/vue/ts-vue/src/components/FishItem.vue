<template>
  <div>
    <ul class="user-info">
      <li v-for="(value, key, index) in userInfoRefs" :key="index" :class="key">
        {{ key }} :{{ value }}
      </li>
    </ul>
  </div>
</template>

<script lang="ts" setup>
import { reactive, toRefs } from "vue";

const userInfo = reactive({
  id: 1,
  name: "Petter",
  age: 18,
  gender: "male",
});
const userInfoRefs = toRefs(userInfo);

setTimeout(() => {
  userInfo.id = 2;
  userInfo.name = "Tom";
  userInfo.age = 20;
}, 2000);
</script>

<style>
#app {
  font-family: 微软雅黑, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
  margin-top: 60px;
}

.user-info {
  margin: 10px;
}
</style>

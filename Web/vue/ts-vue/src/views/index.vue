<template>
  <ul class="list">
    <li
      v-for="(item, index) in 5"
      :key="index"
      class="item"
      :class="{ cur: index === curIndex }"
      @click="curIndex = index"
    >
      {{ item }}
    </li>
  </ul>
  <!-- <FishItem v-bind="Post"></FishItem>
  <FishItem></FishItem> -->
  <router-link to="/home">首页</router-link>
</template>

<script lang="ts" setup>
import { ref } from "vue";

const curIndex = ref(0);
</script>

<style scoped>
.cur {
  color: #ff3e50;
}
</style>

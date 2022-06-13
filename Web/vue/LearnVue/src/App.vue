<template>
  <img alt="Vue logo" src="./assets/logo.png" />
  <h1>App</h1>
  <child-bar :key="1" :uid="data.id" :username="data.name" />
</template>

<script setup lang="ts">
import ChildBar from "cp/ChildBar/index.vue";
// import { ref } from "vue";

const data = {
  id: undefined,
  name: "fish",
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>

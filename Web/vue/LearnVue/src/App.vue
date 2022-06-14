<template>
  <h1>App</h1>
  {{ store.mes }}
</template>

<script setup lang="ts">
import { useStore } from "store";
const store = useStore();
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

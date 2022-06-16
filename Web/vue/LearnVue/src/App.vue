<template>
  <h1>App</h1>
  {{ mes }}
</template>

<script setup lang="ts">
import { useStore } from "./store";
import { computed } from "vue";

const store = useStore();

store.$state = {
  mes: "aaa",
};

const mes = computed({
  get: () => store.mes,
  set(val) {
    store.mes = val;
  },
});

setTimeout(() => {
  mes.value = "haha";
  
}, 1000);
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

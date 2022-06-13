<template>
  <div>
    <h2>Child</h2>
    <p>Data: {{ data }}</p>
  </div>
</template>
<script setup lang="ts">
const proper = defineProps({
  uid: {
    type: Number,
    required: true,
    default: 233,
    validator: (x: number) => x < 100 && x > 0,
  },
  username: String,
});

const data = `uid: ${proper.uid}; username: ${proper.username};`;
console.log(proper);

</script>
<style scoped></style>

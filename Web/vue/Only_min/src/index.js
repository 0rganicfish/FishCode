import createApp from './vue.3.2.min';

const App = {
  data() {
    return {
      count: 0,
    };
  },
};

console.log('mie');
createApp(App).mount('#app');

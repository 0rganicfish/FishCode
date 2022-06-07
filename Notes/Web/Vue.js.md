<h1 align="center"><b>Vue.js</b></h1><br>

[TOC]

<br>

## 基本语法

直接引用文件或是 cdn：`https://unpkg.com/vue@next`

可以理解为 客户端的 HTML 元素是要先经过服务端渲染(编译) `Vue.js` 后才呈现的，所以客户端并不会显示 Vue 的内容

### 应用

#### 创建

- ```JavaScript {.line-numbers}
  <div id="app">
    {{}}
  </div>

  const app = {
    data() {
      return {} //返回对象
    },
    // 函数方法
    methods: {},
  }
  Vue.createApp(app).mount('#app') //要挂载的HTML的元素

  //或：
  const app = Vue.createApp({
    data(){
      return {}
    }
  })
  const vm = app.mount('#app');
  ```

  - `data` 选项是一个函数。Vue 在创建新组件实例的过程中调用此函数。它应该**返回一个对象**，然后 Vue 会通过响应性系统将其包裹起来，并以 `$data` 的形式存储在组件实例中。
  - `mount()` 挂载应用：应用实例必须在调用了 `.mount()` 方法后才会渲染出来。该方法接收一个“容器”参数，可以是一个实际的 DOM 元素或是一个 CSS 选择器字符串

#### 模板语法

- **文本插值**：`{{...}}` 标签的内容将会被替代为对应组件实例中 `message` 属性的值，如果 `message` 属性的值发生了改变，`{{...}}` 标签内容也会更新。
- **指令：** 以 `v-*`为格式的 attribute 被称为一个 Vue 指令，用来操作 DOM

  - `v-html=""`： 转译输出 HTML 标签
    ```html {.line-numbers}
    <span v-html="rawHtml"></span>
    <script>
      return {
        rawHtml: '<span style="color:red">mie</span>',
      };
    </script>
    ```
  - `v-bind:属性名=""`，如 `:id="dynId"` | `:href="url"`，实现动态的属性值
    - 绑定**多类型**时用对象：
      ```html {.line-numbers}
      <div v-bind="obj"></div>
      <script>
        return {
          obj: {
            id: "mie",
            class: "haha btns",
          },
        };
      </script>
      ```
    - 还能使用 js 表达式 (而不是语句)：
      ```html {.line-numbers}
      <div :id="`list-${ids}`"></div>
      <!-- return {ids: xxx} -->
      ```
    - 当绑定 class 为对象时，根据 value 的**布尔值**决定是否带有该 key
      ```html {.line-numbers}
      <div :class="classObj"></div>
      <script>
        return {
          classObj: {
            active: true,
            err: false,
          },
        };
      </script>
      <!-- 最终的结果是 <div class="active"></div> -->
      ```
  - `v-if=""`：根据返回的布尔值来决定该元素是否展示 —— false 时直接就变成了注释 `<!-- -->`
    - 也有 `v-if-else=""` 和 `v-else=""`
  - `v-show=""`：同上，但 false 时是 `display:none`
  - `v-on=""`：监听 DOM 事件，简写：`<p @click="fun"></p>`
  - `v-for="(ele, index) in items"`：循环渲染，相当于是 `forEach`
    - 也能改为 `of`
    - 但为了避免重复渲染，要加属性：`:key="index"`
    - 循环对象时：
      ```html {.line-numbers}
      <li v-for="(value, key, index) in items">
        {{key}}: {{value}}, index: {{index}}
      </li>
      ```
    - 循环范围：
      ```html {.line-numbers}
      <li v-for="n in x">{{n}}</li>
      ```

#### 事件绑定

通过由点 `.` 表示的指令后缀来调用修饰符:

- `.stop` - 阻止冒泡
- `.prevent` - 阻止默认事件
- `.capture` - 阻止捕获
- `.self` - 只监听触发该元素的事件
- `.once` - 只触发一次
- `.left` - 左键事件
- `.right` - 右键事件
- `.middle` - 中间滚轮事件

#### 表单输入绑定

`<input v-model="text">`

`v-model` 还可以用于各种不同类型的输入。它会根据所使用的元素自动扩展到不同的 DOM 属性和事件组合：

- 文本类型的 `<input>` 和 `<textarea>` 元素会使用到 `value` 属性和 `input` 事件；
- `<input type="checkbox">` 和 `<input type="radio">` 使用 `checked` 属性和 `change` 事件；
- `<select>` 使用的 `value` 作为 ` prop`，`change ` 作为事件
  &emsp;&emsp;

**文本：**

```html {.line-numbers}
<span>
  <input v-model="mes" />
  mes is {{mes}}
</span>
```

**复选框：** `checkedNames` 数组将始终包含来自当前选中框的值。

```html {.line-numbers}
<div>Checked names: {{ checkedNames }}</div>

<input type="checkbox" id="jack" value="Jack" v-model="checkedNames" />
<label for="jack">Jack</label>

<input type="checkbox" id="john" value="John" v-model="checkedNames" />
<label for="john">John</label>
<script>
  return {
    checkedNames: [],
  };
</script>
```

**下拉框：**

```html {.line-numbers}
<p>Selected: {{ selected }}</p>
<span>选项：</span>
<select v-model="selected">
  <option v-for="option in options" :value="option.value">
    {{ option.text }}
  </option>
</select>
```

### 生命周期

- `setup()` : 开始创建组件之前，在 `beforeCreate` 和 `created` 之前执行，创建的是 `data` 和 `method`
- `onBeforeMount()` : 组件挂载到节点上之前执行的函数；
- `onMounted()` : 组件挂载完成后执行的函数；
- `onBeforeUpdate()`: 组件更新之前执行的函数；
- `onUpdated()`: 组件更新完成之后执行的函数；
- `onBeforeUnmount()`: 组件卸载之前执行的函数；
- `onUnmounted()`: 组件卸载完成后执行的函数；
- `onActivated()`: 被包含在 `<keep-alive>` 中的组件，会多出两个生命周期钩子函数，被激活时执行；
- `onDeactivated()`: 比如从 A 组件，切换到 B 组件，A 组件消失时执行；
- `onErrorCaptured()`: 当捕获一个来自子孙组件的异常时激活钩子函数。

> PS： 使用`<keep-alive>` 组件会将数据保留在内存中，比如我们不想每次看到一个页面都重新加载数据，就可以使用`<keep-alive>` 组件解决。
> 在 Vue3 里， 每个生命周期函数都要先导入才可以使用，并且所有生命周期函数统一放在 `setup` 里运行。

<br>

## 单组件文件.vue

### 构建项目

- 如果没安装，先安装 `vue-cli` 脚手架
  ```batch {.line-numbers}
  npm install -g @vue/cli
  ```
- 再创建项目

  ```batch {.line-numbers}
  vue create [options] app-name

  cd app-name
  npm run server
  ```

- 或用 GUI 来创建
  ```batch {.line-numbers}
  vue ui
  ```
- 项目文件结构
- <img src="img/Vue_proj.png" width="70%">

<br>

### 运行

**入口：**

使用 Vue 3 的生命周期的情况下，整个组件相关的业务代码，都可以丢到 `setup` 里编写。因为在 setup 之后，其他的生命周期才会被启用

**基本语法：**

```ts {.line-numbers}
import { defineComponent } from "vue";
// defineComponent 可以用于 TypeScript 的类型推导，简化掉很多编写过程中的类型定义
export default defineComponent({
  setup(props, context) {
    // 业务代码写这里...
    return {
      // 需要给 template 用的数据、函数放这里 return 出去...
    };
  },
});
```

- 使用 `setup` 的情况下，请牢记一点：不能再用 `this` 来获取 Vue 实例，也就是无法通过 `this.xxx` 、 `this.fn()` 这样来获取实例上的数据，或者执行实例上的方法。
- 在 Vue 3 的 `defineComponent` 写法里，只要你的数据要在 `<template>` 中使用，就必须在 `setup` 里 `return` 出去。

> 当然，只在函数中调用到，而不需要渲染到模板里的，则无需 return

<br>

### 响应式数据

从返回的数据实时更新

- **ref：** 但是在使用 `ref` 时，不能这样子声明，会报错，正确的声明方式应该是使用 `<>` 来包裹类型定义，紧跟在 `ref API` 之后：
  ```ts {.line-numbers}
  // 单类型
  const msg = ref<string>("Hello World!");
  // 多类型
  const phoneNumber = ref<number | string>(13800138000);
  // 数字数组
  const uids = ref<number[]>([1, 2, 3]);
  ```
  **但是：**
  - 定义**挂载节点**后，也是必须通过 `xxx.value` 才能正确操作到挂载的 `DOM` 元素或组件（详见下方的变量的读取与赋值）
  - 请保证视图渲染完毕后，再执行 DOM 或组件的相关操作，需要放到生命周期的 `onMounted` 或者 `nextTick` 函数里
  - 该变量必须 `return` 出去才可以给到 `template` 使用（这一点是 3.x 生命周期的硬性要求，子组件的数据和方法如果要给父组件操作，也要 return 出来才可以）。
  - 当变量是 DOM 时，类型应该是 [HTML 元素](https://developer.mozilla.org/zh-CN/docs/Web/API/Document_Object_Model#html_%E5%85%83%E7%B4%A0%E6%8E%A5%E5%8F%A3)
  - 读取任何 ref 对象的值都**必须**通过 `xxx.value` 才可以正确获取到。

<br>

- **reactive:** `reactive` 是继 `ref` 之后最常用的一个响应式 API 了，相对于 `ref`，它的局限性在于只适合对象、数组。
  定义和使用与 ref 差不多，**但：**
  - 在 2.x 的时候，在操作数组时，完全可以和普通数组那样随意的处理数据的变化，依然能够保持响应性。
  - 但在 3.x ，如果使用 `reactive` 定义数组，则不能这么搞了，必须只使用那些不会改变引用地址的操作。

<br>

- **所以：** 为了使用方便的同时又能响应式修改数据，就有了：

  - `toRef` 创建一个新的 `ref` 变量，转换 `reactive` 对象的某个字段为 `ref` 变量

    - 在 `toRef` 的过程中，如果使用了原对象上面不存在的 `key` ，那么定义出来的变量的 `value` 将会是 `undefined` 。
      如果你对这个不存在的 `key` 的 `ref` 变量，进行了 `value` 赋值，那么原来的对象也会同步增加这个 `key`，其值也会同步更新。

  - `toRefs` 创建一个新的对象，它的每个字段都是 `reactive` 对象各个字段的 `ref` 变量。本身是个普通对象，但是它的每个字段，都是与原来关联的 `ref` 变量

> 一般是，先用 `ref` 定义一个响应式数据，再转为 `reactive` 进行使用

<br>

### 函数的编写

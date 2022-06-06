<h1 align="center"><b>Vue.js</b></h1><br>

[TOC]

<br>

## 起步

#### 带脚手架项目文件

- 先安装 `vue-cli` 脚手架
  ```batch {.line-numbers}
  npm install -g @vue/cli
  ```
- 再创建项目
  ```batch {.line-numbers}
  vue create [options] app-name
   rem 运行
  cd app-name
  npm run server
  ```
- 或用 GUI 来创建
  ```batch {.line-numbers}
  vue ui
  ```
- 项目文件结构
- <img src="img/Vue_proj.png" width="70%">

#### 仅 Vue.min.js

直接引用文件或是 cdn：`https://unpkg.com/vue@next`

## 基本语法

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
            id: 'mie',
            class: 'haha btns',
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

### 生命周期钩子

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

<br>

## 单组件文件.vue

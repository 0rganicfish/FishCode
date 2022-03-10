<p style="font-size: 40px; color: #fff"><b>DOM</b></p>

- [README](../../../README.md)
- [JavaScript](JavaScript.md)

[TOC]

# API

## Document

**令见：**[DOM Document](DOM_Document.md)

## Element

`Element` 是一个通用性非常强的基类，所有 `Document` 对象下的对象都继承自它。这个接口描述了所有相同种类的元素所普遍具有的方法和属性。一些接口继承自 `Element` 并且增加了一些额外功能的接口描述了具体的行为。

**令见：** [DOM Element](DOM_Element.md)

## NodeList

## 其他 API

### EventTarget

EventTarget 是一个 DOM 接口，由可以接收事件、并且可以创建侦听器的对象实现。

**方法**

- `addEventListener()` 方法将指定的监听器注册到 EventTarget 上，当该对象**触发指定的事件**时，指定的回调**函数就会被执行**。

  - **定义：**

  ```JavaScript {.line-numbers}
  addEventListener(type, listener, options);
  // type：DOM事件 (没有on)
  // listener 函数或对象
  ```

  - **例：**

  ```JavaScript {.line-numbers}
  card.addEventListener("click", () => {
  console.log("Hello);
  });
  ```

###

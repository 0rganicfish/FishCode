 <h1 align="center"><b>JavaSE</b></h1><br>

- [README.md](../../README.md)

[TOC]

<br>

# 基础语法

## 第一行 Java

Java 是完全面向对象的语言，文件名与类名相同，且首字母通常大写。用 `javac *.java` 将 `*.java` 文件编译后得到二进制文件 `*.class`

```Java {.line-numbers}
import java.util.Scanner;

public class Fish {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        System.out.println(str);
    }
}
```

<br>

## 数据类型

### 基本类型

还是 `int`、`float`、`String`、`char`、`boolean`，**常量**为 `final`

- **整形：**
  - 范围： `byte`： $ \pm2^7-1$ 、 `short`： $ \pm2^{15}-1 $ 、 `int`： $ \pm2^{31}-1 $
    、`long`： $ \pm2^{63}-1 $
  - 特殊表示：长数字可以用下划线分隔： `int a = 2_0000_0000`，`0x`开头表十六进制，`0b`开头表示二进制
- **浮点型：**
  - 范围：`float`： $ \pm 3.4 \times 10^{38} $ 、`double`： $ \pm 1.79 \times 10^{308} $
  - 表示：`float` 类型要以 `f` 结尾
- **单字符：**
  - `char` 类型是一个单一的 16 位 `Unicode` 字符
  - 最小值是 `\u0000`（十进制等效值为 `0`）
  - 最大值是 `\uffff`（即为 `65535`）

<br>

### 数组

- **创建：**
  ```Java {.line-numbers}
  int[] arr = new int[len];        //指定长度但不能初始化
  int[] arr = new int[]{233, 455}; // 初始化并推断长度
  // 或直接地：
  int[] arr = {233};
  // 而字符串数组：
  String[] str = {"fish", "mie"};
  ```
- **特性：** 数组是引用型数据，直接用等号赋值数组时，两者指向同一个地址
- **方法：**

<br>

### 字符串

- **多行字符串：** 其中共同的前置空格会被去掉
  ```Java {.line-numbers}
  String str = """
          |  mie |
          |  Fish|
          |  233 |
          """
  ```
- **格式化 | 模板字符串：** 可以用类似 _C 语言_ 的`printf`，也能用 `String.format("", xx)`：
  ```Java {.line-numbers}
  public static String fun(String key, int value) {
      return String.format("""
              {
                  key: %s,
                  value: %d
              }""", key, value);
  }
  ```

<br>

## 面向对象

### 修饰符

- **控制访问权限：**
  - 默认为 `default`，只能在当前类或包下的类访问
  - `private` 只能在当前类访问
  - `protected` 可在被继承的子类访问
  - `public` 可以在任何地方被访问
- **`static`：**
  - **静态方法**
    - 静态方法可以直接 **通过类名调用**，任何对象也可以调用，因此静态方法中不存在 `this` 和 `super` 关键词
    - 静态方法 **不可以访问** 所属类的实例变量和实例方法（非静态）！因为实例变量和方法都是与对象相关的，而 **静态方法是独立于对象的**
    - `static` 方法必须被实现，不可以抽象
    - 静态方法 **可以直接调用** 同类的其他的静态成员（包括变量和方法）
    - 虽然静态方法不可以调用非静态成员，但是对象可以调用静态方法
  - **静态变量：** 可以看作 `static` 变量为一种全局变量
    - 可以被构造器和实例方法调用
    - 属于整个类而不是某一个对象
    - 不会被回收
  - **静态代码块：** 一段不依赖于类和方法的代码
    - 静态代码块在类被加载的的时候运行且只运行一次
    - 静态代码块**优先于主函数执行**。静态代码块还是写在类中，由类调用
    - 静态代码块中的变量是局部变量，和普通方法中的变量没有区别
- **`final`：**
  - `final` 修饰类时，表明这个类 **不能被继承**。 且类中的所有成员方法都会被**隐式地**指定为 `final` 方法
  - `final` 修饰方法时，表明这个方法 **不能被任何子类重写**，因此，如果只有在想明确禁止该方法在子类中被覆盖的情况下才将方法设置为 `final`
  - `final` 修饰变量分为两种情况，一种是修饰基本数据类型，表示数据类型的**值不能被修改**； 一种是修饰引用类型，表示对其初始化之后便**不能再让其指向另一个对象**
- **`this`：**
  - 指向对象本身，或对象中的变量
  - `this(args)` 用于调用构造函数
- **`super`：** 和 `this` 差不多，但指向了被继承的父类。且：调用 `super()` 必须写在子类构造方法的第一行，否则编译不通过

### 函数

- **可变参数列表：** 传入的参数个数可变，可为数组，参数最终体现的是**数组**类型
  ```Java {.line-numbers}
  public static int add(int... numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    System.out.println(Arrays.toString(numbers));
    return sum;
  }
  ```

<br>

# 数据结构（STL）

**[STL 详解](https://blog.csdn.net/u010183728/article/details/81913729)**

- [首页](main.md)
- [数据结构（STL）](#数据结构stl)
  - [**序列式容器（可序）**](#序列式容器可序)
    - [**Vector**](#vector)
    - [**deque**](#`deque`)
    - [**List**](#list)
  - [**关联式容器 （已序）**](#关联式容器-已序)
    - [**Map、multimap**](#mapmultimap)
    - [**Set、multiset**](#setmultiset)
  - [**其他**](#其他)
    - [**Stack**](#stack)
    - [**queue、priority_queue**](#queuepriority_queue)
  - [**迭代器**](#迭代器)
  - [**STL 函数**](#stl-函数)

</br></br>

## **序列式容器（可序）**

### **Vector**

```C++ {.line-numbers}
vector<int>a;        初始化则是 vector<int>a(10, 1);  a有10个为1的元素
cin >> x;
a.push_back(x);
int pos = find(a.begin(), a.end(), x) //返回位置
a.pop_back(); 移出最后一个元素

同时也能当做数组来使用：a[i]， sort(a.begin(), a.end());
定义动态二维数组：vector<vector<int> > shu(N, vector<int>(M)); -->N行M列

#include<vector>
vector<int> a, b; //tw
1. a.push_back(x)  在数组的最后添加一个数据
2. a.pop_back()  去掉数组的最后一个数据
3. a.at(pos)  得到编号位置的数据
4. a.begin()  得到数组头的指针
5. a.end()   得到数组的最后一个单元 + 1 的指针
6. a.front()  得到数组头的引用
7. a.back()  得到数组的最后一个单元的引用
8. a.max_size()   得到vector最大可以是多大
9. a.capacity()   当前vector分配的大小
10. a.size()   当前使用数据的大小
11. a.resize()   改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
12. a.reserve()   改变当前vecotr所分配空间的大小
13. a.erase(pos)   删除指针指向的数据项
14. a.clear()   清空当前的vector
15. a.rbegin()   将vector反转后的开始指针返回(其实就是原来的end-1)
16. a.rend()   将vector反转构的结束指针返回(其实就是原来的begin-1)
17. a.empty()   判断vector是否为空
18. a.swap(b)   与另一个vector交换数据
```

---

### **deque**

#### deque（双向队列）的一些特点

- 支持随机访问，即支持[ ]以及 at()，但是性能没有`vector`好。
- 可以在内部进行插入和删除操作，但性能不及`list`。
- `deque`两端都能够快速插入和删除元素，而`vector`只能在尾端进行。
- `deque`的元素存取和迭代器操作会稍微慢一些，因为`deque`的内部结构会多一个间接过程。
- `deque`迭代器是特殊的智能指针，而不是一般指针，它需要在不同的区块之间跳转。
- `deque`可以包含更多的元素，其`max_size`可能更大，因为不止使用一块内存。
- `deque`不支持对容量和内存分配时机的控制。
- 在除了首尾两端的其他地方插入和删除元素，都将会导致指向`deque`元素的任何`pointers`、`references`、`iterators`失效。不过，`deque`的内存重分配优于`vector`，因为其内部结构显示不需要复制所有元素。
- `deque`的内存区块不再被使用时，会被释放，`deque`的内存大小是可缩减的。不过，是不是这么做以及怎么做由实际操作版本定义。
- `deque`不提供容量操作：`capacity()`和`reverse()`，但是`vector`可以。

---

### **List**

#### list 定义

- List 是 stl 实现的双向链表，与向量(`vectors`)相比, 它允许快速的插入和删除，但是随机访问却比较慢。

</br></br>

## **关联式容器 （已序）**

### **Map、multimap**

- 对 `map` 的定义：
  ```C++ {.line-numbers}
  template <class Key, class Value, class Compare = less<Key> > ... map
  ```
- 所以定义`map`的时候，默认是按`key`的值小到大排序的。要按大到小时， 就`map<xxx, xxx, greater<key> >xxx`

- 当要按`Value`，或自定义`key`来排序时，要另外写 cmp 函数（重载）：

  ```C++ {.line-numbers}
  struct CmpByKeyLength {   //以key的长度来排序
  bool operator()(const string& k1, const string& k2) {
      return k1.length() < k2.length();
  }
  };
  map<string, int, CmpByKeyLength> xx;
  ```

- 按 **`Value`** 排序：

  ```C++ {.line-numbers}
  typedef pair<string, int> PAIR;
  bool cmp_by_value(const PAIR &lhs, const PAIR &rhs)
  {
      return lhs.second < rhs.second;
  }

  int main()
  {
      map<string, int> name_score;
      // 输入map数据 ......
      vector<PAIR> ns_vec(name_score.begin(), name_score.end());
      sort(ns_vec.begin(), ns_vec.end(), cmp_by_value);

      for (int i = 0; i != ns_vec.size(); ++i)
          cout << ns_vec[i].first << " " << ns_vec[i].second << endl;
  }
  ```

  ```C++ {.line-numbers}
  插入：  s.insert(make_pair( 1, "abcd") );
  指定位置插入:  map<int, string>::iterator it = shop.begin();
                shop.insert(it, make_pair(3, "qaq"));

  map 的 find() 函数用来查找 key 的，返回迭代器：
    auto it = map.find(key);
    cout << it->map.second;
  没找到则返回 map.end()
  ```

---

### **Set、multiset**

</br></br>

## **其他**

### **Stack**

```C++ {.line-numbers}
x = n.top();           //取栈与栈运算
n.pop();
y = n.top();
n.pop();
n.push(x + y);

while (!n.empty())  来循环操作栈
```

---

### **queue、priority_queue**

- queue

  ```C++ {.line-numbers}
  #include <queue>
  queue<int>a;
  n.push(n.front())   ///实现队列的循环  push是在队列的尾部添加
  n.back();            //pop是删除队列的第一个元素
  ```

- 优先队列

  - 定义：`priority_queue<元素类型, 基础序列的类型，比较的类型> name;`
    基础序列默认为 `vector` ，比较类型默认为 `less<value_type>`

    ```C++ {.line-numbers}
    priority_queue <pair<int, int>, vector<pair<int, int> >, cmp> q;
    priority_queue <int,vector<int>,greater<int> > q;
    ```

  - 一则：

    ```C++ {.line-numbers}
    typedef pair<int, int> Pair;
    struct cmp
    {
        bool operator()(const Pair &a, const Pair &b)
        {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        } // 先按first小到大排序，first相等时按second小到大排序
    };
    ostream &operator<<(ostream &out, const Pair &O)
    {
        return out << "(" << O.first << ", " << O.second << ")" << endl;
    }  // 重载输出符 <<
    int main()
    {
        priority_queue<Pair, vector<Pair>, cmp> q;
        int n, a, b;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a >> b, q.push(make_pair(a, b));
        while (!q.empty())  // 队列没有迭代器
            cout << q.top(), q.pop();
    }
    ```

</br></br>

## **迭代器**

- 迭代器要遍历，随机访问是指用下标或 at()

  - vector 随机访问， `deque` 随机访问， stack 不支持， queue 不支持， priority_queue 不支持

  - list 双向，set 双向， multiset 双向 ， map 双向， multimap 双向

</br></br>

## **STL 函数**

1.

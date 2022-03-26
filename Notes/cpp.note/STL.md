# 数据结构（STL）

**[STL 详解](https://blog.csdn.net/u010183728/article/details/81913729)**

- [首页](main.md)

[TOC]

<br><br>

## 序列式容器（可序）

### Vector

- 一些定义

```C++ {.line-numbers}
vector<int>a;        初始化则是 vector<int>a(10, 1);  a有10个为1的元素
cin >> x;
a.push_back(x);
int pos = find(a.begin(), a.end(), x) //返回位置
a.pop_back(); 移出最后一个元素
```

- 同时也能当做数组来使用：a[i]， `sort(a.begin(), a.end());`

- 定义动态二维数组：`vector<vector<int> > shu(N, vector<int>(M));` -->N 行 M 列

- `vector<int> a, b;`

  1. `a.insert(a.begin() + n, x)` 在 下标 n - 1 之前插入 x
  2. `a.push_back(x)` 在数组的最后添加一个数据
  3. `a.pop_back()` 去掉数组的最后一个数据
  4. `a.at(pos)` 得到编号位置的数据
  5. `a.begin()` 得到数组头的指针
  6. `a.end()` 得到数组的最后一个单元 + 1 的指针
  7. `a.front()` 得到数组头的引用
  8. `a.back()` 得到数组的最后一个单元的引用
  9. `a.max_size()` 得到 `vector` 最大可以是多大
  10. `a.capacity()` 当前 `vector` 分配的大小
  11. `a.size()` 当前使用数据的大小
  12. `a.resize()` 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
  13. `a.reserve()` 改变当前 `vecotr` 所分配空间的大小
  14. `a.erase(a.begin() + n)` 删除 下标 n 的元素， (也可以有范围)
  15. `a.clear()` 清空当前的 `vector`
  16. `a.rbegin()` 将 `vector` 反转后的开始指针返回(其实就是原来的 end-1)
  17. `a.rend()` 将 `vector` 反转构的结束指针返回(其实就是原来的 begin-1)
  18. `a.empty()` 判断` vector` 是否为空
  19. `a.swap(b)` 与另一个 `vector` 交换数据

---

### deque

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

### List

#### list 定义

- List 是 stl 实现的双向链表，与向量(`vectors`)相比, 它允许快速的插入和删除，但是随机访问却比较慢。
- 可以直接` s.sort();` 或 `s.sort(greater<name>());`

<br><br>

## 关联式容器 （已序）

### Map、multimap

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

### Set、multiset

- set 也是在输入时排序、去重
- `set` 的定义
  ```C++ {.line-numbers}
  set<class key, class compare = less<key_name> >name;
  ```
- 一些函数：
  ```C++ {.line-numbers}
  a.insert(key)  //插入key
  a.erase(key)  //删除key
  a.erase(*a.begin() + n)  //删除下标n
  ```
- 其实道理和 map 差不多 hh
  <br><br>

## 其他

### Stack

```C++ {.line-numbers}
x = n.top();           //取栈与栈运算
n.pop();
y = n.top();
n.pop();
n.push(x + y);

while (!n.empty())  来循环操作栈
```

---

### queue、priority_queue

#### queue

```C++ {.line-numbers}
#include <queue>
queue<int>a;
n.push(n.front())   ///实现队列的循环  push是在队列的尾部添加
n.back();            //pop是删除队列的第一个元素
```

#### 优先队列

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
      } // 先按first小到大排序，first相等时按second小到大排序, 而且与 sort 的 cmp 的 < 相反
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

  当然，也可以用 `struct` 代替 `pair`

  ```C++ {.line-numbers}

  struct student
  {
    string name;
    int score;
  };
  struct cmp
  {
    bool operator()(const student &a, const student &b) const
    {
        return a.score < b.score || (a.score == b.score && a.name > b.name);
    }
  };
  priority_queue <student, vector<student>, cmp> pq;
  // in main:
  string name;
  int score;
  cin >> name >> score;
  pq.push({name, score});
  ```

<br><br>

## 迭代器

- 迭代器要遍历，随机访问是指用下标或 at()

  - `vector` 随机访问， `deque` 随机访问， `stack` 不支持， `queue` 不支持， `priority_queue` 不支持

  - `list` 双向，`set` 双向， `multiset` 双向 ， `map` 双向， `multimap` 双向

<br><br>

## STL 函数

- `find`：顺序查找。

  - `find(v.begin(), v.end(), value)`，其中 `value` 为需要查找的值。

- `find_end`：逆序查找。

  - `find_end(v.begin(), v.end(), value)`。

- `reverse`：翻转数组、字符串。

  - `reverse(v.begin(), v.end())` 或 `reverse(a + begin, a + end)`。

- `unique`：去除容器中相邻的重复元素。

  - `unique(ForwardIterator first, ForwardIterator last)`，返回值为指向 **去重后** 容器结尾的迭代器，原容器大小不变。与 `sort` 结合使用可以实现完整容器去重。

- `random_shuffle`：随机地打乱数组。

  - `random_shuffle(v.begin(), v.end())` 或 `random_shuffle(v + begin, v + end)`。

- `sort`：排序。

  - `sort(v.begin(), v.end(), cmp)` 或 `sort(a + begin, a + end, cmp)`，其中 `end` 是排序的数组最后一个元素的后一位，cmp 为自定义的比较函数。

- `stable_sort`：稳定排序，用法同 `sort()`。

- `nth_element`：按指定范围进行分类，即找出序列中第 大的元素，使其左边均为小于它的数，右边均为大于它的数。

  - `nth_element(v.begin(), v.begin() + mid, v.end(), cmp)` 或 `nth_element(a + begin, a + begin + mid, a + end, cmp)`。

- `binary_search`：二分查找。

  - `binary_search(v.begin(), v.end(), value)`，其中 `value` 为需要查找的值。

- `merge`：将两个（已排序的）序列 **有序合并** 到第三个序列的 **插入迭代器** 上。

  - `merge(v1.begin(), v1.end(), v2.begin(), v2.end() ,back_inserter(v3))`。

- `inplace_merge`：将两个（已按小于运算符排序的）：

  - `[first,middle), [middle,last)` 范围 **原地合并为一个有序序列**。

  - `inplace_merge(v.begin(), v.begin() + middle, v.end())`。

- `lower_bound`：在一个有序序列中进行二分查找，返回指向第一个 **大于等于** 的元素的位置的迭代器。如果不存在这样的元素，则返回尾迭代器。

  - `lower_bound(v.begin(),v.end(),x)`。

- ` upper_bound`：在一个有序序列中进行二分查找，返回指向第一个 **大于** 的元素的位置的迭代器。如果不存在这样的元素，则返回尾迭代器。

  - `upper_bound(v.begin(),v.end(),x)`。

- `next_permutation`：将当前排列更改为 **全排列中的下一个排列**。

  - 如果当前排列已经是 **全排列中的最后一个排列**（元素完全从大到小排列），函数返回 `false` 并将排列更改为 **全排列中的第一个排列**（元素完全从小到大排列）；否则，函数返回 `true`。
  - `next_permutation(v.begin(), v.end()) ` 或 `next_permutation(v + begin, v + end)`。

- `partial_sum`：求前缀和。

  - 设源容器为 $ x $，目标容器为 $ y$ ，则令 $ y[i]=x[0]+x[1]+...+x[i] $ 。
  - `partial_sum(src.begin(), src.end(), back_inserter(dst))`。

- `*max_element`: 返回最大元素的迭代器

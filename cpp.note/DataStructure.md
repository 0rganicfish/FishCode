# 数据结构（STL）

**[STL 详解](https://blog.csdn.net/u010183728/article/details/81913729)**

- [首页](main.md)
- [序列式容器（可序）](#序列式容器可序)
  - [Vector](#vector)
  - [Deque](#deque)
  - [List](#list)
- [关联式容器 （已序）](#关联式容器-已序)
  - [Map、multimap](#mapmultimap)
  - [Set、multiset](#setmultiset)
- [其他](#其他)
  - [Stack](#stack)
  - [queue、priority_queue](#queuepriority_queue)
- [迭代器](#迭代器)
- [STL函数](#stl函数)


</br></br>

## **序列式容器（可序）**
### **Vector**

  ```C++
  vector<int>a;        初始化则是 vector<int>a(10, 1);  a有10个为1的元素
  cin >> x;
  a.push_back(x);
  int pos = find(a.begin(), a.end(), x) //返回位置
  a.pop_back(); 移出最后一个元素

  同时也能当做数组来使用：a[i]， sort(a.begin(), a.end());
  定义动态二维数组：vector<vector<int> > shu(N, vector<int>(M)); -->N行M列

  #include<vector>
  vector<int> a,b;
  1. push_back  在数组的最后添加一个数据
  2. pop_back  去掉数组的最后一个数据
  3. at  得到编号位置的数据
  4. begin  得到数组头的指针
  5. end   得到数组的最后一个单元+1的指针
  6. front  得到数组头的引用
  7.back  得到数组的最后一个单元的引用
  8.max_size   得到vector最大可以是多大
  9.capacity   当前vector分配的大小
  10.size   当前使用数据的大小
  11.resize   改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
  12.reserve   改变当前vecotr所分配空间的大小
  13.erase   删除指针指向的数据项
  14.clear   清空当前的vector
  15.rbegin   将vector反转后的开始指针返回(其实就是原来的end-1)
  16.rend   将vector反转构的结束指针返回(其实就是原来的begin-1)
  17.empty   判断vector是否为空
  18.swap   与另一个vector交换数据
  ```

---

### **Deque**


---

### **List**


</br></br>

## **关联式容器 （已序）**
### **Map、multimap**

  ```C++
      map<string, int> shop;
      int n, t, sum = 0;
      string s;
      cin >> n;
      while (n--)
      {
          cin >> s >> t;
          shop[s] += t;
      }
      for (auto i = shop.begin(); i != shop.end(); i++)
          sum += i->second;
      cout << sum;
  ```

  ```C++
  插入：  s.insert( pair<int, string>( 1, "abcd") );   且会有返回值：bool类型
  指定位置插入：  map<int, string>::iterator it = shop.begin();
              shop.insert(it, pair<int, string>(3, "qaq"));
  ```

---

### **Set、multiset**

</br></br>

## **其他**
### **Stack**

  ```C++
  x = n.top();           //取栈与栈运算
  n.pop();
  y = n.top();
  n.pop();
  n.push(x + y);

  while (!n.empty())  来循环操作栈
  ```

---

### **queue、priority_queue**

  ```C++
  #include <queue>
  queue<int>a;

  n.push(n.front())   ///实现队列的循环  push是在队列的尾部添加
  n.back();            //pop是删除队列的第一个元素
  ```

</br></br>

## **迭代器**

- 迭代器要遍历，随机访问是指用下标或 at()

    - vector 随机访问， deque 随机访问， stack 不支持， queue 不支持， priority_queue 不支持

    - list 双向，set 双向， multiset 双向 ， map 双向， multimap 双向

</br></br>

## **STL函数**

1. 
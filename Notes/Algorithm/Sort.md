# 排序

- [首页](Main.md)
- [图解排序](https://zhuanlan.zhihu.com/p/437834776)

[TOC]

### 选择排序

```C++ {.line-numbers}
void pai(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minn = i;
        for (int j = i + 1; j < n; j++)
            if (a[minn] > a[j])
                minn = j;
        swap(a[i], a[minn]);
    }
}
```

### 空间换时间的桶排序

```C++ {.line-numbers}
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        t[a[i]]++;
    }
    for (i = 0, j = 0; i < MAX; i++)
         while (t[i]--)
            a[j++] = i;
```

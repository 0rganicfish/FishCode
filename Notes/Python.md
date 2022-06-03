 <p style="font-size: 40px; color: #fff; " align="center"><b>Python.note</b></p>

- [README.md](../README.md)
  [TOC]

# 一些语法

# 库

# 其他

## 打包 exe

若需将 `xxx.py` 文件打包，只需在 `xxx.py` 文件所在目录下终端执行：

```powershell
pyinstaller xxx.py
```

常用可选项及说明：

- -F：打包后只生成单个 exe 格式文件；
- -D：默认选项，创建一个目录，包含 exe 文件以及大量依赖文件；
- -c：默认选项，使用控制台(就是类似 cmd 的黑框)；
- -w：不使用控制台；
- -p：添加搜索路径，让其找到对应的库；
- -i：改变生成程序的 icon 图标。

<h1 align="center"><b>Chaos 不好分类的杂在一起</b></h1><br>

[TOC]

<br>

# npm | pnpm ...

- **切换下载源：** `npm config set registry https://registry.npmmirror.com/`
- **发布：**
  - **登录或注册：** `npm adduser | login`
  - **发布：** `npm publish`
  - **同步到淘宝源：** 到 https://npmmirror.com 搜索包，再同步

<br>

# git | Github

- **git 的一些：**
  - `git clone [url]`：克隆项目 / `git pull` 拉取最新代码
  - `git remote`： 查看是否有远程仓库
    没有远程仓库 ---> `git remote add [远程仓库名] [远程地址]`： 配置远程仓库
  - `git branch -b [新分支名]`： 创建新的分支，在新分支上修改代码
  - `git add.` ：提交
  - `git commit -m '描述'`： 提交
  - `git checkout [分支名]`： 切换到要合并的分支
  - `git merge [分支名]`： 把修改代码的分支合并到当前分支
  - `git push [远程仓库名] [分支名]`： 提交到远程仓库
  - `git branch -d [分支名]`： 删除之前修改代码的分支,删之前先 `branch` 查看
  - `git clone [url]`： 克隆代码
  - `git checkout [分支名]`： 切换到最新的开发分支，如 `git checkou dev`
  - `git checkout -b [分支名]`： 将当前分支复制到新的分支进行开发，如 `git checkout -b my_dev`
- 提交代码前先更新远程的代码，但如果当前分支修改了代码没有提交，更新下来的代码可能会导致与当前未提交的代码冲突或被覆盖。
  ```batch {.line-numbers}
  git stash  // 将当前修改但未提交的代码弹出
  git pull或git pull origin [分支名] // 更新代码
  git stash pop // 将弹出的代码取出
  git add .
  git commit -m '描述'
  git push
  ```

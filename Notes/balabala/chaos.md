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
  - `git remote`： 查看是否有远程仓库
    没有远程仓库 ---> `git remote add [远程仓库名] [远程地址]`： 配置远程仓库
  - `git clone [url]`：克隆项目 / `git pull` 拉取最新代码
  - `git status`：本地仓库状态
  - `git add.` ：提交到暂存区中
  - `git commit -m '描述'`： 提交到本地仓库中
  - `git push [远程仓库名] [分支名]`： 提交到远程仓库
- **分支：**
  - `git branch`：列出本地的所有分支，当前所在分支以 "\*" 标出
  - `git branch -v`：列出本地的所有分支并显示最后一次提交，当前所在分支以 "\*" 标出
  - `git branch -b [新分支名]`： 创建新的分支，在新分支上修改代码
  - `git branch -d [分支名]`： 删除之前修改代码的分支,删之前先 `branch` 查看
  - `git branch -m [<原分支名称>] <新的分支名称>`：修改分支名
  - `git checkout [分支名]`： 切换到指定的分支
  - `git checkout -b [分支名]`： 将当前分支复制到新的分支进行开发。等同于 `git branch` 和 `git checkout` 两个命令合并
  - `git merge [分支名]`： 把修改代码的分支合并到当前分支
- 提交代码前先更新远程的代码，但如果当前分支修改了代码没有提交，更新下来的代码可能会导致与当前未提交的代码冲突或被覆盖。所以： `git stash`：放弃当前更改

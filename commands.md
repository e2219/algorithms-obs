```shell
# 改变当前工作目录
cd <path_to_directory>
# list directory's items
ls <path_to_directory>
# 打印文件的前 x 行
head -nx <path_to_file>
# 在 file 中搜素含有关键字 key 的行
grep <key> <file> 
# 打印文件内容
cat <path_to_file>
# 寻找符合特定条件的文件
find ~/Downloads -type f -size +100M -exec -lh {} \; -mtime +30
find /path/to/dir -name "com*"
find . -name "*.md" -exec -grep -l "TODO" {}\;


ls -l /

以长格式（-l）列出(ls)根目录(/)的内容
长格式(-l)： 显示详细信息(权限 所有者 大小 时间)
drwxr-xr-x   4 root root       4096 Jan 27 22:06 boot


find ~/Downloads -type f -name "*.zip" -mtime +30

glob 是一种文件名匹配形式，用于将通识符(*)展开为实际的文件名
ls *.txt    ls file? .txt(?匹配单个字符)    ls {a,b,c}.txt

'...'    "..."    $'...'
'...': 完全禁止展开，完全引用，原封不动，写啥是啥
"...": 允许变量和命令展开。（保留整体，部分展开）
"$HOME *.c"   ->    /home/fhy *.c
可转义的有限 (\"  \\  \$  \`)
$'...': 支持C风格转译
!: 不会被双引号保护，在" "中会历史展开 返回上个操作 ep. !ls   !!


```

TODO: 自己手动运行一遍
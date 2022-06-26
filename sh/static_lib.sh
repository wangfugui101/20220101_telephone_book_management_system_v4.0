#! /bin/bash
#制作目标文件.o
gcc source/add_menu.c -o source/add_menu.o -c -I ./include
gcc source/delete_menu.c -o source/delete_menu.o -c -I ./include
gcc source/file.c -o source/file.o -c -I ./include
gcc source/interface.c -o source/interface.o -c -I ./include
gcc source/other.c -o source/other.o -c -I ./include
gcc source/query_menu.c -o source/query_menu.o -c -I ./include
gcc source/show_menu.c -o source/show_menu.o -c -I ./include
gcc source/update_menu.c -o source/update_menu.o -c -I ./include
#将所有.o文件合成一个.a文件
ar rcs ./library/libmy_static.a ./source/*.o
#删除所有的.o文件
rm ./source/*.o
echo 该系统静态库制作完成
#执行make命令,编译的命令会变成make
make
clear
./bin/contacts
### 1. linux下编译运行c++程序
```
g++ -W file_name.cpp -o another_name
./file_name
```
- -W: 输入错误信息

1. 字符数组的输入输出

   - `scanf`输入，`printf`输出

     ```c++
     #include <stdio.h>
     int main(){
         char str[10];
         scanf("%s", str);
         printf("%s", str);
         return 0;
     }
     ```

     **注**：`%s`识别`空格`作为字符串的结尾；`scanf`在使用`%s`时，对应数组名是不需要加`&`运算符的。
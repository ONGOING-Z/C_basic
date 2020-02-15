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

2. 数组初始化符号`{}`

3. `ascii`

   A: 65; a: 97
   
4. 结构体的初始化

   ```c++
   scanf("%d %c %d", &a, &data, &b);
   node[a] = {data, b, false};
   ```

5. ```c++
   printf("%05d", i);
   ```

   使不足５位的整数的高位补０。

6. ```c++
   scanf("%d %c");
   ```

   // `scanf()`使用`%c`可以读入`空格`，要注意格式！
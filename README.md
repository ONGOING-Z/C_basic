# C Basic

[toc]

## 一、一些细节

1. linux下编译运行c++程序

```bash
g++ -W file_name.cpp -o another_name
./file_name
```

`-W`: 输出错误信息

1. 字符数组的输入输出
    `scanf`输入，`printf`输出

    ```c++
    #include <stdio.h>
    int main(){
        char str[10];
        scanf("%s", str);
        printf("%s", str);
        return 0;
    }
    ```

    注: `%s`识别`空格`作为字符串的结尾；`scanf`在使用`%s`时，对应数组名是不需要加`&`运算符的。

2. 数组初始化符号`{}`
3. A/a的ascii值
   A: 65; a: 97
4. 结构体的初始化

    ```c++
    scanf("%d %c %d", &a, &data, &b);
    node[a] = {data, b, false};  // 注意时花括号，和数组初始化一样。
    ```

5. 输出补位

    ```c++
    printf("%05d", i);  // 使不足５位的整数的高位补０。
    printf("%5d", i);  // 使不足５位的整数的高位补为空。
    ```

6. %c读入空格

    ```c
    scanf("%d %c");
    ```

    `scanf()`使用`%c`可以读入`空格`，要注意格式！

7. 使用new运算符为链表结点分配内存空间

    使用方法：`typename *p = new typename;`

    ```c++
    int *p = new int;
    node *p = new node;
    int *p = new arr[10000];
    ```

8. `memset`对数组中每一个元素赋相同的值

   格式：`memset(name, value, sizeof(name))`

   前提条件：添加`string.h`

   *建议赋值为0或-1*, 不易出错。

9. Get array length(C)

    ```c
    int arr[];
    int length = sizeof(arr)/sizeof(arr[0]); // 总字节数/第一个元素字节数
    ```

10. define

    `#define 名字 替换文本`

    （1）符号常量通常用大写字母拼写
    （2）末尾无分号

### 二、c++

#### 1. vector

> 使用：`#include<vector>`；除此之外，还需加上`using namespace std;`

##### （1）定义

```c++
vector<typename> name;
```

初始化: `vector<int> abc(10);`,初始化了10个默认值为0的元素.
初始化: `vector<int> temp = { 4, 1, 2, 1, 2 };`
*注：其长度可以根据需要进行变化，“变长数组”*

##### （2）vector容器内元素的访问

例子 

```c++
vector<typename> vi;
```

- 通过`下标`访问

  ```c++
  vi[index];  // 下标从为0~vi.size()-1
  ```

- 通过`迭代器`访问

  迭代器(iterator)定义：`vector<typename>::iterator it;`
  // it 是一个 vector<typename>::iterator 型的变量
  // 这样得到了迭代器it，访问vector里的内容方式如下：

  ```c++
  *it
  ```

  ```c++
  // 测试vector
  #include <cstdio>
  #include <vector>
  using namespace std;
  int main(){
      vector<int> vi;
      for(int i = 1; i <= 5; i++){
          vi.push_back(i);
      }
      vector<int>::iterator it = vi.begin(); // vi.begin()取vi首元素地址
      for(int i = 0; i < 5; i++){
          printf("%d\n", *(it+i));
      }
      return 0;
  }
  ```

  ```c++
  // vector_test_2
  #include <cstdio>
  #include <vector>
  using namespace std;
  int main(){
      vector<int> vi;
      for(int i = 1; i <= 5; i++){
          vi.push_back(i);
      }
      for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
          printf("%d ", *it);
      }
      return 0;
  }
  ```

##### （3）vector常用函数

- `push_back()`

  push_back(x): 在vector后添加元素x，时间复杂度`O(1)`

  ```c++
  // vector_test_3
  // push_back()
  #include <cstdio>
  #include <vector>
  using namespace std;
  int main(){
      vector<int> vi;
      for(int i = 1; i <=3; i++){
          vi.push_back(i);
      }
      for(int i = 0; i < 3; i++){
          printf("%d ", vi[i]);
      }
      return 0;
  }
  ```

- `pop_back()`

  pop_back(): 删除vector尾元素，时间复杂度`O(1)`

  ```c++
  // vector_test_4
  // pop_back()
  #include <cstdio>
  #include <vector>
  using namespace std;
  int main(){
      vector<int> vi;
      for(int i = 1; i <= 5; i++){
          vi.push_back(i);
      }
      vi.pop_back();
      for(int i = 0; i < vi.size(); i++){
          printf("%d ", vi[i]);
      }
      return 0;
  }
  // result: 1 2 3 4
  ```

- size()

  用来获得vector中元素个数，时间复杂度`O(1)`

- clear()

  用来清空vector中的所有元素，时间复杂度`O(n)`

- insert()

  `insert(it, x)`: 向vector迭代器it处插入元素x，时间复杂度`O(N)`

  ```c++
  // vector_test_7
  // insert(it, x)
  #include <cstdio>
  #include <vector>
  using namespace std;
  int main(){
      vector<int> vi;
      for(int i = 1; i <= 3; i++){
          vi.push_back(i);
      }
      vi.insert(vi.begin()+2, -1);
      for(int i = 0; i < vi.size(); i++){
          printf("%d ", vi[i]);
      }
      return 0;
  }
  // result: 1 2 -1 3
  ```

- erase()

  时间复杂度均为`O(N)`

  - 删除单个元素 erase(it)

    ```c++
    // vector_test_8
    // erase()
    #include <cstdio>
    #include <vector>
    using namespace std;
    int main(){
        vector<int> vi;
        for(int i = 1; i <= 5; i++){
            vi.push_back(i);
        }
        vi.erase(vi.begin()+3);
        for(int i = 0; i < vi.size(); i++){
            printf("%d\n", vi[i]);
        }
        return 0;
    }
    // result: 1 2 3 5
    ```

    

  - 删除区间所有元素 erase(first, last) **左开右闭**

    

  

  

  

  

#### 2. stack

##### （1）定义

添加`#include <stack>`与`using namespace std;`

定义写法：

```c++
stack<typename> name;
```



##### （2）stack容器内元素访问

后进先出，只能通过`top()`访问栈顶元素。

##### （3）常用函数

- push()

  push(x): 将x入栈，时间复杂度`O(1)`

- top()

  top(): 获得栈顶元素，时间复杂度`O(1)`

- pop()

  pop(): 弹出栈顶元素，时间复杂度`O(1)`

- empty()

  检测stack是否为空。返回`true`为空。时间复杂度`O(1)`

- size()

  返回stack内元素个数。时间复杂度`O(1)`

#### 3. string

##### （1）定义

添加`#include <string>`与`using namespace std`

`string str;`

初始化：`string str = "abcd";`

##### （2）string中内容访问

- 通过下标访问

  `str[i]`

- 通过迭代器访问

  定义：`string::iterator it;`

  通过`*it`访问string中的每一位。

  ```c++
  // string_test_3
  #include <cstdio>
  #include <string>
  using namespace std;
  int main(){
      string str = "abcd";
      for(string::iterator it = str.begin(); it != str.end(); it++){
          printf("%c", *it);
      } 
      return 0;
  }
  ```

  

##### （3）常用函数

#### 4. queue

##### （1）定义

预先条件：

```c++
#include <queue>
using namespace std;
```

`queue<typename> name;`

##### （2）容器内元素访问

通过`front()`访问队首元素，通过`back()`访问队尾元素。

```c++
// queue_test_1
#include <cstdio>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    for(int i = 0; i < 5; i++) {
        q.push(i);
    }
    printf("%d %d\n", q.front(), q.back());
    return 0;
}
result:
0 4
```

##### （3）常用函数

- push()

  `push(x)`：将x入队。

  时间复杂度：`O(1)`

- front()/back()

  时间复杂度：`O(1)`

- pop()

  pop()：出队

  时间复杂度：`O(1)`

- empty()

  检测q是否为空，为空返回true.

  时间复杂度：`O(1)`

- size()

  返回元素个数。

  时间复杂度：`O(1)`

##### （4）用途

- 广度优先搜索

#### 5. algorithm头文件下常用函数

> 须添加`using namespace std;`

##### （1）max()/min()/abs()

- max(x, y): 返回x, y中最大值

- min(x, y): 返回x, y中最小值

  **参数必须是两个， 可以是浮点数**

- max(x, max(y, z)): 返回三者中最大值

- abx(x): 返回x绝对值  // **x必须是整数**

- fabs(x): **浮点数绝对值，使用`math`头文件**

##### （2）swap()

- swap(x, y): 交换x和y的值

##### （3）reverse()

- reverse(it, it2): 将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素进行反转。

  ```c++
  // algorithm_test_3
  #include <cstdio>
  #include <algorithm>
  using namespace std;
  int main(){
      int a[10] = {10, 11, 12, 13, 14, 15};
      reverse(a, a+4);
      for(int i = 0; i < 6; i++){
          printf("%d ", a[i]);
      }
      return 0;
  }
  result: 13 12 11 10 14 15
  ```

##### （4）sort()

- 如何使用sort排序

  - 使用

    ```c++
    #include <algorithm>
    using namespace std;
    ```

    `sort(首元素地址(必填), 尾元素地址(必填), 比较函数(非必填))`

    注：不写比较函数，默认递增排序

    ```c++
    // algorithm_test_4
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int main(){
        int a[6] = {9, 4, 2, 5, 6, -1};
        sort(a, a+4); // [0, 4)
        for(int i = 0; i < 6; i++)
            printf("%d ", a[i]);
        printf("\n");
        sort(a, a+6); // [0, 6)
        for(int i = 0; i < 6; i++)
            printf("%d ", a[i]);
        return 0;
    }
    result:
    ```

    ![img_1](images/img_1.png)

-  如何实现比较函数cmp

  - 基本数据类型数组的排序

    ```c++
    // 实现从大到小排序
    // algorithm_test_5
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    
    bool cmp(int a, int b){
        return a > b;  // 当a>b时，a放在b前边
    }
    int main(){
        int a[] = {1, 2, 3, 4};
        sort(a, a+4, cmp);
        for(int i = 0; i < 4; i++){
            printf("%d ", a[i]);
        }
        return 0;
    }
    result:
    4 3 2 1
    ```

  - 结构体数组的排序

    定义如下结构体：

    ```c++
    struct node{
        int x, y;
    }ssd[10];
    ```

    **将ssd数组按x从大到小排序**：

    ```c++
    bool cmp(node a, node b){
        return a.x > b.x;
    }
    ```

    eg.

    ```c++
    // algorithm_test_6
    // 结构体数组的排序
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    
    struct node{
        int x, y;
    }ssd[10];
    bool cmp(node a, node b){
        return a.x > b.x;
    }
    
    int main(){
        ssd[0].x = 2;
        ssd[0].y = 2;
        ssd[1].x = 1;
        ssd[1].y = 3;
        ssd[2].x = 3;
        ssd[2].y = 1;
        sort(ssd, ssd+3, cmp);
        for(int i = 0; i < 3; i++){
            printf("%d %d\n", ssd[i].x, ssd[i].y);
        }
        return 0;
    }
    ```

    result:

    ![img_2](images/img_2.png)

##### (5) fill

- 将数组或容器中某一段区间赋为某个相同的值。==赋值可以是数组类型对应的任何值==

```c++
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    fill(a, a+5, 23);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
result:
23 23 23 23 23
```



#### 6. map

> 翻译为映射。
>
> 例如在定义数组时，是定义了一个从`int`到`int`的映射，如`arr[0] = 5`是将0映射到5.
>
> map可以将任何基本类型映射到任何基本类型。

##### （1）定义

- 前提条件

  ```c++
  #include <map>
  using namespace std;
  ```

- map定义

  ```c++
  map<typename1, typename2> mp;
  ```

  注：如果是字符串到整型的映射，必须使用`string`而不能用`char数组`

  ```c++
  map<string, int> mp;
  ```

##### （2）容器内元素访问

- 通过下标访问

  ```c++
  // map_test_1
  #include <cstdio>
  #include <map>
  using namespace std;
  int main() {
      map<char, int> mp;
      mp['c'] = 20;
      mp['c'] = 30;
      printf("%d\n", mp['c']);
      return 0;
  }
  ```

- 通过迭代器访问(跳过)

##### （3）常用函数

- find()
- size()
- clear()


### 《C和指针》
#### 1th 快速上手
1. 数组名

```c
int arr[4];
```
假设`int`型变量占4 Byte，那么这个声明，编译器会给c预留内存空间4×4 Byte，并且
数组名代表着指向数组第一个元素的指针。

2. 字符串常量存储在常量区，常量区存储的内容是不能被修改的。
3. 指针指定一个存储与计算机内存中的值的地址。
4. 每个 C 程序必须有一个 main 函数，因为它是程序执行的起点。
5. 在 C 语言中，数组参数是以`引用(reference)`形式进行传递的，即传址调用，
而标量和常量是按`值(value)`传递的。
在函数中对标量参数的任何修改都会在函数返回时丢失，因此，被调用函数无法修改
调用函数以传值形式传递给它的参数。
然而，当被调用函数修改数组参数的其中一个元素时，调用函数所传递的数组就会被实际地修改。

6. 在 C
   语言中，字符串是一串以`NUL`字节结尾的字符。`NUL`是作为字符串终止符，它本身并不被看作是字符串的一部分。字符串常量就是源程序中被`双引号`括起来的一串字符。
   例如, `"Hello"`在内存中占据6个字节的空间。
7.  由于scanf函数的实现原理，所有标量参数的前面必须加上一个`&`符号。数组参数前面不需要加上`&`符号，但是若数组参数中出现下标引用，即实际参数是数组某个特定元素，那么它的前面也必须加上`&`

8. 编程提示
  + 在while和if表达式中蕴含赋值操作
  + 始终要进行检查，确保数组不越界

#### 3th 数据

1. 在C语言中，仅有4中基本数据类型 --
   整型、浮点型、指针和聚合类型（如数组和结构等).
2. 指针可以有效地实现如tree和list这类高级数据结构。
3. 房子和它的门牌号码标识
4. 可以把计算机内存想象成一条长街上的一间间房子，每间房子都用一个唯一的号码进行标识。每个位置包含一个值，这和它的地址是独立且显著不同的，即使它们都是数字.
5. 程序在使用字符串常量会生成一个“指向字符的常量指针”。当一个字符串常量出现于一个表达式中时，表达式所使用的值就是这些字符所存储的地址，而不是这些字符本身。
6. 不能把字符串常量赋值给一个字符数组，因为字符串常量的直接值是一个指针，而不是这些字符本身。

### 逻辑运算

#### 1. 异或

异或是一个数学运算: 简单来说，就是相同为0，不同为1.

```text
0 0 -> 0
0 1 -> 1
1 0 -> 1
1 1 -> 0
```

为了便于理解，也可以理解为半加运算(省略进位)

```text
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = (1)0
```

##### 应用

- 实现两个数的交换，不必使用临时变量

    ```c
    // a = 10100001, b = 00000110
    // 可以自行演算一下
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    ```

- 判断两个整数是否相等

    ```c
    return ((a ^ b) == 0);
    ```

### C++ STL

#### accumulate

`accumulate`定义在`#include<numeric>`中，作用有两个，一个是累加求和，另一个是自定义类型数据的处理

1. 累加求和

```c++
int sum = accumulate(vec.begin(), vec.end(), begin_value);
```

前两个形参: 累加元素范围; 第三个形参: 累加初值

一个例子

```c++
#include <numeric>
#include <vector>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> va(&arr[0], &arr[5]);
    int sum = accumulate(va.begin(), va.end(), 0);
    printf("%d\n", sum);
    return 0;
}
```

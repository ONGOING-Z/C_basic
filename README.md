# C Basic

[toc]

## 易错地

0. linux下编译运行c++程序

    ```bash
    g++ -W input.cpp -o output_name
    ./output_name
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

11. C中常量INT_MAX和INT_MIN分别表示最大、最小整数，定义在头文件limits.h中. INT_MAX = 2^31-1，INT_MIN= -2^31
12. 逻辑移位

    逻辑移位: (1)逻辑左移 (2)逻辑右移; 移出的空位都用0来补。
13. nullptr

    其指c++ 中的空指针常量。

14. c++ delete

    假设ptr是一个指针，delete ptr代表释放内存，只用来释放ptr指向的内存。

15. to_string()
    
    将数值转换为字符串。

16. for循环遍历字符串的一种新方法

    ```c++
    #include <stdio.h>
    #include <vector>
    #include <string>
    using namespace std;

    int main(void)
    {
        string str = "better";
        for (char c : str)
        {
            printf("%c\n", c);
        }

        return 0;
    }
    ```
17. c++ auto (since C++ 11)(谨慎使用)

    可以自动推断变量类型
    1. auto变量必须在定义时进行初始化，如果不进行初始化，就不能进行变量类型的推断了。

18. c++ pair/ make_pair

    C++标准程序库中凡是“必须返回两个值”的函数， 也都会利用pair对象。

    `make_pair`的用法
    无需写出型别， 就可以生成一个pair对象。
    例： `std::make_pair(42, '@');`

    而不必费力写成： `std::pair<int, char>(42, '@')`

    值的访问: 两个值可以分别用pair的两个公有函数first和second访问。

19. map的count和find,map和unordered_map

    使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。

    使用find，返回的是被查找元素的位置，没有则返回map.end()。

20. string.substr()

    string.substr(start, [length])
    ```c++
    string s = "12345" 
    string sub1 = s.substr(3); // sub1 = "345"
    string sub2 =  s.substr(3, 2);  // sub2 = "34"
    ```
21. string to int: stoi()


   stoi(str, start_position, 2) 2是进制，此例意为将2进制的str从position转换成10进制

22. char to int: `c - '0'`
23. int to char: `i + '0'`
24. 异或

  - 性质: a ^ b即为a和b的二进制形式每一位进行运算，最后得到的结果。每位运算逻辑:
      相同为0， 不同为1. 类似半加。
  - 规律:
    - 任何数和本身异或为`0`
    - 任何数和0异或为`本身`

25. pow(), not power, 需要`cmath`头文件
26. 自己写的头文件要用`""`引用；标准的头文件要用`<>`引用。

    非系统头文件的查找通常开始于源文件所在的路径。

27. 声明与定义

    - 定义只可出现一次，声明可以出现多次。
28. 引用

   `int&`, 这里的`&`不是取地址符号，叫做`引用符号`.
   变量的引用就是变量的别名。相当于一个人的小名

   - 声明引用时必须指定代表是哪一个变量，即对它进行初始化
      ```c++
      int &a = b; // 声明a是b的引用
      ```

      如果只是`int &a`, 这样就是错误的。
   - 引用和其所代表的变量共享同一内存单元，系统不为引用另外分配存储单元。
   - 如何判断`&`是`引用`还是`取地址符`
      方法: 判断`&a`这样形式前是否有`类型符号`

29. 在 C++ 中，分别使用`.h` 和`.cpp` 来定义一个类。 `.h` 中存放类的声明，函数原型（放在类的声明中）。 `.cpp` 存放函数体。

也就是说，一个存放声明(declaration)，一个存放定义（definition)。

30. 当数组作为函数参数进行传递时，数组就会自动退化为同类型指针。

```c++
int GetSize(int data[])
{
   return sizeof(data);
}

int main(void)
{
    int data[] = {1, 3, 4, 5};
    int size = Getsize(data); // 4

}
```

31. size_t: size_t主要用于计数，如sizeof函数返回值类型即为size_t。在不同位的机器中所占的位数也不同，size_t是无符号数。
32. assert(): 
  1. `#include <assert.h>`

33. `const char*`是指向常量的指针，而不是指针本身为常量。通过该指针不能修改它所指向的数据。
  `char const*`和上面这种写法等价。
34. `char * const ptr`: 一个指向字符的指针常数, 即const指针，不能修改ptr指针，但是可以修改指针指向的内容。
  ```c++
   int main(int argc, char *argv[])
   {
      char str[] = "hello world";
      char ss[] = "good game!";
      char * const ptr = str;

      for (int i = 0; i < 11; i++)
         cout << ptr[i];
      cout << endl;

      ptr[0] = 's';
      //ptr = ss; // wrong

      dbg(ptr);
      

      return 0;
   }
  ```

35. `const char *`到`char *`的转换

   const char*是不能直接赋值到char*的, char*要另外开辟新的空间
   ```c++
   const char * str = "abcde";
   char *res = new char[100]; 
   strcpy(str, res);
   ```

36. cin遇到空格就会停止。
37. 字符数组和string的转换
  1. 字符数组-> string
      ```c++
      char ch[];
      string s = ch;
      ```
  2. string -> 字符数组
     ```c++
     char ch[10];
     string str("ABC");
     strcpy(ch, str.c_str());
     ```

38. string.push_back(): 在字符串末尾添加字符
39. const: const是constant的简写，是不变的意思。但并不是说它修饰常量，而是说它限定一个变量为只读。
40. map中元素如何排序
  1. sort方法只能对线性容器进行排序，但是map是一个集合容器, 利用sort不能直接对map进行排序
  2. 将map的key值和value值放在pair类型的vector中，构造比较函数cmp
  ```c++
  bool cmp(pair<char, int> p1, pair<char, int> p2)
      return p1.second > p2.second;
  ```

### C++

#### 1. vector

> 使用：`#include<vector>`；除此之外，还需加上`using namespace std;`

##### （1）定义

```c++
vector<typename> name;
```

初始化1: `vector<int> abc(10);`,初始化了10个默认值为0的元素.
初始化2: `vector<int> temp = { 4, 1, 2, 1, 2 };`
初始化3: `vector<int> v{1, 2, 4, 5};`  // construction 

注：其长度可以根据需要进行变化，“变长数组”

1. 指定大小

```c++
// Create a vector v1 with 3 elements of default value 0
vector<int> v1(3);
```

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
  // it 是一个`vector<typename>::iterator` 型的变量
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

- front(): 返回第一个元素引用
- back(): 返回最后一个元素引用

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
- reverse一个vector
    `reverse(res.begin(), res.end());`

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

#### maltimap

multimap 容器保存的是有序的键/值对，但它可以保存**重复**的元素。


#### 6. map

**注意**: 
- map中的key是唯一的，并且不能修改，遇到重复的key就会插入失败

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

6. 在 C语言中，字符串是一串以`NUL`字节结尾的字符。`NUL`是作为字符串终止符，它本身并不被看作是字符串的一部分。字符串常量就是源程序中被`双引号`括起来的一串字符。 例如, `"Hello"`在内存中占据6个字节的空间。
7.  由于scanf函数的实现原理，所有标量参数的前面必须加上一个`&`符号。数组参数前面不需要加上`&`符号，但是若数组参数中出现下标引用，即实际参数是数组某个特定元素，那么它的前面也必须加上`&`

8. 编程提示
    - 在while和if表达式中蕴含赋值操作
    - 始终要进行检查，确保数组不越界

#### 3th 数据

1. 在C语言中，仅有4中基本数据类型 --
   整型、浮点型、指针和聚合类型（如数组和结构等).
2. 指针可以有效地实现如tree和list这类高级数据结构。
3. 房子和它的门牌号码标识
4. 可以把计算机内存想象成一条长街上的一间间房子，每间房子都用一个唯一的号码进行标识。每个位置包含一个值，这和它的地址是独立且显著不同的，即使它们都是数字.
5. 程序在使用字符串常量会生成一个“指向字符的常量指针”。当一个字符串常量出现于一个表达式中时，表达式所使用的值就是这些字符所存储的地址，而不是这些字符本身。
6. 不能把字符串常量赋值给一个字符数组，因为字符串常量的直接值是一个指针，而不是这些字符本身。
7. typedef允许你为各种数据类型定义新名字。
  `typedef int another_name`

    使用typedef声明类型可以减少使声明变得又臭又长的危险，尤其是那些复杂的声明。

#### 4th 语句

1. 空语句

    C最简单的语句就是空语句，它本身只包含一个分号。空语句本身并不执行任何任务，但有时还是有用。
    适用场景: 语法要求出现一条完整的语句。
2. 括号是if语句的一部分。
3. C并不具备布尔类型，零值表示假，非零值表示真。

  ```c
  if (x > 3)
     printf("...");
  ```
  
  上边这条语句中，表达式`x > 3`的值将是0或1.

#### 5th 操作符和表达式

1. AND、OR、XOR要求操作数为整数类型，它们对操作数对应的位进行指定操作，每次对左右操作数的各一位进行操作。
2. 下标引用操作和间接访问表达式是等价的。
    `array[下标] <=> *(array + (下标))`

#### 6th 指针

![varialbe_and_addr](./images/variable_addr.png)

Pointers - variables that store address of another variable.
指针变量存储的是地址

0. 间接访问(de-referencing)操作符
1. 变量给了我们更方便的方法记住地址，但是硬件仍然通过地址访问内存位置。
2. 变量的值就是分配给该变量的内存位置所存储的数值。??
3. 指针变量可以作为左值，并不是因为它们是指针，而是因为它们是变量。对指针变量进行间接访问表示我们应该访问指针所指向的位置。

![Image](img/pointer_1.png)

![Image](img/pointer_2.png)


`int *b = &a`和`b = &a`的区别是什么?
这两个表达的应该是一样的意思。
看第二个b，这个b代表的是指针，如果加上声明语句的话和前一个是一样的
感觉`int * p; p = &a;`,这个更好理解。

一个例子

```c
#include <stdio.h>
int main(int argc, char *argv[])
{
    int a = 8;
    int *p;
    p = &a; // &a is address of a
    printf("%d\n", p); // p is 2002
    printf("%d\n", p + 1); // p+1 is 2006

    return 0;
}
```

4. a pointer to pointer(mycodeschool)

    ```c
    int *p;
    int **q;
    q = &p;
    ```

![Image](img/pointer_to_pointer.png)

----

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

#### unordered_set

##### 定义

c++ unordered_set定义: 是一个集合，集合中的每一个元素都是唯一的，就算插入几个相同的元素，但是最后保留下的只有一个。

注意: unordered_set中数据是无序的.

##### 方法

1. unordered_set::find()

    unordered_set::find()函数是C++ STL中的内置函数，用于在容器中搜索元素。它返回元素的迭代器，如果找到其他元素，则返回指向unordered_set::end()的迭代器。

    用法： unordered_set_name.find(key)

    ```c++
    if(s.find(xx) != s.end()) xxx
    ```

2. unordered_set::insert(element)

    unordered_set::insert(element)

3. set 与 unordered_set

何时使用`set`
  - 需要有序的数据!

#### unordered_map

```c++
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    unordered_map<int, string> myMap = {{5, "张大"}, {6, "李五"}};
    myMap[2] = "李四";
    myMap.insert(pair<int, string>(3, "陈二"));

    auto iter = myMap.begin();
    while (iter != myMap.end())
    {
        cout << iter->first << "," << iter->second << endl;
        ++iter;
    }
    return 0;
}
```

两个属性值:
myMap.first # myMap->first是错误的写法
myMap.second

#### set

set中每个值都唯一，系统可以根据元素的值自动排序.
1. set.insert()

```c++
#include <stdio.h>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
    set<int> set1;
    for (int i = 0; i < 10; i++)
    {
        set1.insert(i);
    }
    set<int>::iterator it;
    for (it = set1.begin(); it != set1.end(); it++)
        printf("%d ", *it);

    return 0;
}
```

#### pair

#### begin()/end()

#### map()

#### 字符串的输入

1. `cin`输入遇到`空格`就会结束

   所以在输入一段话的时候，使用cin只会接收到第一个单词。

2. string - > const char *

   `.c_str()`

3. 遍历字符数组

4. 字符串转换成整型数`atoi(const char *ptr)`

   头文件: `stdlib.h`/`cstdlib`

5. 带有空格的一段话输入

   使用`getline(cin, str)`输入，这个函数遇到空格会继续输入。

[toc]

### 一、一些细节

1. linux下编译运行c++程序

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
   node[a] = {data, b, false};  // 注意时花括号，和数组初始化一样。
   ```

5. ```c++
   printf("%05d", i);  // 使不足５位的整数的高位补０。
   printf("%5d", i);  // 使不足５位的整数的高位补为空。
```
   

   
6. ```c++
   scanf("%d %c");
   ```

   // `scanf()`使用`%c`可以读入`空格`，要注意格式！

   

### 二、c++

#### 1. vector

> 使用：`#include<vector>`；除此之外，还需加上`using namespace std;`

##### （1）定义

```c++
vector<typename> name;
```

*注：其长度可以根据需要进行变化，“变长数组”*

##### （2）vector容器内元素的访问

eg. 

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



#### 4. algorithm头文件下常用函数

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



  

  
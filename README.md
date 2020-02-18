[toc]



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

   

### c++

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

添加`#include <stack>`与`using namespace std`

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

  

  



  

  
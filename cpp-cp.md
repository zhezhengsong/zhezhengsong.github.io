https://codeforces.com/blog/entry/15643
https://codeforces.com/blog/entry/9702
https://codeforces.com/blog/entry/64218
https://codeforces.com/blog/entry/62393
https://codeforces.com/blog/entry/74684
https://en.oi-wiki.org/lang/new/
https://codeforces.com/blog/entry/96344
# Use C++ in Competetive Programming

Zhezheng Song

In the realm of Competitive Programming (CP), C++ is renowned for its execution speed, making it a popular choice among programmers. While languages like Python and Java offer ease in certain areas, such as big integer arithmetic, C++ stands out in its universal applicability in the International Collegiate Programming Contest (ICPC), where time constraints are critical. Another merit of C++ lies in the abundance of resources tailored for competitive programming. Though known for its complexity and myriad of features, many of these are not essential in CP. Based on my experience, this article is crafted to demystify C++ by focusing on features and programming tricks that are most beneficial in competitive programming. Assuming you have a foundational understanding of C++, I will guide you through these useful aspects of C++. Stay tuned for continuous updates as I discover new and helpful insights.

## Headers, Macros, and a fixed start for every code

### Headers

Usually, a lot of header files need to be included at the front of the code. However, you can do it in one line:

```cpp
#include <bits/stdc++.h>
```

because this header file includes (almost) all the header files you need. 

You can also write your own header file, like "myheader.h". Then you put it into the same directory as your code. Then you can use:

```cpp
#include "myheader.h" 
```

to include it. Notice that you need to use double quotation marks ("") instead of angle brackets (<>) for your own header file. Also, you can use the compile command "-I <header_file_path>" to tell the compiler where to find header files so that you can put it anywhere.

### Macros



## Read/Write Optimization (cin/cout)

## Standard Template Library (STL)
STL is allowed to use in the ICPC contest. It includes some template ，里面包含了一些模板化的通用的数据结构和算法。由于其模板化的特点，它能够兼容自定义的数据类型，避免大量的造轮子工作。NOI 和 ICPC 赛事都支持 STL 库的使用，因此合理利用 STL 可以避免编写无用算法，并且充分利用编译器对模板库优化提高效率。STL 库的详细介绍请参见对应的页面： STL 容器 和 STL 算法 。

I see lots of programmers write code like this one:

pair<int, int> p;
vector<int> v;
// ...
p = make_pair(3, 4);
v.push_back(4); v.push_back(5);
while you can just do this:

pair<int, int> p;
vector<int> v;
// ...
p = {3, 4};
v = {4, 5};


## Compiler and Run/Debug using command line


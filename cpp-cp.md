---
permalink: /cpp-cp.html
---


https://codeforces.com/blog/entry/15643
https://codeforces.com/blog/entry/9702
https://codeforces.com/blog/entry/64218
https://codeforces.com/blog/entry/62393
https://codeforces.com/blog/entry/74684
https://en.oi-wiki.org/lang/new/
https://codeforces.com/blog/entry/96344

markdown inline block
# Use C++ in Competetive Programming

Zhezheng Song

In the realm of Competitive Programming (CP), C++ is renowned for its execution speed, making it a popular choice among programmers. While languages like Python and Java offer ease in certain areas, such as big integer arithmetic, C++ stands out in its universal applicability in the International Collegiate Programming Contest (ICPC), where time constraints are critical. Another merit of C++ lies in the abundance of resources tailored for competitive programming. Though known for its complexity and myriad of features, many of these are not essential in CP. Based on my experience, this article is crafted to demystify C++ by focusing on features and programming tricks that are most beneficial in competitive programming. Assuming you have a foundational understanding of C++, I will guide you through these useful aspects of C++. Stay tuned for continuous updates as I discover new and helpful insights.

## Headers

There's one header file containing all the header file you need:

```cpp
#include <bits/stdc++.h>
```

You can also write your own header file, like "myheader.h". Then you put it into the same directory as your code. Then you can use:

```cpp
#include "myheader.h" 
```

to include it. Notice that you need to use double quotation marks ("") instead of angle brackets (<>) for your own header file. Also, you can use the compile command "-I <header_file_path>" to tell the compiler where to find header files so that you can put it anywhere.

## Read/Write Optimization (cin/cout)

## Standard Template Library (STL)
STL is part of the C++ standard library which contains a lot of built-in template implementations for lots of data structures and algorithms. It is allowed to use in the ICPC contest. Using it can avoid writing tedious code for algorithms and usually there are compiler optimizations for standard libraries. I'll give a introduction to some most used containers/algorithm in STL. You can go to https://en.cppreference.com/w/ for detailed usage and efficiency for each function.


### A trick to assign values to containers
For a `pair<int, int> p;`, instead of assign value to it by `p = make_pair(3, 4);`, you can use `p = {3, 4};`.

```cpp
pair<int, int> p;
vector<int> v;
p = make_pair(3, 4);
v.push_back(4); v.push_back(5);

```
while you can just do this:

```cpp
pair<int, int> p;
vector<int> v;

v = {4, 5};
```



## Compiler and Run/Debug using command line


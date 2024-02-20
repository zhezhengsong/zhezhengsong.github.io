# Use C++ in Competetive Programming

Zhezheng Song

In the realm of Competitive Programming (CP), C++ is renowned for its execution speed, making it a popular choice among programmers. While languages like Python and Java offer ease in certain areas, such as big integer arithmetic, C++ stands out in its universal applicability in the International Collegiate Programming Contest (ICPC), where time constraints are critical. Another merit of C++ lies in the abundance of resources tailored for competitive programming. Though known for its complexity and myriad of features, many of these are not essential in CP. For instance, while Object-Oriented Programming ('Class') is a cornerstone in large-scale software development, in CP, simpler structures like 'Structs' often suffice, streamlining coding and debugging processes. Based on my experience, this article is crafted to demystify C++ by focusing on features and programming tricks that are most beneficial in competitive programming. Assuming you have a foundational understanding of C++, I will guide you through these useful aspects of C++. Stay tuned for continuous updates as I discover new and helpful insights.

## Headers, Macros, and a fixed start for every code

### Headers

Usually, a lot of header files need to be included at the front of the code. However, you can do it in one line:

```
#include <bits/stdc++.h>
```

because this header file includes (almost) all the header files you need. 

You can also write your own header file, like "myheader.h". Then you put it into the same directory as your code. Then you can use:

```
#include "myheader.h" 
```

to include it. Notice that you need to use double quotation marks ("") instead of angle brackets (<>) for your own header file. Also, you can use the compile command "-I <header_file_path>" to tell the compiler where to find header files so that you can put it anywhere.

### Macros



## Read/Write Optimization (cin/cout)

## STL

## Compiler and Run/Debug using command line


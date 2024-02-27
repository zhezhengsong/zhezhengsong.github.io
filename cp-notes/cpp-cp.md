---
permalink: /cp-notes/cpp-cp.html
---
auto
# Use C++ in Competetive Programming

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
to include it. Notice that you need to use double quotation marks ("") instead of angle brackets (<>) for your own header file. Also, you can use the compile command `-I <header_file_path>` to tell the compiler where to find header files so that you can put it anywhere.

## Read/Write Optimization (cin/cout)

## Standard Template Library (STL)
The Standard Template Library (STL) is a part of the C++ standard library, offering a comprehensive set of template classes for various data structures and algorithms. It is permitted for use in the ICPC. Utilizing the STL can save significant time and effort, as it eliminates the need to write complex code for common algorithms and data structures. Additionally, the STL benefits from compiler optimizations, which can enhance performance. In this introduction, I will highlight some of the most commonly used containers and algorithms in the STL. For detailed information on each function's usage and efficiency, visit the comprehensive resource at [cppreference.com](https://en.cppreference.com/w/).

### STL containers
**Taxonomy:**
+ Sequence Containers:
Elements are stored in a sequential structure
	- `vector`: a sequential list to whose backend elements can be added efficiently.
	- `deque`: a sequential list to whose both ends elements can be added efficiently.
	- `array`: a sequential list of fixed size.
	- `list`: a doubly linked list.
	- `forward_list`: a singly linked list.
+ Associative Containers:
Elements are stored in a tree structure. They're implemented using the *red–black tree*.
	- `set/multiset`: a container used to store distinct elements in an orderly manner. `multiset` allows equal elements to exist.
	- `map/multimap`:  A set composed of {key, value} pairs arranged in certain order of he key. `multimap` allows equal elements to exist.
+ Unordered Containers:
They're implemented using the *hashmap*. The difference with `set/multiset` and `map/multimap` is that elements are unordered.
	- `unordered_set/unordered_multiset`
	- `unordered_map/unordered_multimap`
+ Container Adaptars:
They are not really containers since they doesn't contain certain features (e.g., iterator, `clear()` function...)
	- 'stack' (LIFO) and 'queue' (FIFO): They are encapsulations of `deque`.
	- `priority_queue`: A queue with sorted element. It's an encapsulation of `vector`.

Common funcitons:?

#### Sequence Containers
**`vector`**
**`deque`**

#### Associative Containers
#### Unordered Containers
#### Container Adaptars


#### A trick to assign values to containers
For a `pair<int, int> p;`, instead of assign value to it by `p = make_pair(3, 4);`, you can use `p = {3, 4};`.
This also work for a more complex `pair` and other containers(`vector`, `deque`, `set`, `list`, `array`, and `tuple`):
+ `pair<pair<string, long long>, int> p = {3, {"szz", 22ll}, 2};`
+ `vector<int> v = {2, 1, 4, 7};`
However, it doesn't work for `stack` or `queue`.

### STL algorithms
`__gcd(value1, value2)`
You don't need to code Euclidean Algorithm for a gcd function, from now on we can use. This function returns gcd of two numbers.
__builtin_ffs(x)
This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.

e.g. __builtin_ffs(10) = 2 because 10 is '...10 1 0' in base 2 and first 1-bit from right is at index 1 (0-based) and function returns 1 + index.

three)

__builtin_clz(x)
This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_clz(16) = 27 because 16 is ' ... 10000'. Number of bits in a unsigned int is 32. so function returns 32 — 5 = 27.

four)

__builtin_ctz(x)
This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_ctz(16) = 4 because 16 is '...1 0000 '. Number of trailing 0-bits is 4.

five)

__builtin_popcount(x)
This function returns number of 1-bits of x. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_popcount(14) = 3 because 14 is '... 111 0' and has three 1-bits.
### `bitset`
### `string`
### `pair`
## Compiler and Run/Debug using command line


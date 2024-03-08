---
permalink: /cp-notes/basics/cpp-cp.html
---

# Use C++ in Competetive Programming
（STL, fast IO included）
In the realm of Competitive Programming (CP), C++ is renowned for its execution speed, making it a popular choice among programmers. While languages like Python and Java offer ease in certain areas, such as big integer arithmetic, C++ stands out in its universal applicability in the International Collegiate Programming Contest (ICPC), where time constraints are critical. Another merit of C++ lies in the abundance of resources tailored for competitive programming. Though known for its complexity and myriad of features, many of these are not essential in CP. Based on my experience, this article is crafted to demystify C++ by focusing on features and programming tricks that are most beneficial in competitive programming. Assuming you have a foundational understanding of C++, I will guide you through these useful aspects of C++. Stay tuned for continuous updates as I discover new and helpful insights.
For the whole article, assuming `using namespace std;` is being used.

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

## Read/Write
### cin/cout
By default, `cin/cout` is much slower than `scanf/printf`. The main reason is that in order to be compatible with C and ensure that the program does cause chaos when using `printf` and `cout` together, C++ synchronize these two output streams. In order to unsynchronize, we can use:
```cpp
ios::sync_with_stdio(false);
cin.tie(0);
```
Now, the `cin/cout` is mostly as fast as `scanf/printf`. However, now we shouldn't use `cin` and `scanf` together and we shouldn't use `cout` and `printf` together.

### Faster IO
(It seems to me this is not very popular in the ICPC regionals)
There is an even faster way to input/output. Notice that we focus on integer for now. You can use the same way to support other types.
**Theory**
`getchar()` reads one byte of data and cast it to `char` type with a very fast speed. Thus, we can utilize the process of "read `char` and then cast to `int`" to achieve faster input. The sign needs to be taken care of. When a character which is not a digit nor a sign is read, the input of this integer should be over. Code:
```cpp
int read() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9') {  // ch 不是数字时
	if (ch == '-') w = -1;        // 判断是否为负
		ch = getchar();               // 继续读入
	}
	while (ch >= '0' && ch <= '9') {  // ch 是数字时
		x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
		// x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
		// ASCII 码，相当于将 ch 转化为对应数字
		// 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
		ch = getchar();  // 继续读入
	}
	return x * w;  // The actual number = absolute value * sign
}
```
Then we can use `int n = read()` to input an integer to `n`.
Similarly, we can use `putchar()` to optimize the output. Again, we need to take care of the sign and output digit in the reverse order because `% (mod)` takes out the last digit of a number. Code (a stack is used to avoid recursion):
```cpp
void write(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top) putchar(sta[--top] + 48);  // 48 is the ascii number for '0'
}
```
Now we can use `write(n)` tto output `n`.
#### Make it more compatible
To avoid writing multiple `read()` function for different types (`long long`, `__int128`,...), we can write a `template` for all the integer types:

```cpp
template <typename T>
T read() {
	T sum = 0, fl = 1;  // Define sum, fl, and ch to be of the wanted type
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}
```
To use it:
```cpp
int a = read<int>();
long long b = read<long long>();
__int128 c = read<__int128>();
```
## Standard Template Library (STL)
The Standard Template Library (STL) is a part of the C++ standard library, offering a comprehensive set of template classes for various data structures and algorithms. It is permitted for use in the ICPC. Utilizing the STL can save significant time and effort, as it eliminates the need to write complex code for common algorithms and data structures. Additionally, the STL benefits from compiler optimizations, which can enhance performance. In this introduction, I will highlight some of the most commonly used containers and algorithms in the STL. For detailed information on each function's usage and efficiency, visit the comprehensive resource at [cppreference.com](https://en.cppreference.com/w/).

### STL containers
**Taxonomy:**
+ Sequence Containers:
Elements are stored in a sequential structure
	- `vector`: a sequential list to whose backend elements can be added efficiently.
	- `array`: a sequential list of fixed size.
	- `deque`: a sequential list to whose both ends elements can be added efficiently.
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
	- `stack` (LIFO) and `queue` (FIFO): They are encapsulations of `deque`.
	- `priority_queue`: A queue with sorted element. It's an encapsulation of `vector`.

Common funcitons:?

#### Sequence Containers
**`vector`**

**`array`**
**`deque`**
**`list`**
**`forward_list`**


#### Associative Containers
**`set`**
搜索、移除和插入拥有对数复杂度
插入与删除操作
insert(x) 当容器中没有等价元素的时候，将元素 x 插入到 set 中。
erase(x) 删除值为 x 的 所有 元素，返回删除元素的个数。
erase(pos) 删除迭代器为 pos 的元素，要求迭代器必须合法。
erase(first,last) 删除迭代器在 [first,last) 范围内的所有元素。
clear() 清空 set。
insert 函数的返回值
insert 函数的返回值类型为 pair<iterator, bool>，其中 iterator 是一个指向所插入元素（或者是指向等于所插入值的原本就在容器中的元素）的迭代器，而 bool 则代表元素是否插入成功，由于 set 中的元素具有唯一性质，所以如果在 set 中已有等值元素，则插入会失败，返回 false，否则插入成功，返回 true；map 中的 insert 也是如此。
**`map`**
#### Unordered Containers
#### Container Adaptars
**`stack`**
**`queue`** (FIFO): They are encapsulations of `deque`.
**`priority_queue`**
#### `auto`
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

int x = min({a, b, c, d});

`unique`
`unique(begin, end)` goes from begin to end, removes consecutive duplicates and returns the end of the resulting iterator range. For example, `vector <int> vec = {1, 1, 2, 3, 3, 3, 1, 2};`. The `unique(vec.begin(), vec.end());` will make `vec` to be {1, 2, 3, 1, 2, ?, ?, ?} (? means unknown) and return `vec.begin() + 5`. Usually, to make a vector containing only its unique elements, one writes:
```cpp
sort(vec.begin(), vec.end());
vec.resize(unique(all(vec)) - vec.begin());
```
`merge`
`merge` takes 5 arguments: begin and end of one interval to merge, begin and end of the second interval to merge, and where to write the result. remember to allocate the required memory.
For example, to initialize a segment tree with each node containing a sorted list of values from the corresponding range:
```cpp
for (int v = n - 1; v > 0; --v) {
    nodes[v].resize(nodes[2 * v].size() + nodes[2 * v + 1].size());
    merge(nodes[2 * v].begin(), nodes[2 * v].end(), nodes[2 * v + 1].begin(), nodes[2 * v + 1].end(), nodes[v].begin());
}
```

`binary_search(all(vec), key)` returns a bool.
`partition_point`
If we talk about binary search: assume you have a vector and a predicate p(x) so that p(x) = true for all elements of some prefix of vector vec and false on all others. To find the first place where p(x) doesn't hold one can simply use

int pos = partition_point(all(vec), p) - vec.begin();
In other words, partition_point(begin, end, p) returns the first iterator iter that p(*iter) = false, assuming that the condition above holds, that is, p is true on some prefix of [begin, end). I didn't use this in competitive programming (yet), but once wanted to use it for my job. Thanks to fdoer again for sharing his wisdom.
`!!`
Assume you want to use a function which maps 0 to 0 and every non-zero number to 1 (for example, to count non-zero numbers on all prefix subrectangles). The most observant of you may have notices that this is simply a cast to bool. The easiest bool casting operator is !! and it works like this:

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + !!a[i][j];
    }
}
### `bitset`
#### Print a binary representation of a number
If you want to print the last 20 bits of a number, you may write:
```cpp
void print_binary(int n) {
    for (int i = 0; i < 20; ++ i) {
        cout << !!(n & (1 << i));
    }
    cout << "\n";
}
```
However, there's a much easier way:
```cpp
cout << bitset<20>(n) << "\n";
```
Also, if you want to print an octal or a hexadecimal representation of a number, you can simply write cout << oct << n << "\n" and cout << hex << n << "\n", respectively. To return back to normal decimal, use cout << dec. TBD
### `string`
### `pair`
## Compiler and Run/Debug using command line
Compiler
Make use of C++17. Use -Wall -Wextra -Wshadow flags for compilation, and try to eliminate all of the warning messages, this will prevent you from having some silly bugs. There are more debugging flags like -fsanitize=undefined which helps you eliminate bugs such as array out-of-range access and integer overflow during runtime. For more information, check out "Read More" section.

## Competitive Coding Recommendations
Use struct instead of class. Rationale: It defaults to public, and you don't need encapsulation in competitive programming!

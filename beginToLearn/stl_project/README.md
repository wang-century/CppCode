<pre>
<h2>STL初识</h2>
<h4>STL的诞生</h4>
    ·长久以来,软件界一直希望建立一种可重复利用的东西
    ·C++的面向对象和泛型编程思想,目的就是复用性的提升
    ·大多情况下,数据结构和算法都未能有一套标准导致被迫从事大量重复工作
    ·为了建立数据结构和算法的一套标准诞生了STL
<h4>STL基本概念</h4>
    ·STL( Standard Template Library标准模板库)
    ·STL从广义上分为:容器( container)算法 (algorithm)迭代器( Iterator)
    ·容器和算法之间通过迭代器进行无缝连接。
    ·STL几乎所有的代码都采用了模板类或者模板函数
<h4>STL六大组件</h4>
    STL大体分为六大组件,分别是容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
    1.容器:各种数据结构,如 vector、 list, deque、set、map等用来存放数据。
    2.算法:各种常用的算法,如sort、find、copy、 for_each等
    3.迭代器:扮演了容器与算法之间的胶合剂
    4.仿函数:行为类似函数,可作为算法的某种策略
    5.适配器:一种用来修饰容器或者仿函数或迭代器接口的东西。
    6.空间配置器:负责空间的配置与管理。
<h4>STL中容器、算法、迭代器</h4>
    容器:置物之所也
        STL容器就是将运用最广泛的一些数据结构实现出来
        常用的数据结构:数组,链表树,栈,队列,集合,映射表等
        这些容器分为序列式容器和关联式容器两种:
            序列式容器:强调值的排序,序列式容器中的每个元素均有固定的位置
            关联式容器:二叉树结构,各元素之间没有严格的物理上的顺序关系
    算法:问题之解法也
        有限的步骤,解决逻辑或数学上的问题,这一门学科我们叫做算法( Algorithms)
        算法分为质变算法和非质变算法
            质变算法:是指运算过程中会更改区间内的元素的内容。例如拷贝,替换,删除等等
            非质变算法:是指运算过程中不会更改区间内的元素内容,例如查找、计数、遍历、寻找极值等等
    迭代器:容器和算法之间粘合剂
        提供一种方法,使之能够依序寻访某个容器所含的各个元素,而又无需暴露该容器的内部表示方式
        每个容器都有自己专属的迭代器
        迭代器使用非常类似于指针,初学阶段我们可以先理解迭代器为指针
        
        迭代器种类:
        种类          功能                          支持运算
        输入迭代器    对数据的只读访问                只读,支持++、==、!=
        输出迭代器    对数据的只写访问                只写,支持++
        前向迭代器    读写操作,并能向前推进迭代器       读写,支持++、=
        双向迭代器    读写操作,并能向前和向后操作       读写,支持++、-
        随机访问迭    读写操作,可以以跳跃的方式,        读写,支持++、[n]、-n、<、<=、>、>=
        代器         访问任意数据，功能最强的迭代器
        
        常用的容器中迭代器种类为双向迭代器,和随机访问迭代器I
    
<h2>容器算法迭代器初识</h2>
    了解STL中容器、算法、迭代器概念之后,我们利用代码感受STL的魅力
    STL中最常用的容器为Vector,可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器
<h4>vector存放内置数据类型</h4>
    容器：vector
    算法：for_each
    迭代器：vector&lt;int>::interator
<h4>vector存放自定义数据类型</h4>
<h4>vector容器嵌套容器</h4>

<h4>string基本概念</h4>
<h5>string基本概念</h5>
    本质:
        ●string是C++风格的字符串，而string本质上是一个类
    string和char *区别:
        ●char*是一个指针
        ●string是一个类,类内部封装了char*, 管理这个字符串，是一个char*型的容器。
    特点:
        string类内部封装了很多成员方法
        例如:查找find, 拷贝copy,删除delete替换replace,插入insert
        string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责
<h5>string构造函数</h5>
    构造函数原型:
        string();                   //创建一个空的字符串例如: string str;
        string(const char* s);      //使用字符串s初始化
        string(const string& str);  //使用一 个string对象初始化另 -个string对象
        string(int n, char c);     //使用n个字符c初始化

<h5>string赋值操作</h5>
    功能描述:
        ●给string字符串进行赋值
    赋值的函数原型:
    ● string& operator=(const char* s);     //char*类型字符串赋值给当前的字符串
    ● string& operator=(const string &s);   //把字符串s赋给当前的字符串
    ● string& operator=(char C);            //字符赋值给当前的字符串
    ● string& assign(const char *s);        //把字符串s赋给当前的字符串
    ● string& assign(const char *s，int n);  //把字符串s的前n个字符赋给当前的字符串
    ● string& assign(const string &s);       //把字符串s赋给当前字符串
    ● string& assign(int n，char C);         //用n个字符c赋给当前字符串

<h5>string字符串拼接</h5>
    功能描述: 
        ●实现在字符串末尾拼接字符串
    函数原型:
    ●string& operator+=(const char* str);       //重载+=操作符
    ●string& operator+=(const char C);          //重载+=操作符
    ●string& operator+=(const string& str);     //重载+=操作符
    ●string& append(const char *s);             //把字符串s连接到当前字符串结尾
    ●string& append(const char *s，int n);      //把字符串s的前n个字符连接到当前字符串结尾
    ●string& append(const string &s);                   //同operator+=(const string& str)
    ●string& append(const string &s， int pos, int n);   //字符串s中从pos开始的n个字符连接到字符串结尾

</pre>
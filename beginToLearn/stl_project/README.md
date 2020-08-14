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

<h5>string查找和替换</h5>
    功能描述:
        ●查找:查找指定字符串是否存在
        ●替换:在指定的位置替换字符串
    函数原型:
    ●int find(const string& str, int pos=0) const;        //查找str第一次出现位置,从pos开始查找
    ●int find(const char* s,int pos=0) const;             //查找s第一次出现位置从pos开始查找
    ●int find(const char* s，int pos, int n) const;          //从pos位置查找s的前n个字符第一次位置
    ●int find(const char c,int pos = 0) const;              //查找字符c第一次出现位置
    ●int rfind(const string& str, int pos = npos) const;    //查找str最后一次位置,从pos开始查找
    ●int rfind(const char* s, int pos = npos) const;        //查找s最后- -次出现位置，从pos开始查找
    ●int rfind(const char* s, int pos, int n) const;        //从pos查找s的前n个字符最后一-次位置
    ●int rfind(const char c, int pos =0) const;             //查找字符c最后一次出现位置
    ●string& replace(int pos, int n, const string& str);    //替换从pos开始n个字符为字符串str
    ●string& replace(int pos， int n,const char* s);         //替换从pos开始的n个字符为字符串s


<h5>string字符串比较</h5>
    功能描述:
        ●字符串之间的比较
    比较方式:
        ●字符串比较是按字符的ASCII码进行对比
        =返回0
        >返回1
        &lt;返回-1
    函数原型:
    ●int compare(const string &s) const;   //与字符串s比较
    ●int compare(const char *S) const;      //与字符串s比较

<h5>string字符存取</h5>
    string中单个字符存取方式有两种
        ●char& operator[](int n);   //通过[方式取字符
        ●char& at(int n);           //通过at方法获取字符


<h5>string插入和删除</h5>
    功能描述:
        ●对string字符串进行插入和删除字符操作
    函数原型:
        ●string& insert(int pos, const char* s);    //插入字符串
        ●string& insert(int pos，const string& str);//插入字符串
        ●string& insert(int pos, int n,char C);     //在指定位置插入n个字符C
        ●string& erase(int pos, int n = npos);      //删除从Pos开始的n个字符


<h5>string子串</h5>
    功能描述:
        从字符串中获取想要的子串
    函数原型:
        string substr(int pos =0, int n = npos) const; //返回由pos开始的n个字符组成的字符串


<h4>vector容器</h4>
<h5>vector基本概念</h5>
    功能:
    ●vector数据结构和数组非常相似，也称为单端数组
    
    vector与普通数组区别:
    ●不同之处在于数组是静态空间，而vector可以动态扩展
    
    动态扩展:
    ●并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
    ●vector容器的迭代器是支持随机访问的迭代器
    
<h5>vector构造函数</h5>
    功能描述:
        创建vector容器
    函数原型:
    vector&lt;T> v;                  //采用模板实现类实现，默认构造函数
    vector(v.begin()，v.end());      //将v[begin(), end()]区间中的元素拷贝给本身
    vector(n, elem);                //构造函数将n个elem拷贝给本身
    vector(const vector &vec);      //拷贝构造函数。

<h5>vector赋值操作</h5>
    功能描述: 
        ●给vector容器进行赋值

    函数原型:
        ●vector& operator=(const vector &vec);  //重载等号操作符
        ●assign(beg，end);                       //将[beg, end)]区间中的数据拷贝赋值给本身。
        ●assign(n, elem);                       //将n个elem拷贝赋值给本身。

<h5>vector容量和大小</h5>
    功能描述:
        ●对vector容器的容量和大小操作
    函数原型:
        ●empty();           //判断容器是否为空
        ●capacity();        //容器的容量
        ●size();            //返回容器中元素的个数
        ●resize(int num);，  //重新指定容器的长度为num,若容器变长,则以默认值填充新位置。
                             //如果容器变短，则末尾超出容器长度的元素被删除。
        ●resize(int num, elem);   //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除

<h5>vector插入和删除</h5>
    功能描述: 
        ●对vector容器进行插入、 删除操作
    函数原型:
        push_back(ele);     //尾部插入元素ele
        ●pop_back();        //删除最后-个元素
        ●insert(const_iterator pos, ele);   //迭代器指向位置pos插入元素ele
        ●insert(const_iterator pos, int count ,ele); //迭代器指向位置pos插入count个元素ele
        ●erase(const_iterator pos);    //删除迭代器指向的元素
        ●erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
        ●clear();   //删除容器中所有元素


<h5>vector数据存取</h5>
    功能描述: 
        ●对vector中的数据的存取操作
    函数原型:
        ●at(int idx);   //返回索引idx所指的数据
        ●operator[];    //返回索引所指的数据
        ●front();       //返回容器中第一个数据元素
        ●back();        //返回容器中最后一个数据元素


<h5>vector互换容器</h5>
    功能描述: 
        ●实现两个容器内元素互换
    函数原型:
        swap(vec);  // 将vec与本身的元素互换  
        
        
<h5>vector预留空间</h5>
    功能描述:
        ●减少vector在动态扩 展容量时的扩展次数

    函数原型:
        reserve(int len); //容器预留len个元素长度,预留位置不初始化，元素不可访问。

<h4>deque容器</h4>
<h5>deque容器基本概念</h5>
    功能:
        ●双端数组，可以对头端进行插入删除操作
    deque与vector区别:
        ●vector对于头部的插入删除效率低，数据量越大，效率越低
        ●deque相对而言 ，对头部的插入删除速度回比vector快
        ●vector访问元素时的速度 会比deque快,这和两者内部实现有关
    deque内部工作原理:
        deque内部有个中控器，维护每段缓冲区中的内容,缓冲区中存放真实数据
        中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
    deque容器的迭代器也是支持随机访问的
<h5>deque容器构造函数</h5>
    功能描述:
        ●deque容器构造

    函数原型: 
        ●deque&lt;T> deqT;  //默认构造形式
        ●deque(beg, end);   //构造函数将[beg, end)区间中的元素拷贝给本身。
        ●deque(n, elem);    //构造函数将n个elem拷贝给本身。
        ●deque(const deque &deq); //拷贝构造函数

<h5>deque赋值操作</h5>
    功能描述:
        ●给deque容 器进行赋值

    函数原型:
        ●deque& operator=(const deque &deq);//重载等号操作符
        ●assign(beg，end);//将[beg, end)区间中的数据拷贝赋值给本身。
        ●assign(n, elem);//将n个elem拷贝赋值给本身。

<h5>deque大小操作</h5>
    功能描述:
        ●对deque容器的大小进行操作
    
    函数原型:
        ●deque.empty();         //判断容器是否为空
        ●deque.size();          //返回容器中元素的个数
        ●deque.resize(num);     //重新指定容器的长度为num，若容器变长,则以默认值填充新位置。
                                //如果容器变短，则末尾超出容器长度的元素被删除。
        ●deque.resize(num, elem);   //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除。

<h5>deque插入和删除</h5>
    功能描述:
        ●向deque容器中插入和删除数据
        
    函数原型:
        两端插入操作:
        ●push_back(elem);   //在容器尾部添加一个数据
        ●push_front(elem);  //在容器头部插入一个数据
        ●pop_back();        //删除容器最后一个数据
        ●pop_front();       //删除容器第一个数据
        
        指定位置操作:
        ●insert(pos,elem);      //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
        ●insert(pos,n,elem);    //在pos位置插入n个elem数据，无返回值。
        ●insert(pos ,beg,end);  //在pos位置插入beg,end)区间的数据，无返回值。
        ●clear();               //清空容器的所有数据
        ●erase(beg, end);       //删除[beg,end)区间的数据，返回下一一个数据的位置。
        ●erase(pos);            //删除pos位置的数据，返回下一个数据的位置。

<h5>deque数据存取</h5>
    功能描述:
        ●对deque中的数据的存取操作

    函数原型:
        ●at(int idx);   //返回索引idx所指的数据
        ●operator[];    //返回索引idx所指的数据
        ●front();       //返回容器中第一个数据元素
        ●back();        //返回容器中最后一个数据元素

<h5>deque排序</h5>
    功能描述:
        ●利用算法实现对deque容器进行排序
    算法:
        sort(iterator beg, iterator end) //对beg和end区间内元素进行排序    注：vector也可以使用该算法


<h4>案例-评委打分</h4>
    案例描述
        有5名选手:选手ABCDE, 10个评委分别对每一名选手打分, 去除最高分，去除评委中最低分，取平均分。

    实现步骤
        1.创建五名选手,放到vector中
        2.遍历vector容器，取出来每一个选手, 执行for循环，可以把10个评分打分存到deque容器中
        3.sort算法对deque容器中分数排序，去除最高和最低分
        4.deque容器遍历-遍，累加总分
        5.获取平均分


<h4>stack容器</h4>
<h5>stack基本概念</h5>
    概念: stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口
    栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
    栈中进入数据称为入栈(push)
    栈中弹出数据成为出栈(pop)
    
    
<h5>stack常用接口</h5>
    功能描述:栈容器常用的对外接口
    构造函数:
        stack&lt;T> stk;     // stack采用模板类实现，stack对象的默认构造形式
        stack( const stack &stk); //拷贝构造函数
    赋值操作:
        stack& operator=( const stack &stk);    //重载等号操作符
    数据存取:
        push(elem);     // 向栈顶添加元素
        pop();          // 从栈顶移除第一个元素
        top();          // 返回栈顶元素
    大小操作:
        empty();        // 判断堆栈是否为空
        size();         //返回栈的大小

<h4>queue容器</h4>
<h5>queue基本概念</h5>
    概念：queue是一种先进先出的数据结构，他有两个出口
    队列容器允许从一端新增元素，另一端移除元素
    队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
    队列中进数据称为入队(push)
    队列中出数据称为出队(pop)
<h5>queue常用接口</h5>
    功能描述:队列容器常用的对外接口
    构造函数:
        queue&lt;T> que;   // queue采用模板类实现， queue对象的默认构造形式
        queue(const queue &que);    //拷贝构造函数
    赋值操作:
        queue& operator=(const queue &que); //重载等号操作符
    数据存取:
        push(elem); //往队尾添加元素
        pop();      //从队头移除第一个元素
        back();     //返回最后一个元素
        front();    //返回第一个元素
    大小操作:
        empty();    //判断堆栈是否为空
        size();     //返回栈的大小


<h4>list容器</h4>
<h5>list基本概念</h5>
    功能:将数据进行链式存储
    链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
    链表的组成:链表由一系列结点组成
    结点的组成:一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
    STL中的链表是—个双向循环链表
    与数组比较：
        优点：可以对任意位置进行快速插入或删除元素
        缺点：
            容器遍历速度没有数组快
            占用空间比数组大
    由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
    list的优点:
        .采用动态存储分配，不会造成内存浪费和溢出
        ·链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    list的缺点:
        ·链表灵活，但是空间(指针域)和时间(遍历）额外耗费较大
    List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
    总结:STL中List和vector是两个最常被使用的容器，各有优缺点

<h5>list构造函数</h5>
    功能描述:
        .创建list容器
    函数原型:
    list&lt;T> lst;     //list采用采用模板类实现,对象的默认构造形式:
    list(beg,end);      //构造函数将[beg, end)区间中的元素拷贝给本身。
    list(n,elem);       //构造函数将n个elem拷贝给本身。
    list(const list &lst);  //拷贝构造函数。

<h5>list赋值和交换</h5>
    功能描述:
        给list容器进行赋值，以及交换list容器
    函数原型:
        assign(beg，end);    //将[beg, end)区间中的数据拷贝赋值给本身。
        assign(n， elem);    //将n个elem拷贝赋值给本身。
        list&operator=( const list &lst);   //重载等号操作符
        swap(lst);      //将lst与本身的元素互换。

<h5>list大小操作</h5>
    功能描述:
        对list容器的大小进行操作
    函数原型:
        size();     //返回容器中元素的个数
        empty();    //判断容器是否为空
        resize(num);    //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                        //如果容器变短，则末尾超出容器长度的元素被删除。
        resize( num，elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                             //如果容器变短，则末尾超出容器长度的元素被删除。

<h5>list插入和删除</h5>
    功能描述:
        对list容器进行数据的插入和删除
    函数原型:
        . push_back(elem);      //在容器尾部加入一个元素
        . pop_back();           //删除容器中最后一个元素
        . push_front(elem);     //在容器开头插入一个元素
        . pop_front();          //从容器开头移除第一个元素
        . insert(pos,elem);     //在pos位置插elem元素的拷贝，返回新数据的位置。
        . insert(pos,n,elem);    //在pos位置插入n个elem数据，无返回值。
        . insert(pos,beg,end);   //在pos位置插入[beg,end)区间的数据，无返回值。
        . clear();          //移除容器的所有数据
        . erase(beg,end);   //删除[beg,end)区间的数据，返回下一个数据的位置。
        . erase(pos);       //删除pos位置的数据，返回下一个数据的位置。
        . remove(elem);     //删除容器中所有与elem值匹配的元素。

<h5>list数据存取</h5>
    功能描述:
        .对list容器中数据进行存取
    函数原型:
        front();    //返回第一个元素。
        back();     //返回最后一个元素。

<h5>list反转和排序</h5>
    功能描述:
        ·将容器中的元素反转，以及将容器中的数据进行排序
    函数原型:
    revere();   //反转链表
    sort();     //链表排序

<h5>排序案例</h5>
    案例描述：
        将Human自定义类型数据进行排序，Human属性有姓名、年龄、身高
    排序规则：
        按照年龄进行升序，如果年龄相同按照身高进行排序
    总结:
        ·对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
        ·高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂

<h4>set/multiset容器</h4>
<h5>set基本概念</h5>
    简介:
        ·所有元素都会在插入时自动被排序
    本质:
        .vet/multiset属于关联式容器，底层结构是用二叉树实现。
    set和multiset区别:
        .set不允许容器中有重复的元素
        .multiset允许容器中有重复的元素
<h5>set构造和赋值</h5>
    功能描述:创建set容器以及赋值
    构造:
        set&lt;T> st;      //默认构造函数:
        set(const set &st);    //拷贝构造函数
    赋值:
        set& operator=(const set &st);  //重载等号操作符

<h5>set大小和交换</h5>
    功能描述:
        ·统计set容器大小以及交换set容器
    函数原型:
        size();     //返回容器中元素的数目
        empty();    //判断容器是否为空
        swap(st);   //交换两个集合容器
        
<h5>set插入和删除</h5>
    功能描述:
        set容器进行插入数据和删除数据
    函数原型:
        insert(elem);   //在容器中插入元素。
        clear();        //清除所有元素
        erase(pos);     //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg，end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
        erase(elem);    //删除容器中值为elem的元素。

<h5>set查找和统计</h5>
    功能描述:
        ·对set容器进行查找数据以及统计数据
    函数原型:
        find(key);  //查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回set.end();
        count(key); //统计key的元素个数


<h5>set和multiset区别</h5>
    学习目标:
        ·掌握set和multiset的区别
    区别:
        set不可以插入重复数据，而multiset可以
        set插入数据的同时会返回插入结果，表示插入是否成功
        multiset不会检测数据，因此可以插入重复数据

<h5>set容器排序</h5>
    学习目标:
        set容器默认排序规则为从小到大工掌握如何改变排序规则
    主要技术点:
        ·利用仿函数，可以改变排序规则
    总结:
        对于自定义数据类型，set必须指定排序规则才可以插入数据

    
    
<h5>pair对组创建</h5>
    功能描述:
        成对出现的数据，利用对组可以返回两个数据
    两种创建方式:
        pair&lt;type,type> p (value1,value2 );
        pair&lt;type,type> p = make_pair(value1,value2 );

<h5>map/multimap容器</h5>
    map基本概念
    简介:
        map中所有元素都是pair
        pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
        ·所有元素都会根据元素的键值自动排序
    本质:
        . map/multimap属于关联式容器，底层结构是用二叉树实现。
    优点:
        ·可以根据key值快速找到value值
    map和multimap区别:
        map不允许容器中有重复key值元素
        multimap允许容器中有重复key值元素
        
<h5>map构造和赋值</h5>
    功能描述:
        对map容器进行构造和赋值操作
    函数原型:
    构造:
    map&lt;T1，12> mp;       //map默认构造函数:
    map(const map &mp);      //拷贝构造函数
    
    赋值:
        map& operator=(const map &mp);//重载等号操作符
        
<h5>map大小和交换</h5>
    功能描述:
        ·统计map容器大小以及交换map容器
    函数原型:
        size();     //返回容器中元素的数目
        empty();    //判断容器是否为空
        swap(st);   //交换两个集合容器

<h5>map插入和删除</h5>
    功能描述:
        map容器进行插入数据和删除数据
    函数原型:
        insert(elem);       //在容器中插入元素。
        clear();            //清除所有元素
        erase(pos);         //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg,end);     //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
        erase(key);         //删除容器中值为key的元素。

<h5>map查找和统计</h5>
    功能描述:
        ·对map容器进行查找数据以及统计数据
    函数原型:
        find(key);      //查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回map.end();
        count(key);      //统计key的元素个数

<h5>map容器排序</h5>
    学习目标:
        map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则
    主要技术点:
        利用仿函数，可以改变排序规则
    总结:
        利用仿函数可以指定map容器的排序规则
        对于自定义数据类型，map必须要指定排序规则,司set容器

<h5>案例-员工分组</h5>
    案例描述
        ·公司今天招聘了10个员工(ABCDEFGHI)，10名员工进入公司之后，需要指派员工在那个部门工作
        ·员工信息有:姓名工资组成;部门分为:策划、美术、研发
        ·随机给10名员工分配部门和工资
        ·通过multimap进行信息的插入key(部门编号) value(员工)
        ·分部门显示员工信息
    实现步骤
        1.创建10名员工，放到vector中
        2.遍历vector容器，取出每个员工，进行随机分组
        3.分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
        4.分部门显示员工信息

<h4>STL-函数对象</h4>
    函数对象
    函数对象概念:
        ·重载函数调用操作符的类，其对象常称为函数对象
        ·函数对象使用重载的(时，行为类似函数调用，也叫仿函数
    本质:
        函数对象(仿函数)是一个类，不是一个函数

<h5>函数对象使用</h5>
    特点:
        函数对象在使用时，可以像普通函数那样调用,可以有参数，可以有返回值
        函数对象超出普通函数的概念，函数对象可以有自己的状态
        函数对象可以作为参数传递


<h4>谓词</h4>
    谓词概念:
        返回bool类型的仿函数称为谓词
        如果operator()接受一个参数，那么叫做一元谓词
        如果operator()接受两个参数，那么叫做二元谓词


<h4>内建函数对象</h4>
    内建函数对象意义
    概念:
        . STL内建了—些函数对象
    分类:
        ·算术仿函数
        ·关系仿函数
        ·逻辑仿函数
    用法:
        ·这些仿函数所产生的对象，用法和—般函数完全相同
        ·使用内建函数对象，需要引入头文件|#include&lt;functional>
<h5>算术仿函数</h5>
    功能描述:
        ·实现四则运算
        ·其中negate是一元运算，其他都是二元运算
    仿函数原型:
        template&lt;class T> T plus&lt;T>         //加法仿函数
        template&lt;class T> T minus&lt;T>        //减法仿函数
        template&lt;class T> T multiplies&lt;T>    //乘法仿函数
        template&lt;class T> T divides&lt;T>      //除法仿函数
        template&lt;class T> T modulus&lt;T>      //取模仿函数
        template&lt;class T> T negate&lt;T>       //取反仿函数

<h5>关系仿函数</h5>
    功能描述:
        ·实现关系对比
    仿函数原型:
        template&lt;class t> bool equal_to&lt;T>          //等于
        template&lt;class T> bool not_equal_to&lt;T>      //不等于
        template&lt;class t> bool greater&lt;T>           //大于
        template&lt;class T> bool greater_equal&lt;T>     //大于等于
        template&lt;class T> bool less&lt;T>              //小于
        template&lt;class T> bool less_equal&lt;T>        //小于等于

<h5>逻辑仿函数</h5>
    功能描述:
        实现逻辑运算
    函数原型:
        template&lt;class r> bool logical_and&lt;T>       //逻辑与
        template&lt;class r> bool logical_or&lt;T>        //逻辑或
        template&lt;class r> bool logical_not&lt;T>       //逻辑非

<h4>STL-常用算法</h4>
    概述:
        ·算法主要是由头文件&lt;algorithm>&lt;functional>&lt;numeric>组成。
        &lt;algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
        &lt;numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
        &lt;functional>定义了—些模板类,用以声明函数对象。

    常用遍历算法
    算法简介:
        for_each        //遍历容器
        transform       //搬运容器到另一个容器中
    
    for_each
        功能描述:
            实现遍历容器
            函数原型:
                for_each(iterator beg, iterator end，_func);     
                    //遍历算法遍历容器元素
                    // beg开始迭代器
                    // end结束迭代器
                    // _func函数或者函数对象
    
    transform
        功能描述:
            搬运容器到另—个容器中
        函数原型:
            transform(iterator beg1， iterator end1， iterator beg2，_func);
                //beg1源容器开始迭代器
                //end1源容器结束迭代器
                //beg2目标容器开始迭代器
                //_func函数或者函数对象

    常用查找算法
    算法简介:
    find            //查找元素
    find_if         //按条件查找元素
    adjacent_find   //查找相邻重复元素
    binary_search   //二分查找法
    count           //统计元素个数
    count_if        //按条件统计元素个数
    
    find功能描述:
        ·查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
    
    函数原型:
        find(iterator beg, iterator end，value);
            //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
            // beg开始迭代器
            // end结束迭代器
            // value查找的元素

    find_if功能描述:
        ·按条件查找元素
    函数原型:
        find_if(iterator beg，iterator end，_pred);
            //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
            // beg开始迭代器
            // end结束迭代器
            // _Pred函数或者谓词（返回bool类型的仿函数)

    adjacent_find功能描述:
        .查找相邻重复元素
    函数原型:
        adjacent_find(iterator beg， iterator end);
            //查找相邻重复元素,返回相邻元素的第一个位置的迭代器
            // beg开始迭代器
            // end结束迭代器

    binary_search功能描述:
        查找指定元素是否存在
    函数原型:
        bool binary_search(iterator beg， iterator end，value);
            //查找指定的元素，查到返回true否则false
            //注意:在无序序列中不可用
            // beg开始迭代器
            // end结束迭代器
            // value查找的元素
    
    count功能描述:
        统计元素个数
    函数原型:
        count(iterator beg， iterator end，value);
            // 统计元素出现次数
            // beg开始迭代器
            // end结束迭代器
            // value统计的元素

    count_if功能描述:
        ·按条件统计元素个数
    函数原型:
        count_if(iterator beg, iterator end，_pred);
            // 按条件统计元素出现次数
            // beg开始迭代器
            // end结束迭代器
            // _Pred 谓词
    
    常用排序算法
    算法简介:
        sort            //对容器内元素进行排序
        random_shuffle  //洗牌指定范围内的元素随机调整次序
        merge           //容器元素合并，并存储到另—容器中
        reverse         //反转指定范围的元素
    
    sort功能描述:
        . 对容器内元素进行排序
    函数原型:
        sort(iterator beg， iterator end，_pred);
            //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
            //beg开始迭代器
            //_pred 谓词

    random_shuffle功能描述:
        ·洗牌指定范围内的元素随机调整次序
    函数原型:
        random_shuffle(iterator beg， iterator end);
            //指定范围内的元素随机调整次序
            // beg开始迭代器
            // end结束迭代器

    merge功能描述:
        .两个容器元素合并，并存储到另—容器中
    函数原型:
        merge(iterator beg1，iterator end1，iterator beg2，iterator end2，iterator dest);
            //容器元素合并，并存储到另—容器中
            注意:两个容器必须是有序的
            // beg1容器1开始迭代器
            // end1容器1结束迭代器
            // beg2容器2开始迭代器
            // end2容器2结束迭代器
            // dest目标容器开始迭代器

    reverse功能描述:
        .将容器内元素进行反转
    函数原型:
        reverse(iterator beg， iterator end);
            // 反转指定范围的元素
            // beg开始迭代器
            // end结束迭代器

    常用拷贝和替换算法
    算法简介:
        copy        //容器内指定范围的元素拷贝到另—容器中
        replace     //将容器内指定范围的旧元素修改为新元素
        replace_if  //容器内指定范围满足条件的元素替换为新元素
        swap        //互换两个容器的元素
    
    copy功能描述:
        .容器内指定范围的元素拷贝到另—容器中
    函数原型:
        copy(iterator beg， iterator end，iterator dest);
        //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

    replace功能描述:
        将容器内指定范围的旧元素修改为新元素
    函数原型:
        replace(iterator beg， iterator end，oldvalue，newvalue);
        //将区间内旧元素替换成新元素
        // beg开始迭代器
        // end结束迭代器
        // oldvalue 旧元素
        // newvalue新元素

    replace_if功能描述:
        ·将区间内满足条件的元素，替换成指定元素
    函数原型:
        replace_if(iterator beg， iterator end，_pred，newvalue);
        //按条件替换元素，满足条件的替换成指定元素
        // beg开始迭代器
        // end结束迭代器
        // _pred谓词
        // newalue替换的新元素
    
    swap功能描述:
        互换两个容器的元素
    函数原型:
        swap(container c1,container c2);
        //互换两个容器的元素
        // c1容器1
        // c2容器2

    常用算术生成算法
    注意:
        ·算术生成算法属于小型算法，使用时包含的头文件为#include &lt;numeric>
    算法简介:
        accumulate          //计算容器元素累计总和
        fill                //向容器中添加元素
        
    accumulate功能描述:
        ·计算区间内容器元素累计总和
    函数原型:
        accumulate(iterator beg，iterator end，value);
        //计算容器元素累计总和
        // beg开始迭代器
        // end 结束迭代器
        // value起始值

    fll功能描述:
        ·向容器中填充指定的元素
    函数原型:
        fill(iterator beg， iterator end， value);
        //向容器中填充元素
        //beg开始迭代器
        //end结束迭代器
        //value填充的值

    
    常用集合算法
    算法简介:
        set_intersection    //求两个容器的交集
        set_union           //求两个容器的并集
        set_difference      //求两个容器的差集
    
    set_intersection功能描述:
        ·求两个容器的交集
    
    函数原型;
        set_intersection(iterator beg1，iterator end1，iterator beg2，iterator end2，iterator dest);
        求两个集合的交集
        注意:两个集合必须是有序序列
        // beg1容器1开始迭代器
        // end1容器1结束迭代器
        // beg2容器2开始迭代器
        // end2容器2结束迭代器
        // dest目标容器开始迭代器
    总结:
        求交集的两个集合必须的有序序列
        目标容器开辟空间需要从两个容器中取小值
        set_intersection返回值是交集中最后一个元素的位置

    set_union功能描述:
        ·求两个集合的并集
    函数原型:
        set_union(iterator beg1，iterator end1，iterator beg2，iterator end2，iterator dest);
        //求两个集合的并集
        注意:两个集合必须是有序序列
        // beg1容器1开始迭代躏
        // end1容器1结束迭代器
        // beg2容器2开始迭代器
        // end2容器2结束迭代器
        // dest目标容器开始迭代器
    总结:
        求并集的两个集合必须的有序序列
        目标容器开辟空间需要两个容器相加
        set_union返回值既是并集中最后一个元素的位置

    set_difference功能描述:
        求两个集合的差集
    函数原型:
        set_difference(iterator beg1，iterator end1，iterator beg2，iterator end2，iterator dest);
        求两个集合的差集
        注意:两个集合必须是有序序列
        beg1容器1开始迭代器
        end1容器1结束迭代器
        beg2容器2开始迭代器
        end2容器2结束迭代器
        dest目标容器开始迭代器
    总结:
        ·求差集的两个集合必须的有序序列
        ·目标容器开辟空间需要从两个容器取较大值
        .set_difference返回值既是差集中最后一个元素的位置
</pre>
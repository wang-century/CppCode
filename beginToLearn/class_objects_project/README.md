类和对象
<pre>
面向对象三大特性：封装、继承、多态

访问权限：
    public      公共权限：类内可以访问，类外可以访问
    protected   保护权限：类内可以访问，类外不可以访问（继承后可以访问）
    private     私有权限：类内可以访问，类外不可以访问（继承后不可以访问）


封装
    意义：
        将属性和行为作为一个整体，体现生活中的事物
        将属性和行为加以权限控制    
    
    语法：
        class 类名{访问权限:属性/行为};
        
    示例：
        1.设计一个圆类，求圆的周长
        2.设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
        3.设计立方体(Cube)，求出立方体的面积和体积，分别用全局函数和成员函数判断两个立方体是否相等
        4.设计一个圆形类(Circle)，和一个点类(Point)，计算点和圆的关系(通过点和圆心的距离判断：点在圆内、圆上、圆外)
        
        
struct和class的区别：
        struct默认访问权限是公有
        class默认权限是私有


构造函数和析构函数：
    用于对象的初始化和清理，会被编译器自动调用，若不定义，编译器会自动提供空实现的构造和析构函数。
    
    构造函数：
        主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用
        语法：类名(){}
            1.没有返回值也没有void
            2.函数名称和类名相同
            3.构造函数可以有参数，因此可以实现重载
            4.程序在调用对象时会自动调用构造函数，并且只会调用一次
    析构函数：
        主要作用在于对象销毁前系统自动调用，执行清理工作
        语法：～类名(){}
            1.没有返回值也没有void
            2.函数名称和类名相同，但要在名称前加符号～
            3.不可以有参数，不可以重载
            4.程序在对象销毁前会自动调用析构函数，并且只会调用一次
    
构造函数的分类及调用
    两种分类方式：
        按参数分：有参构造和无参构造
        按类型分：普通构造和拷贝构造
    三种调用方式：
        括号法     Person p1; Person p2(10); Person p3(p2);
        显示法     Person p1; Person p2 = Person(10); Person p3 = Person(p2);
        隐式转换法

拷贝构造函数的使用时机：
    1.使用一个已经创建完毕的对象来初始化一个新对象
    2.值传递的方式给函数参数传递
    3.以值方式返回局部对象
    
构造函数调用规则：
    默认情况，编译器会给一个类添加3个函数：默认构造函数、默认析构函数、默认拷贝构造函数
    如果用户定义了有参构造函数，编译器不会再提供默认无参构造，但会提供默认拷贝构造
    如果用户定义了拷贝构造函数，编译器不会再提供其它构造函数
    
深拷贝和浅拷贝：
    浅拷贝：简单的赋值拷贝操作
    深拷贝：在堆区重新申请空间，进行拷贝操作
    
静态成员
    说明：静态成员就是在成员变量或成员函数前加关键字static
    静态成员变量：
        所有对象共享同一份数据
        在编译阶段分配内存
        类内声明，类外初始化
    静态成员函数：
        所有对象共享同一个函数
        静态成员函数只能访问静态成员变量
        
this指针：
    this指针指向被调用的成员函数所属的对象
    this指针是隐含每一个非静态成员函数内的一种指针，不需要定义，直接使用
    用途：
        当形参和成员变量同名时，可用this指针来区分
        在类的非静态成员函数中返回对象本身，可用return *this
        

const修饰成员函数
    常函数：
        成员函数后加const后称之为常函数
        常函数内不可以修改成员属性
        成员属性声明时加关键字mutable，在常函数中可以修改该关键字
    常对象：
        声明对象前加const称该对象为常对象
        常对象只能调用常函数   


友元
    目的是让一个函数或者类访问另一个类中的私有成员
    三种实现：
        全局函数作友元
        类做友元
        成员函数做友元
        
        
运算符重载
    概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同数据类型
    加号运算符重载(+)：
        作用：实现两个自定数据类型相加的运算
        方式：
            通过成员函数重载+号
            通过全局函数重载+号
    注意：
        对于内置的数据类型的表达式的运算符是不可能改变的
        不要滥用运算符重载
    
    左移运算符重载(<<)：
        作用：可以输出自定义数据类型
    
    递增运算符重载(++):
        作用：通过重载递增运算符实现自己的整形数据
        说明：前置递增返回引用，后置递增返回值
    
    赋值运算符重载(=)：
        注：C++编译器至少给一个类添加4个函数：（默认构造函数、默认析构函数、默认拷贝构造函数、赋值运算符operator=），如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
    
    关系运算符重载(==,!=)：
        作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
        
    函数调用运算符重载(())：
        由于重载后使用的方式非常像函数的调用，因此称为仿函数
        仿函数没有固定写法，非常灵活
    


继承：
    好处：减少代码量
    语法：class 子类: 继承方式 父类
    继承方式：
    注：父类中的私有权限成员，子类中无法访问;父类中所有非静态成员属性都会被子类继承下去，包括私有属性(父类中的私有成员属性被编译器隐藏了，因此无法访问，但确实被继承了)
        公共继承  父类中的公共权限成员 到子类中依然是公共权限 父类中的保护权限成员到子类中依然是保护权限  
        保护继承  父类中的公共权限成员 到子类中是保护权限 父类中的保护权限成员到子类中依然是保护权限  
        私有继承  父类中的公共权限成员 到子类中是私有权限 父类中的保护权限成员到子类中是私有权限
    总结：
        继承中，先调用父类构造函数，再调用子类构造函数，析构顺序与构造顺序相反
    
继承同名成员处理方式：
    访问子类同名成员 直接访问即可
    访问父类同名成员 需要添加作用域
    
继承同名静态成员处理方式：
    注：与同名成员处理方式一致
    访问子类同名成员 直接访问即可
        访问父类同名成员 需要添加作用域
        
多继承语法(不建议)：
    说明：c++允许一个类继承多个类，多继承可能会引发父类中有同名成员出现，需要加作用域区分
    语法：class 子类:继承方式 父类1, 继承方式 父类2...
    
菱形继承
    概念：
        两个派生类继承同一个基类
        又有某个类同时继承两个派生类
        这种继承成为菱形继承，或钻石继承
    假设有一个Animal动物类，派生了两个类 Sheep羊类、Camel骆驼类，又有一个Alpaca羊驼类继承了羊类和骆驼类
    问题：
        羊继承了动物的数据，骆驼同样继承了动物的数据，当羊驼使用数据时，会产生二义性
        羊驼继承自动物的数据继承了两份(资源浪费)，其实只要一份就可以(利用虚继承可以解决)
        
           
           
多态
    当父类的指针或引用指向子类对象的时候，发生多态
    优点：
        代码组织结构清晰
        可读性强
        利于前期后期的扩展以及维护
    
    分类：
        静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
        动态多态：派生类和虚函数实现运行时多态
    静态多态和动态多态的区别：
        静态多态的函数地址早绑定 - 编译阶段确定函数地址
        动态多态的函数地址晚绑定 - 运行阶段确定函数地址
    动态多态的满足条件：
        1.有继承关系
        2.子类重写父类的虚函数
    
    多态案例：
        1.计算器类
            描述：利用多态技术，实现两个操作数进行运算的计算器类 
        2.制作饮品
            描述：制作饮品的大致流程为：煮水->冲泡->倒入杯中->加入辅料
                利用多态实现本例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
                咖啡（煮水->冲泡咖啡->倒入杯中->加糖和牛奶）
                冲茶叶(煮水->冲泡茶叶->倒入杯中->加柠檬)   
        3.电脑组装
            描述：电脑主要组成部件为CPU、显卡、内存条
                将每个零件封装出抽象类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenove厂商
                创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
                测试时组装三台不同的电脑进行工作
    
纯虚函数和抽象类
    在多态中，通常父类中虚函数的实现是无意义的，主要是调用子类重写的内容，因此可以将函数修改为纯虚函数
    纯虚函数语法：virtual 返回值类型 函数名 (参数列表) = 0;
    当类中有了纯虚函数，这个类也被称为抽象类
    抽象类特点：
        无法实例化对象
        子类必须重写抽象类中的纯虚函数，否则也属于抽象类
        
虚析构和纯虚析构
    说明：多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
    解决方式：将父类中的析构函数改为虚析构或纯虚析构
    虚析构和纯虚析构共性：
        可以解决父类指针释放子类对象
        都需要有具体的函数实现
    区别：
        如果是纯虚析构，该类属于抽象类，无法实例化对象
    语法：
        虚析构语法：virtual ~类名(){}
        纯虚析构语法：virtual ~类名()=0;  类名::类名(){}
    
</pre>
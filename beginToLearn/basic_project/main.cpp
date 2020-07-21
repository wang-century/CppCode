#include <iostream>
#include <string>
#include "include/basic_extend.h"

using namespace std;

// macro constant
#define Day 7


// 结构体的定义  struct 结构体名 {结构体成员列表};
struct Student {
    // 成员列表
    string name;
    int age;
    float score;
}student3;

// 结构体嵌套
struct Teacher{
    int id;
    string name;
    int age;
    struct Student stu;
};

void print_helloworld();

// 函数声明
void define_variable();

void define_macro_constant();

void use_sizeof();

void arithmetic_operation();

void use_do_while();

void find_three_figures_narcissistic_number();

void use_for();

void desk_knock();

void nested_loop();

void print_multiplication_table();

void use_goto();

void use_array();

void bubble_sort();

void double_dimensional_array();

int sum_two_number(int number1, int number2);



void print_student_info_by_point(Student * point);
void print_student_info(const Student * stu);

int main() {
    // print "hello world!" in command line
    print_helloworld();
    define_variable();
    define_macro_constant();
    use_sizeof();
    //input_content();
    arithmetic_operation();
    //use_if();
    //input_3_number_out_max_number();
    //use_switch();
    //use_while();
    use_do_while();
    find_three_figures_narcissistic_number();
    use_for();
    desk_knock();
    nested_loop();
    print_multiplication_table();
    use_goto();
    use_array();
    bubble_sort();
    double_dimensional_array();
    int sum = sum_two_number(1, 2);
    cout << sum << endl;
    cout << return_max_number(1,2) << endl;
    use_point();    // 使用指针
    int a = 1;
    int b = 2;
    point_and_function(&a,&b);
    cout << "a,b的值为：" << a << "\t" << b << endl;
    // 利用指针对数组进行升序排列
    int array[] = {4,3,6,9,1,2,10,8,7,5};
    int len = sizeof(array)/sizeof(array[0]);
    bubble_sort2(array,len);
    cout << "冒泡排序结果为：" << endl;
    for (int i:array){
        cout << i << " ";
    }
    cout << endl;

    // 结构体创建具体学生
    struct Student student1;
    student1.name = "章三";
    student1.age = 20;
    student1.score = 300;
    cout << "姓名：" << student1.name << "年龄：" << student1.age << "分数：" << student1.score << endl;
    struct Student student2 = {
            "里斯", 20 , 200
    };
    cout << "姓名：" << student2.name << "年龄：" << student2.age << "分数：" << student2.score << endl;
    student3.name = "王五";
    student3.age = 21;
    student3.score = 250;

    // 结构体数组
    Student stuArray[2] = {
            {"哈哈",20,210},
            {"嘿嘿",21,220}
    };
    // 给结构体数组中元素赋值
    stuArray[0].name = "年你和";
    // 遍历结构体数组
    for (int i=0;i<2;i++){
        cout << "姓名：" << stuArray[i].name << "年龄：" << stuArray[i].age << "分数：" << stuArray[i].score << endl;
    }

    // 结构体指针
    Student student4 = {"萨",20,240};
    Student *point_student4 = &student4;
    cout << point_student4->name << "\t" << point_student4->age << "\t" << point_student4->score << endl;


    // 结构体嵌套结构体
    Teacher teacher1 = {1000,"老王",30,student4};
    cout << "老师姓名：" << teacher1.name << "\t年龄：" << teacher1.age << "\t教导学生：" << teacher1.stu.name << endl;

    // 结构体作函数参数
    // 1.值传递 2.地址传递
    print_student_info(&student4);
    print_student_info_by_point(&student4);


    // 内存四区
    memeory_four_area();

    // 堆
    int * point_heap_a = use_heap();
    cout << "堆的数据：" << *point_heap_a << endl;

    // new关键字
    use_new();

    // 引用
    use_reference();

    // 函数默认参数
    cout << "函数默认参数：" << function_default_argument(10,20) << endl;

    // 函数重载
    function_overloading();

    return 0;
}




void print_student_info(const Student * stu){   // 结构体使用const  一旦有修改的操作就会报错，防止误操作
    // 打印学生信息
    cout << "姓名：" << stu->name << "年龄：" << stu->age << "分数：" << stu->score << endl;
}

void print_student_info_by_point(Student * point){
    // 使用指针打印学生信息
    cout << point->name << "\t" << point->age << "\t" << point->score << endl;
}


// print "hello world!" in command line
void print_helloworld() {
    cout << "\n01.Print Hello World" << endl;
    cout << "hello world!" << endl;
}

void define_variable() {
    cout << "\n02.Define Variable" << endl;
    int a = 10;
    float b = 3.14f;
    double c = 3.14;
    float d = 3e2;  // scientific notation
    char ch1 = 'a';  // note: 1.use '' 2.only one char
    char ch2 = 'A';
    char string1[] = "hello world";
    string string2 = "hello world";
    bool flag = true;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;
    cout << "ch1=" << ch1 << " in ASCII:" << (int) ch1 << endl;
    cout << "ch2=" << ch2 << " in ASCII:" << (int) ch2 << endl;
    cout << "string1=" << string1 << endl;
    cout << "string2=" << string2 << endl;
    cout << "flag=" << flag << endl;
    cout << "bool type use memory:" << sizeof(bool) << endl;
}

// macro constant
void define_macro_constant() {
    /* 1.#define Day 7
     * 2.const int month = 12;
     * */
    const int Month = 12;
    cout << "\n03.Macro Constant" << endl;
    cout << "every week have days:" << Day << endl;
    cout << "every year have months:" << Month << endl;
}

// statistical memory space
void use_sizeof() {
    cout << "\n04.Sizeof" << endl;
    cout << "short memory:" << sizeof(short) << endl;
    cout << "int memory:" << sizeof(int) << endl;
    cout << "long memory:" << sizeof(long) << endl;
    cout << "long long memory:" << sizeof(long long) << endl;
    cout << "float memory:" << sizeof(float) << endl;
    cout << "double memory:" << sizeof(double) << endl;
}

void input_content() {
    // cin >> variable
    cout << "\n05.Input Content" << endl;
    int age;
    cout << "Please input your age:" << endl;
    cin >> age; // input age

    string name = "hello";
    cout << "Please input your name:" << endl;
    cin >> name;    // input name

    cout << "Input result:\nname:" << name << "\tage:" << age << endl;
}

void arithmetic_operation() {
    cout << "\n06.Arithmetic Operation" << endl;
    int num1 = 10;
    int num2 = 3;

    cout << num1 + num2 << endl;
    cout << num1 - num2 << endl;
    cout << num1 * num2 << endl;
    cout << num1 / num2 << endl;
    cout << num1 % num2 << endl;

    int a = 1;
    int b = ++a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    int c = 1;
    int d = c++;
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;

    // +=  -=  *=  /=  %=
    int e = 10;
    e += 1;
    cout << "e=" << e << endl;

    // comparison operation:== != <= >= < >
    int f = 10;
    int g = 10;
    int h = 11;
    cout << "f==g  " << (f == g) << endl;
    cout << "f!=g  " << (f != g) << endl;
    cout << "g<=h  " << (g <= h) << endl;

    // logical operator:! && ||   note:  not  and  or
    int i = 10;
    cout << "!i=" << (!i) << endl;

    int j = 0;
    cout << "i&&j=" << (i && j) << endl;
    cout << "i&&1=" << (i && 1) << endl;

    cout << "i||j=" << (i || j) << endl;

    // ternary operator
    int number1 = 10;
    int number2 = 20;
    int number3;
    // if a>b result is a  else result is b   note: return is variable
    number3 = a > b ? a : b;
    (number1 < number2 ? number1 : number2) = 100;

    cout << "number3=" << number3 << endl;
    cout << "number1=" << number1 << endl;


}

void use_if() {
    cout << "\n06.If Else" << endl;
    int age;
    cout << "Please input you age:" << endl;
    cin >> age;
    if (age == 18) {
        cout << "Oh, You are adult now." << endl;
    } else if (age > 18) {
        cout << "You are adult." << endl;
    } else {
        cout << "You are teenager." << endl;
    }
}

void input_3_number_out_max_number() {
    int a, b, c;
    cout << "Please number a:" << endl;
    cin >> a;
    cout << "Please number b:" << endl;
    cin >> b;
    cout << "Please number c:" << endl;
    cin >> c;
    if (a > b) {   // a>b
        if (a > c) {
            cout << "Max number is a:" << a << endl;
        } else {
            cout << "Max number is c:" << c << endl;
        }
    } else {  // a<b
        if (b > c) {
            cout << "Max number is b:" << b << endl;
        } else {
            cout << "Max number is c:" << c << endl;
        }
    }
}

void use_switch() {
    // movie rating
    int score;
    cout << "Please rate the movie(0-10):" << endl;
    cin >> score;
    switch (score) {
        case 10:
        case 9:
            cout << "You think the movie is very great." << endl;
            break;
        case 8:
        case 7:
            cout << "You think the movie is great." << endl;
            break;
        case 6:
        case 5:
            cout << "You think the movie is good." << endl;
            break;
        default:
            cout << "You think the movie is bad." << endl;
    }
}

void use_while() {
    // print 0~9
    int number = 0;
    while (number < 10) {
        cout << number << endl;
        number++;
    }
    // guess number
    int rand_number = rand() % 100 + 1; // random generate 1-100
    int guess_number;
    int count_guess_time = 0;
    cout << "Please enter your guess number:" << endl;
    cin >> guess_number;
    while (guess_number != rand_number) {
        if (guess_number > rand_number) {
            cout << "Your number is big" << endl;
        } else {
            cout << "Your number is small" << endl;
        }
        count_guess_time++;
        cout << "Please enter your guess number:" << endl;
        cin >> guess_number;
    }
    if (rand_number == guess_number) {
        cout << "Congratulation! Guess right! Your guess time is:" << count_guess_time << endl;
    }

}

void use_do_while() {
    // print 0-9
    int number = 0;
    do {
        cout << number << "\t";
        number++;
    } while (number < 10);
    cout << "\n";
}

void find_three_figures_narcissistic_number() {
    // find 100-999 narcissistic_number
    int number = 100;

    while (number < 1000) {
        int a, b, c;
        a = number % 10;
        b = (number / 10) % 10;
        c = number / 100;
        if (a * a * a + b * b * b + c * c * c == number) {
            cout << number << " is narcissistic number." << endl;
        }
        number++;
    }
}

void use_for() {
    // print 0-9
    for (int i = 0; i < 10; i++) {
        cout << i << "\t";
    }
    cout << "\n";
}

void desk_knock() {
    // 1-100 if: number%10==7  or  number/10==7  or number%7==0  print this number
    for (int number = 1; number < 100; number++) {
        if (number % 10 == 7 || number / 10 == 7 || number % 7 == 0) {
            cout << number << "\t";
        }
    }
    cout << endl;
}

void nested_loop() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void print_multiplication_table() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "*" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }

}

void use_goto() {
    cout << "1" << endl;
    cout << "2" << endl;
    goto FLAG;
    cout << "3" << endl;
    FLAG:
    cout << "4" << endl;
    cout << "5" << endl;
}

void use_array() {
    // define array
    int arry1[20];
    int array2[20] = {1, 2, 3};
    int array3[] = {1, 2, 3};

    for (int i : array2) {
        cout << i << "\t";
    }
    cout << endl;

    // find max number
    int numbers[] = {100, 300, 50, 30, 399, 102};
    int max_number = 0;
    for (int i:numbers) {
        if (i > max_number) {
            max_number = i;
        }
    }
    cout << "Max number is:" << max_number << endl;

    // reverse array
    int start_point = 0;
    int end_point = sizeof(numbers) / sizeof(numbers[0]) - 1;

    for (; start_point < end_point; start_point++, end_point--) {
        cout << start_point << "\t" << end_point << endl;
        int trans_number = numbers[start_point];
        numbers[start_point] = numbers[end_point];
        numbers[end_point] = trans_number;
    }
    for (int i:numbers) {
        cout << i << endl;
    }
}

void bubble_sort() {
    int array[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int array_length = sizeof(array) / sizeof(array[0]);
    int trans_number;

    for (int i:array) {
        cout << i << "\t";
    }

    cout << endl;

    // bubble sort
    for (int i = 0; i < array_length - 1; i++) {
        for (int j = 0; j < array_length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                trans_number = array[j];
                array[j] = array[j + 1];
                array[j + 1] = trans_number;
            }
        }
    }

    for (int i:array) {
        cout << i << "\t";
    }
    cout << endl;

}

void double_dimensional_array() {
    // fout methods
    int arry1[2][3];    // 1
    int arry2[2][3] = { // 2
            {1, 2, 3},
            {4, 5, 6}
    };
    int arry3[2][3] = {1, 2, 3, 4, 5, 6}; // 3
    int arry4[][3] = {1, 2, 3}; // 4

    cout << "double dimensional array use memory:" << sizeof(arry2) << endl;
    cout << "double dimensional array address:" << (long) arry2 << endl;
    // there have three students score please save it use array and print it
    /* zhangsan  100  100  100
     * lisi      90   50   100
     * wangwu    60   70   80
     * */
    float students_score[3][3] = {
            {100, 100, 100},
            {90,  50,  100},
            {60,  70,  80}
    };
    string names[3] = {"zhangsan", "lisi", "wangwu"};

    for (int i = 0; i < 3; i++) {
        float sum_score = 0;
        for (float j : students_score[i]) {
            cout << j << "\t";
            sum_score += j;
        }
        cout << names[i] << " sum score:" << sum_score << endl;
    }
}



int sum_two_number(int number1, int number2) {
    // 返回两数和
    int sum;
    sum = number1 + number2;
    return sum;
}


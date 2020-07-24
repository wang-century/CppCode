文件操作
<pre>
说明：通过文件可以将数据持久化
    C++中对文件操作需要头文件fstream

文件类型分为两种：
    1.文本文件      文件以ASCII形式存储在计算机中
    2.二进制文件     文件以文本的二进制形式存储在计算机中

操作文件的三大类：
    1.ofstream  写操作
    2.ifstream  读操作
    3.fstream   读写操作
    
写文件步骤：
    1.引入头文件
        #include "fstream"
    2.创建流对象
        ofstream ofs;
    3.打开文件
        ofs.open("文件路径","打开方式");
    4.写数据
        ofs<<"写入的数据";
    5.关闭文件
        ofs.close();
        
文件打开方式：
    打开方式                解释
    ios::in              为读文件而打开文件
    ios::out             为写文件而打开文件
    ios::ate             初始位置:文件尾
    ios::app             追加方式写文件
    ios::trunc           如果文件存在先删除,再创建
    ios::binary          二进制方式
    注：文件打开方式可以配合使用，利用|操作符
    如：用二进制方式写文件 <code>ios::binary | ios::out</code>
</pre>

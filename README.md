# Garlic_Design 算法课设

![pic](pic/下载.jpg)

## 函数描述如下
-一. 文件读写类
-`1.创建页面文件函数`---根据所给文件，建立序号-网址的对应关系
-`2.创建单词列表函数`---每出现一个新的单词，则序号加1，并对应这个新单词
-`3.创建临时索引函数`---遍历文件中所有单词，创建单词（对应序号）-网址（对应序号）的对应关系
-`4.创建倒排索引函数`---合并同一单词的所有网址
-`5.读取页面文件函数`---每次读取一组 序号-单词，与当前单词比对
-`6.读取临时索引函数`---每次读取一组 单词-网址 对应信息
-`7.读取倒排索引函数`---每次读取一组 单词-网址-网址-网址……信息

-二.数据处理类
-`1.分词函数`---将输入的句子分割为若干单词
-`2.排序`---根据各网页出现次数对网页进行排序，由大至小
-`3.查找统计`---根据输入的单词在倒排索引中查找，并记录各网页出现次数

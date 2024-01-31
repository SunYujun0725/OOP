README

姓名: 孫渝鈞
學號: 409510049
e-mail: yujun91725@gmail.com

完成項目:
PartA:
1.cube.cpp: C++寫兩個operator overloading，其中'/'為non-member function，要用friend來實作，而判斷所有數值相乘是否不等於的函式要用member function來實作。
2.cube.h: cube.cpp的標頭檔，用來連接main.cpp及cube.cpp檔，裡面還包含所有class Cube的參數及函式宣告。
3.makefile: 將main.cpp及cube.cpp編譯成partA.out檔的指令。
4.partA.out: C++的執行檔。
5.main.cpp: 測試operator overloading的主函式
PartB:
1.time.cpp: C++寫<<、>>、<、>、<=、>=、==、!=、t1++、++t1、t1--、--t1、+(兩個class相加)、-(兩個class相減)、＋(一個class加另一整數)、-(一個class減另一整數)等多個operator overloading。
2.time.h: time.cpp的標頭檔，用來連接main.cpp及time.cpp檔，裡面還包含所有class Time的參數及函式宣告。
3.makefile: 將main.cpp及time.cpp編譯成partB.out檔的指令。
4.partB.out: C++的執行檔。
5.main.cpp: 測試operator overloading的主函式
6.readme:作業及程式細節資訊



Bouns:
partB:
1.在輸入class資料的時候有判斷是否為合法輸入，例如：12:13:14:15、12~13~24:23、12~12:23:23:23、12:12~234:234等皆為不合法輸入。
2.在輸入class資料的時候有判斷是否為負數，如果輸入有其中一個值為負數的話就全部設為00~00:00:00。
3.額外寫了兩個一整數加/減一個class Time的operator overloading，例如：12334+t1、565789-t1。



Reference:
1.c++(字串轉整數)：https://www.delftstack.com/zh-tw/howto/cpp/how-to-convert-string-to-int-in-cpp/
2.c++(operator overloading):http://wccclab.cs.nchu.edu.tw/www/images/VCplusplus/ch6.pdf
			    https://www.csie.ntu.edu.tw/~r95116/CA200/slide/C3_Overloading.pdf
			    https://openhome.cc/Gossip/CppGossip/OverloadOperator.html


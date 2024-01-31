README

姓名: 孫渝鈞
學號: 409510049
e-mail: yujun91725@gmail.com

完成項目:
1.oophw3.cpp: C++寫一程式輸入美金並且要生成用硬幣面值(quarters,dimes,nickels,pennies)的等值數量。並且要照Minimum class requirements去寫，我的member function寫法是把要傳入的參數都設為const確保我在這個function內不會動到這個變數，且我的member function不會回傳任何值而是都存在class的private內，最後在public另外寫多個印出的inline const 的print function用來回傳（不印出）dollar_value.q.d.n.p結果，並且確保我回傳的值為const，最後在class private寫的print函式來印出所有回傳值。 		    
2.Makefile: 編譯oophw3.cpp檔的指令。
3.oophw3.out: C++的執行檔。
4.Readme:   作業及程式細節資訊。

Bouns:
1.輸入不合法(小數點後超過二位數或少於二位數)就會直接印出輸入錯誤，例如：2.345、3.3。另外小數點前有超過一位數被歸為合法數，例如：23.34。
2.可以輸入且執行多個測資，例如：./a.out 2.33 2.47 4.10 4.3 34.45。


Reference:
1.(C++double轉int):https://blog.csdn.net/lin200753/article/details/27952897
2.(C++ class用法):https://www.runoob.com/cplusplus/cpp-classes-objects.html
3.(C++ inline用法):https://www.runoob.com/w3cnote/cpp-inline-usage.html
4.(C++ member function):https://docs.microsoft.com/zh-tw/cpp/cpp/overview-of-member-functions?view=msvc-170


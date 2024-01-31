README

姓名: 孫渝鈞
學號: 409510049
e-mail: yujun91725@gmail.com

完成項目:
1.Grid.cpp: C++寫一程式要印出迷宮，及走出過程圖，裡面有包含老師要求的9個member function及3個constructor，除此之外我還另外寫了兩個member function，分別用來隨機取值，用來隨機取出口，及傳入Grid::g(2,5)時還需要另外隨機取mover的位置。
2.Grid.h: Grid.cpp的標頭檔，用來連接main.cpp及Grid.cpp檔。  
3.Makefile: 將main.cpp及Grid.cpp編譯成oophw4.out檔的指令。
4.oophw4.out: C++的執行檔。
5.Readme:   作業及程式細節資訊。
6 main.cpp: 測試迷宮走向檔案


Bouns:
1.建立有圍牆和出口的迷宮，我的做法是直接讓迷宮最外層建成圍牆。
2.Grow時不會隨機取到角落為出口，因為我Grow的做法是把原本的迷宮邊邊牆的部分還原成'.'，這邊還要記得先將原本出口的位置記下來，接著再將迷宮往外拉大，外面建牆，中間原本在迷宮內的block,item,空白等都要保留，再把原本迷宮的出口直接往平移拉到最外面，原本在建迷宮的出口位置就不會有在角落的問題，所以直接平移到外面去也不會出現出口在角落。
3.在要放入block及item的參數裡多判斷是否為可以放的位置，像是'.'或空格就可以放，item不能放在牆上之類的，block不可以放在出口位置等等。
4.PutDown(int r, int c)裡多加判斷item要放的位置是否為mover所在位置，是的話就執行PutDown()function。



Reference:
1.c++(隨機取值)：https://blog.gtwang.org/programming/c-cpp-rand-random-number-generation-tutorial-examples/


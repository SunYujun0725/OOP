//
//  main.cpp
//  Avg.cpp
//
//  Created by 孫渝鈞 on 2022/3/2.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

int main() {
    
    double number=0;  //有幾筆資料
    double sum=0;     //總和
    long length=0;
    double avg=0;     //平均
    int checkfloat=0; //確認是否有小數點 0:沒有

    string grade;  //成績（string）
    while( 1 ){    //重複輸入計算多次平均
        checkfloat=0;
        std::cout << "Please input your score :" << endl;
        std::cin >> grade;  //輸入字串
        if(grade.compare("end")==0){  //輸入end代表結束程式
            break;
        }
        number++;
        length=grade.length();    //計算字串長度
        for(long j=0;j<length;j++){   
            if(grade[j]=='.'){    //有小數點＝>錯誤輸入
                std::cout << "illegal input, ending the program..." << endl;
                sum=0;            //歸零
                number=0;
                checkfloat=1;     //是小數點
            }
        }
        if(checkfloat==0){  //沒有小數點

            if(atoi(grade.c_str())>=0&&atoi(grade.c_str())<=100){ //判斷是否在0~100間
                sum+=atoi(grade.c_str()); //sum加總
            }  

            else if(grade.compare("-1")==0){   //字串為-1＝>印出平均
                avg=sum/(number-1);
                std::cout << "Your average score is :";
                std::cout << avg << endl;
                sum=0;     //歸零
                number=0;
            }

            else {  //其他為錯誤輸入
                std::cout << "illegal input, ending the program..." << endl;  
                sum=0;     //歸零
                number=0;
            }
        }
        
    }
    return 0;
}

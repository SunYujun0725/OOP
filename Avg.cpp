//
//  main.cpp
//  Avg.cpp
//
//  Created by 孫渝鈞 on 2022/3/2.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

int main() {
    
    double number=0;
    double sum=0;
    long length=0;
    double avg=0;
    int checkfloat=0; //確認是否有小數點 //0:沒有

    string grade;
    while( 1 ){    //重複輸入計算多次平均
        checkfloat=0;
        std::cout << "Please input your score :" << endl;
        std::cin >> grade;
        if(grade.compare("end")==0){  //輸入end代表結束程式
            break;
        }
        number++;
        length=grade.length();
        for(long j=0;j<length;j++){
            if(grade[j]=='.'){
                std::cout << "illegal input, ending the program..." << endl;
                sum=0;
                number=0;
                checkfloat=1;  //是小數點
            }
        }
        if(checkfloat==0){
            if(atoi(grade.c_str())>=0&&atoi(grade.c_str())<=100){
                sum+=atoi(grade.c_str());
            }
            else if(grade.compare("-1")==0){
                avg=sum/(number-1);
                std::cout << "Your average score is :";
                std::cout << avg << endl;
            }
            else if(grade.compare("-1")!=0&&atoi(grade.c_str())==-1){
                sum=0;
                number=0;
            }
            else {
                std::cout << "illegal input, ending the program..." << endl;
                sum=0;
                number=0;
            }
        }
        
    }
    return 0;
}

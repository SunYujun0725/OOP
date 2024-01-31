#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <ctime>
#include <random>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;
using namespace std;

int getDigit(int number){  //如果小於10則回傳原本數，否則回傳各個位數相加
    if(number<10){
        return number;
    }
    else{
        return (number/10)+(number%10);
    }
}
int sumofDoubleEvenPlace(const string& buffer){  //偶數項*2相加
    long length=0;  //信用卡字串長度
    long EvenSum=0; //偶數項*2相加
    length=buffer.length();
    if(length%2==0){  //14 or 16個數
        for(int i=0;i<length;i+=2){
            EvenSum+=getDigit(((int)buffer[i]-48)*2); //將字元轉成整數然後*2 去判斷是否大於10
        }
    }
    else{    //13 or 15個數
        for(int i=1;i<length;i+=2){
            EvenSum+=getDigit(((int)buffer[i]-48)*2); //將字元轉成整數然後*2 去判斷是否大於10
        }
    }
    return EvenSum;
}
int sumOfOddPlace(const string& buffer){   //奇數項相加
    long length=0;  //信用卡字串長度
    long OddSum=0;
    length=buffer.length();
    if(length%2==0){  //14 or 16個數
        for(int i=1;i<length;i+=2){
            OddSum+=(int)buffer[i]-48;  //將字元轉數字然後相加
        }
    }
    else{    //13 or 15個數
        for(int i=0;i<length;i+=2){
            OddSum+=(int)buffer[i]-48;
        }
    }
    return OddSum;
}
BOOL isvalid(const string& buffer){  //判斷是否正確輸入
    if((sumofDoubleEvenPlace(buffer)+sumOfOddPlace(buffer))%10==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
BOOL startsWith(const string& buffer,const string& substr){   //判斷是否為004 005 006 0037
    if(buffer.compare(substr)==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int cardtype(const string& buffer){  //判斷信用卡品牌
    if(buffer[0]=='4'){
        cout << "Visa card #"<< endl;
    }
    else if(buffer[0]=='5'){
        cout << "MasterCard card #"<<endl;
    }
    else if(buffer[0]=='6'){
        cout << "Discover card #"<<endl;
    }
    else if(buffer[0]=='3'&&buffer[1]=='7'){
        cout << "American Express card #"<<endl;
    }
    else{
        cout << "card and unknown brand #"<<endl;
    }
    return 0;
}
string random(long MIN,long MAX){   //隨機生成合法信用卡卡號

    long randnumber=rand() % (MAX - MIN + 1) + MIN;
    std::stringstream ss;
    ss << randnumber;
    string strrandnumber = ss.str();
    if(isvalid(strrandnumber)==1){   //隨機產生的數本身就符合
        return strrandnumber;
    }
    else{
        long Complement=10-((sumofDoubleEvenPlace(ss.str())+sumOfOddPlace(ss.str()))%10);  //與整除10相差幾個數

        int EvenDouble[]={0,2,4,6,8,1,3,5,7,9};  //存放*2後會是多少
        int EvenMaxAdd[]={9,7,5,3,1,8,6,4,2,0};  //存放最多可以補多少
        
        for(int i=2;i<16;i++){
            if(i%2==0){   //在偶數位的陣列
                if( ((int)strrandnumber[i]-48) < 9 ){
                    if(Complement < EvenMaxAdd[ ((int)strrandnumber[i]-48) ]){  //如果要加的數小於最大可加的值
                        for(int j=0;j<10;j++){
                            if(EvenDouble[j]==EvenDouble[((int)strrandnumber[i]-48)]+Complement){
                                strrandnumber[i]=j+'0';
                                Complement=0;
                                break;
                            }
                        }
                    }
                    else{       //直接加到最大可以加的數
                        Complement-=9-EvenDouble[((int)strrandnumber[i]-48)];
                        strrandnumber[i]='9';
                    }
                }
            }
            else{    //在奇數位的陣列
                if( ((int)strrandnumber[i]-48) < 9 ){
                    if( Complement < 9-((int)strrandnumber[i]-48) ){   //如果要加的數小於最大可加的值
                        strrandnumber[i]=((int)strrandnumber[i]-48+Complement)+'0';
                        Complement=0;
                    }
                    else{
                        Complement-=9-((int)strrandnumber[i]-48);
                        strrandnumber[i]='9';
                    }
                }
            }
            if(Complement==0){
                if(isvalid(strrandnumber)==0){  //檢查印出是否正確
                    printf("-------\n");
                }
                return strrandnumber; //產生出來結束函示
            }
        }
     }
     random(MIN,MAX);   //跑到最後都沒有結果就重新產生一個隨機數
     return 0;
}
int generated(const string& buffer){   //產生合法卡號

    if(startsWith(buffer,"004")==1){
        cout << "Generated a valid Visa card #: ";
        cout <<random(4000000000000000,4999999999999999)<<"; ";
    }
    else if(startsWith(buffer,"005")==1){
        cout << "Generated a valid MasterCard card #: ";
        cout <<random(5000000000000000,5999999999999999)<<"; ";
    }
    else if(startsWith(buffer,"006")==1){
        cout << "Generated a valid Discover card #: ";
        cout <<random(6000000000000000,6999999999999999)<<"; ";
    }
    else if(startsWith(buffer,"0037")==1){
        cout << "Generated a valid American Express card #: ";
        cout <<random(3700000000000000,3799999999999999)<<"; ";
    }
    else{
        cout << "不是合法輸入";
    }
    return 0;
}

int main(){
    long length=0;
    srand( (unsigned)time(NULL) );  //隨機種子
    std::vector<std::string> names;
    std::ifstream ifs("input.txt", std::ios::in);
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    } 
    else {
        std::string buffer;
        while (std::getline(ifs, buffer)) {
            length=buffer.length();
            if(length>=13&&length<=16){
                if(isvalid(buffer)==1){ //是合法輸入
                    cout << buffer <<": a valid ";
                    cardtype(buffer);
                }
                else{    //不是合法輸入
                    cout << buffer <<": an invalid ";
                    cardtype(buffer);
                }
            }
            else{
                float time_use=0;
                struct timeval start;
                struct timeval end;
                gettimeofday(&start,NULL);  //生成合法卡號開始時間
                generated(buffer);    //產生一組16位合法卡號
                gettimeofday(&end,NULL);   //生成合法卡號結束時間
                time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);  //微秒
                cout << "Timing: "<< time_use <<" microseconds"<<endl;
            }
            names.push_back(buffer);
        }
        ifs.close();
    }
    ifs.close();
    return 0;
}
number = 0.0      #有幾筆資料 
total = 0.0       #總和
avg = 0.0         #平均
checkfloat = 0    #檢查是否為小數點 ＃0:不是
string = '-1'
stringend = 'end' #結束程式

while(1):         #重複輸入計算多次平均
    checkfloat=0
    print('Please input your score :')
    grade=str(input())  #輸入一字串為成績
    number+=1
    lenght=len(grade)   #計算字串長度

    if(grade==stringend):    #輸入end代表結束程式
        break
        
    for i in range(0,lenght-1):
        if(grade[i]=='.'):   #有小數點＝>錯誤輸入
            print('illegal input, ending the program...')
            total=0.0        #歸零
            number=0.0
            checkfloat=1     #是小數點
            
    if(checkfloat==0):       #沒有小數點(正確輸入)
        
        if(int(grade)>=0 and int(grade)<=100):   #判斷是否在0~100間
            
            total+=int(grade)   #total加總
            
        elif(grade==string):    #字串為-1＝>印出平均
            avg=total/(number-1)
            print('Your average score is :',end = '')
            print(avg)
            total=0.0     #歸零
            number=0.0
            
        else:    #其他為錯誤輸入
            print('llegal input, ending the program...'); 
            total=0.0     #歸零
            number=0.0
      
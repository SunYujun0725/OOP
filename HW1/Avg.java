import java.util.Scanner;

public class Avg {
    public static void main(String[] args) {
        double number = 0.0;  //有幾筆資料
        double sum = 0.0;     //總和
        int length = 0;  
        double avg = 0.0;     //平均
        int checkfloat = 0;   // 確認是否有小數點 0:沒有
        String grade;         //成績（string）
        Scanner sc = new Scanner(System.in);  

            while (true) {    //重複輸入計算多次平均
                checkfloat = 0;
                System.out.println("Please input your score :");
                grade = sc.next();        //輸入一string
                length = grade.length();  // 求出字串長度
                number++;
                if (grade.compareTo("end") == 0) {  //如果輸入end代表結束程式（跳出迴圈）

                    break;
                }
                for (int i = 0; i < length; i++) { 
                    if (grade.charAt(i) == '.') {  //有小數點＝>錯誤輸入
                        System.out.printf("illegal input, ending the program...\n");
                        sum = 0.0;       //歸零
                        number = 0.0;
                        checkfloat = 1;  //是小數點
                    }
                }
                if (checkfloat == 0) {  //沒有小數點（符合）輸入

                    if (Integer.parseInt(grade) >= 0 && Integer.parseInt(grade) <= 100) { //判斷是否在0~100間
                        sum += Integer.parseInt(grade);  //sum加總
                    } 

                    else if (grade.compareTo("-1") == 0) {  //字串為-1＝>印出平均
                        avg = sum / (number - 1);
                        System.out.printf("Your average score is :");
                        System.out.println(avg);
                        sum = 0.0;    //歸零
                        number = 0.0;
                    } 

                    else {   //其他為錯誤輸入
                        System.out.printf("illegal input, ending the program...\n");  
                        sum = 0.0;    //歸零
                        number = 0.0;
                    }
                }
            }
        sc.close();
    }
}

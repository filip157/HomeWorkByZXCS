#include <stdio.h>
#include <stdlib.h>
int moth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; //建立一個全域陣列，表示所有月份之天數

int d2d(int m1,int d1,int m2,int d2,int y){     //計算該年天數
    int days=0; //此年天數總和
    int leapyear; //閏年判斷
    if(y%4 == 0){
        if(y%100 == 0){
            if(y%400 == 0){
                leapyear = 1;
            }
            else{
                leapyear = 0;
            }
        }
        else{
            leapyear = 1;
        }
    }
    else{
        leapyear = 0;
    }
    
    if(leapyear==1){ //辨識閏年函數
        moth[1]=29; //如果是閏年就把2月(mday陣列第1項)，改成29
    }
    else{
        moth[1]=28; //不然就是28
    }

    int res=0;
    for(int i=m1-1;i<m2;i++){       //加總該月天數
        res += moth[i];
    }


    days += res;        //加總該年總天數
    days -= d1-1;       //
    days -= (moth[m2-1]-d2);
    return days;

}

int main(void){
    int y1,m1,d1,y2,m2,d2,allDays=0; //allDays：所有加起來的天數
    printf("輸入日期(格式 Y/M/D-Y/M/D):  ");
    scanf("%d/%d/%d-%d/%d/%d",&y1,&m1,&d1,&y2,&m2,&d2); //輸入兩個日期

    if(y2-y1>1){ //如果中間有完整年

        allDays+=d2d(m1,d1,12,31,y1); //呼叫d2d算出第一年，參數：起始日期到第一年的最後一天
        allDays+=d2d(1,1,m2,d2,y2); //呼叫d2d算出最後一年，參數：最後一年的第一天到結束日期
        for(int i=y1+1;i<y2;i++){
            allDays+=d2d(1,1,12,31,i); //中間完整的直接呼叫1/1到12/31累加
        }
    }
    else if(y2-y1==1){ //如果只有兩年
        allDays+=d2d(m1,d1,12,31,y1);
        allDays+=d2d(1,1,m2,d2,y2); //相較上面就只是少了累加完整年wwwww
    }
    else if(y2-y1==0){ //只有一年
        allDays+=d2d(m1,d1,m2,d2,y1); //直接呼叫d2d，然後就什麼都不用管了XD
    }



    printf("%d\n",allDays); //最後輸出
    return 0;
}//強制合體萬歲wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
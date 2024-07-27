//小a很喜欢数学 ，， 巴拉巴拉，你能帮小a解决这个问题吗 --> 把题目中的过程抽象成运算然后编程解决
//津津的存储计划 -->题目的过程合理并且可以被代码直接模拟 --> 模拟题


//for 知道次数用for循环
//while 做。。。直到。。。

#include <stdio.h>

int main(){
    int month[12];
    for(int i = 0 ; i < 12 ; i++) scanf("%d", &month[i]);

    int pocket = 0 , mom = 0;
    int flag = 0 , loser = 0;

    for(int i = 0 ; i < 12 ;i++){
        pocket += 300;
        
        if(pocket < month[i]){
            flag = 1;
            loser = -1*(i+1);
            break;
        } 

        pocket -= month[i];

        while(pocket >= 100){
            pocket -= 100;
            mom += 100;
        }
    }


    if(flag) printf("%d",loser);
    else printf("%d", pocket + mom + mom/5 );

    return 0;
}






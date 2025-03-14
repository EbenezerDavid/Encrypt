/*
This is a simple password encrypt applacation!

        GNU GENERAL PUBLIC LICENSE
          Version 3, 29 June 2007

        2025/03/14     EbenezerDavid
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addpass.h"
#include "puzzle.h"




int main(){
    int i_cnum;
    char custom_input[500] = {0};

    printf("=================================Menu=============================================\n");
    printf("0. 创建账户（文件名）. \n");
    //printf("1. 登陆. \n");
    //printf("2. 查看现有账户和密码. \n");
    printf("3. 退出. \n");
    printf("==================================================================================\n");
    printf("[0-3] 选择：");

    if (scanf("%d", &i_cnum) != 0) {
        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
        char endout[500] = {0};
        cr_custom(custom_input, sizeof(custom_input), i_cnum, endout);
        //printf("%s\n", endout);
    } else {
        printf("Error \n");
    }

    return EXIT_SUCCESS;
}
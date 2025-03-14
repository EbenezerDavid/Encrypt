/*这个是创建一个文件，里面写入密码

  2025/03/14 EbenezerDavid
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addpass.h"
#include "puzzle.h"


int cr_custom(char choice[], int size, int want, char re_custom_file[]) {

	char* name[] = {"用户名(文件名)（建议英文）", "密码"};
	char user_input[500] = {0};
	if (want == 0) {
		int i_crea = 0;
			
			printf("请输入 %s:", name[i_crea]);
        	if(fgets(choice, size, stdin) != NULL) {
        		size_t len = strlen(choice);
        		if (len == size - 1 && choice[len - 1] != '\n') {
        			int ch;
        			while ((ch = getchar()) != '\n' && ch != EOF);
        		}
        		if (len > 0 && choice[len - 1] == '\n') {
        			choice[len - 1] = '\0';
        		}
        		//用3个变量来给账户的储存文件取名字
				char filename[100] = {0};
				const char *prefix = ".";
				const char *suffix = ".txt";
				const char *fname = choice;
				snprintf(filename, sizeof(filename), "%s%s%s", prefix, fname, suffix);
				strncpy(re_custom_file, filename, size);
    			re_custom_file[size - 1] = '\0';

				one_go:
					char digital[999] = {0};
					strncpy(digital, filename, sizeof(digital));
					digital[sizeof(digital) - 1] = '\0';
					if (i_crea == 0) {
						FILE *create = fopen(filename, "w+");
						/*if (create == NULL) {
							printf("请使用root用户或者sudo！ \n");

							return 1;
						}*/
						if (create != NULL) {
        					//fprintf(create, "%s\n", choice);
        					fclose(create);
        					printf("[OK]\n ");
        					if (i_crea == 0) {
        					i_crea ++;
        					goto one_go;

        					return 0;
							}	
						}else {
							printf("Error. \n");

							return 1;
						}
					}

					if (i_crea == 1) {
						printf("请输入 %s:", name[i_crea]);
						if (fgets(choice, size, stdin) != NULL) {
							size_t len = strlen(choice);
							if (len == size - 1 && choice[len - 1] != '\n') {
								int ch;
								while((ch = getchar()) != '\n' && ch != EOF);
							}
							if (len > 0 && choice[len - 1] == '\n') {
								choice[len - 1] = '\0';
							}
						}
						FILE *writef = fopen(digital, "w+");
						if (writef == NULL) {
							printf("请使用root用户或者sudo！ \n");

							return 1;
						} else {
							//int keys = 37;
							int keys;
							printf("输入数字密钥：");
							scanf("%d", &keys);
							char outencrypt[999] = {0};
							lockpass(choice, outencrypt, keys);
							fprintf(writef, "%s\n", outencrypt);
							fclose(writef);

							return 0;
						}

					return 0;
				}	
		
			}
	}
	return 0;
}
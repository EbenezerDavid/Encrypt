/*

这是定义加密和解密的文件

*/



#include <string.h>
#include "puzzle.h"


//加密函数，用法pass是密码，output是加密后结果，key是密钥
void lockpass(const char *pass, char *output, int key) {

	size_t length = strlen(pass);
	for (size_t i = 0; i <= length; i++) {
		int averror = (int)pass[i] * key;
		averror = averror % 256;
		output[i] = (char)averror;
	}

	size_t vslen = strlen(output);
	output[vslen] = '\0';
}

void unpass(const char *pass, char *output, int key) {

	size_t length = strlen(pass);
	for (size_t i = 0; i <= length; i++) {
		int averror = (int)pass[i] * key;
		averror = averror % 256;
		output[i] = (char)averror;
	}

	size_t vslen = strlen(output);
	output[vslen] = '\0';
}
#ifndef PUZZLE_H
#define PUZZLE_H

//加密
void lockpass(const char *pass, char *output, int key);

//解密
void unpass(const char *pass, char *output, int key);

#endif
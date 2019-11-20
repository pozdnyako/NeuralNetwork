#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <cstdio>

extern int n_tabs;

#define LOG(mod, ...) \
    for(int LOG_i = 0; LOG_i < n_tabs; LOG_i ++) {printf("\t");}\
    printf(mod "\n", ##__VA_ARGS__);

#define LOG_V(mod, vec) \
    for(int LOG_i = 0; LOG_i < n_tabs; LOG_i ++) {printf("\t");}\
    printf("%d: ", vec.size());\
    for(int LOG_i = 0; LOG_i < (int)vec.size(); LOG_i ++) { \
        printf(mod " ", vec[LOG_i]);\
    }\
    printf("\n");

#define ERROR_LOG(mod, ...) \
    for(int LOG_i = 0; LOG_i < n_tabs; LOG_i ++) {printf("\t");}\
    printf("[ERROR]\t" mod "\n", ##__VA_ARGS__);

#define pTAB n_tabs ++;
#define mTAB n_tabs --;

#endif // DEBUG_H_INCLUDED

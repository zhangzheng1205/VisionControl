#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//酒精 二级板 温度窗
// #ifndef  JiujingAveWindowSize
// #define JiujingAveWindowSize 60
// #endif
// #ifndef ErjibanAveWindowSize
// #define ErjibanAveWindowSize 60
// #endif

struct node{
    float value;
    struct node* next;
};


class PROCESS_FILE{
public:
    int jiujing_ave_flag = 0;
    int jiujing_ave_set = 0;

    int erjiban_ave_flag = 0;
    int erjiban_ave_set = 0;

    /**
     * @brief read_file 文件读取
     * @param file_name 文件名
     * @param data 用来存放文件内容
     * @return 传入的字符串指针
     */
    char* read_file(char* file_name, char* data);

    char* write_file(char* file_name, char* data);

    char* array_encode(double (*array)[8], char* data, int len);

    int array_decode(double (*array)[8], char* data, int len);

    int get_parameter_from_file(char* file_name, double (*array)[8], int len);

    int store_new_parameter(char* file_name, double (*array)[8]);

    int store_new_rev_viscosity(char* file_name, double (*array)[8]);

    char* make_file(char* file_name);

};

#endif // PROCESS_FILE_H

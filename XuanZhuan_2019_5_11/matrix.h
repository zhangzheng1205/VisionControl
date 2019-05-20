#ifndef MATRIX_H
#define MATRIX_H
#include "stdio.h"
#include "stdlib.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef DataType
#define DataType double
#endif

#define ColNum 3

#define matrix_colnum 9
#define matrix_row 10


/**
* @brief 定义矩阵结构体
* @pointer 矩阵第一个元素的地址
* @row 矩阵的行数
* @col 矩阵的列数
*/
typedef struct matrix
{
    DataType** pointer;
    int row;
    int col;
}matrix;


    /**
    * @brief change_arraytomatrix 将二维数组数据存入矩阵
    * @param col 列数
    * @param row 行数
    * @return
    */
//    matrix change_arraytomatrix(DataType(*array)[ColNum], int col, int row);

    /**
    * @brief matrix_free 释放矩阵占用的内存
    * @param obj
    * @return
    */
    int matrix_free(matrix obj);

    /**
    * @brief matrix_sub 矩阵相减 a - b
    * @param a 被减数
    * @param b 减数
    * @return 相减的结果在新的内存空间
    */
    matrix matrix_sub(matrix a, matrix b);

    /**
    * @brief get_onecol_inverse 求单列矩阵的广义逆
    * @param obj
    * @return 结果在新的内存空间
    */
    matrix get_onecol_inverse(matrix obj);

    /**
    * @brief matrix_is_zero 判断矩阵是否全0
    * @param obj
    * @return 1->是全0 0->不是
    */
    int matrix_is_zero(matrix obj);

    /**
    * @brief matrix_mul_constant 常数与矩阵相乘
    * @param obj 矩阵
    * @param num 常数
    * @return 返回矩阵内存位置与输入矩阵相同
    */
    matrix matrix_mul_constant(DataType num, matrix obj);

    /**
    * @brief matrix_mul 矩阵相乘 a * b
    * @param a
    * @param b
    * @return 相乘的结果
    */
    matrix matrix_mul(matrix a, matrix b);

    /**
    * @brief Greville Greville求广义逆
    * @param old
    * @return
    */
    matrix Greville(matrix old);

    /**
    * @brief matrix_display 格式化输出矩阵
    * @param obj
    * @return 0
    */
    int matrix_display(matrix obj);

    /**
     * @brief get_parameter_b 计算b参数[b1, b2, b3]
     * @param speed 转速数组
     * @param viscosity 黏度数组
     * @param row 数组长度
     * @param type 计算类型
     * @return
     */
    DataType* get_parameter_B(DataType* speed, DataType* viscosity, int len, int type);


    DataType** get_parameter_matrix(DataType (*speed)[matrix_row], DataType (*viscosity)[matrix_row]);



#ifdef __cplusplus
}

#endif
#endif

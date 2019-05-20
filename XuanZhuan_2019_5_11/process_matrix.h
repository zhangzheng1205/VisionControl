#ifndef PROCESS_MATRIX_H
#define PROCESS_MATRIX_H
#endif // C_CODE_H

class PROCESS_MATRIX{

public:
    /**
     * @brief get_parameter 计算b参数数组
     * @param N N数组
     * @param n n数组
     * @param len 数组长度
     * @param type 计算类型
     * @return
     */
    double* get_parameter(double* N, double* n, int len, int type);
    double** get_matrix(double (*speed)[9], double (*viscosity)[9]);
    int result_free(double** a);
};

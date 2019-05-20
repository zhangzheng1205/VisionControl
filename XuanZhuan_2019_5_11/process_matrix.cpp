#include "matrix.h"
#include "process_matrix.h"

double* PROCESS_MATRIX::get_parameter(double *N, double *n, int len, int type)
{
    return get_parameter_B(N, n, len, type);
}

double** PROCESS_MATRIX::get_matrix(double (*speed)[9], double (*viscosity)[9])//改成了双参数
{
    int i, j, num;

    double speed_transpose[9][10];
    double viscosity_transpose[9][10];

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 10; j++)
        {
            speed_transpose[i][j] = speed[j][i];
            viscosity_transpose[i][j] = viscosity[j][i];
        }
    }

    for(i = 0; i < 9; i++)
    {
        num = 0;

        for(j = 0; j < 10; j++)
        {
            if(speed_transpose[i][j] * viscosity_transpose[i][j] != 0.0)
                num++;

            if(num > 6)
                speed_transpose[i][j] = 0.0;
        }

        if(num < 3)
        {
            for(j = 0; j < 10; j++)
               speed_transpose[i][j] = 0.0;
        }
    }

    return get_parameter_matrix(speed_transpose, viscosity_transpose);
}

int PROCESS_MATRIX::result_free(DataType** a)
{
    free(a[0]);
    free(a[1]);
    free(a[2]);
    return 0;
}

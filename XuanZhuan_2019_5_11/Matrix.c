#include "matrix.h"
//DataType 为矩阵元素变量类型
//#define DataType double
//#define ColNum 3

// 以obj[col][row]的形式存储 方便之后计算

//**
//* @brief 定义矩阵结构体
//* @pointer 矩阵第一个元素的地址
//* @row 矩阵的行数
//* @col 矩阵的列数
//*/

int matrix_display(matrix obj)
{
    int row, col;
    printf("matrix info:\n");

    for (row = 0; row < obj.row; row++)
    {
        for (col = 0; col < obj.col; col++)
        {
            printf("\t%f", obj.pointer[col][row]);
        }

        printf("\n");
    }

    return 0;
}

int matrix_free(matrix obj)
{
    int i;

    for (i = 0; i < obj.col; i++)
    {
        free(obj.pointer[i]);
    }

    free(obj.pointer);

    return 1;
}

matrix matrix_transpose(matrix old)
{
    int i, j;
    matrix result;
    result.row = old.col;
    result.col = old.row;

    result.pointer = (DataType**)malloc(result.col * sizeof(DataType*));

    for (i = 0; i < result.col; i++)
    {
        result.pointer[i] = (DataType*)malloc(result.row * sizeof(DataType));

        for (j = 0; j < result.row; j++)
        {
            result.pointer[i][j] = old.pointer[j][i];
        }
    }

    return result;
}

matrix matrix_sub(matrix a, matrix b)
{
    if (a.col != b.col && a.row != b.row)
        exit(1);

    int i, j;
    matrix result;
    result.col = a.col;
    result.row = a.row;

    result.pointer = (DataType**)malloc(result.col * sizeof(DataType*));

    for (i = 0; i < result.col; i++)
    {
        result.pointer[i] = (DataType*)malloc(result.row * sizeof(DataType));

        for (j = 0; j < result.row; j++)
        {
            result.pointer[i][j] = a.pointer[i][j] - b.pointer[i][j];
        }
    }

    return result;
}

matrix matrix_mul(matrix a, matrix b)
{
    if (a.col != b.row)
        exit(1);

    int i, j, k;
    double t;
    matrix result;
    result.col = b.col;
    result.row = a.row;

    result.pointer = (DataType**)malloc(result.col * sizeof(DataType*));

    for (i = 0; i < result.col; i++)
    {
        result.pointer[i] = (DataType*)malloc(result.row * sizeof(DataType));

        for (j = 0; j < result.row; j++)
        {
            t = 0.0;

            for (k = 0; k < a.col; k++)
            {
                t += a.pointer[k][j] * b.pointer[i][k];
            }

            result.pointer[i][j] = t;
        }
    }

    return result;
}

matrix matrix_mul_constant(DataType num, matrix obj)
{
    int i, j;

    for (i = 0; i < obj.col; i++)
    {
        for (j = 0; j < obj.row; j++)
        {
            obj.pointer[i][j] *= num;
        }
    }

    return obj;
}

matrix get_onecol_inverse(matrix obj)
{
    if(obj.col != 1)
        exit(1);

    matrix result, temp, temp2;
    DataType i;

    result.col = obj.row;
    result.row = obj.col;

    temp = matrix_transpose(obj);

    temp2 = matrix_mul(temp, obj);

    i = temp2.pointer[0][0];

    if(i != 0)
        result = matrix_mul_constant(1.0 / i, temp);
    else
        result = matrix_mul_constant(0.0, temp);

    matrix_free(temp2);
    return result;
}

int matrix_is_zero(matrix obj)
{
    int i, j;

    for (i = 0; i < obj.col; i++)
    {
        for (j = 0; j < obj.row; j++)
        {
            if (obj.pointer[i][j] != 0.0)
                return 0;
        }
    }
    return 1;
}

matrix Greville(matrix old)
{
    if(matrix_is_zero(old))
        return matrix_transpose(old);


    if (old.col > old.row)
    {
        exit(1);
    }

    //son->A(k-1)
    matrix d_k, d_kH, a_k, c_k, b_kH, son, son_inverse, result;
    matrix temp, temp2;
    DataType i;
    int j, k;

    if (old.col != 1)
    {
        son = old;
        son.col--;
        son_inverse = Greville(son);

        a_k.col = 1;
        a_k.row = old.row;
        a_k.pointer = &old.pointer[old.col - 1];
        d_k = matrix_mul(son_inverse, a_k);
        temp = matrix_mul(son, d_k);
        c_k = matrix_sub(a_k, temp);
        matrix_free(temp);

        if (matrix_is_zero(c_k))
        {
            d_kH = matrix_transpose(d_k);
            temp = matrix_mul(d_kH, d_k);
            i = 1.0 + temp.pointer[0][0];
            matrix_free(temp);
            temp = matrix_mul(d_kH, son_inverse);
            b_kH = matrix_mul_constant(1.0 / i, temp);
            matrix_free(temp);
            matrix_free(d_kH);
        }
        else {
            b_kH = Greville(c_k);
        }

        result.col = b_kH.col;
        result.row = son_inverse.row + b_kH.row;
        result.pointer = (DataType**)malloc(result.col * sizeof(DataType*));

        if (son_inverse.row == 0 || b_kH.row == 0)
            exit(1);

        for (j = 0; j < result.col; j++)
        {
            result.pointer[j] = (DataType*)malloc(result.row * sizeof(DataType));

            for (k = 0; k < son_inverse.row; k++)
            {
                temp = matrix_mul(d_k, b_kH);
                temp2 = matrix_sub(son_inverse, temp);
                result.pointer[j][k] = temp2.pointer[j][k];
                matrix_free(temp);
                matrix_free(temp2);
            }

            for (k = 0; k < b_kH.row; k++)
            {
                result.pointer[j][k + son_inverse.row] = b_kH.pointer[j][k];
            }
        }

        //matrix d_k, d_kH, a_k, c_k, b_kH, son, son_inverse, result;
        matrix_free(son_inverse);
        matrix_free(d_k);
        matrix_free(c_k);
        matrix_free(b_kH);

        return result;

    }
    else {
        return get_onecol_inverse(old);
    }

}

DataType* get_parameter_B(DataType* N, DataType* n, int len, int type)
{
    int i, j;
    matrix speed, viscosity, temp, result;

    viscosity.col = 1;
    viscosity.row = len;
    viscosity.pointer = (DataType**)malloc(sizeof(DataType*));
    viscosity.pointer[0] = (DataType*)malloc(len * sizeof(DataType));
    for(i = 0; i < len; i++)
    {
        viscosity.pointer[0][i] = n[i];
    }

    speed.col = 3;
    speed.row = len;
    speed.pointer = (DataType**)malloc(ColNum * sizeof(DataType*));

    for(i = 0; i < ColNum; i++)
    {
        speed.pointer[i] = (DataType*)malloc(len * sizeof(DataType));

        for(j = 0; j < len; j++)
        {
            switch(i)
            {
                case 0:
                    speed.pointer[i][j] = (N[j] == 0.0) ? 0.0 : 1.0 / N[j];
                break;
                case 1:
                    speed.pointer[i][j] = (N[j] == 0.0) ? 0.0 : 1.0;
                break;
                case 2:
                    speed.pointer[i][j] = (N[j] == 0.0) ? 0.0 : N[j];
                break;
            default:
                exit(1);
            }
        }
    }
    if(type == 0)
    {
        temp = Greville(speed);
        result = matrix_mul(temp, viscosity);

        matrix_free(temp);
        matrix_free(viscosity);
        matrix_free(speed);

    }else if(type == 1)
    {
        result = matrix_mul(speed, viscosity);

        matrix_free(viscosity);
        matrix_free(speed);
    }
    DataType* a = result.pointer[0];
    free(result.pointer);
    return a;
}

DataType** get_parameter_matrix(double (*speed)[matrix_row], double (*viscosity)[matrix_row])
{
    int i, j;
    DataType* temp;
    DataType** result = (DataType**)malloc(3 * sizeof(DataType*));

    for(i = 0; i < 3; i++)
    {
        result[i] = (DataType*)malloc(matrix_colnum * sizeof(DataType));
    }

    for(i = 0; i < matrix_colnum; i++)
    {
        temp = get_parameter_B(speed[i], viscosity[i], matrix_row, 0);

        for(j = 0; j < 3; j++)
        {
            result[j][i] = temp[j];
        }

        free(temp);
    }

    return result;
}



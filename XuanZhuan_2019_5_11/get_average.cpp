#include "get_average.h"

using namespace std;

// 窗口大小初始化
struct ave_struct * GET_AVERAGE::init_list(int length)
{
    struct ave_struct *i = new struct ave_struct;
    i->flag = 0;
    i->set = 0;
    i->len = length;
    i->array = new float[length];
    return i;
}

// 获取窗口的平均值 当窗口没有元素时返回 FLT_MAX
float GET_AVERAGE::get_ave(struct ave_struct *node)
{
    if (node->set == 0 && node->flag == 0)
        return FLT_MAX;

    if (node->flag == 0)
    {
        float sum = 0;
        for (int i = 0; i < node->set; ++i)
            sum += node->array[i];
        return sum / node->set;
    }else{
        float sum = 0;
        for (int i = 0; i < node->len; ++i)
            sum += node->array[i];
        return sum / node->len;
    }
}

// 向窗口中加入元素 并返回平均值
float GET_AVERAGE::insert_element(float element, struct ave_struct *node)
{
    node->array[node->set++] = element;
    if (node->set == node->len)
    {
        node->set = 0;
        node->flag = 1;
    }

    return get_ave(node);
}

// 返回填满的窗口平均值 如果未填满 返回FLT_MAX
float GET_AVERAGE::get_full_ave(struct ave_struct *node)
{
    if (node->flag == 0)
        return FLT_MAX;

    float sum = 0;
    for (int i = 0; i < node->len; ++i)
        sum += node->array[i];
    return sum / node->len;
}

// 当窗口被填满，且窗口内各个值与reference差值绝对值大于range的个数小于等于number时 返回1 其他时候返回0
int GET_AVERAGE::check_full_array(struct ave_struct *node, float reference, float range, int number)
{
    if (node->flag == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < node->len; i++)
    {
        if (fabs(node->array[i] - reference) > range)
            sum++;
    }
    if (sum > number)
        return 0;
    else
        return 1;
}

// 释放内存空间
void GET_AVERAGE::free_struct(struct ave_struct *node)
{
    delete [] node->array;
    delete node;
}

/*==================polyfit(n,x,y,poly_n,a)===================*/
/*=======拟合y=a0+a1*x+a2*x^2+……+apoly_n*x^poly_n========*/
/*=====n是数据个数 xy是数据值 poly_n是多项式的项数======*/
/*===返回a0,a1,a2,……a[poly_n]，系数比项数多一（常数项）=====*/
void GET_AVERAGE::poly_fit(int n,float *x,float *y,int poly_n,float *p)
{
    int i,j;
    float *tempx,*tempy,*sumxx,*sumxy,*ata;

    tempx = (float *)calloc(n , sizeof(float));
    sumxx = (float *)calloc((poly_n*2+1) , sizeof(float));
    tempy = (float *)calloc(n , sizeof(float));
    sumxy = (float *)calloc((poly_n+1) , sizeof(float));
    ata = (float *)calloc( (poly_n+1)*(poly_n+1) , sizeof(float) );
    for (i=0;i<n;i++)
    {
        tempx[i]=1;
        tempy[i]=y[i];
    }
    for (i=0;i<2*poly_n+1;i++)
    {
        for (sumxx[i]=0,j=0;j<n;j++)
        {
            sumxx[i]+=tempx[j];
            tempx[j]*=x[j];
        }
    }

    for (i=0;i<poly_n+1;i++)
    {
        for (sumxy[i]=0,j=0;j<n;j++)
        {
            sumxy[i]+=tempy[j];
            tempy[j]*=x[j];
        }
    }

    for (i=0;i<poly_n+1;i++)
    {
        for (j=0;j<poly_n+1;j++)
        {
            ata[i*(poly_n+1)+j]=sumxx[i+j];
        }
    }
    gauss_solve(poly_n+1,ata,p,sumxy);

    free(tempx);
    free(sumxx);
    free(tempy);
    free(sumxy);
    free(ata);
}

/*============================================================*/
////    高斯消元法计算得到   n 次多项式的系数
////    n: 系数的个数
////    ata: 线性矩阵
////    sumxy: 线性方程组的Y值
////    p: 返回拟合的结果
/*============================================================*/
void GET_AVERAGE::gauss_solve(int n,float A[],float x[],float b[])
{
    int i,j,k,r;
    float max;
    for (k=0;k<n-1;k++)
    {
        max=fabs(A[k*n+k]);                 // find maxmum
        r=k;
        for (i=k+1;i<n-1;i++)
        {
            if (max<fabs(A[i*n+i]))
            {
                max=fabs(A[i*n+i]);
                r=i;
            }
        }
        if (r!=k)
        {
            for (i=0;i<n;i++)        //change array:A[k]&A[r]
            {
                max=A[k*n+i];
                A[k*n+i]=A[r*n+i];
                A[r*n+i]=max;
            }

            max=b[k];                    //change array:b[k]&b[r]
            b[k]=b[r];
            b[r]=max;
        }

        for (i=k+1;i<n;i++)
        {
            for (j=k+1;j<n;j++)
                A[i*n+j]-=A[i*n+k]*A[k*n+j]/A[k*n+k];
            b[i]-=A[i*n+k]*b[k]/A[k*n+k];
        }
    }

    for (i=n-1;i>=0;x[i]/=A[i*n+i],i--)
    {
        for (j=i+1,x[i]=b[i];j<n;j++)
            x[i]-=A[i*n+j]*x[j];
    }

}

/*n是数据个数 x、y是数据值 p结果 斜率、截距*/
void GET_AVERAGE::least_squares(int n, float *x, float *y, float *p)
{
    float A=0;
    float B=0;
    float C=0;
    float D=0;
    for (int i = 0; i < n; i++)
    {
        A += x[i] * x[i];
        B += x[i];
        C += x[i] * y[i];
        D += y[i];
    }
    // 截距P1 斜率P0
    if(fabs(n*A-B*B) >1e-6){
        p[1] = (A*D-B*C)/(n*A-B*B);
        p[0] = (n*C-B*D)/(n*A-B*B);
    }
    else{
        p[1] = 0;
        p[0] = 1;
    }
}

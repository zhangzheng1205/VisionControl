#include <process_file.h>

using namespace std;                                               //命名空间，防止类名定义冲突

char* PROCESS_FILE::read_file(char* file_name, char* data)         //向data中输入600个字符
{
    ifstream infile;
    infile.open(file_name);

    if(!infile.is_open())
    {
        cout<<"Error Open File"<<endl;
        cout<<file_name<<endl;
        exit(1);
    }

    infile.getline(data, 1000);

    infile.close();
    return data;
}

char* PROCESS_FILE::write_file(char *file_name, char *data)
{
    ofstream outfile;
    outfile.open(file_name);

    if(!outfile.is_open())
    {
        cout<<"Error Open File"<<endl;
        cout<<file_name<<endl;
        exit(1);
    }

    outfile<<data;
    return data;
}

char* PROCESS_FILE::array_encode(double (*array)[8], char* data, int len)
{
    int i, j;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < 9; j++)
        {
            sprintf(data, "%s^%.4f", data, array[i][j]);
        }
    }

    sprintf(data, "%s^", data);
    return data;
}

int PROCESS_FILE::array_decode(double (*array)[8], char *data, int len)
{
    int i, j, k, m = 0;
    double value;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(data[m] == '^')
                m++;

            char part[30] = "";
            k = 0;
            while(data[m] != '^')
            {
                part[k++] = data[m++];
            }
            value = atof(part);
            array[i][j] = value;
        }
    }

    return 1;
}

int PROCESS_FILE::get_parameter_from_file(char *file_name, double (*array)[8], int len)
{
    int i, j;
    char data[1000] = "";
    read_file(file_name, data);
    if(!strcmp(data, ""))
    {
        for(i = 0; i < len; i++)
            for(j = 0; j < 8; j++)
                array[i][j] = 0.0;

        return 0;
    }

    return array_decode(array, data, len);
}

int PROCESS_FILE::store_new_parameter(char *file_name, double (*array)[8])
{
//    int i, j, flag;
    double old[3][8];
    char data[1000] = "";

    if(!get_parameter_from_file(file_name, old, 3))
    {
        write_file(file_name, array_encode(array, data, 3));
        return 0;
    }

 /*   for (j = 0; j < 9; j++)//zc删
    {
        // 判断某一组系数是否更新
        flag = 0;
        for (i = 0; i < 3; i++)
        {
            if (array[i][j] != 0.0)
            {
                flag = 1;
                break;
            }
        }
        // flag == 0 这一组系数采用原来的值
        if (flag == 0)
        {
            for (i = 0; i < 3; i++)
                array[i][j] = old[i][j];
        }
    }*/

    write_file(file_name, array_encode(array, data, 3));
    return 1;
}

int PROCESS_FILE::store_new_rev_viscosity(char *file_name, double (*array)[8])
{
    double old[10][8];
    char data[1000] = "";

    if(!get_parameter_from_file(file_name, old, 10))
    {
        write_file(file_name, array_encode(array, data, 10));
        return 0;
    }

    write_file(file_name, array_encode(array, data, 10));
    return 1;
}

char* PROCESS_FILE::make_file(char *file_name)
{
    ifstream fin(file_name);
    if(!fin)
    {
        fin.close();
        ofstream fout(file_name);
        if(!fout)
        {
            cout<<"File Create Fail!"<<endl;
            return NULL;
        }
        fout.close();
        return file_name;
    }
    fin.close();
    return file_name;
}

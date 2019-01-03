#include <stdlib.h>
#include <stdio.h>

//定义最大数据行数
#define MAXROWCOUNT 10
//定义最大数据列数
#define MAXCOLCOUNT 5

float myData[MAXROWCOUNT][MAXCOLCOUNT];

void ReadDataFromFile(char * filename)
{
    int row = 0, col = 0;
    FILE * fp = fopen(filename, "r");
    
    for(row=0;(!feof(fp)&&(row<MAXROWCOUNT);row++)
        for(col=0;col<MAXCOLCOUNT;
        {
            //use fscanf() to 
            fscanf(fp, "%f", &myData[row][col]);
        }
    fclose(fp);
}

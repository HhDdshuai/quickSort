#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
int Partition(elemType a[],int low,int high){
    int pivot = a[low];                         //将当前表中第一个元素设为枢轴值，对表进行划分
    while(low < high){                          //low > high跳出循环
        while(low < high && a[high] > pivot)    //此处low < high 是为了避免完全逆序时出现数组下溢
            --high;                             //从后往前寻找比pivot小的元素
        a[low] = a[high];                       //将比枢轴小的移动到左端
        while(low < high && a[low] < pivot)
            ++low;                              //从前往后寻找比枢轴大的元素
        a[high] = a[low];                       //将比枢轴大的移动到右端
    }
    a[low] = pivot;                             //枢轴元素放在最终位置
    return low;                                 //返回存放枢轴的最终位置
}
void Q_Sort(elemType a[],int low,int high){
    if(low < high){                             //递归出口
        int pivot_pos = Partition(a,low,high);  //划分
        Q_Sort(a,low,pivot_pos - 1);            //递归调用
        Q_Sort(a,pivot_pos + 1,high);
    }
}

int main()
{
    elemType a[] = {12,864,212,7,54,2,69,76,127,965,5451,761,215,25,85,49,42,14,256,29,
    55,87,66,23,01,861,91,31};
    int len = sizeof(a)/sizeof(elemType);
    Q_Sort(a,0,len - 1);
    for(int i = 0;i < len;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

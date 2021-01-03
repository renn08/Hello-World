#include <stdio.h>
#include <stdlib.h>
//合并数组插入排序
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int pos = (nums1Size + nums2Size) / 2;
    int *numSum = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    //int numSum[100];
    //生成合并数组
    for (int i = 0; i < nums1Size; ++i){
        numSum[i] = nums1[i];
    }
    for (int j = 0; j < nums2Size; ++j){
        numSum[nums1Size + j] = nums2[j];
    }
    //插入排序
    if (nums1Size != 0)
    {
        for (int m = nums1Size; m < (nums1Size + nums2Size); ++m) //从第二个数组的第一位开始
        {
            int n = m - 1; //指向被比较的另外一个数
            int temp = numSum[m];
            while (n >= 0 && numSum [n] > temp)//最好将n>=0写在前面防止出现numSum[-1]的情况
            { //被比较的另一个数排到数组第一个数为止
                numSum[n + 1] = numSum[n];
                numSum[n] = temp;
                n--;
            }
        }
    }
    //确定中位数
    double mid;
    if (2 * pos < nums1Size + nums2Size){
        mid = numSum[pos];
    } //odd
    else{
        mid = (double)(numSum[pos] + numSum[pos - 1]) / 2;//运算内均为int结果需要强制转换
    }//even
    return mid;
}

int main()
{
    int nums1[4] = {0, 0,0,0}, nums2[5] = {-1, 0,0,0,1};
    double ans;
    ans = findMedianSortedArrays(nums1, 4, nums2, 5);
    printf("%lf", ans);
    return 0;
}

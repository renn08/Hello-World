#include <stdio.h>
#include <stdlib.h>
//不合并双指针
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int p = 0, q = 0; //分别指向两个数组
    int pos = (nums1Size + nums2Size) / 2;
    double mid, mid1, mid2;
    if (nums1Size != 0 && nums2Size != 0 && !(nums1Size == 1 && nums2Size == 1))
    {
        if (2 * pos < nums1Size + nums2Size)
        {
            while ((p + q) <= pos)
            {
                if (p < nums1Size && q < nums2Size)
                {
                    if (nums1[p] < nums2[q])
                    {
                        if ((p + q) == pos)
                        {
                            mid = nums1[p];
                            return mid;
                        }
                        p++;
                    }
                    else
                    {
                        if ((p + q) == pos)
                        {
                            mid = nums2[q];
                            return mid;
                        }
                        q++;
                    }
                }
                else
                {
                    if (p == nums1Size)
                    {
                        p--;
                        while ((p + q + 1) <= pos)
                        {
                            if ((p + q + 1) == pos)
                            {
                                mid = nums2[q];
                                return mid;
                            }
                            q++;
                        }
                    }
                    if (q == nums2Size)
                    {
                        q--;
                        while ((p + q + 1) <= pos)
                        {
                            if ((p + q + 1) == pos)
                            {
                                mid = nums1[p];
                                return mid;
                            }
                            p++;
                        }
                    }
                }
            } //odd
        }
        else
        {
            while ((p + q) <= pos)
            {
                if (p < nums1Size && q < nums2Size)
                {
                    if (nums1[p] < nums2[q])
                    {
                        if ((p + q) == pos - 1)
                        {
                            mid1 = nums1[p];
                        }
                        if ((p + q) == pos)
                        {
                            mid2 = nums1[p];
                            mid = (mid1 + mid2) / 2;
                            return mid;
                        }
                        p++; //在比较后再向后移，后移一位的数不确定是下一个
                    }
                    else
                    {
                        if ((p + q) == pos - 1)
                        {
                            mid1 = nums2[q];
                        }
                        if ((p + q) == pos)
                        {
                            mid2 = nums2[q];
                            mid = (mid1 + mid2) / 2;
                            return mid;
                        }
                        q++;
                    }
                }
                else
                {
                    if (p == nums1Size)
                    {
                        p--;
                        while ((p + q + 1) <= pos)
                        {
                            if ((p + q + 1) == pos - 1)
                            {
                                mid1 = nums2[q];
                            }
                            if ((p + q + 1) == pos)
                            {
                                mid2 = nums2[q];
                                mid = (mid1 + mid2) / 2;
                                return mid;
                            }
                            q++;
                        }
                    }
                    if (q == nums2Size)
                    {
                        q--;
                        while ((p + q + 1) <= pos)
                        {
                            if ((p + q + 1) == pos - 1)
                            {
                                mid1 = nums1[p];
                            }
                            if ((p + q + 1) == pos)
                            {
                                mid2 = nums1[p];
                                mid = (mid1 + mid2) / 2;
                                return mid;
                            }
                            p++;
                        }
                    }
                }
            }
             //mid = (double)(numSum[pos] + numSum[pos - 1]) / 2; //运算内均为int结果需要强制转换
        }                            //even
    }
    if (nums1Size == 0){
        if (2 * pos < nums1Size + nums2Size)
        {
            mid = nums2[pos];
        } //odd
        else
        {
            mid = (double)(nums2[pos] + nums2[pos - 1]) / 2; //运算内均为int结果需要强制转换
        }                                                      //even
    }
    if (nums2Size == 0){
        if (2 * pos < nums1Size + nums2Size)
        {
            mid = nums1[pos];
        } //odd
        else
        {
            mid = (double)(nums1[pos] + nums1[pos - 1]) / 2; //运算内均为int结果需要强制转换
        }
    }
    if (nums1Size == 1 && nums2Size == 1){
        mid = (double)(nums1[0] + nums2[0]) / 2;
    }
        return mid;
}

int main()
{
    int nums1[1] = {1}, nums2[3] = {2,3,4};
    double ans;
    ans = findMedianSortedArrays(nums1, 1, nums2, 3);
    printf("%lf", ans);
    return 0;
}

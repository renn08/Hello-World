#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                int *ret = (int*)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main(){
    int nums[5] = {2,7,11,15};
    char ret[5] = {0};
    int target = 9;
    int a = 2;
    int *returnSize = &a;//直接定义指针不赋值是危险的，随机分配的地址可能覆盖掉原有数据。需要初始化
    *returnSize = 2;
    twoSum(nums, 5, target, returnSize);
    for (int i = 0; i < a; ++i){
        printf("%d", twoSum(nums, 5, target, returnSize)[i]);
    }
    printf("\n");
    printf("Size: %d", *returnSize);
    return 0;
}

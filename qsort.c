/*A function pointer used as an argument is sometimes referred to as a callback function because the receiving function "calls it back"*/
/*void qsort(void *base, size_t num, size_t width, int (*compare)(const void*, const void*))*/
#include <stdio.h>
#include <stdlib.h>

int compare (const void*, const void*);//const void*指向的值是常量

int main(){
    int arr[5] = {52, 23, 56, 19, 4};
    int num, width, i;

    num = sizeof(arr)/sizeof(arr[0]);//the number of element in the array
    width = sizeof(arr[0]);//the size of the element
    qsort((void*)arr, num, width, compare);//对arr强制转换为空指针
    /*这一步相当于：int (*compare)(const void*, const void*)) = compare，也就是一次对compare函数的function pointer declaration*/
    for (i = 0; i < 5; ++i){
        printf("%d ", arr[i]);
    }
    return 0;
}

int compare(const void *elem1, const void *elem2){
    if((*(int*)elem1) == (*(int*)elem2)) return 0;
    else if ((*(int *)elem1) < (*(int *)elem2)) return -1;
    else return 1;
}
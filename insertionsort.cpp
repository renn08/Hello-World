#include <iostream>  
#include <string>  

using namespace std;

int main(){
    int a[6] = {1,7,6,3,4,3};
    int i, j, m, k;
    for (j = 1; j < 6; j++){
        i = 0;
        while (a[j] > a[i]){
            i++;
        }
        m = a[j];
        for (k = 0; k < j - i; k++){
            a[j - k] = a[j - k -1];
        }
        a[i] = m;
    }
    for (i = 0; i < 6; i++){
        cout << a[i] << '\n';
    }
    return 0;
}
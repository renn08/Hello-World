#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string t = "CS106";
    char a[6] = "CS106";
    cout << a << endl; 
    if (a[5] == '\0'){
        cout << 0 << endl;
    }
    cout << string(a) << endl;//force to convert
    string lip(t, 3);
    string T = t + 'X';
    t = T.c_str();
    cout << t << endl;
    cout << "lip is " << lip << endl;
    cout << string(t, 3) <<endl;
    return 0;
}

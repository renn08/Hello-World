#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    s = "CS106";
    for (int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
    cout << s << endl;
    return 0;
}
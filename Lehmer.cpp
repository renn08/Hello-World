#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

void read_to_map(map<int, int> & m, string source){
    int j = 0;
    string temp0;//n
    string temp1;//root
    int odd = 1;

    int enable = 0;//0 read n, 1 read root, 2 don't read 
    if(source[0] == ' '){
        enable = 2;
    }
    else{
        enable = 0;
    }

    for (int i = 0; i < source.size(); i++){
        if(source[i] == ' '){
            enable = 2;
        }
        else{
            if(odd){enable = 0;}
            else {enable = 1;}
        }

        if(enable == 0){
            temp0 += source[i];
            odd = 1;
            j = 0;
        }
        else if(enable == 1)
        {
            temp1 += source[i];
            odd = 0;
            j = 1;
        }
        else {
            if(j == 0){odd = 0;}
            else if(j == 1){odd = 1;
            m[stoi(temp0)] = stoi(temp1);
            temp0 = "";
            temp1 = "";}
            j = 3;
        }
    }
}

int main(){
    vector<int> X; //The sequence for pseudorandom numbers
    int a; //multiplier, an element of high multiplicative order modulo m (e.g., a primitive root modulo n)
    int c; //increment 
    int x0; //seed, coprime to m(1 - m-1)
    int m;  //a prime number or a power of a prime number

    string read;
    // read = "3  2                                  5  2                                  7  3                                  9  2                                  11  2                                  13  6                                  16  5                                  17  10                                  19  10                                  23  10                                  25  2                                  27  2                                  29  10                                  31  17                                  32  5                                  37  5                                  41  6                                  43  28                                  47  10                                  49  10                                  53  26                                  59  10                                  61  10                                  64  5                                  67  12                                  71  62                                  73  5                                  79  29                                  81  11                                  83  50                                  89  30                                  97  10
    //        ";
        read = "2 1 38 3 94 5 158 3 3 2 41 6 97 5 162 5 4 3 43 3 98 3 163 2 5 2 46 5 101 2 166 5 6 5 47 5 103 5 167 5 7 3 49 3 106 3 169 2 9 2 50 3 107 2 173 2 10 3 53 2 109 6 178 3 11 2 54 5 113 3 179 2 13 2 58 3 118 11 181 2 14 3 59 2 121 2 191 19 17 3 61 2 122 7 193 5 18 5 62 3 125 2 194 5 19 2 67 2 127 3 197 2 22 7 71 7 131 2 199 3 23 5 73 5 134 7 202 3 25 2 74 5 137 3 206 5 26 7 79 3 139 2 211 2 27 2 81 2 142 7 214 5 29 2 82 7 146 5 218 11 31 3 83 2 149 2 223 3 34 3 86 3 151 6 226 3 37 2 89 3 157 5 227 2 ";
        map<int, int>
            rootmod;
    read_to_map(rootmod, read);
    //cout<< rootmod[3] << '\n';
    //cout<< X+= 1<< '\n';

    /*for x0 = 29, m = 89*, Lehmer RND*/
    // x0 = 29;
    // m = 89;
    // a = rootmod[89];
    // c = 0;
    // X.push_back(x0);
    // int temp, x = 0;
    // while(x != 89 * 3){
    //     temp = (a * X.back() + c) % m;
    //     X.push_back(temp);
    //     x++;
    // }
        
    // cout << "Element" << setw(15) << "Value" << '\n';
    // for(int k = 0; k < X.size(); k++){
    //     cout << setw(7) << k << setw(15) << X[k] << '\n';  
    // }

    /*MINSTD*/
    x0 = 2;
    m = 2147483647;
    a = 7*7*7*7*7;
    c = 0;
    X.push_back(x0);
    int temp, x = 0;
    while (x != 89 * 3)
    {
        temp = (a * X.back() + c) % m;
        X.push_back(temp);
        x++;
    }

    cout << "Element" << setw(15) << "Value" << '\n';
    for (int k = 0; k < X.size(); k++)
    {
        cout << setw(7) << k << setw(15) << X[k] << '\n';
    }
    return 0;
}
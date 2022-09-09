#include <iostream>
#include "PointvsPolygon.h"
#include <fstream>

using namespace std;
#define MAX 10000

int main(){
    ToaDo m[MAX];
    Duong d[MAX];
    int n;
    ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/HaNoi.txt");
    ofstream fileOutput("E:/FileCode/OOP C++/CSDLKG/output.txt");
    if (fileInput.fail() || fileOutput.fail()){
        cout << "Khong mo duoc file !!!";
        return -1;
    } 
    n = 0;
    while ( !fileInput.eof())
    {
        fileInput >> m[n].x >> m[n].y;
        n++;
    }
    n--;
    cout << n << endl;
    LapDuong(m,d,n);
    // for (int i = 0; i < n; i++) {
    //     cout << d[i].a << "  " << d[i].b << endl;
    // };
}
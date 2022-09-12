#include <iostream>
#include <fstream>
#include "PolylineVsPolyline.h"

using namespace std;

int main(){
    polyline d[10000];
    int n;
    cout << "Nhap so duopng trong danh sach : " ;
    cin >> n;
    // ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/input.txt");
    // ofstream fileOutput("E:/FileCode/OOP C++/CSDLKG/output.txt");
    // if (fileInput.fail() || fileOutput.fail()){
    //     cout << "Khong mo duoc file !!!";
    //     return -1;
    // } 
    // n = 0;
    // while ( !fileInput.eof())
    // {
    //     fileInput >> d[n].Nhap();
    //     n++;
    // }
    // n--;
    // fileInput.close();
    for (int i = 0 ; i < n ; i++){
        cout << "Nhap duong " << i+1 << " : "; 
        d[i].Nhap();
        d[i].Taopolyline();
    };
    Xuli(d,n);
    return 0;
}
#include <iostream>
#include <math.h>
#include <fstream>
#include "PointvsPolygon.h"

using namespace std;

int main() {
    ToaDo m[MAX], a;
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
    fileInput.close();
    cout << n << endl;
    cout << "Nhap toa do cua diem : ";
    cin >> a.x >> a.y;
    LapDuong(m, d, n);
    //105.7848102, 21.0490694

    if (KiemTraDiem(m,d,n,a) == -1 ){
        cout << "Diem nam tren vung" << endl;
    } 
    else {
        if (KiemTraDiem(m,d,n,a) == 1){
            cout << "Diem thuoc vung" << endl;
        } else {
            cout << "Diem khong thuoc vung" << endl;
        }
    }
}



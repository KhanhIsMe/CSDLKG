#include <iostream>
#include <fstream>
#include "PointVsPolygon2.h"

using namespace std;

int main(){
    HinhHoc d[10000];
    point td,diem[10000];
    int n,a,b,c,e;
    ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/input.txt");
    ofstream fileOutput("E:/FileCode/OOP C++/CSDLKG/output.txt");
    if (fileInput.fail() || fileOutput.fail()){
        cout << "Khong mo duoc file !!!";
        return -1;
    } 
    n = 0;
    while ( !fileInput.eof())
    {
        fileInput >> diem[n].x >> diem[n].y;
        n++;
    }
    n--;
    fileInput.close();
    cout << n << endl;
    cout << "Nhap toa do cua diem : ";
    cin >> td.x >> td.y;
    //105.7848102, 21.0490694
    for (int i = 0 ; i < n-1 ; i++){
        d[i].Nhap(diem[i].x,diem[i].y,diem[i+1].x,diem[i+1].y);
        d[i].TaoPolyline();
    }
    d[n-1].Nhap(diem[n-1].x,diem[n-1].y,diem[0].x,diem[0].y);
    d[n-1].TaoPolyline();
    if (KiemTraDiem(d,n,td) == -1 ){
        cout << "Diem nam tren vung" << endl;
    } 
    else {
        if (KiemTraDiem(d,n,td) == 1){
            cout << "Diem thuoc vung" << endl;
        } else {
            cout << "Diem khong thuoc vung" << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include "PolylineVsPolyline.h"

using namespace std;

int main(){
    polyline d[10000];
    int n,a,b,c,e;
    ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/Polygon.txt");
    ofstream fileOutput("E:/FileCode/OOP C++/CSDLKG/output.txt");
    if (fileInput.fail() || fileOutput.fail()){
        cout << "Khong mo duoc file !!!";
        return -1;
    } 
    n = 0;
    while ( !fileInput.eof())
    {
        fileInput >> a >> b >> c >> e;
        d[n].Nhap(a,b,c,e);
        d[n].Taopolyline();
        n++;
    }
    n--;
    fileInput.close();
    cout << n << endl;
    Xuli(d,n);
    return 0;
}
#include <iostream>
#include "PointvsPolygon.h"

using namespace std;
struct GiaoDiem
{
    float x,y;
};
//kiểm tra hai polygon có cắt nhau không
int TimCat(Duong d1[],Duong d2[] , int i, int j){
    ToaDo GD;
    GD.x = (d2[j].b - d1[i].b) / (d1[i].a - d2[j].a);
    GD.y = GD.x * d1[i].a + d1[i].b;
    if ( ThuocGioiHan(d1,GD,i) == 1 && ThuocGioiHan(d2,GD,j) == 1)
        return 1;
    else return 0; 
};

int KiemTraCat(ToaDo m1[] , ToaDo m2[], Duong d1[],Duong d2[] , int n, int l){
    int kq = 0;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < l ; j++){
            if (TimCat(d1,d2,i,j) == 1){
                kq = 1;
            } 
        }
        if (kq == 1) return 1;
            else {
                if (kq == 0){
                    ToaDo a = m2[0]; 
                    if (KiemTraDiem(m1,d1,n,a) == 1)
                        return 2;
                    else {
                        a = m1[0];
                        if (KiemTraDiem(m2,d2,l,a) == 1)
                            return 3;
                        else return 0;
                    }
                }
            }
}

int main(){
    ToaDo m1[MAX],m2[MAX],a;
    Duong d1[MAX],d2[MAX];
     int n,l,dem = 0;
    ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/Polygon.txt");
    
    if (fileInput.fail()){
        cout << "Khong mo duoc file !!!";
        return -1;
    } 
    n = 0; l = 0;
    while ( !fileInput.eof())
    {
        fileInput >> n;
        for (int i = 0 ; i < n; i++){
            fileInput >> m1[i].x >> m1[i].y;
        }
        fileInput >> l;
        for (int i = 0; i < l; i++){
            fileInput >> m2[i].x >> m2[i].y;
        }
    }
    fileInput.close();
    LapDuong(m1,d1,n);
    LapDuong(m2,d2,l);
    if (KiemTraCat(m1,m2,d1,d2,n,l) == 1)
        cout << "Hai hinh cat nhau" ;
    else if (KiemTraCat(m1,m2,d1,d2,n,l) == 2)
            cout << "Hinh hai nam trong hinh mot";
        else if (KiemTraCat(m1,m2,d1,d2,n,l) == 3)
                cout << "Hinh mot nam trong hinh hai";
            else 
                    cout << "Hai hinh khong cat nhau";
}
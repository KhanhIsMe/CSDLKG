#include <iostream>
#include "PointvsPolygon.h"
#include "PointVsPolygon2.h"


using namespace std;
class GiaoDiem{
    public:
        float x,y;
        int lk;
};
//kiểm tra hai polygon có cắt nhau không
// int TimCat(Duong d1[],Duong d2[] , int i, int j, ToaDo &a){
//     a.x = (d2[j].b - d1[i].b) / (d1[i].a - d2[j].a);
//     a.y = a.x * d1[i].a + d1[i].b;
//     if ( ThuocGioiHan(d1,a,i) == 1 && ThuocGioiHan(d2,a,j) == 1)
//         return 1;
//     else return 0; 
// };

int TimCat(HinhHoc d1 ,HinhHoc d2 , point &a){
    a.x = (d2.b - d1.b) / (d1.a - d2.a);
    a.y = a.x * d1.a + d1.b;
    if ( ThuocGioiHan(d1,a) == 1 && ThuocGioiHan(d2,a) == 1)
        return 1;
    else return 0; 
};

int KiemTraCat(HinhHoc d1[], HinhHoc d2[] , int n, int l){
    int kq = 0;
    point a;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < l ; j++){
            if (TimCat(d1[i],d2[j],a) == 1){
            } 
                kq = 1;
        }
        if (kq == 1) return 1;
            else {
                if (kq == 0){
                    a.x = d2[0].x1;
                    a.y = d2[0].y1;
                    if (KiemTraDiem(d1,n,a) == 1)
                        return 2;
                    else {
                         a.x = d1[0].x1;
                         a.y = d1[0].y1;
                        if (KiemTraDiem(d2,l,a) == 1)
                            return 3;
                        else return 0;
                    }
                }
            }
};

// int TaoDS(ToaDo m1[] , ToaDo m2[], Duong d1[],Duong d2[] , int n, int l , GiaoDiem gd[] , int &dempt)
// {
//     for (int i = 0 ; i < n){
        
//     }
// }

int main(){
    HinhHoc d1[MAX],d2[MAX];
    point a;
    int n,l,dem = 0;
    GiaoDiem l1[MAX],l2[MAX];
    
}
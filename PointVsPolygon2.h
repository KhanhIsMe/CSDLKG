#include <iostream>
#include <fstream>

class point{
    public:
        float x,y;
};

class HinhHoc
{
private:
    /* data */
public:
    float x1,y1,x2,y2,a,b,xMax,xMin,yMax,yMin;
    HinhHoc(/* args */);
    friend point;
    void Nhap(float a,float b,float c,float e);
    void TaoPolyline();
    friend int ThuocGioiHan(HinhHoc d, point a);
    friend int KiemTraDinhDuoi(HinhHoc d , point a);
    friend int DiemThuocDuong(HinhHoc d[] , point a, int n);
    friend int KiemTraGiao(HinhHoc d[], int n , point a);
    friend int KiemTraDiem(HinhHoc d[] , int n , point a);
};

HinhHoc::HinhHoc(/* args */)
{
}

void HinhHoc::Nhap(float a,float b,float c,float e){
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = e;
};

// Tạo lớp Polylien 
void HinhHoc::TaoPolyline(){
    a = (y1 - y2) / (x1 - x2);
    b = y1 - a * x1;
    if (x1>=x2){
        xMax = x1;
        xMin = x2;
    } else{
        xMax = x2;
        xMin = x1;
    }
    if (y1>y2){
        yMax = y1;
        yMin = y2;
    } else {
        yMax = y2;
        yMin = y1;
    }
};

//Kiểm tra điểm có thuộc đoạn thẳng hay không
int ThuocGioiHan(HinhHoc d, point a){
    if ((d.xMin <= a.x && a.x <= d.xMax) && (d.yMin <= a.y && a.y <= d.yMax)) return 1;
    return 0;
};

//Kiểm tra điểm có phải là đỉnh dưới của đường thẳng hay không
int KiemTraDinhDuoi(HinhHoc d , point a){
    if ((a.x == d.x1 && a.y == d.y1) || (a.x == d.x2 && a.y == d.y2)){
        if (a.y < d.y1 || a.y < d.y2) return 1;
    };
    return 0;
};

//kiểm tra điểm có nằm trên vùng hay không
int DiemThuocDuong(HinhHoc d[] , point a, int n){
    for (int i = 0; i < n; i++) {
        if (ThuocGioiHan(d[i],a) == 1) {
            if ((d[i].a * a.x - a.y + d[i].b) == 0) return 1;
        };
    }
    return 0;
};

//Tính tổng số giao điểm với vùng
int KiemTraGiao(HinhHoc d[], int n , point a){
    point GD;
    int dem = 0;
    for (int i = 0; i < n ; i++){
        GD.y = a.y;
        GD.x = (a.y-d[i].b)/d[i].a;
        if (d[i].a != 0 && ThuocGioiHan(d[i],GD) == 1 && KiemTraDinhDuoi(d[i],GD) != 1 && GD.x >= a.x) dem++;
    };
    return dem;
};

//Kiểm tra điểm có thuộc vùng hay không
int KiemTraDiem(HinhHoc d[] , int n , point a){
    if (DiemThuocDuong(d,a,n) == 1)
        return -1;
    else 
        if (KiemTraGiao(d,n,a) % 2 == 1)
            return 1;
        else
            return 0;
}





#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
#define MAX 10000

struct ToaDo
{
    float x, y;
};

struct Duong
{
    float a, b, GHx1, GHx2, GHy1, GHy2;
};

// Tạo ra mảng đường từ các tọa độ của polygon
void LapDuong(ToaDo m[], Duong d[], int n) {
    int dem = 0, i;
    float  a, b;
    for (i = 1; i < n; i++) {
        a = (m[i].y - m[i - 1].y) / (m[i].x - m[i - 1].x);
        b = m[i].y - a * m[i].x;
        if (m[i].x >= m[i - 1].x) {
            d[dem].GHx1 = m[i].x;
            d[dem].GHx2 = m[i - 1].x;
        }
        else {
            d[dem].GHx1 = m[i - 1].x;
            d[dem].GHx2 = m[i].x;
        }

        if (m[i].y >= m[i - 1].y) {
            d[dem].GHy1 = m[i].y;
            d[dem].GHy2 = m[i - 1].y;
        }
        else {
            d[dem].GHy1 = m[i - 1].y;
            d[dem].GHy2 = m[i].y;
        }
        d[dem].a = a;
        d[dem].b = b;
        dem++;
    };
    a = (m[0].y - m[n - 1].y) / (m[0].x - m[n - 1].x);
    b = m[0].y - a * m[0].x;
    d[dem].a = a;
    d[dem].b = b;
    if (m[0].x >= m[n - 1].x) {
        d[dem].GHx1 = m[0].x;
        d[dem].GHx2 = m[n - 1].x;
    }
    else {
        d[dem].GHx1 = m[n - 1].x;
        d[dem].GHx2 = m[0].x;
    }

    if (m[0].y >= m[n - 1].y) {
        d[dem].GHy1 = m[0].y;
        d[dem].GHy2 = m[n - 1].y;
    }
    else {
        d[dem].GHy1 = m[n - 1].y;
        d[dem].GHy2 = m[0].y;
    }
};

// kiểm tra điểm có thuocj đoạn thảng hay không
int ThuocGioiHan(Duong d[], ToaDo a, int i){
    if ((d[i].GHx2 <= a.x && a.x <= d[i].GHx1) && (d[i].GHy2 <= a.y && a.y <= d[i].GHy1)) return 1;
    return 0;
}
 // Kiểm tra có phải là đỉnh dưới của đường thẳng hay không
int KiemTraDinhDuoi(ToaDo m[], int i, int j, ToaDo GD){
    if ((GD.x == m[i].x && GD.y == m[i].y) || (GD.x == m[j].x && GD.y == m[j].y)){
        if (GD.y < m[i].y || GD.y < m[j].y) return 1;
    };
    return 0;
};

//Kiểm tra một điểm có thuộc đường hay không
int DiemThuocDuong(Duong d[], ToaDo a, int n) {
    for (int i = 0; i < n; i++) {
        if (ThuocGioiHan(d,a,i) == 1) {
            if ((d[i].a * a.x - a.y + d[i].b) == 0) return 1;
        };
    }
    return 0;
}

//Tìm tất cả những điểm giao
int KiemTraGiao(ToaDo m[], Duong d[], int n, ToaDo a){
    ToaDo GD;
    int dem = 0;
    for (int i = 0 ; i < n - 1 ; i++ ){
        GD.y = a.y;
        GD.x = (a.y-d[i].b)/d[i].a;
        if (d[i].a != 0 && ThuocGioiHan(d,GD,i) == 1  && KiemTraDinhDuoi(m,i,i+1,GD) != 1 && GD.x >= a.x ) dem++;
    };
    GD.y = a.y;
    GD.x = (a.y-d[n-1].b)/d[n-1].a;
    if (d[n-1].a != 0 && ThuocGioiHan(d,GD,n-1) == 1 && KiemTraDinhDuoi(m,n-1,0,GD) != 1 && GD.x >= a.x ) dem++;
    return dem;
}

//Kiểm tra xem điểm có nằm trong vùng hay không
int KiemTraDiem(ToaDo m[], Duong d[], int n, ToaDo a){
    if (DiemThuocDuong(d, a, n) == 1) // kiểm tra điểm có nằm trên polygon hay không
        return -1;
    else
        if (KiemTraGiao(m, d, n, a) % 2 == 1) // nếu số điểm giao là lẻ thì điểm nằm trong vùng
            return 1;
        else
            return 0;
}


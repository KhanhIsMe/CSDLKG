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

int ThuocGioiHan(Duong d[], ToaDo a, int i){
    if ((d[i].GHx2 <= a.x && a.x <= d[i].GHx1) && (d[i].GHy2 <= a.y && a.y <= d[i].GHy1)) return 1;
    return 0;
}

int KiemTraDinhDuoi(ToaDo m[], int i, int j, ToaDo GD){
    if ((GD.x == m[i].x && GD.y == m[i].y) || (GD.x == m[j].x && GD.y == m[j].y)){
        if (GD.y < m[i].y || GD.y < m[j].y) return 1;
    };
    return 0;
};

int DiemThuocDuong(Duong d[], ToaDo a, int n) {
    
    for (int i = 0; i < n; i++) {
        if (ThuocGioiHan(d,a,i) == 1) {
            if ((d[i].a * a.x - a.y + d[i].b) == 0) return 1;
        };
    }
    return 0;
}

int KiemTraGiao(ToaDo m[], Duong d[], int n, ToaDo a){
    ToaDo GD;
    int dem = 0;
    for (int i = 0 ; i < n - 1 ; i++ ){
        GD.y = a.y;
        GD.x = (a.y-d[i].b)/d[i].a;
        if (d[i].a != 0 && ThuocGioiHan(d,GD,i) && KiemTraDinhDuoi(m,i,i+1,GD) != 1 && GD.x >= a.x ) dem++;
    };
    GD.y = a.y;
    GD.x = (a.y-d[n-1].b)/d[n-1].a;
    if (d[n-1].a != 0 && ThuocGioiHan(d,GD,n-1) && KiemTraDinhDuoi(m,n-1,0,GD) != 1 && GD.x >= a.x ) dem++;
    return dem;
}

int main() {
    ToaDo m[MAX], a;
    Duong d[MAX];
    int n;
    ifstream fileInput("E:/FileCode/OOP C++/CSDLKG/input.txt");
    ofstream fileOutput("E:/FileCode/OOP C++/CSDLKG/output.txt");
    if (fileInput.fail() || fileOutput.fail()){
        cout << "Khong mo duoc file !!!";
        return -1;
    } 
    n = 0;
    while ( !fileInput.eof())
    {
        // fileInput >> n;
        // for (int i = 0; i < n; i++) {
        //     fileInput >> m[i].x >> m[i].y;
        // };
        fileInput >> m[n].x >> m[n].y;
        n++;
    }
    n--;
    fileInput.close();
    cout << n << endl;
    // cout << "Nhap so diem : ";
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cout << "Nhap toa do diem " << i + 1 << " : ";
    //     cin >> m[i].x >> m[i].y;
    // };
    cout << "Nhap toa do cua diem : ";
    cin >> a.x >> a.y;
    LapDuong(m, d, n);
    //105.7848102, 21.0490694

    if (DiemThuocDuong(d, a, n) == 1)
        cout << "Diem nam tren vung" << endl;
    else
        if (KiemTraGiao(m, d, n, a) % 2 == 1)
            cout << "Diem thuoc vung" << endl;
        else
            cout << "Diem khong thuoc vung" << endl;
        

    // for (int i = 0; i < n; i++) {
    //     cout << d[i].a << "  " << d[i].b << endl;
    // };
    // cout << KiemTraGiao(m, d, n, a);
}



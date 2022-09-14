#include <iostream>
#include <fstream>

using namespace std;

class point{
    public: 
        float x,y;
};

class giaodiem{
    public:
        float a,b,xg,yg,x1,x2,y1,y2;
        int trung = 0;
};

class polyline
{
public:
    float x1,y1,x2,y2,a,b,xMax,xMin,yMax,yMin;
    polyline();
    ~polyline();
    void Nhap(float a,float b,float c,float d);
    void Taopolyline();
    friend int KiemTraGiao(polyline d[],int i , int j , giaodiem a[] , int &dem);
    friend point;
    friend giaodiem;
    friend int KiemTraThuoc(polyline d[] , int i , int j , point GD);
    friend void TimTrung(polyline d[], int i , int j , giaodiem GD[] , int dem);
};

polyline::polyline()
{
}

polyline::~polyline()
{
}

void polyline::Nhap(float a,float b,float c,float e){
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = e;
};

// Tạo lớp Polylien 
void polyline::Taopolyline(){
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

//Kiểm tra xem hai đường trùng nhau từ đâu đến đâu
void TimTrung(polyline d[], int i , int j , giaodiem GD[] , int dem){
    int kt = 0;
    point Q;
    GD[dem].a = i+1;
    GD[dem].b = j+1;
    GD[dem].trung = 1; 
    Q.x = d[i].x1;
    Q.y = d[i].y1;
    if (KiemTraThuoc(d,i,j,Q) == 1){
        if (kt == 0){
            kt = 1;
            GD[dem].x1 = Q.x;
            GD[dem].y1 = Q.y;
        } else {
            GD[dem].x2 = Q.x;
            GD[dem].y2 = Q.y;
            return;
        }
    }
    Q.x = d[i].x2;
    Q.y = d[i].y2;
    if (KiemTraThuoc(d,i,j,Q) == 1){
        if (kt == 0){
            kt = 1;
            GD[dem].x1 = Q.x;
            GD[dem].y1 = Q.y;
        } else {
            GD[dem].x2 = Q.x;
            GD[dem].y2 = Q.y;
            return;
        }
    }
    Q.x = d[j].x1;
    Q.y = d[j].y1;
    if (KiemTraThuoc(d,i,j,Q) == 1){
        if (kt == 0){
            kt = 1;
            GD[dem].x1 = Q.x;
            GD[dem].y1 = Q.y;
        } else {
            GD[dem].x2 = Q.x;
            GD[dem].y2 = Q.y;
            return;
        }
    }
    Q.x = d[j].x2;
    Q.y = d[j].y2;
    if (KiemTraThuoc(d,i,j,Q) == 1){
        if (kt == 0){
            kt = 1;
            GD[dem].x1 = Q.x;
            GD[dem].y1 = Q.y;
        } else {
            GD[dem].x2 = Q.x;
            GD[dem].y2 = Q.y;
            return;
        }
    }
};

// kiểm tra một điểm có thuộc một đoạn thẳng hay không
int KiemTraThuoc(polyline d[] , int i , int j , point GD){
    if (d[i].xMin <= GD.x && GD.x <= d[i].xMax && d[i].yMin <= GD.y && GD.y <= d[i].yMax) {
        if (d[j].xMin <= GD.x && GD.x <= d[j].xMax && d[j].yMin <= GD.y && GD.y <= d[j].yMax)
            return 1;
    }
    return 0;
};

//Kiểm tra hai đường thẳng có trùng nhau hay không
int KiemTraGiao(polyline d[],int i , int j , giaodiem a[] , int &dem){
    point GD;
    if (d[i].a == d[j].a && d[i].b == d[j].b){ //hai đường thẳng trùng nhau
        dem++;
        TimTrung(d,i,j,a,dem);
        return -1;
    } 
    else if (d[i].a == d[j].a) return 0; // hai đường thẳng song song với nhau
    else {                                  // haidduongwf thẳng cắt nhau
        GD.x = (d[j].b - d[i].b)/(d[i].a - d[j].a);
        GD.y = (d[i].a * GD.x + d[i].b);
        if (KiemTraThuoc(d,i,j,GD) == 1) { // kiểm tra điểm cắt có thuộc 2 đoạn thẳng hay không
            dem++;
            a[dem].a = i+1;
            a[dem].b = j+1;
            a[dem].xg = GD.x;
            a[dem].yg = GD.y;
            return 1;
        }
        else return 0;
    }
};

int Xuli(polyline d[] , int n){
    int dem = 0;
    giaodiem GD[1000];
    for (int i = 0 ; i < n-1 ; i++){
        for (int j = i+1 ; j < n ; j++){ 
           KiemTraGiao(d,i,j,GD,dem);
        }
    }
    if (dem == 0) 
        cout << "Khong co duong nao cat nhau";
    else
        for (int i = 1 ; i <= dem ; i++){
            if (GD[i].trung == 0){
                cout << "Hai duong thang " << GD[i].a << " va " << GD[i].b << " cat nhau tai (" <<  GD[i].xg << "," << GD[i].yg << ")" << endl;
            } 
            else {
                cout << "Hai duong thang " << GD[i].a << " va " << GD[i].b << " trung nhau tu (" <<  GD[i].x1 << "," << GD[i].y1 << ") " << "den (" <<  GD[i].x2 << "," << GD[i].y2 << ")" << endl;
            }
        }
}

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
typedef struct 
{
    string hoten;
    int ngaysinh;
    char gioitinh;
    float diem;
}sinhvien;

void nhapthongtinmotsv(sinhvien *sv)
{
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv->hoten);
    
    do {
        cout <<"Nhap ngay sinh: ";
        cin >> sv->ngaysinh;
        if (sv->ngaysinh < 1 || sv -> ngaysinh > 31) {
            cout << "Ngay sinh khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv->ngaysinh < 1 || sv -> ngaysinh > 31);
    
    do {
        cout << "Nhap gioi tinh (Male/Female)(M/F): ";
        cin >> sv->gioitinh;
        if (sv -> gioitinh != 'M' && sv -> gioitinh != 'F'){
        	cout << "Gioi tinh khong hop le! Vui long nhap lai. " << endl;
		}
    } while (sv -> gioitinh != 'M' && sv -> gioitinh != 'F');

    do {
        cout << "Nhap diem: ";
        cin >> sv->diem;
        if (sv->diem < 0 || sv->diem > 10) {
            cout << "Diem khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv->diem < 0 || sv->diem > 10);
}

void nhapds(sinhvien *sv, int n)
{
    for(int i=0; i<n; i++) 
	{
		cout<<"Sinh vien thu "<<i+1<<endl;
        nhapthongtinmotsv(&sv[i]);
    }
}

void inthongtin(const sinhvien& sv) 
{
    cout << "Ho ten: " << sv.hoten << endl;
    cout << "Ngay sinh: " << sv.ngaysinh << endl;
    cout << "Gioi tinh: " << sv.gioitinh << endl;
    cout << "Diem: "<< sv.diem << endl;
}

void hienthidanhsach(sinhvien sv[], int n) 
{
	for (int i = 0; i < n; i++) 
	{
        cout << "Sinh vien thu "<< i+1 <<": "<< endl;
        inthongtin(sv[i]);
        cout << "-------------------------" << endl;
    }
}

void Suathongtin(sinhvien &sv) 
{
    cout << "Nhap thong tin moi cho sinh vien: " << sv.hoten << endl;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.hoten);
    cout << "Nhap ngay sinh: ";
    cin >> sv.ngaysinh;
    cout << "Nhap gioi tinh: ";
    cin >> sv.gioitinh;
    cout << "Nhap diem: ";
    cin >> sv.diem;
}

void suaThongTinDanhSach(sinhvien *sv, int n) {
    int k;
    cout << "Nhap vi tri sinh vien muon sua: ";
    cin >> k;
    if (k >= 1 && k <= n) {
        Suathongtin(sv[k - 1]); 
        cout << "Da sua thong tin cho sinh vien thu " << k << endl;
    } else {
        cout << "Vi tri sinh vien khong hop le!" << endl;
    }
}

void chenThongTinSinhVien(sinhvien *sv, int &n) {
    int pos;
    cout << "Nhap vi tri muon chen: ";
    cin >> pos;
    if (pos >= 1 && pos <= n + 1) {
        sinhvien svMoi;
        nhapthongtinmotsv(&svMoi);
        for (int i = n; i >= pos; i--) {
            sv[i] = sv[i - 1];
        }
        sv[pos - 1] = svMoi;
        n++; 
        cout << "Da chen thong tin sinh vien moi vao vi tri " << pos << endl;
    } else {
        cout << "Vi tri chen khong hop le!" << endl;
    }
}

void sapXepTheoDiemGiamDan(sinhvien *sv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sv[j].diem < sv[j + 1].diem) {
                swap (sv[i], sv[j]);
            }
        }
    }
}

void Menu (){
    cout << "================MENU================" << endl;
    cout << "1. Nhap thong tin 1 sinh vien. "<< endl;
    cout << "2. Nhap thong tin danh sach sinh vien. "<< endl;
    cout << "3. In thong tin 1 sinh vien. "<< endl;
    cout << "4. Hien thi danh sach sinh vien. "<< endl;
    cout << "5. Sua thong tin 1 sinh vien. "<< endl;
    cout << "6. Sua thong tin danh sach sinh vien. "<< endl;
    cout << "7. Chen thong tin 1 sinh vien. " << endl;
    cout << "8. Sap xep danh sach theo diem. " << endl;
    cout << "9. Sinh vien diem cao nhat. " << endl;
    cout << "10. Sinh vien nam cao diem nhat & sinh vien nu thap diem nhat. " << endl;
    cout << "11. Danh sach sinh vien ten bat dau bang chu 'N'. "<< endl;
    cout << "===================================" <<endl;
}

int main(){
    int n;
    sinhvien *sv1;
    int luachon;
    
    do {
        Menu();
        cout << "Nhap lua chon cua ban (1-11): ";
        cin >> luachon;
        
        switch (luachon){
            case 1:
                sv1 = new sinhvien[1];
                nhapds(sv1, 1);
                break;
            case 2:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                sv1 = new sinhvien[n];
                nhapds(sv1, n);
                break;
            case 3:
                int k;
                cout << "Nhap vi tri sinh vien can xem: ";
                cin >> k;
                if (k >= 1 && k <= n) {
                    inthongtin(sv1[k - 1]); 
                } else {
                    cout << "Vi tri sinh vien khong hop le!" << endl;
                }
                break;
            case 4:
                hienthidanhsach(sv1, n);
                break;
            case 5:
                int vitri;
                cout << "Nhap vi tri sinh vien muon sua: ";
                cin >> vitri;
                if (vitri >= 1 && vitri <= n) {
                    Suathongtin(sv1[vitri - 1]); 
                    cout << "Da sua thong tin cho sinh vien thu " << vitri << endl;
                } else {
                    cout << "Vi tri sinh vien khong hop le!" << endl;
                }
                break;
            case 6:
                suaThongTinDanhSach(sv1, n);
                break;
            case 7:
                chenThongTinSinhVien(sv1, n);
                break;
            case 8:
                sapXepTheoDiemGiamDan(sv1, n);
                break;
            case 9:
                
                break;
            case 10:
            	
                break;
            case 11:
			 
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }
    } while (luachon != 0);

    return 0;
}


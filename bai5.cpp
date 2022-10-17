#include <iostream>
#include <fstream>
using namespace std;

string dinh = " ABCDEF";

void docMaTranKe(int a[20][20], int &n, string path){
    fstream f;
    f.open(path, ios::in);
    f >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++ )
            f >> a[i][j];
    f.close();
}
void printMatrix(int a[20][20], int n){
    cout << n << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void ghiDanhSachCanh(int a[20][20], int &n, string path){ // path = "input2_2.txt"
    fstream f;
    f.open(path, ios::out);
    //f << "Dau\tCuoi\n";
    for (int i = 1; i <= n; i++){
        cout << endl;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1) f << i << "\t" << j << endl;
        }
    }
    f.close();
}
void ghiDanhSachKe(int a[20][20], int &n, string path){ // path = "input2_1.txt"
    fstream f;
    f.open(path, ios::out);
    for (int i = 1; i <= n; i++){
        f << i;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1) f << "\t" << j;
        }
        f << endl;
    }
    f.close();
}
int main()
{
    int a[20][20], n;
    docMaTranKe(a, n, "input2.txt");
    printMatrix(a, n);
    ghiDanhSachCanh(a, n, "input2_2.txt");
    ghiDanhSachKe(a, n, "input2_1.txt");
    return 0;
}

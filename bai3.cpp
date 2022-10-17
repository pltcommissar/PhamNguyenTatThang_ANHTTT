#include <iostream>
#include <fstream>
using namespace std;

void doSthing(){
    fstream f;
    f.open("input1_1.txt", ios::in); //"input1_1.txt" la danh sach ke cua do thi vo huong
    string str;
    int i = 0 , j = 0, a[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            a[i][j] = 0;
    while (!f.eof()){
        i++;
        cout << i << " | ";
        j = 0;
        getline(f, str); //doc hang dau tien
        for (int k = 1; k < str.length(); k++){
            if (str[k] <= '9' && str[k] >= '1' ){
                j++;
                a[i][j] = str[k] - 48;
                cout  << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    int n = i - 1;
    for (int  i = 1; i <= n; i++){
        cout << endl;
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "  ";
    }
    //ghi ma tran ke
    f.close();
    f.open("output1_1.txt", ios::out);
    int  b[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            b[i][j] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 0) {
                b[i][(a[i][j])] = 1;
                b[(a[i][j])][i] = 1;
            }
        }
    }
    f << "Ma tran ke: \n";
    for (int  i = 1; i <= n; i++){
        f << endl;
        for (int j = 1; j <= n; j++)
            f << b[i][j] << "  ";
    }
    f << "\n\nDanh sach canh:\n";
    f << "Dau\tCuoi\n";
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (b[i][j] == 1) f << i << "\t" << j << endl;
        }
    }

    f << "\nBac cua tung dinh: \n";
    for (int i = 1; i <= n; i++){
        f << "Bac cua dinh " << i << " : ";
        int d = 0;
        for (int j = 1; j <= n; j++) if (b[i][j] == 1) d++;
        f << d << endl;
    }
    f.close();


}

int main()
{
    doSthing();
    return 0;
}

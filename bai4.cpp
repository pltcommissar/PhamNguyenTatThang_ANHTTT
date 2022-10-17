#include <iostream>
#include <fstream>
using namespace std;

void doSthing(){
    fstream f;
    f.open("input1_2.txt", ios::in); //"input1_1.txt" la danh sach ke cua do thi vo huong
    string str;
    int i = 0 , j = 0, a[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            a[i][j] = 0;
    int n = 0;
    while (!f.eof()){
        f >> i >> j;
        if (i > n) n = i;
        if (j > n) n = j;
        a[i][j] = a[j][i] = 1;
    }
    //n = (n+1)/2; // so dong
    cout << "n = " << n;
    f.close();
    f.open("output1_2.txt", ios::out);
    //ghi ma tran ke
    f << "Ma tran ke :\n";
    for (int  i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            f << a[i][j] << "  ";
        f << endl;
    }

    //ghi danh sach ke:
    f << "\n\nDanh sach ke: \n";
    for (int i = 1; i <= n; i++){
        f << i << " | ";
        for (int j = 1; j <=n; j++){
            if (a[i][j] == 1) f << j << "\t";
        }
        f << endl;
    }

    f << "\nBac cua tung dinh: \n";
    for (int i = 1; i <= n; i++){
        f << "Bac cua dinh " << i << " : ";
        int d = 0;
        for (int j = 1; j <= n; j++) if (a[i][j] == 1) d++;
        f << d << endl;
    }
    f.close();
}

int main()
{
    doSthing();
    return 0;
}

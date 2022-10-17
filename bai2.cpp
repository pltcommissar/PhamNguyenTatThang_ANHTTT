#include <iostream>
#include <fstream>
using namespace std;

string dinh = " ABCDEF";

void docMaTranKe(int a[20][20], int &n, string path)
{
    fstream f;
    f.open(path, ios::in);
    f >> n;
    cout << n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++ )
            f >> a[i][j];
    f.close();
}
void printMatrix(int a[20][20], int n)
{
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << endl;
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}

void ghiDanhSachCanh(int a[20][20], int &n, string path)
{ // path = "input1_2.txt"
    fstream f;
    f.open(path, ios::out);
    //f << "Dau\tCuoi\n";
    for (int i = 1; i <= n; i++)
	{
        cout << endl;
        for (int j = i+1; j <= n; j++)
		{
            if (a[i][j] == 1) f << i << "\t" << j << endl;
                //f << dinh[i] << "\t" << dinh[j] << endl;
        }
    }
    f.close();
}
void ghiDanhSachKe(int a[20][20], int &n, string path)
{ // path = "input1_1.txt"
    fstream f;
    f.open(path, ios::out);
    for (int i = 1; i <= n; i++)
	{
        f << i << "\t\t";
        for (int j = 1; j <= n; j++)
		{
            if (a[i][j] == 1) f << "\t" << j;
        }
        f << endl;
    }
    f.close();
}
int main()
{
    int a[20][20], n;
    docMaTranKe(a, n, "input1.txt");
    printMatrix(a, n);
    ghiDanhSachCanh(a, n, "input1_2.txt");
    ghiDanhSachKe(a, n, "input1_1.txt");
    return 0;
}

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class DoThi
{
	private:
		int n;
		int a[30][30];
	public:
		DoThi();
		void inMaTranKe();
		void docMaTranKe(char tenFile[50]);
		void docDSKe(char tenFile[50]);
		void docDSCanh(char tenFile[50]);
		int timBac(int);
		void timDinhKe(int);
		int soDinh();
		int soCanh();
};
DoThi::DoThi()
{
	n=0;
	for(int i = 1; i<= n; i++)
	{
    	for(int j = 1; j <= n; i++)
    	{  
        	a[i][j] = 0;
    	}
	}
}
void DoThi::inMaTranKe()
{
	cout<<"MA TRAN KE"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

void DoThi::docMaTranKe(char tenFile[50])
{
	fstream f;
	f.open(tenFile,ios::in);
	if(f.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
	f>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			f>>a[i][j];
	}
	f.close();
}
void DoThi::docDSKe(char tenFile[50])
{
	fstream f;
	string s; 
	f.open(tenFile,ios::in);
	if(f.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
	getline(f,s);
	n=s[0]-48;
	for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            a[i][j] = 0;
    int i=0,j=0;  
    int m;
	while(!f.eof())
	{
		getline(f,s);
		i=s[0]-48;
		for (int k = 1; k < s.length(); k++)
		{
			if (s[k] <= '9' && s[k] >= '1' )
			{
                m=s[k]-48;
                a[i][m] = 1;
            }
           
		}
				
    }
}
void DoThi::docDSCanh(char tenFile[50])
{
	fstream f;;
	f.open(tenFile,ios::in);
	if(f.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
    int g,h;
	f>>n;
	for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            a[i][j] = 0;
	while(!f.eof())
	{
		f>>g;
		f>>h;
		a[g][h]=1;
		a[h][g]=1;
	}
}
int DoThi::timBac(int b)
{
	for (int i = 1; i <= n; i++)
	{
        int sum= 0;
        for (int j = 1; j <= n; j++) 
			if (a[i][j] == 1) 
				sum++;
		if(i==b)
			return sum;
    }
}
void DoThi::timDinhKe(int b)
{
	cout<<"Cac dinh ke dinh "<<b<<" :\t";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1 && i==b)
			{
				cout<<j<<"\t";
			}
		}	
	}
}
int DoThi::soDinh()
{
	return n;
}
int DoThi::soCanh()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=timBac(i);
	return sum;
}
int main()
{
	
	cout<<"MENU"<<endl;
	cout<<"1. In ma tran ke"<<endl;
	cout<<"2. Tim bac cua dinh"<<endl;
	cout<<"3. Tim dinh ke cua mot dinh"<<endl;
	cout<<"4. So dinh cua do thi"<<endl;
	cout<<"5. So canh cua do thi"<<endl;
	cout<<"6. Thoat"<<endl;
	int q;
	
	do
	{
		do
		{
			cout<<"Nhap lua chon: ";
			cin>>q;
		}while(q>6 || q<1);
		DoThi d;
		d.docMaTranKe("input1.txt");
		switch(q)
		{
			case 1:
			{
				d.inMaTranKe();
				break;
			}
			case 2:
				{
					int f;
					do
					{
						cout<<"Nhap dinh can tim: ";
						cin>>f;
					}while(f<0||f>d.soDinh());
					cout<<"Bac cua dinh "<<f<<" la: "<<d.timBac(f)<<endl;
					break;
				}
			case 3:
				{
					int f;
					do
					{
						cout<<"Nhap dinh can tim: ";
						cin>>f;
					}while(f<0||f>d.soDinh());
					d.timDinhKe(f);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"So dinh cua do thi: "<<d.soDinh()<<endl;
					break;
				}
			case 5:
				{
					cout<<"So canh cua do thi: "<<d.soCanh()<<endl;
					break;
				}
			default : return 0;
		}
	}while(q!=6);
}


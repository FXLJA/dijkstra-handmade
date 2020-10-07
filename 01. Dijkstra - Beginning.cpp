#include <iostream>
#include <conio.h>

using namespace std;

//Variable declaration
int cost[10][10];		//harga edge
int jarak[20];			//harga jarak yang ditempuh
int i;					//parameter for 1 & indeks baris
int j;					//parameter for 2 & indeks kolom
int k;					//variabel pembantu untuk menentukan jumlah edge
int verteks;			//jumlah node
int edge;				//jumlah edge
int start;				//verteks awal
int totcost;			//jarak total
int S[20];				//mengecek semua jalur yang bisa dilewati
int path[20];			//jumlah hop yang diambil sebagai hasil jarak terpemdek
int p;					//menentukan arah hop dan jumlah hop yang akan diambil

int djikstra_algorithm (int start, int verteks)
{
int min;

	for (i = 1; i <= verteks; i++)
	{
		S[i] = 0;								//setel semua jalur yang mungkin dilewati senilai 0
		jarak[i] = cost[start][i];				//teentukan nilai jarak dengan memakai nilai edge pada node start (saat ini 0)
	}
	
	path[++p] = start;							//path ke-p dimulai dari node start
	S[start] = 1;								//setel node start sebagai node urutan pertama
	jarak[start] = 0;							//setel jarak pada node start menjadi 0 (karena menunjuk pada node itu sendiri)
	
	for (i = 2; i <= verteks - 1; i++)						/*semua perintah didalam scope ini akan diulang 
															  sejumlah dengan jumlah node yang diinputkan oleh user*/
	{
		k = -1;												//menentukan nilai variabel pembantu k. -1 untuk mencegah hop membentuk sebuah sirkuit
		min = 31999;										//menentukan jarak minimal (infinite karena belum diketahui jarak antar edge / belum dicek)
		
		for (j = 1; j <= verteks; j++)						//cek untuk seluruh node yang ada:
		{
			if (jarak[j] < min && S[j] != 1)				/*apakah jaraknya < infinite dan apakah dia bukan node start
															  (karena tadi node start adalah node dengan indeks S[1])*/
			{												//jika kedua kondisi == true, maka:
				min = jarak[j];								//1. nilai edge tersebut menggantikan nilai infinite pada variabel min
				k = j;										//2. node ke-j dijadikan sebagai tujuan hop berikutnya
			}
		}
		
		if (cost[start][k] <= jarak[k])						/*apabila nilai edge antara node start dan hop berikutnya
															  lebih kecil daripada nilai edge yang dicek*/
		{
			p = 1;											/*atur p menjadi 1 (artinya hop mundur)
															  node yang tadinya menjadi tujuan hop berikutnya batal dan diganti
															  dengan node lain dari blok "if" di atas [if (jarak[j] < min && S[j] != 1)]*/
		}
		
		path[++p] = k;										/*apabila semua pengecekan kondisi sudah selesai, lakukan hop.
															  1. jumlah indeks dalam array "path" akan bertambah 1
															  2. nilai dari indeks tersebut adalah jarak terpendek dari evaluasi [for-if] di atas*/
		
		//menampilkan daftar hop dari start sampai tujuan
		for (j = 1; j <= p; j++)
		{
			cout << path[j];
		}
		cout << endl;
		
		S[k] = 1;
		
		//menghitung jarak total dari semua path yang mungkin dilalui
		for (j = 1; j <= verteks; j++)
		{
			if (cost[k][j] != 31999 && 
				jarak[j] >= jarak[k] + cost[k][j] && 
				S[j] != 1)
			{
				jarak[j] = jarak[k] + cost[k][j];
			}
		}
	}
}

int main()
{
int c;

	cout <<"Masukkan jumlah verteks		: ";
	cin >> verteks;
	cout <<"Masukkan jumlah edge		: "; 
	cin >> edge;
	cout << endl << endl;
	
	cout <<"Masukkan harga tiap edge" << endl;
    
	for (k = 1; k <= edge; k++)
    {
    	cout << "Tentukan baris			: ";
        cin >> i;
		cout << "Tentukan kolom			: ";
		cin >> j;
		cout << "Masukkan nilai edge		: ";
		cin >> c;
		
		cout << endl << endl; 
		
        cost[i][j] = c;
    }
    
	for (i = 1; i <= verteks; i++)							//lakukan 2x for untuk mengecek semua node dan posisinya dalam baris dan kolom
    {														//i untuk baris
        for (j = 1; j <= verteks; j++)
        {													//j untuk kolom
            if (cost[i][j] == 0)							/*apabila jumlah jarak dari seluruh node tersebut == 0
            												  artinya belum ada node yang dijadikan titik keberangkatan*/
            {
                cost[i][j] = 31999;							//atur nilai jaraknya sebagai infinite (karena belum dicek)
                cout <<"Tentukan verteks awal: ";
                cin >> start;								//tentukan node start disini
                cout << start << endl;
                
                djikstra_algorithm (start, verteks);		//jalankan algoritma Djikstra
            }
        }
    }
 }

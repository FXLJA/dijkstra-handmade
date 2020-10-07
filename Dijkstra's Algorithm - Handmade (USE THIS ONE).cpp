//Dijkstra's Algorithm

/* 	Jason Alexander 		(32180082)
	Julian Saputra 			(32180087)
	Martien Junaedi 		(32180134)
	Willy Stevanus Susilo 	(32180075)

Menentukan jarak terpendek dari node Start ke semua node yang ada di dalam graf
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

#define infinite 999		//perbandingan konstan untuk menentukan jalur yang akan diambil

using namespace std;

int node;					//jumlah node
int source;					//sumber edge
int destination;			//tujuan edge
int harga;					//harga edge

int graf [100][100];		/* membuat wadah untuk menampung seluruh node dan edge
							   untuk membuat sebuah graf, proyeksikan semua elemen kedalam array kosong */
							   
int jarak[100];				/* harga total yang ditempuh untuk mencapai tujuan node ...
							   untuk setiap node, akan disimpan didalam indeks yang berbeda untuk mencegah nilai ter-overwrite */

bool cek[100];				//mendata semua node yang sudah dikunjungi

/* WARNING: Node yang "sudah dikunjungi" != node yang sudah dilewati
		    Node yang "sudah dikunjungi" == node yang sudah dicek semua node tetangganya (yaitu semua node yang bersifat DIRECTLY CONNECTED)
										    dan didata jaraknya dari node start */

//Algoritma Dijkstra
int dijkstra (int x)		//x = node Start
{
int node_terdekat = -1;					//inti dari dijkstra adalah mencari setiap node terdekat
int edge_terpendek = infinite;			//dan membandingkan edge terpendek untuk mencapai node target

	cek[x] = true;			//karena x akan diisi dengan node Start, maka x ditandai sebagai node yang "sudah dikunjungi"
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Step 1: perbandingan jarak (WARNING: Baca perlahan-lahan)

	for (int i = 1; i <= node; i++)
	{ //open scope for
		if ( //open scope kondisi if 1 			//Jika:
				(cek[i] == false) &&			// 1. Node ke-i belum dikunjungi DAN
				(graf[x][i] != -1)				// 2. Node start (yaitu [x]) dan node yang dicek (yaitu [i]) memiliki koneksi, maka:
		   ) //close scope kondisi if 1
		
		{ //open scope perintah if 1
			if ( //open scope kondisi if 2							//Jika:
					(jarak[x] + graf[x][i] < jarak[i]) ||			/* 1. Jarak gabungan antara node Start dan berapapun nilai jarak dalam graf
																	      lebih kecil dari infinite ATAU */
					(jarak[i] == infinite)							// 2. Nilai indeks ke-i dalam array masih infinite
			   ) //close scope kondisi if 2
			{ //open scope perintah if 2
				jarak[i] = jarak[x] + graf[x][i];					//perintah inilah yang akan meng-update jarak infinite menjadi harga edge
			} //close scope perintah if 2
		} //close scope perintah if 1
	} //close scope for

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Step 2: penentuan jalur (WARNING: Baca perlahan-lahan)

	for (int i = 0; i <= node; i++)
	{ //open scope for
		if ( //open scope kondisi if						//Jika:
				(cek[i] == false) 	&&						//1. Node tersebut belum dikunjungi DAN
				(jarak[i] >= 0)		&&						//2. Jarak total untuk mencapai node tsb >= 0 (artinya node tsb bukan node Start) DAN
				(
					(edge_terpendek > jarak[i]) ||			//3. Nilai edge terpendek lebih besar dari jarak untuk mencapai node di indeks ke-i ATAU
					(edge_terpendek == infinite)			//4. Nilai edge terpendek tidak berubah dari awal karena baru dicek
					
															//Kombinasi yang mungkin adalah 1-2-3 atau 1-2-4
				)
		   ) //close scope kondisi if
		{ //open scope perintah if
			edge_terpendek = jarak[i];
			node_terdekat = i;
		} //close scope perintah if
	} //close scope for
	
	if (node_terdekat != -1)
	{
		dijkstra (node_terdekat);
		return 0;
	}
	
return 0;
}

//Main Program
int main()
{
int loop;

	//inisialisasi node
	cout << "Masukkan jumlah node: ";
	cin >> node;
	cout << endl;

	for (int i = 0; i <= node; i++)
	{
		for (int j = 0; j <= node; j++)
		{
			graf[i][j] = -1;			//-1 == node tidak terkoneksi
		}
	}
	
	//inisialisasi jarak
	for (int i = 0; i <= node; i++)
	{
		jarak[i] = infinite;			//setel semua jarak = infinite di awal karena jarak aslinya belum diketahui
	}
	
	//inisialisasi node Start
	jarak[1] = 0;						//0 == menunjuk ke diri sendiri
	
	//meng-assign harga edge
	do
	{
		cout << "Node sumber	: ";
		cin >> source;
		cout << "Node tujuan	: ";
		cin >> destination;
		cout << "Harga edge	: ";
		cin >> harga;
		
		graf[source][destination] = harga;
		cout << endl;
		
		cout << "Lagi? (1: Ya / 0: Tidak)" << endl;
		cout << "Pilihan: ";
		cin >> loop;
		cout << endl;
		
		if (loop == 0)
		{
			goto run;
		}
	}
	while (loop != 0);
	
	//memanggil algoritma Dijkstra
	run:
	dijkstra(1);							//1 adalah urutan node Start
	
	//menampilkan jalur
	cout << "Starting node adalah node 1" << endl << endl;
	
	for (int i = 1; i <= node; i++)
	{			
		cout << "Jarak terpendek ke node " << i 
			 << " bernilai: " << jarak[i] << endl;
	}
	
getch();
return 0;
}

/*
	Nama	 : Giri Prahasta Putra
	Kelas	 : C1
	NIM		 : 1000231
	Tanggal	 : 4 Februari 2011
	-------------------------
	Program  : Penghitung luas bangun prisma bertutup limas
	Versi	 : 0.83
	Deskripsi: User memasukkan panjang sisi, tinggi prisma,
			   dan tinggi limas kemudian diberikan hasil luas
*/

#include <stdio.h>
#include <math.h>

//mendeklarasikan fungsi yang digunakan
 float tinggiSegitigaAlas(int nSisi, float sisiP);
 float luasAlas(float nSisi, float sisiP, float tinggiSegitigaAlas);
 float luasSelimutPrisma(float nSisi, float sisiP, float tinggiPrisma);
 float luasLimas(float nSisi, float sisiP, float tinggiLimas, float tinggiSegitigaAlas);

//fungsi utama ----------------------------------------------------------------
int main(){

	/*
	  DEKLARASI VARIABEL
	  Variabel diinisialisasi nilai dibawah kritis
	  agar terjadi perulangan jika user tidak memasukkan
	  nilai yang sesuai
	  
	  nSisi, 		banyak sisi bangun harus  >= 3
	  sisiP,	 	besar sisi bangun harus   >= 0
	  tinggiPrisma, besar tinggi prisma harus >= 0
	  tinggiLimas,  besar tinggi limas harus  >= 0
	 */
	int   nSisi 		=  0; 	//deklarasi variabel banyak sisi
	float sisiP 		= -1; 	//deklarasi variabel besar panjang sisi
	float tinggiPrisma	= -1;	//deklarasi variabel besar tinggi prisma
	float tinggiLimas	= -1;	//deklarasi variabel besar tinggi limas
	
	float _tinggiSegitigaAlas;  //deklarasi variabel panjang tinggi segitiga
	float _luasAlas;			//deklarasi variabel besar luas alas
	float _luasSelimut;			//deklarasi variabel besar luas selimut
	float _luasLimas;			//deklarasi variabel besar luas limas
	float _luasTotal;			//deklarasi variabel jumlah luas total
	
	//Meminta user memasukkan banyak sisi
		while (nSisi < 3) { //memaksa user memasukkan sisi >= 3
			printf("Masukkan banyaknya sisi yang digunakan (>=3) : ");
			scanf("%d", &nSisi);
			
			if(nSisi < 3) {
				printf("Banyak sisi harus >= 3\n");
			}
		}
	
	//Meminta user memasukkan besar panjang sisi
		while (sisiP < 0) { //memaksa user memasukkan panjang sisi >= 0
			printf("Masukkan besar panjang sisi            (>=0) : ");
			scanf("%f", &sisiP);
			if(sisiP < 0) {
				printf("Besar panjang sisi harus >= 0\n");
			}
		}
	
	//Meminta user memasukkan besar tinggi prisma
		while (tinggiPrisma < 0) { //memaksa user memasukkan tinggi prisma >= 0
			printf("Masukkan besar tinggi prisma           (>=0) : ");
			scanf("%f", &tinggiPrisma);
			if(tinggiPrisma < 0) {
				printf("Besar tinggi prisma harus >=0\n");
			}
		}
	//Meminta user memasukkan besar tinggi limas
		while (tinggiLimas < 0) { //memaksa user memasukkan tinggi limas >=0
			printf("Masukkan besar tinggi limas            (>=0) : ");
			scanf("%f", &tinggiLimas);
			if(tinggiLimas < 0){
				printf("Besar tinggi limas harus >=0\n");
			}
		}
	//Memproses masukkan user
		_tinggiSegitigaAlas = tinggiSegitigaAlas(nSisi, sisiP); 						 //menghitung tinggi segitiga satuan
		_luasAlas 			= luasAlas(nSisi, sisiP, _tinggiSegitigaAlas); 				 //menghitung luas alas bangun
		_luasSelimut 		= luasSelimutPrisma(nSisi, sisiP, tinggiPrisma); 			 //menghitung luas selimut prisma
		_luasLimas			= luasLimas(nSisi, sisiP, tinggiLimas, _tinggiSegitigaAlas); //menghitung luas tutup berbentuk limas
		_luasTotal			= _luasAlas + _luasSelimut + _luasLimas;					 //menjumlah luas setiap bagian
		
	//Menampilkan hasil perhitungan
	printf("luas alas         : %.3f\n",_luasAlas);
	printf("luas selimut      : %.3f\n",_luasSelimut);
	printf("luas limas        : %.3f\n",_luasLimas);
	printf("luas total bangun : %.3f\n",_luasTotal);
	
	return 1; //mengembalikan nilai lemparan
}


//menghitung tinggi segitiga satuan -------------------------------------------
/**
 *	Untuk menghitung bangun poligon diperlukan tinggi
 *	segitiga satuan.
**/

float tinggiSegitigaAlas(int nSisi, float sisiP){
	//deklarasi variabel
	 float derP;	//deklarasi variabel sudut pusat
	 float derB;	//deklarasi variabel sudut bawah
	 float sisiB;	//deklarasi variabel sisi kaki
	 float tinggi;	//deklarasi variabel tinggi
	
	/*
	 *	Satu buah poligon terdiri dari beberapa segitiga
	 *	yang disusun. Untuk mengetahui besar sudut puncak
	 *	segitiga satuan dilakukan dengan membagi
	 *	360 derajat sejumlah banyaknya sisi yang digunakan
	 */
	 	derP = 360/nSisi; //menghitung besar sudut pusat
	
	/*
	 *	Satu buah segitiga memiliki besar sudut 180 derajat. Dikarenakan
	 *	satu buah segitiga penyusun pada poligon adalah segitiga sama kaki
	 *	maka sudutnya sama. Untuk mengetahui salah satu sudutnya dengan
	 *	mengurangi 180 dengan sudut pusat kemudian dibagi dua.
	 */
		 derB = (180-derP)/2; //menghitung besar sudut kaki segitiga sama kaki
	
	/*
	 *	Untuk menggunakan fungsi sin di bahasa C harus berupa masukan
	 *	dalam satuan radian. Untuk mempermudah maka derajat yang ada
	 *	dibagi dengan 57.3 (atau 180/pi)
	 */
	 	derB = derB/57.3; //mengkonversi derajat pusat menjadi radian
	 	derP = derP/57.3; //mengkonversi derajat kaki menjadi radian

	/*
	 *	Setelah mengetahui besar sudut dua titik (titik pusat dan
	 *	titik kaki) dan panjang satu sisi (sisiP) maka sisi kaki (sisiB)
	 *	dapat dicari dengan persamaan sin
	 */
		sisiB = (sisiP*sin(derB))/sin(derP); //menghitung panjang sisi kaki segitiga sama kaki

	/*
	 *	Setelah didapat panjang semua sisi dapat dicari tinggi segitiga
	 *	dengan menggunakan teorema Pythagoras.
	 */
		tinggi = sqrt((sisiB*sisiB)-((sisiP/2)*(sisiP/2))); //menghitung tinggi segitiga dengan teorema Pythagoras

	return tinggi; //mengembalikan nilai fungsi

}


//menghitung luas alas bangun -------------------------------------------------
/**
 *	Untuk menghitung luas alas menggunakan segitiga sama kaki
 *	dikarenakan poligon yang menjadi alas terdiri dari segitiga-segitiga
 *	yang disusun melingkar. Konsepnya untuk mencari luas dengan
 *	menghitung luas sebuah segitiga tersebut kemudian dikalikan sebanyak
 *	sisi yang dicari.
**/
float luasAlas(float nSisi, float sisiP, float tinggiSegitigaAlas){
	//deklarasi variabel
	 float luas;

		luas = (sisiP * tinggiSegitigaAlas)/2; //menghitung luas sebuah segitiga
		luas = luas * nSisi; 				   //menghitung luas poligon dari gabungan segitiga

	return luas; 					 		 //mengembalikan nilai fungsi
}


//menghitung luas selimut bangun ----------------------------------------------
/**
 *	Untuk menghitung selimut bangun menggunakan persegi panjang karena
 *	selimut terdiri dari persegi panjang yang tersusun mengeliling dengan lebar
 *	berupa sisiP dan panjang berupa tinggiPrisma. Konsepnya untuk
 *	mencari luas dengan menghitung luas sebuah persegi panjang
 *	kemudian dikalikan sebanyak sisi yang dicari.
**/
float luasSelimutPrisma(float nSisi, float sisiP, float tinggiPrisma){
	
	//deklarasi variabel
	 float luas;
	
		luas = sisiP * tinggiPrisma;  //menghitung luas sebuah persegi panjang
		luas = luas * nSisi; 		  //menghitung luas selimut dari gabungan persegi panjang
	
	return luas;  					  //mengembalikan nilai fungsi
}


//menghitung luas tutup bangun
/*
	Untuk menghitung tutup bangun berupa limas dengan menggunakan
	segitiga karena limas terdiri dari segitiga yang tersusun mengeliling.
	Konsep untuk mencari luas limas dengan menghitung luas sebuah segitiga
	kemudian dikalikan sebanyak sisi yang dicari.
*/
float luasLimas(float nSisi, float sisiP, float tinggiLimas, float tinggiSegitigaAlas){
	//deklarasi variabel
	 float luas;
	 float tinggiSegitigaLimas;
	 
	/*
	 *	Untuk menghitung luas segitiga penyusun limas diperlukan tinggi segitiga limas.
	 *	Tinggi satu segitiga penyusun bangun limas didapatkan dari
	 *	mengakarkan kuadrat tinggi limas ditambah kuadrat jarak setengah
	 *  alas segitiga ke titik pusat (tinggiSegitigaAlas)
	 */
	 	tinggiSegitigaLimas = sqrt((tinggiSegitigaAlas*tinggiSegitigaAlas)+(tinggiLimas*tinggiLimas)); //mencari tinggi segitiga limas dengan teorema pythagoras
	
	 	luas = (sisiP * tinggiSegitigaLimas)/2; //menghitung luas sebuah segitiga
	 	luas = luas * nSisi;					//menghitung luas limas dari gabungan segitiga
	 	
	return luas;								//mengembalikan nilai fungsi
}

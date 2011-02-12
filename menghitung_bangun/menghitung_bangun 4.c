/*
	Nama	 : Giri Prahasta Putra
	Kelas	 : C1
	NIM		 : 1000231
	Tanggal	 : 4 Februari 2011
	
	Program  : Penghitung luas bangun prisma bertutup limas
	Deskripsi: User memasukkan panjang sisi, tinggi prisma,
			   dan tinggi limas kemudian diberikan hasil luas
*/


#include <stdio.h>
#include <math.h>

//mendeklarasikan fungsi yang digunakan
float tinggiSegitiga(int nSisi, float sisiP);
float luasAlas(float nSisi, float sisiP, float tinggiSegitiga);
float luasSelimutPrisma(float nSisi, float sisiP, float tinggiPrisma);


//fungsi utama ----------------------------------------------------------------
int main(){
	int nSisi; 				//deklarasi variabel banyak sisi
	float sisiP; 			//deklarasi variabel besar sisi
	float tinggiPrisma;		//deklarasi variabel besar tinggi prisma
	float _tinggiSegitiga;  //deklarasi variabel panjang tinggi segitiga
	float _luasAlas;		//deklarasi variabel besar luas alas
	float _luasSelimut;		//deklarasi variabel besar luas selimut
	
	//Meminta user memasukkan banyak sisi
	printf("Masukkan banyaknya sisi yang digunakan : ");
	scanf("%d", &nSisi);
	
	//Meminta user memasukkan besar panjang sisi
	printf("Masukkan besar panjang sisi : ");
	scanf("%f", &sisiP);
	
	//Meminta user memasukkan besar tinggi prisma
	printf("Masukkan besar tinggi prisma : ");
	scanf("%f", &tinggiPrisma);
	
	_tinggiSegitiga = tinggiSegitiga(nSisi, sisiP); //menghitung tinggi segitiga satuan
	_luasAlas 		= luasAlas(nSisi, sisiP, _tinggiSegitiga); //menghitung luas alas bangun
	_luasSelimut 	= luasSelimutPrisma(nSisi, sisiP, tinggiPrisma); //menghitung luas selimut prisma
	
	printf("luas alas :%f",_luasAlas);
	printf("luas selimut:%f",_luasSelimut);
}



//menghitung tinggi segitiga satuan -------------------------------------------
/*
	Untuk menghitung bangun poligon diperlukan tinggi
	segitiga satuan.
*/

float tinggiSegitiga(int nSisi, float sisiP){
	//deklarasi variabel
	 float derP;	//deklarasi variabel sudut pusat
	 float derB;	//deklarasi variabel sudut bawah
	 float sisiB;	//deklarasi variabel sisi kaki
	 float tinggi;	//deklarasi variabel tinggi
	
	/*
		Satu buah poligon terdiri dari beberapa segitiga
		yang disusun. Untuk mengetahui titik pusatnya dengan membagi
		360 derajat dengan banyaknya sisi yang digunakan
	*/
	 derP = 360/nSisi; //menghitung besar sudut pusat (puncak segitiga dari satu bagian segitiga poligon alas)
	
	/*
		Satu buah segitiga memiliki besar sudut 180 derajat. Dikarenakan
		satu buah satuan segitiga pada poligon adalah segitiga sama kaki
		maka sudutnya sama. Untuk mengetahui salah satu sudutnya dengan
		mengurangi 180 dengan sudut pusat kemudian dibagi dua.
	*/
	 derB = (180-derP)/2; //menghitung besar sudut kaki segitiga sama kaki
	
	/*
		Untuk menggunakan fungsi cos dan sin di bahasa C harus berupa masukan
		dalam satuan radian. Untuk mempermudah maka derajat yang ada
		dibagi dengan 57.3 (atau 180/pi)
	*/
	 derB = derB/57.3; //mengkonversi derajat pusat menjadi radian
	 derP = derP/57.3; //mengkonversi derajat kaki menjadi radian

	/*
		Setelah mengetahui besar sudut dua titik (titik pusat dan
		titik kaki) dan panjang satu sisi (sisiP) maka sisi kaki (sisiB)
		dapat dicari dengan persamaan sin
	*/
	sisiB = (sisiP*sin(derB))/sin(derP); //menghitung panjang sisi kaki segitiga sama kaki

	/*
		Setelah didapat panjang semua sisi dapat dicari tinggi segitiga
		dengan menggunakan teorema Pythagoras.
	*/
	tinggi = sqrt((sisiB*sisiB)-((sisiP/2)*(sisiP/2))); //menghitung tinggi segitiga dengan teorema Pythagoras

	return tinggi; //mengembalikan nilai fungsi

}



//menghitung luas alas bangun -------------------------------------------------
/*
	Untuk menghitung luas alas menggunakan segitiga sama kaki.
	Dikarenakan poligon yang menjadi alas terdiri dari segitiga-segitiga
	yang disusun melingkar. Konsepnya untuk mencari luas dengan
	menghitung luas sebuah segitiga tersebut kemudian dikalikan sebanyak
	sisi yang dicari.
*/
float luasAlas(float nSisi, float sisiP, float tinggiSegitiga){
	//deklarasi variabel
	 float luas;

	luas = (sisiP*tinggiSegitiga)/2; //menghitung luas sebuah segitiga
	luas = luas*nSisi; //menghitung luas poligon dari gabungan segitiga

	return luas; //mengembalikan nilai fungsi
}



//menghitung luas selimut bangun ----------------------------------------------
/*
	Untuk menghitung selimut bangun menggunakan persegi panjang.
	Selimut terdiri dari persegi panjang yang tersusun dengan lebar
	berupa sisiP dan panjang berupa tinggiPrisma. Konsepnya untuk
	mencari luas dengan menghitung luas sebuah persegi panjang
	kemudian dikalikan sebanyak sisi yang dicari.
*/
float luasSelimutPrisma(float nSisi, float sisiP, float tinggiPrisma){
	
	//deklarasi variabel
	 float luas;
	
	luas = sisiP*tinggiPrisma; //menghitung luas sebuah persegi panjang
	luas = luas*nSisi; //menghitung luas selimut dari gabungan persegi panjang
	
	return luas;  //mengembalikan nilai fungsi
}
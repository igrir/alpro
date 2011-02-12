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

//menginisialisasi fungsi-fungsi yang digunakan
float luasAlas(float nSisi, float sisiP);
float luasSelimutPrisma(float nSisi, float sisiP, float tinggiPrisma);


int main(){

	//deklarasi variabel
	 int nSisi; //deklarasi banyaknya sisi
	 float sisiP; //deklarasi besar panjang sisi
	 float tinggiPrisma; //deklarasi tinggi prisma
	 float tinggiLimas;  //deklarasi tinggi limas
	 
	printf("%f",luasAlas(6,1));
	printf("%f",simpananTinggi);
	return 1;
}

//menghitung luas alas bangun
/*
	Untuk menghitung luas alas menggunakan segitiga sama kaki.
	Dikarenakan poligon yang menjadi alas terdiri dari segitiga-segitiga
	yang disusun melingkar. Konsepnya untuk mencari luas dengan
	menghitung luas sebuah segitiga tersebut kemudian dikalikan sebanyak
	sisi yang dicari.
*/
float luasAlas(float nSisi, float sisiP){
	
	//deklarasi variabel
	 float derP;
	 float derB;
	 float sisiB;
	 float tinggiSegitiga;
	 float luas;
	
	derP = 360/nSisi; //menghitung besar sudut pusat (puncak segitiga dari satu bagian segitiga poligon alas)
	
	derB = (180-derP)/2; //menghitung besar sudut kaki segitiga sama kaki
	
	derB = derB*57.3; //mengkonversi derajat pusat menjadi radian
	derP = derP*57.3; //mengkonversi derajat kaki menjadi radian
	
	sisiB = (sisiP*sin(derB))/sin(derP); //menghitung panjang sisi kaki segitiga sama kaki
	
	tinggiSegitiga = sqrt((sisiB*sisiB)-((sisiP/2)*(sisiP/2))); //menghitung tinggi segitiga dengan teorema Pythagoras
	
	luas = (sisiP*tinggiSegitiga)/2; //menghitung luas sebuah segitiga
	
	luas = luas*nSisi; //menghitung luas poligon dari gabungan segitiga

	return luas;
}


//menghitung luas selimut bangun
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
}

//menghitung luas tutup bangun
/*
	Untuk menghitung tutup bangun berupa limas dengan menggunakan
	segitiga. Limas terdiri dari segitiga yang tersusun. Konsepnya untuk
	mencari luas dengan menghitung luas sebuah segitiga kemudian
	dikalikan sebanyak sisi yang dicari
*/
float luasLimas(float nSisi, float sisiP, float tinggiLimas){
	//deklarasi variabel
	 float derP;
	 float derB;
	 float sisiB;
	 float tinggiSegitiga;
	 float luas;
	
	derP = 360/nSisi; //menghitung besar sudut pusat (puncak segitiga dari satu bagian segitiga poligon alas)
	
	derB = (180-derP)/2; //menghitung besar sudut kaki segitiga sama kaki
	
	derB = derB*57.3; //mengkonversi derajat pusat menjadi radian
	derP = derP*57.3; //mengkonversi derajat kaki menjadi radian
	
	sisiB = (sisiP*sin(derB))/sin(derP); //menghitung panjang sisi kaki segitiga sama kaki
	
	tinggiSegitiga = sqrt((sisiB*sisiB)-((sisiP/2)*(sisiP/2))); //menghitung tinggi segitiga dengan teorema Pythagoras

	return luas;
}

/*
Menghitung bangun
*/


#include <stdio.h>
#include <math.h>

int main(){
	printf("%f",tinggiSegitiga(6,5));
}

//menghitung tinggi segitiga satuan

/*
	Untuk menghitung bangun poligon diperlukan tinggi
	segitiga satuan.
*/

float tinggiSegitiga(float nSisi, float sisiP){
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
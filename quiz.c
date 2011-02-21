/*
Nama		: Giri Prahasta Putra
NIM			: 1000231
Kelas		: C1
Program		: Pembulatan uang ke atas
Keterangan	: Ada yang 25, 50, 100. Uang akan dibulatkan ke pecahan ke atas
*/

int main(){
	//Deklarasi variabel
	int uang;			//variabel untuk memasukkan input uang
	int pembulatan;		//variabel untuk uang sisa yang kurang pada pembulatan
	int dibulatkan;		//variabel untuk uang tambahan yang dibulatkan
	int hasil;			//variabel untuk jumlah uang yang telah dibulatkan
	
	int rts_rbu=0;		//variabel untuk menampilkan banyak ratusan ribu dipakai
	int plh_rbu=0;		//variabel untuk menampilkan banyak puluhan ribu dipakai
	int rbu=0;			//variabel untuk menampilkan banyak ribuan dipakai
	int rts=0;			//variabel untuk menampilkan banyak ratusan dipakai
	int plh=0;			//variabel untuk menampilkan banyak puluhan dipakai
	int stu=0;			//variabel untuk menampilkan banyak satuan dipakai
	
	printf("Masukkan jumlah uang yang akan dibulatkan : ");
	scanf("%d",&uang);
	
	pembulatan = uang%100;	//menghitung uang tersisa yang belum dibulatkan
	
	if (pembulatan > 0 && pembulatan < 25){			//pembulatan jika uang mendekati 25 rupiah
		dibulatkan = 25-pembulatan;
		hasil	   = uang+dibulatkan;
	}else if(pembulatan > 25 && pembulatan <50){	//pembulatan jika uang mendekati 50 rupiah
		dibulatkan = 50-pembulatan;
		hasil	   = uang+dibulatkan;
	}else if(pembulatan > 50 && pembulatan <75){	//pembulatan jika uang mendekati 75 rupiah
		dibulatkan = 75-pembulatan;
		hasil	   = uang+dibulatkan;
	}else if(pembulatan > 75 && pembulatan < 100){	//pembulatan jika uang mendekati 100 rupiah
		dibulatkan = 100-pembulatan;
		hasil	   = uang+dibulatkan;
	}else{											//mengembalikan nilai jika tidak ada yang dibulatkan
		hasil	   = uang;
	}
	
	rts_rbu = (hasil/100000);																//mencari banyak ratusan ribu yang dipakai
	plh_rbu = (hasil/10000)-rts_rbu*10;														//mencari banyak puluhan ribu yang dipakai
	rbu 	= (hasil/1000)-((plh_rbu*10)+(rts_rbu*100));									//mencari banyak ribuan yang dipakai
	rts 	= (hasil/100)-((rbu*10)+(plh_rbu*100)+(rts_rbu*1000));							//mencari banyak ratusan yang dipakai
	plh 	= (hasil/10)-((rts*10)+(rbu*100)+(plh_rbu*1000)+(rts_rbu*10000));				//mencari banyak puluhan yang dipakai
	stu 	= (hasil/1)-((plh*10)+(rts*100)+(rbu*1000)+(plh_rbu*10000)+(rts_rbu*100000));	//mencari banyak satuan yang dipakai
	
	printf("Uang yang telah dibulatkan adalah %d\n", hasil);	//memberikan nilai dari hasil pembulatan
	
	//memberikan satuan uang yang diberikan
	printf("%d Ratusan Ribu\n",rts_rbu);		//memberikan banyak ratusan ribu yang diberikan
	printf("%d Puluhan Ribu\n",plh_rbu);		//memberikan banyak ratusan ribu yang diberikan
	printf("%d Ribu\n",rbu);					//memberikan banyak ratusan ribu yang diberikan
	printf("%d Ratusan\n",rts);					//memberikan banyak ratusan ribu yang diberikan
	printf("%d Puluhan\n",plh);					//memberikan banyak ratusan ribu yang diberikan
	printf("%d Satuan\n",stu);					//memberikan banyak ratusan ribu yang diberikan
	
	
	return 0;
}

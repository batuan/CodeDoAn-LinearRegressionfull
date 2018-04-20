#include <iostream>6
#include<conio.h>
#include <armadillo>
#include"linearRegression .h"
using namespace std;
using namespace arma;

// Armadillo documentation is available at:
// http://arma.sourceforge.net/docs.html

int
main(int argc, char** argv)
  {
	mat ketquasoxo;
	ketquasoxo.load("w.txt", arma_ascii);
	mat thamSo1 = ketquasoxo.col(1);
	mat thamSo2 = ketquasoxo.cols(1,2);
	mat thamSo3 = ketquasoxo.cols(1, 3);
	mat thamSo4 = ketquasoxo.cols(1, 4);
	mat thamSo5 = ketquasoxo.cols(1, 5);
	//cout << thamSo5;
	//cout << ketquasoxo<<endl;
	//cout << X1;
	mat Y = ketquasoxo.col(2);
	mat heSo1 = LinearRegreeOne(thamSo1, Y);
	mat heSo2 = LinearRegreeOne(thamSo2, ketquasoxo.col(3));
	mat heSo3 = LinearRegreeOne(thamSo3, ketquasoxo.col(4));
	mat heSo4 = LinearRegreeOne(thamSo4, ketquasoxo.col(5));
	mat heso5 = LinearRegreeOne(thamSo5, ketquasoxo.col(6));
	mat conSoMayMan = ones(2,1) ;
	double x;
	ketquasoxo(0, 0);
	cout << "nhap vao con so may man" << endl;
	cin >> x;
	conSoMayMan(1, 0) = x;
	//cout << heSo2;
	mat ketqua =  KetQuaTraVe(heSo1, conSoMayMan);
	conSoMayMan = join_cols(conSoMayMan, ketqua);
	ketqua = KetQuaTraVe(heSo2, conSoMayMan);
	conSoMayMan = join_cols(conSoMayMan, ketqua);
	ketqua = KetQuaTraVe(heSo3, conSoMayMan);
	conSoMayMan = join_cols(conSoMayMan, ketqua);
	ketqua = KetQuaTraVe(heSo4, conSoMayMan);
	conSoMayMan = join_cols(conSoMayMan, ketqua);
	ketqua = KetQuaTraVe(heso5, conSoMayMan);
	conSoMayMan = join_cols(conSoMayMan, ketqua);
	//cout << conSoMayMan;
	cout << "Day so ban nen danh ngay hom nay la:"<<endl;
	cout << (int)conSoMayMan(1, 0)<<" "<<(int) conSoMayMan(2,0)<< " " << (int)conSoMayMan(3, 0)<< " " << (int)conSoMayMan(4, 0)<< " " << (int)conSoMayMan(5, 0)<< " " << (int)conSoMayMan(6, 0)<<endl;
	getch();
	return 0;
	
  }



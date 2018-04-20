#include<armadillo>
#include<iostream>
using namespace std;
using namespace arma;

mat LinearRegreeOne(mat X, mat Y) {
	vec one = ones(X.n_rows);
	mat Xbar = join_rows(one, X);
	mat A = Xbar.t()*Xbar;
	mat b = Xbar.t() * Y;
	mat w = pinv(A) * b;
	return w;
}

mat KetQuaTraVe(mat thamSo, mat conSo) {
	
	mat t = thamSo.t()*conSo;
	mat t_moi = zeros(1,1);
	t_moi(0, 0) = t(0, 0);
	//conSo = join_cols(conSo, t);
	//cout << conSo;
	return t_moi;
}
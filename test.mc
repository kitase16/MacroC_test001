#include <stdio>
#include <string>

#define Num 10

let Fib(N){
	return Fib(N, 0, 1);
}

let Fib(N, A, B){
	let C = A+B;
	if (B > N) {
		return B;
	}
	else {
		return Fib(N,B, C);
	}
}

let print(String X){
	for (let i = 0; i < X.strlen(); i++) {
		put X[i];//put one ascii or number
	}
}

let ToString(N){
	let S = "";
	while (N > 0) {
		let D = N % 10;
		S = char(D + 48) + S;//48 is ascii for '0'
		N = N / 10;
	}
	return S;
}


let main() {
	print(10.Fib().ToString());
	return 0;
}
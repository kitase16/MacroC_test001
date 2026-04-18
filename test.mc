#include <stdio>
#include <string>

//navigation: C with classes and lambada functions awaits you. on and complile to move? i dont know. so C++ aka. C with Classes, AWAITS YOU!

//this is a test file for the new features of the language. it includes classes, lambada functions, and string manipulation.
//the main function is at the bottom, and it prints the 10th Fibonacci number as a string.
//the Fibonacci function is implemented using recursion, and the ToString function converts an integer to a string.
//the output of this program should be "55", which is the 10th Fibonacci number.
//note: the Fib function is implemented using tail recursion, which is optimized by the compiler to avoid stack overflow.
//also note: the Add function is a lambada function that takes two integers and returns their sum. it is not used in the main function, but it is included to demonstrate the syntax of lambada functions.
//the syntax of the language is similar to C, but with some differences. for example, the Fib function is defined using the "let" keyword, and the main function is defined using the "main" keyword. also, the print function is defined using a loop to print each character of the string, instead of using a built-in function like printf.
//the purpose of this test file is to demonstrate the new features of the language and to ensure that they are working correctly. it is not meant to be a complete program, but rather a test case for the new features. if the program compiles and runs successfully, it should print "55" to the console.
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

let Add = lambada(A, B) {
	return A + B;
}

let main() {
	print(10.Fib().ToString());
	return 0;
}
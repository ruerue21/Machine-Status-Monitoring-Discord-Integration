/* T07: Algorithmic Efficiency Explorer
This program is designed to explore big O notion and algorithms
by Dr. Jan Pearce of Berea College
Licensed under a Creative Commons Attribution,
Share Alike 3.0 United States License */

#include <iostream>
#include <cmath>

using namespace std;

int looponconstant1(int n) {
	/*  demonstrates O(1) behavior
	pre: n is positive integer
	post: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < 1; i++) {
		count++; // # this line executes
	}
	return (count);
}

int looponconstant4(int n) {
	/* demonstrates O(1) behavior
	pre: n is a positive integer
	post: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < 4; i++) {
		count++; // # this line executes
	}
	return (count);
}

int loopn(int n) {
	/* demonstrates O(n) behavior
	pre:  n is a positive integer
	post:  returns count # iterations */

	int count = 0;
	for (int i = 0; i < n; i++) {
		count++; // # this line executes
	}
	return (count);
}

int sequential(int n) {
	/* demonstrates O(n) behavior
	pre: n is positive integer
	post: returns count # iterations */
	int count = 0;
	for (int i = 0; i < n; i++) {
		count++; //this # iterations
	}
	for (int i = 0; i < n; i++) {
		count++;	//plus this # iterations
	}
	return (count);
}

int nestedconstant(int n) {
	/* demonstrates O(n) behavior
	pre:  n is a positive integer
	post: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			count++;  // # this line executes
		}
	}
	return (count);
}

int twonested(int n) {
	/* demonstrates O(n**2) behavior
	pre:  n is positive integer
	pot: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count++;  // # this line executes		
		}
	}
	return (count);
}

int threenested(int n) {
	/* threenested demonstrates O(n**3) behavior
	pre:  n is a positive integer
	post: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				count++;  // # this line executes				
			}
		}
	}
	return (count);
}

int powern(int n) {
	/* powern demonstrates O(2**n)) behavior
	pre: n is a positive integer
	pot: returns count # iterations*/

	int count = 0;
	for (int i = 0; i < pow(2, n); i++) {
		count++; // # this line executes
	}
	return (count);
}

int halving(int n) {
	/*  demonstrates O(log(int n)) behavior
	pre:  n is a positive integer
	pot: returns count # iterations*/

	int count = 0;
	int loopcounter = n;
	while (loopcounter > 1) {
		count++;  // # this line executes
		loopcounter = loopcounter / 2; // integer division
	}
	return (count);
}

int loopincrementn(int n) {
	/* demonstrates O(n) behavior
	pre:  n is a positive integer
	post: returns count # iterations */

	int count = 0;
	int s = 10;
	int add = 2;
	for (int i = s; i < n; i = i + add) {
		count++; // # this line executes
		// cout << count << endl;
	}
	return (count);
}

int main() {
	int n;
	cout << "\nPlease enter n: ";
	cin >> n;

	while (n > 0) {
		// execution based on # inputs
		cout << "\nfor n = " << n << ":" << endl;
		cout << "\tlooponconstant1(" << n << ") = " << looponconstant1(n) << endl;
		cout << "\tlooponconstant4(" << n << ") = " << looponconstant4(n) << endl;
		cout << "\tloopn(" << n << ") = " << loopn(n) << endl;
		cout << "\tsequential(" << n << ") = " << sequential(n) << endl;
		cout << "\tnestedconstant(" << n << ") = " << nestedconstant(n) << endl;
		cout << "\ttwonested(" << n << ") = " << twonested(n) << endl;
		cout << "\tthreenested(" << n << ") = " << threenested(n) << endl;
		cout << "\tpowern(" << n << ") = " << powern(n) << endl;
		cout << "\thalving(" << n << ") = " << halving(n) << endl;
		cout << "\tloopincrementn(" << n << ") = " << loopincrementn(n) << endl;

		cout << "\nPlease enter another n: ";
		cin >> n;
	}\
		return 0;
}

#include <iostream> 
using namespace std;

template <class A> 

A addCrap(A a, A b){
	return a+b;
}

int main(){ 

	int x = 7, y = 43, z;
	z= addCrap(x,y);
	
	double d1 = 33.6, d2 = 21.9, d3;
	d3 = addCrap(d1,d2);
	
	char c1 = 'A', c2 = 5, c3;
	c3 = addCrap(c1,c2);
	
	cout << z << endl;
	cout << d3<< endl;
	cout << c3 << endl;
	
	return 0;
}
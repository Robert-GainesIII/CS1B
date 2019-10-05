#include <iostream> 
using namespace std;

template <class T>

class Bobby{
	
	T first, second;
	public:
	Bobby(T a, T b){
		first = a;
		second = b;
	}
	T bigger();
};

template <class T>
T Bobby<T>::bigger(){
	return (first > second ? first : second);
}

int main(){
	
	Bobby <int> bob(69, 105);
	cout << bob.bigger(); 
}
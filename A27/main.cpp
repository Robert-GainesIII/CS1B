#include <iostream> 
using namespace std;

template <class T>

class Chunky{
	
	public:
	Chunky(T x){
		cout << x << " is not a character!" << endl;
	}
	
};

template <>
class Chunky<char>{
	public: 
	Chunky(char x){
		cout << x << " is indeed a character!" << endl;
	}
};

int main(){
	
	Chunky <int> obj1(7);
	Chunky <double> obj2(3.154);
	Chunky <char> obj3('q');
}
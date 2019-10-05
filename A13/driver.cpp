#include "creditCardType.h" 

int main(){
	
	cout << "credit Card Count: " << creditCardType::getCardCount() << endl;
	cout << "current Balance: " << creditCardType::getBalance() << endl;
	
	creditCardType bobs("bobs");
	
	bobs.purchase(200);
	
	creditCardType davinas("davina's" , "2440 2455 2111 4350");
	
	davinas.purchase(1000);
	
	creditCardType ours("Joint Checking Account", "3532 0253 2435 0324", "02/23");
	
	ours.purchase(10000);
	

	
	

	
	return 0;
}
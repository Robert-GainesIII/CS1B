#include "serendipity.h"
int bookType::bookCount = 0; 
int bookType::DBSIZE = 0;
/*
SETTERS
*/

	bookType::bookType(){
		
	}
	
	bookType::bookType(string title, string isbn, string author, string publisher, string date, int qty, double wholesale, double retail, int index){
		setBookTitle(title);
		setISBN(isbn);
		setAuthor(author);
		setPublisher(publisher);
		setDateAdded(date);
		setQtyOnHand(qty);
		setWholesale(wholesale);
		setRetail(retail);
		setIndex(index);
	}

	void bookType::setBookTitle(string newBookTitle){
		bookTitle = newBookTitle;
	}
	void bookType::setISBN(string newISBN){
		isbn = newISBN;
	}
	void bookType::setAuthor(string newAuthor){
		author = newAuthor;
	}
	void bookType::setPublisher(string newPublisher){
		publisher = newPublisher;
	}
	void bookType::setDateAdded(string newDateAdded){
		dateAdded = newDateAdded;
		string m = dateAdded.substr(0,2);
		string d= dateAdded.substr(3,5);
		string y = dateAdded.substr(6,9);
		month = atoi( m.c_str() );
		day = atoi( d.c_str() );
		year = atoi( y.c_str() );
	}
	void bookType::setQtyOnHand(int newQtyOnHand){
		qtyOnHand = newQtyOnHand;
	}
	void bookType::setWholesale(float newWholesale){
		wholesale = newWholesale;
	}
	void bookType::setRetail(float newRetail){
		retail = newRetail;
	}

	void bookType::incBookCount(){
		bookCount++;
	}

	void bookType::decBookCount(){
		bookCount--;
	}
/*
GETTERS
*/	
	
	string bookType::getBookTitle() const{
		return bookTitle;
	}
	string bookType::getISBN() const{
		return isbn;
	}
	string bookType::getAuthor()const{
		return author;
	}
	string bookType::getPublisher()const{
		return publisher;
	}
	string bookType::getDateAdded()const{
		return dateAdded;
	}
	int bookType::getQtyOnHand()const{
		return qtyOnHand;
	}
	double bookType::getWholesale()const{
		return wholesale;
	}
	double bookType::getRetail()const{
		return retail;
	}
	int bookType::getBookCount(){
		return bookCount;
	}
	 int bookType::getDBSIZE(){
		return DBSIZE;
	}

	void bookType::print(){
		cout << setfill(' ');
		system("cls");
		cout << setw(100) << right << "Serendipity BookSellers" << endl;
		cout << setw(100/4) << "Book Information" << endl;
		cout << "ISBN:" << isbn << endl;
		cout << "Title:" << bookTitle << endl;
		cout << "Author:" << author << endl;
		cout << "Publisher:" << publisher << endl;
		cout << "Date Added:" << dateAdded << endl;
		cout << "Quantity-On-Hand:" << qtyOnHand << endl;
		cout << "Wholesale Cost:" << wholesale << endl;
		cout << "Retail Price:" << retail << endl;
		system("pause");
	}
	bool bookType::equals(bookType book){
		return false;
	}
	
	
	void bookType::setIndex(int a){
		index = a;
	}
	
	int bookType::getIndex()const{
		return index;
	}

	int bookType::getSortCode()const{
		return sortcode;
	}
	
	void bookType::setSortCode(int a){
		sortcode = a;
	}
	
	void bookType::addToCheckoutTotal(int a){
		checkoutTotal+= a;
	}
	
	int bookType::getCheckoutTotal()const{
		return checkoutTotal;
	}
	
	void bookType::setDBSize(int dbsize){
		DBSIZE = dbsize;
	}
	
	
	
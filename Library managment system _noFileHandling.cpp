#include<iostream>
using namespace std;

struct Book {
	string title;
	string author;
	string publicationName;
	string bookID;
	int price;
	int quantity;
};
int numberOfBooks = 0;
Book listOfBooks[100];
string password = "password";

void getData();
void show(int);
void showAll();
int search();
void issue();
void deleteBook();
void libraryTeacher();
void libraryStudent();
void startProgram();
void update();

int currentlyShowing = 0;

int main() {
	while (true){
		if (currentlyShowing == 0)
			startProgram();
		if (currentlyShowing == 1)
			libraryStudent();
		if (currentlyShowing == 2)
			libraryTeacher();
	}
}

void getData() {
	Book b1;
	cout<<"Enter book details"<<endl;
	cout<<"Enter title of book: ";
	cin.ignore();
	getline(cin, b1.title);
	cout<<"Enter author name of book: ";
	getline(cin, b1.author);
	cout<<"Enter publication name of book: ";
	getline(cin, b1.publicationName);
	cout<<"Enter ID of book: ";
	getline(cin, b1.bookID);
	cout<<"Enter price of book: ";
	cin>>b1.price;
	cout<<"Enter quantity of book: ";
	cin>>b1.quantity;
	
	listOfBooks[numberOfBooks++] = b1;
}

void show(int i) {
	if (listOfBooks[i].title == "DELETED")
		return;
	cout<<"\nBook Title : "<<listOfBooks[i].title<<endl;
    cout<<"\nBook's Author Name : "<<listOfBooks[i].author<<endl;
    cout<<"\nBook's ID : "<<listOfBooks[i].bookID<<endl;
    cout<<"\nBook's Publication : "<<listOfBooks[i].publicationName<<endl;
    cout<<"\nBook's Price : "<<listOfBooks[i].price<<endl;
	cout<<"\nBook's Quantity : "<<listOfBooks[i].quantity<<endl;
}

void showAll(){
	cout<<"Viewing all books"<<endl<<endl;
	for (int i=0; i<numberOfBooks; i++){
		show(i);
		cout<<"--------------------------"<<endl;
	}
		
}

int search() {
	int option;
	cout<<"How would you like to search for the book?"<<endl;
	cout<<"1) Search by title"<<endl;
	cout<<"2) Search by book id"<<endl;
	cout<<"\nEnter your option: ";
	
	cin>>option;
	if (option == 1){
		string bookTitle;
		cout<<"Enter book title: ";
		cin.ignore();
		getline(cin, bookTitle);	
		bool bookFound = false;
		for (int i=0; i<numberOfBooks; i++){
			if (listOfBooks[i].title == bookTitle){
				bookFound = true;
				show(i);
				return i;
			}
		}
		if (!bookFound){
			cout<<"Book of title '"<<bookFound<<"' not found"<<endl;
			return -1;
		}
	} else {
		string bookID;
		cout<<"Enter book ID: ";
		cin.ignore();
		getline(cin, bookID);	
		bool bookFound = false;
		for (int i=0; i<numberOfBooks; i++){
			if (listOfBooks[i].bookID == bookID){
				bookFound = true;
				show(i);
				return i;
			}
		}
		if (!bookFound){
			cout<<"Book of id '"<<bookID<<"' not found"<<endl;
			return -1;
		}
	}
}

void update() {
	int option;
	cout<<"How would you like to search for the book?"<<endl;
	cout<<"1) Search by title"<<endl;
	cout<<"2) Search by book id"<<endl;
	cout<<"\nEnter your option: ";
	
	cin>>option;
	if (option == 1){
		string bookTitle;
		cin.ignore();
		cout<<"Enter book title: ";
		getline(cin, bookTitle);	
		bool bookFound = false;
		for (int i=0; i<numberOfBooks; i++){
			if (listOfBooks[i].title == bookTitle){
				bookFound = true;
				cout<<"Enter new book details"<<endl;
				cout<<"Enter title of book: ";
				getline(cin, listOfBooks[i].title);
				cout<<"Enter author name of book: ";
				getline(cin, listOfBooks[i].author);
				cout<<"Enter publication name of book: ";
				getline(cin, listOfBooks[i].publicationName);
				cout<<"Enter ID of book: ";
				getline(cin, listOfBooks[i].bookID);
				cout<<"Enter price of book: ";
				cin>>listOfBooks[i].price;
				cout<<"Enter quantity of book: ";
				cin>>listOfBooks[i].quantity;
			}
		}
		if (!bookFound){
			cout<<"Book of title '"<<bookFound<<"' not found"<<endl;
			return;
		}
	} else {
		string bookID;
		cout<<"Enter book ID: ";
		cin.ignore();
		getline(cin, bookID);	
		bool bookFound = false;
		for (int i=0; i<numberOfBooks; i++){
			if (listOfBooks[i].bookID == bookID){
				bookFound = true;
				cout<<"Enter new book details"<<endl;
				cout<<"Enter title of book: ";
				getline(cin, listOfBooks[i].title);
				cout<<"Enter author name of book: ";
				getline(cin, listOfBooks[i].author);
				cout<<"Enter publication name of book: ";
				getline(cin, listOfBooks[i].publicationName);
				cout<<"Enter ID of book: ";
				getline(cin, listOfBooks[i].bookID);
				cout<<"Enter price of book: ";
				cin>>listOfBooks[i].price;
				cout<<"Enter quantity of book: ";
				cin>>listOfBooks[i].quantity;
			}
		}
		if (!bookFound){
			cout<<"Book of id '"<<bookID<<"' not found"<<endl;
			return;
		}
	}
	cout<<"Update Successful"<<endl;
}

void deleteBook(int i){
	listOfBooks[i].title = "DELETED";
}

void updatePassword() {
	string oldPass;
	cout<<"Enter old password: ";
	cin>>oldPass;
	
	if (oldPass != password){
		cout<<"Wrong password"<<endl;
		return;
	}
	
	string newPass;
	cout<<"Enter new password: ";
	cin>>newPass;
	password = newPass;
}

void startProgram() {
	int i;
    cout<<"\n LIBRARY MANAGEMENT SYSTEM "<<"\n"<<endl;
    cout<<"\n>>Please Choose Any Option To login \n"<<endl;
    cout<<"\n1.Student\n\n2.Teacher\n\n3.Close Application\n"<<endl;
    cout<<"\nEnter your choice : "<<endl;
    cin>>i;
    switch(i){
    	case 1:{
    		system("cls");
    		currentlyShowing = 1;
        	libraryStudent();
			break;
		}
		
		case 2:{
			system("cls");
			
			string pass;
			cout<<"Enter password to access Library as a Teacher: ";
			cin>>pass;
			if (pass != password){
				cout<<"Wrong password"<<endl;
				return;
			}
			
			currentlyShowing = 2;
			libraryTeacher();
			break;
		}
		
		case 3: {
			exit(0);
			break;
		}
		
		default: {
			cout<<"Wrong option chosen..."<<endl;
			break;
		}
	}
}

void issue() {
	string name;
	cout<<"Enter student name that is issuing book: ";
	getline(cin, name);
	
	int i = search();
	
	cout<<"Book of title '"<<listOfBooks[i].title<<"' has been successfully issued by '"<<name<<"'"<<endl;
}

void libraryStudent() {
	int i;
        cout<<"\n************ WELCOME LIBRARYSTUDENT ************\n"<<endl;
        cout<<"\n>>Please Choose One Option:\n"<<endl;
        cout<<"\n1.View Books\n\n2.Issue Book\n\n3.Search Book\n\n4.Go to Main Menu\n\n5.Close the application"<<endl;
        cout<<"\nEnter your choice : "<<endl;
        cin>>i;
        
        switch(i){
        	case 1: {
        		showAll();
				break;
			}
			case 2: {
				issue();
				break;
			}
			
			case 3: {
				search();
				break;
			}
			
			case 4: {
				system("cls");
				currentlyShowing = 0;
				break;
			}
			
			case 5: {
				exit(0);
				break;
			}
		}
}

void libraryTeacher() {
	int i;
	cout<<"\n************ WELCOME LIBRARYCLERK ************\n"<<endl;
    cout<<"\n>>Please Choose One Option:\n"<<endl;
    cout<<"\n1.Add new book\n\n2.View ListofBooks\n\n3.Search for a Book\n\n4.Update\n\n5.Go to main menu\n\n6.Change SecurityPassword\n\n7.Close Application\n"<<endl;
    cout<<"\nEnter your choice : "<<endl;
    cin>>i;
    
    switch(i){
    	case 1: {
    		getData();
			break;
		}
    	case 2:{
    		showAll();
			break;
		}
		case 3: {
			search();
			break;
		}
		case 4: {
			update();
			break;
		}
		case 5: {
			system("cls");
			currentlyShowing = 0;
			break;
		}
		case 6: {
			updatePassword();
			break;
		}
		case 7: {
			exit(0);
			break;
		}
	}
}

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title,*rating;
public:	
	book()	{
	author= new char[20];
	title=new char[20];
    rating=new char[20];
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void addbook();
	
};

void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Rating: ";   cin.getline(rating,20); 
	
}

void book::editdata()	{
	
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Rating: ";   cin.getline(rating,20);

	
}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nRating Name: "<<rating; 
	
}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

void book::addbook()	{
	cout<<"\nEnter Book to add: "<< title;;
}

int main()	{
	book *B[20];
	int i=0,r,t,choice;
	char title[20],author[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Search For Book"
		<<"\n3. Edit Details Of Book"
		<<"\n4. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new book;
				B[i]->feeddata();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  cin.getline(author,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(title,author))	{
						B[t]->addbook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in your library";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  cin.getline(author,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(title,author))	{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in your library";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  cin.getline(author,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(title,author))	{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in your library";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;

}
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
struct Lib
{

       char BookTitle[100],BookAuthor[50],StringCopy[20],StringCopy1[50];
       int q,B,p;
       Lib()
       {
           strcpy(BookTitle,"NO Book Title");
           strcpy(BookAuthor,"No Author Name");
           strcpy(StringCopy,"No Book ID");
           strcpy(StringCopy1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void LibraryStudent();
          void pass();
          void LibraryTeacher();
          void SecurityPassword();
          void getdata();
          void show(int);
          void ListofBooks(int);
          void update();
          void see(int);
          int branch(int);
          void BookIssue();
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\nEnter the details :-\n"<<endl;
                    cout<<"\nEnter Book's Name : "<<endl;
                    cin.getline(BookTitle,100);
                    for(i=0;BookTitle[i]!='\0';i++)
                    {
                    if(BookTitle[i]>='a'&&BookTitle[i]<='z')
                       BookTitle[i]-=32;
                    }
                    cout<<"\nEnter Author's Name : "<<endl;
                    cin.getline(BookAuthor,50);
                    cout<<"\nEnter Publication name : "<<endl;
                    cin.getline(StringCopy1,50);
                    cout<<"\nEnter Book's ID : "<<endl;
                    cin.getline(StringCopy,20);
                    cout<<"\nEnter Book's Price : "<<endl;
                    cin>>p;
                    cout<<"\nEnter Book's Quantity : "<<endl;
                    cin>>q;
}
void Lib::show(int i)
{
    cout<<"\nBook Title : "<<BookTitle<<endl;
    cout<<"\nBook's Author Name : "<<BookAuthor<<endl;
    cout<<"\nBook's ID : "<<StringCopy<<endl;
    cout<<"\nBook's Publication : "<<StringCopy1<<endl;
    if(i==2)
    {
        cout<<"\nBook's Price : "<<p<<endl;
        cout<<"\nBook's Quantity : "<<q<<endl;
    }
}
  void Lib::ListofBooks(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\nFile Not Found."<<endl;
                else
                {
                    cout<<"\n    ************ Book List ************ \n\n"<<endl;
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n********** "<<r<<". ********** \n"<<endl;
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\nPress any key to continue....."<<endl;
                getch();
                system("cls");
                if(i==1)
                    LibraryStudent();
                else
                    LibraryTeacher();
    }
  void Lib::update()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n>>Please Choose one option :-\n"<<endl;
    cout<<"\n1.Modification In Current Books\n\n2.Add New Book\n\n3.Delete A Book\n\n4.Go back\n"<<endl;
    cout<<"\n\n  Excuse me!Please Enter your choice : "<<endl;
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\nFile Not Found\n"<<endl;
                        cout<<"\nPress any key to continue....."<<endl;
                        getch();
                        system("cls");
                        LibraryTeacher();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\nPlease Choose One Option :-\n"<<endl;
                        cout<<"\n1.Search By Book Title\n\n2.Search By Book's ID\n"<<endl;
                        cout<<"\nEnter Your Choice : "<<endl;
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\nEnter Book Title : "<<endl;
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&BookTitle[i]!='\0'&&st1[i]!='\0'&&(st1[i]==BookTitle[i]||st1[i]==BookTitle[i]+32);i++);
                                        if(BookTitle[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\nEnter Book's ID : "<<endl;
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&StringCopy[i]!='\0'&&st1[i]!='\0'&&st1[i]==StringCopy[i];i++);
                                        if(StringCopy[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\nWrong Input.....:(\n"<<endl;
                            cout<<"\nPress any key to continue....."<<endl;
                            getch();
                            system("cls");
                            update();
                        }
                        if(cont==0)
                        {
                            cout<<"\nBook Not Found.\n"<<endl;
                            cout<<"\nPress any key to continue....."<<endl;
                            getch();
                            system("cls");
                            update();
                        }
                        else
                            cout<<"\nUpdate Successful.\n"<<endl;


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\nBook added Successfully.\n"<<endl;
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\nFile Not Found\n"<<endl;
                        cout<<"\nPress any key to continue....."<<endl;
                        getch();
                        intf1.close();
                        system("cls");
                        LibraryTeacher();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\nPlease Choose One Option for deletion:-\n"<<endl;
                        cout<<"\n1.By Book Title\n\n2.By Book's ID\n"<<endl;
                        cout<<"\nEnter Your Choice : "<<endl;
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\nEnter Book Title : "<<endl;
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&BookTitle[i]!='\0'&&st1[i]!='\0'&&(st1[i]==BookTitle[i]||st1[i]==BookTitle[i]+32);i++);
                                        if(BookTitle[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\nEnter Book's ID : "<<endl;
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&StringCopy[i]!='\0'&&st1[i]!='\0'&&st1[i]==StringCopy[i];i++);
                                        if(StringCopy[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\nWrong Input.....:(\n"<<endl;
                            cout<<"\nPress any key to continue....."<<endl;
                            getch();
                            system("cls");
                            update();
                        }
                        if(cont==0)
                        {
                            cout<<"\nBook Not Found.\n"<<endl;
                            cout<<"\nPress any key to continue....."<<endl;
                            getch();
                            system("cls");
                            update();
                        }
                        else
                            cout<<"\nDeletion Successful.\n"<<endl;

    }
    else if(i==4)
    {
    system("cls");
    LibraryTeacher();
    }
    else
    {
    cout<<"\nWrong Input.\n"<<endl;
    cout<<"\nPress any key to continue....."<<endl;
    getch();
    system("cls");
    update();
    }
    cout<<"\nPress any key to continue....."<<endl;
    getch();
    system("cls");
    LibraryTeacher();

  }
  int Lib::branch(int x)
  {
      int i;
      cout<<"\n>>Please Choose one Branch :-\n"<<endl;
      cout<<"\n1.BIT\n\n2.EE\n\n3.EC\n\n4.CIVIL\n\n5.MECHANICAL\n\n6.1ST YEAR\n\n7.Go to menu\n"<<endl;
      cout<<"\nEnter youur choice : "<<endl;
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  LibraryStudent();
                  else
                    LibraryTeacher();
          default : cout<<"\nPlease enter correct option :("<<endl;
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Lib::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\nFile Not Found.\n"<<endl;
            cout<<"\n->Press any key to continue....."<<endl;
            getch();
            system("cls");
            if(x==1)
            LibraryStudent();
            else
            LibraryTeacher();
        }

      system("cls");
      cout<<"\nPlease Choose one option :-\n"<<endl;
      cout<<"\n1.Search By Name\n\n2.Search By Book's ID\n"<<endl;
      cout<<"\nEnter Your Choice : "<<endl;
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\nEnter Book's Name : "<<endl;
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&BookTitle[i]!='\0'&&ch[i]!='\0'&&(ch[i]==BookTitle[i]||ch[i]==BookTitle[i]+32);i++);
            if(BookTitle[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\nBook Found :-\n"<<endl;
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\nEnter Book's ID : "<<endl;
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&StringCopy[i]!='\0'&&ch[i]!='\0'&&ch[i]==StringCopy[i];i++);
              if(StringCopy[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\nBook Found :-\n"<<endl;
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\nPlease enter correct option :("<<endl;
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\nThis Book is not available ?? \n"<<endl;

    cout<<"\nPress any key to continue....."<<endl;
    getch();
    system("cls");
    if(x==1)
    LibraryStudent();
    else
    LibraryTeacher();


  }
void Lib::BookIssue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n->Please Choose one option :-\n"<<endl;
    cout<<"\n1.BookIssue Book\n\n2.View BookIssued Book\n\n3.Search LibraryStudent who isuued books\n\n4.ReBookIssue Book\n\n5.Return Book\n\n6.Go back to menu\n\nEnter Your Choice : "<<endl;
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n->Please Enter Details :-\n"<<endl;
    cout<<"\nEnter Book Title : "<<endl;
    cin.getline(BookTitle,100);
    cout<<"\nEnter Book's ID : "<<endl;
    cin.getline(StringCopy,20);
    //strcpy(st,StringCopy);
    der(StringCopy,b,1);
    cout<<"\nEnter LibraryStudent Name : "<<endl;
    cin.getline(BookAuthor,100);
    cout<<"\nEnter LibraryStudent's ID : "<<endl;
    cin.getline(StringCopy1,20);
    cout<<"\nEnter date : "<<endl;
    cin>>q>>B>>p;
    ofstream outf("LibraryStudent.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\nBookIssue Successfully.\n"<<endl;
    }
    else if(i==2)
    {
    ifstream intf("LibraryStudent.txt",ios::binary);
    system("cls");
    cout<<"\n->The Details are :-\n"<<endl;
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n********** "<<i<<". ********** \n"<<endl;
    cout<<"\nLibraryStudent Name : "<<BookAuthor<<"\n"<<"LibraryStudent's ID : "<<StringCopy1<<"\n"<<"Book Title : "<<BookTitle<<"\n"<<"Book's ID : "<<StringCopy<<"\n"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n"<<endl;
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n->Please Enter Details :-\n"<<endl;
        cout<<"\n\nEnter LibraryStudent Name : "<<endl;
        cin.getline(st,50);
        cout<<"\n\nEnter LibraryStudent's ID : "<<endl;
        cin.getline(st1,20);
        system("cls");
        ifstream intf("LibraryStudent.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;StringCopy1[i]!='\0'&&st1[i]!='\0'&&st1[i]==StringCopy1[i];i++);
              if(StringCopy1[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n->The Details are :-\n"<<endl;
                      cout<<"\nLibraryStudent Name : "<<BookAuthor;
                      cout<<"\nLibraryStudent's ID : "<<StringCopy1;
                  }
                  cout<<"\n\n******* "<<cont<<". Book details *******\n"<<endl;
                  cout<<"\nBook Title : "<<BookTitle;
                  cout<<"\nBook's ID : "<<StringCopy;
                  cout<<"\nDate : "<<q<<"/"<<B<<"/"<<p<<"\n"<<endl;
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\nNo record found."<<endl;
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n->Please Enter Details :-\n"<<endl;
    cout<<"\n\nEnter LibraryStudent's ID : "<<endl;
    cin.getline(st,50);
    cout<<"\nEnter Book's ID : "<<endl;
    cin.getline(st1,20);
    fstream intf("LibraryStudent.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;StringCopy[i]!='\0'&&st1[i]!='\0'&&st1[i]==StringCopy[i];i++);
            for(j=0;StringCopy1[j]!='\0'&&st[j]!='\0'&&st[j]==StringCopy1[j];j++);
            if(StringCopy[i]=='\0'&&StringCopy1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\nEnter New Date : "<<endl;
                    cin>>q>>B>>p;
                    fine(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\nReBookIssue successfully."<<endl; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n->Please Enter Details :-\n"<<endl;
    cout<<"\nEnter Book's ID : "<<endl;
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\nEnter LibraryStudent's ID : "<<endl;
    cin.getline(st,20);
    cout<<"\nEnter Present date : "<<endl;
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("LibraryStudent.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;StringCopy[i]!='\0'&&st1[i]!='\0'&&st1[i]==StringCopy[i];i++);
            for(j=0;StringCopy1[j]!='\0'&&st[j]!='\0'&&st[j]==StringCopy1[j];j++);
            if(StringCopy[i]=='\0'&&StringCopy1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(q,B,p,d,m,y);
                    cout<<"\nReturned successfully."<<endl;
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("LibraryStudent.txt");
    rename("temp.txt","LibraryStudent.txt");
    }
    else if(i==6)
    {
    system("cls");
    LibraryTeacher();
    }
    else
        cout<<"\nWrong Input.\n"<<endl;

    cout<<"\n\nPress any key to continue....."<<endl;
    getch();
    system("cls");
    LibraryTeacher();
}
void Lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\nThe Total Fine is : "<<n2;
    
}
void Lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&StringCopy[i]!='\0'&&st[i]!='\0'&&st[i]==StringCopy[i];i++);
        if(StringCopy[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\nBook not found.\n"<<endl;
        cout<<"\n\nPress any key to continue....."<<endl;
        getch();
        system("cls");
        BookIssue();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n LIBRARY MANAGEMENT SYSTEM "<<"\n"<<endl;
        cout<<"\n>>Please Choose Any Option To login \n"<<endl;
        cout<<"\n1.Student\n\n2.Teacher\n\n3.Close Application\n"<<endl;
        cout<<"\nEnter your choice : "<<endl;
        cin>>i;
        if(i==1)
        {
            system("cls");
            LibraryStudent();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\nPlease enter correct option :("<<endl;
            getch();
            system("CLS");
           get();
        }
}
void Lib::LibraryStudent()
{
    int i;
        cout<<"\n************ WELCOME LIBRARYSTUDENT ************\n"<<endl;
        cout<<"\n>>Please Choose One Option:\n"<<endl;
        cout<<"\n1.View Books\n\n2.Issue Book\n\n3.Search Book\n\n4.Go to Main Menu\n\n5.Close the application"<<endl;
        cout<<"\nEnter your choice : "<<endl;
        cin>>i;
            if(i==1)
                ListofBooks(1);
                else if(i==2)
                BookIssue();
            else if(i==3)
                see(1);
            else if(i==4)
            {
                system("cls");
                get();
            }
            else if(i==5)
                exit(0);
            else
            {
                cout<<"\nPlease enter correct option :("<<endl;
                getch();
                system("cls");
                LibraryStudent();
            }
}
void Lib::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\nEnter SecurityPassword : "<<endl;
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b"<<endl;
    }
    else
    {
    cout<<"*"<<endl;
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("SecurityPassword.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        LibraryTeacher();
    }
    else
    {
        cout<<"\n\nWrong SecurityPassword.\n\ntry again.....\n"<<endl;
        getch();
        system("cls");
        get();
    }
}
void Lib::LibraryTeacher()
{
    int i;
        cout<<"\n************ WELCOME LIBRARYCLERK ************\n"<<endl;
        cout<<"\n>>Please Choose One Option:\n"<<endl;
        cout<<"\n1.View ListofBooks\n\n2.Search for a Book\n\n3.Update/Add Book\n\n4.BookIssue Book\n\n5.Go to main menu\n\n6.Change SecurityPassword\n\n7.Close Application\n"<<endl;
        cout<<"\nEnter your choice : "<<endl;
        cin>>i;
        switch(i)
        {
            case 1:ListofBooks(2);
                     break;
            case 2:see(2);
                     break;
            case 3:update();
                     break;
            case 4:BookIssue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:SecurityPassword();
                    break;
            case 7:exit(0);
            default:cout<<"\nPlease enter correct option :("<<endl;
            getch();
            system("cls");
            LibraryTeacher();
        }
}
void Lib::SecurityPassword()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\nEnter Old SecurityPassword : "<<endl;
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b"<<endl;
    }
    else
    {
    cout<<"*"<<endl;
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("SecurityPassword.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n**The SecurityPassword Should be less than 20 characters & don't use spaces**\n\n"<<endl;
        cout<<"\nEnter New SecurityPassword : "<<endl;
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\nYou did't follow the instruction \n\nPress any key for try again....."<<endl;
                getch();
                system("cls");
                SecurityPassword();
                LibraryTeacher();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b"<<endl;
        }
        else
        {
        cout<<"*"<<endl;
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("SecurityPassword.txt");
        outf<<st;
        outf.close();
        cout<<"\n\nYour SecurityPassword has been changed Successfully."<<endl;
        cout<<"\nPress any key to continue......"<<endl;
        getch();
        system("cls");
        LibraryTeacher();
    }
    else
    {
        cout<<"\n\nSecurityPassword is wrong.....\n"<<endl;
        cout<<"\nEnter 1 for retry or 2 for menu"<<endl;
        cin>>i;
        if(i==1)
        {
        system("cls");
        2
		();
        }
        else
        {
            system("cls");
            LibraryTeacher();
        }
    }
}
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}

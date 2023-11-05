#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

struct Books
{
  int ISBN;
  string judul, pengarang;
  bool availability;
  struct Books *next;
};

struct Members
{
  int ID;
  string name;
  struct Members *next;
};

struct Loans
{
  int bookISBN, memberID;
  string loanDate, returnDate; // format : dd-MM-yyyy
  struct Loans *next;
};

typedef struct Books books;
typedef struct Members members;
typedef struct Loans loans;

// common function declaration
void list_command();

// ENTITIES FUNCTION DECLARATION

// BOOK SERVICE
void books_command();

// MEMBER SERVICE
void members_command();
void add_member(members **memberHead);
void display_member(members **memberHead);

// LOAN SERVICE
void loans_command();

// REPORT SERVICE
void reports_command();

int main()
{
  books *bookHead;
  members *memberHead;
  loans *loanHead;

  while (true)
  {
    int cmd = 0;
    list_command();
    cin >> cmd;

    switch (cmd)
    {
    case 1:
      // menu buku
      cmd = 0;
      books_command();
      cin >> cmd;
      continue;
    case 2:
      // menu anggota
      cmd = 0;
      members_command();
      cin >> cmd;
      switch (cmd)
      {
      case 1:
        add_member(&memberHead);
        break;
      case 2:
        display_member(&memberHead);
        break;
      default:
        cout << "Invalid Command";
        break;
      }
      continue;
    case 3:
      // Menu Peminjaman
      loans_command();
      cin >> cmd;
      continue;
    case 4:
      // Menu Laporan 
      reports_command();
      cin >> cmd;
      continue;
    case 0:
      break;
    default:
      cout << "Invalid command" << endl;
      system("pause");
      continue;
    }

    break;
  }
}

// COMMON FUNCTION INITIATION
void list_command()
{
  system("cls");
  cout << "=============== Menu ===============" << endl;
  cout << "1.\tBook Service" << endl;
  cout << "2.\tMember Service" << endl;
  cout << "3.\tLoan Service" << endl;
  cout << "4.\tReport Service" << endl;
  cout << "0.\tExit Program" << endl;
  cout << "============= Command =============" << endl;
  cout << "Select the menu you want to go: ";
}

// ENTITIES FUNCTION INITIATION

// BOOK SERVICE
void books_command()
{
  system("cls");
  cout << "========= Book Service =========" << endl;
  cout << "1.\tAdd New Book" << endl;
  cout << "2.\tDisplay All Book" << endl;
  cout << "3.\tSearch Book By Title, Author, ISBN" << endl;
  cout << "============ command ============" << endl;
  cout << "Select the menu you want to go: ";
}

// MEMBER SERVICE
void members_command()
{
  system("cls");
  cout << "========= Member Service =========" << endl;
  cout << "1.\tAdd New Member" << endl;
  cout << "2.\tDisplay All Member" << endl;
  cout << "============ command ============" << endl;
  cout << "Select the menu you want to go: ";
}
void add_member(members **memberHead)
{
}
void display_member(members **memberHead)
{
}

// LOAN SERVICE
void loans_command()
{
  system("cls");
  cout << "========= Loan Service =========" << endl;
  cout << "1.\tYour Command" << endl;
  cout << "============ command ============" << endl;
  cout << "Select the menu you want to go: ";
}

// REPORT SERVICE
void reports_command()
{
  system("cls");
  cout << "========= Report Service =========" << endl;
  cout << "1.\tYour Command" << endl;
  cout << "============ command ============" << endl;
  cout << "Select the menu you want to go: ";
}

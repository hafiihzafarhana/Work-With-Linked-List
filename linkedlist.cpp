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
// your code here

// BOOK SERVICE

// LOAN SERVICE
// your code here

// REPORT SERVICE
// your code here

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
      continue;
    case 2:
      // menu anggota
      continue;
    case 3:
      // menu peminjaman
      continue;
    case 4:
      // menu laporan
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
// your code here

// BOOK SERVICE
// your code here

// LOAN SERVICE
// your code here

// REPORT SERVICE
// your code here

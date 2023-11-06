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
void add_book(books **bookHead);
void display_book(books **bookHead);

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

  bookHead = nullptr;

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
      switch (cmd)
      {
      case 1:
        add_book(&bookHead);
        break;

      case 2:
        display_book(&bookHead);
        break;
      
      default:
        break;
      }
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
  // system("cls");
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
  // system("cls");
  cout << "========= Book Service =========" << endl;
  cout << "1.\tAdd New Book" << endl;
  cout << "2.\tDisplay All Book" << endl;
  cout << "3.\tSearch Book By Title, Author, ISBN" << endl;
  cout << "============ command ============" << endl;
  cout << "Select the menu you want to go: ";
}

// Books **bookHead, akan menunjuk ke element pertama
void add_book(books **bookHead){
  // Alokasi memori dinamis untuk objek bertipe Books
  // Tidak perlu ada pengechekan NULL karena sudah diatur oleh Build in yaitu std::bad_alloc
  books *pNew = new books;
  
  // Deklarasi
  int isbn;
  string judl, pengarang;

  cout<<"Masukan Data ISBN: ";
  cin>>isbn;

  if (isbn < 1) {
    cout << "Harus angka lebih dari 0" << endl;
    delete pNew; // Hapus elemen yang sudah dialokasikan karena ggagal
    return;
  }

  cout<<"Masukan Data Judul: ";
  cin>>judl;
  cout<<"Masukan Data Pengarang: ";
  cin>>pengarang;

  pNew -> ISBN = isbn;
  pNew -> judul = judl;
  pNew -> pengarang = pengarang;
  pNew -> availability = true;

  // hubungkan data baru dengan elemet awal yang sudah ada atau nullptr
  pNew -> next = *bookHead;

  // Jadikan data pertama menjadi data terbaru
  *bookHead = pNew;
}

void display_book(books **bookHead){
  books* current;
  current = *bookHead;
  while (current != nullptr) {
        cout << "ISBN: " << current->ISBN << endl;
        cout << "Judul: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Ketersediaan: " << (current->availability ? "Tersedia" : "Tidak Tersedia") << endl;

        // Pindah ke buku berikutnya dalam linked list
        current = current->next;
    }
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

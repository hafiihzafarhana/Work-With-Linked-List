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
void loans_command(books **bookHead, loans **loanHead, members **memberHead);
void add_loan(loans **loanHead, int bookISBN, int memberID, const string &loanDate, const string &returnDate);
void borrow_book(books **bookHead, int ISBN, const string &loanDate, int memberID, loans **loanHead);
void return_book(books **bookHead, int ISBN, const string &returnDate, loans **loanHead);
void display_loans(loans **loanHead);

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
      loans_command(&bookHead, &loanHead, &memberHead);
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
void loans_command(books **bookHead, loans **loanHead, members **memberHead) {
    while (true) {
        system("cls");
        cout << "========= Loan Service =========" << endl;
        cout << "1.\tBorrow a Book" << endl;
        cout << "2.\tReturn a Book" << endl;
        cout << "3.\tDisplay All Loans" << endl;
        cout << "4.\tBack to Main Menu" << endl;
        cout << "============ Command ============" << endl;
        cout << "Select the menu you want to go: ";

        int cmd;
        cin >> cmd;
        int memberID, bookISBN;
        string loanDate, returnDate;
        int returnMemberID, returnBookISBN;
        string returnReturnDate;

        switch (cmd) {
            case 1:
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Book ISBN: ";
                cin >> bookISBN;
                cout << "Enter Loan Date (dd-MM-yyyy): ";
                cin >> loanDate;
                borrow_book(bookHead, bookISBN, loanDate, memberID, loanHead);
                break;
            case 2:
                cout << "Enter Member ID: ";
                cin >> returnMemberID;
                cout << "Enter Book ISBN: ";
                cin >> returnBookISBN;
                cout << "Enter Return Date (dd-MM-yyyy): ";
                cin >> returnReturnDate;
                return_book(bookHead, returnBookISBN, returnReturnDate, loanHead);
                break;
            case 3:
                display_loans(loanHead);
                break;
            case 4:
                return;
            default:
                cout << "Invalid command" << endl;
                system("pause");
                break;
        }
    }
}

void display_loans(loans **loanHead) {
    if (*loanHead == nullptr) {
        cout << "No loans available." << endl;
        return;
    }

    cout << "======= Loan List =======" << endl;
    loans *currentLoan = *loanHead;
    while (currentLoan != nullptr) {
        cout << "Book ISBN: " << currentLoan->bookISBN << endl;
        cout << "Member ID: " << currentLoan->memberID << endl;
        cout << "Loan Date: " << currentLoan->loanDate << endl;
        cout << "Return Date: " << currentLoan->returnDate << endl;
        cout << "------------------------" << endl;
        currentLoan = currentLoan->next;
    }
    cout << "========================" << endl;
}

void add_loan(loans **loanHead, int bookISBN, int memberID, const string &loanDate, const string &returnDate) {
    loans *newLoan = new loans;
    newLoan->bookISBN = bookISBN;
    newLoan->memberID = memberID;
    newLoan->loanDate = loanDate;
    newLoan->returnDate = returnDate;
    newLoan->next = *loanHead;
    *loanHead = newLoan;
    cout << "Loan added successfully." << endl;
}

void borrow_book(books **bookHead, int ISBN, const string &loanDate, int memberID, loans **loanHead) {
    books *currentBook = *bookHead;

    while (currentBook != nullptr) {
        if (currentBook->ISBN == ISBN && currentBook->availability) {
            currentBook->availability = false;
            add_loan(loanHead, ISBN, memberID, loanDate, "");
            cout << "Book with ISBN " << ISBN << " has been borrowed successfully." << endl;
            return;
        }
        currentBook = currentBook->next;
    }

    cout << "Book with ISBN " << ISBN << " is not available for borrowing." << endl;
}

void return_book(books **bookHead, int ISBN, const string &returnDate, loans **loanHead) {
    books *currentBook = *bookHead;

    while (currentBook != nullptr) {
        if (currentBook->ISBN == ISBN && !currentBook->availability) {
            currentBook->availability = true;
            loans *currentLoan = *loanHead;
            while (currentLoan != nullptr) {
                if (currentLoan->bookISBN == ISBN) {
                    currentLoan->returnDate = returnDate;
                    break;
                }
                currentLoan = currentLoan->next;
            }

            cout << "Book with ISBN " << ISBN << " has been returned successfully." << endl;
            return;
        }
        currentBook = currentBook->next;
    }

    cout << "Book with ISBN " << ISBN << " cannot be returned as it was not borrowed." << endl;
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

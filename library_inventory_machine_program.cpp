//#include<iostream>
//#include<string>
//using namespace std;
//
//class node
//{
//public:
//    string book_title;
//    string ISBN;
//    int quantity;
//    string author;
//    double price;
//    node* next;
//    node()
//    {
//        book_title = " ";
//        ISBN = " ";
//        quantity = 0;
//        price = 0.0;
//        author = " ";
//        this->next = NULL;
//    }
//    node(string b_name, string isbn, string a_name, double pric, int quant)
//    {
//        book_title = b_name;
//        ISBN = isbn;
//        quantity = quant;
//        price = pric;
//        author = a_name;
//        this->next = NULL;
//    }
//};
//
//class book_list
//{
//public:
//    node* head;
//    book_list()  
//    {
//        head = NULL;
//    }  
//
//    node* search_by_isbn(string isbn)
//    {
//        node* cur = head;
//        while (cur != NULL)
//        {
//            if (cur->ISBN == isbn)
//            {
//                return cur;
//            }
//            cur = cur->next;
//        }
//        return NULL;
//    }
//
//    void addbook(const string& title, const string& isbn, const string& author, double price, int quantity)
//    {
//        node* newnode = new node(title, isbn, author, price, quantity);
//        node* current = head;
//        if (current == NULL)  
//        {
//            head = newnode;
//        }
//        else
//        {
//            while (current->next != NULL)
//            {
//                current = current->next;
//            }
//            current->next = newnode;
//        }
//    }
//
//    void deletebook(const string& isbn)
//    {
//        node* cur = head;
//        node* prev = NULL;
//        while (cur != NULL && cur->ISBN != isbn)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//        if (cur == NULL)
//        {
//            cout << "Book does not find from list.\n";
//            return;
//        }
//        if (prev == NULL)
//        {
//            head = cur->next;
//        }
//        else
//        {
//            prev->next = cur->next;
//        }
//        delete cur;
//        cout << "Book has been deleted.\n";
//    }
//
//    void update_book(const string& isbn, double new_pric)
//    {
//        node* cur = search_by_isbn(isbn);
//        if (cur != NULL)
//        {
//            cur->price = new_pric;
//            cout << "price is changed\n";
//        }
//        else
//        {
//            cout << "book does not fount\n";
//        }
//    }
//
//    void display()
//    {
//        node* cur = head;
//        if (cur == NULL)
//        {
//            cout << "The list is empty.\n";
//            return;
//        }
//        int count = 1;
//        while (cur != NULL)
//        {
//            cout << "***********Detail of " << count << "  book*********\n";
//            cout << "title of book :  " << cur->book_title << "\n";
//            cout << "Name of Author of book :  " << cur->author << "\n";
//            cout << "Price of book :  " << cur->price << "\n";
//            cout << "ISBN of book :  " << cur->ISBN << "\n";
//            cout << "Quantity of book :  " << cur->quantity << "\n";
//            count++;
//            cur = cur->next;
//        }
//    }
//
//    void expensivebook(book_list& expnsive)
//    {
//        node* cur = head;
//        if (cur == NULL)
//        {
//            cout << "list is empty\n";
//        }
//        while (cur != NULL)
//        {
//            if (cur->price > 5000)
//            {
//                expnsive.addbook(cur->book_title, cur->ISBN, cur->author, cur->price, cur->quantity);
//            }
//            cur = cur->next;
//        }
//    }
//};
//
//int main()
//{
//    book_list library;
//    book_list expensive_book;
//    int c;
//    string title, isbn, author;
//    double newprice;
//    int quantity;
//    do
//    {
//        cout << "enter 1 for add new book\n";
//        cout << "enter 2 for searching book\n";
//        cout << "enter 3 for  delete a book\n";
//        cout << "enter 4 for update a book price\n";
//        cout << "enter 5 for  display books\n";
//        cout << "entyer 6 for expensive book :\n";
//        cout << "enter 0 for  exit\n";
//        cout << "Enter your choice: ";
//        cin >> c;
//
//        switch (c)
//        {
//        case 1:
//            cout << "Enter title: ";
//            cin >> title;
//            cout << "Enter ISBN: ";
//            cin >> isbn;
//            cout << "Enter author: ";
//            cin>> author;
//            cout << "Enter price: ";
//            cin >> newprice;
//            cout << "Enter quantity: ";
//            cin >> quantity;
//            library.addbook(title, isbn, author, newprice, quantity);
//            break;
//
//        case 2:
//            cout << "Enter ISBN to search: ";
//            cin >> isbn;
//            if (library.search_by_isbn(isbn) != NULL)
//            {
//                cout << "book was find\n";
//            }
//            else
//            {
//                cout << "Book was not found.\n";
//            }
//            break;
//
//        case 3:
//            cout << "Enter ISBN to delete: ";
//            cin >> isbn;
//            library.deletebook(isbn);
//            break;
//
//        case 4:
//            cout << "Enter ISBN to update: ";
//            cin >> isbn;
//            cout << "Enter new price: ";
//            cin >> newprice;
//            library.update_book(isbn, newprice);
//            break;
//
//        case 5:
//            cout << "print all book in the library : ";
//            library.display();
//            cout << "\n";
//            break;
//
//        case 6:
//            cout << "list of expensive books :";
//            library.expensivebook(expensive_book);
//            cout << "\n";
//            expensive_book.display();
//            cout << "\n";
//            break;
//
//        case 0:
//            cout << "Exit\n";
//            break;
//
//        default:
//            cout << "Invalid choice try again\n";
//            break;
//        }
//    } while (c != 0);
//
//    system("pause");
//    return 0;
//}

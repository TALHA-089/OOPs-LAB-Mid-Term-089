#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Book;
class ShoppingCart;
class Store;

class Book
{
private:
    
    string Bookname;
    string Author;
    float Price = 0;
    bool Availability;
    
public:
    
    
    void setBookName(string Name)
    {
        this->Bookname = Name;
    }
    
    void setBookAuthor(string Author)
    {
        this->Author = Author;
    }
    
    void setPrice(float Price)
    {
        this->Price = Price;
    }
    
    string getName()
    {
        return Bookname;
    }
    
    string getAuthor()
    {
        return Author;
    }
    
    float getBookPrice()
    {
        return Price;
    }
    
    void setAvailability(bool A)
    {
        this->Availability = A;
    }
    
    bool isAvailable()
    {
        return Availability;
    }
};

class ShoppingCart
{
private:
    
    vector <Book> Books;
    
public:
    
    void addBooks(string bookname, vector<Book> StoreBooks)
    {
        for(auto &it : StoreBooks)
        {
            if(it.getName()== bookname && it.isAvailable())
            {
                Books.push_back(it);
                cout<<"\n\nBook " << bookname<<" Successfully Added To the Cart.";
                return;
            }
            
        }
        cout<<"\nEither the Name is Incorrect or The Book isn't Available";
    }
    
    float checkoutPrice()
    {
        float sum = 0;
        for(auto it : Books)
        {
            sum += it.getBookPrice();
        }
        return sum;
    }
    
    void DisplayCart()
    {
        int count = 0;
        for(auto it : Books)
        {
            cout<<"\n----------Book "<<count+1<<"---------------";
            cout<<"\n\nName: "<<it.getName();
            cout<<"\nAuthor: "<<it.getAuthor();
            cout<<"\nPrice: $"<<it.getBookPrice();
            count++;
        }
    }
};

class Store
{
private:
    
    vector <Book> StoreBooks;

    
public:
    
    void AddBooks(Book newBook)
    {
        StoreBooks.push_back(newBook);
    }
    
    vector <Book> getStoreBooks()
    {
        return StoreBooks;
    }
    
    
    
    void DisplayStoreBooks()
    {
        int count = 0;
        for(auto it : StoreBooks)
        {
            cout<<"\n----------Book "<<count+1<<"---------------";
            cout<<"\n\nName: "<<it.getName();
            cout<<"\nAuthor: "<<it.getAuthor();
            cout<<"\nPrice: $"<<it.getBookPrice();
            cout<<"\nAvailability: "<<it.isAvailable();
            count++;
        }
    }
};


void Main_Menu()
{
    cout<<"\n\n------------Main Menu-------------\n";
    cout<<"1.Add Books to the Store\n";
    cout<<"2.Browse Books\n";
    cout<<"3.Add a Book to the Cart\n";
    cout<<"4.Display Cart Content\n";
    cout<<"5.Proceed with Checkout\n";
    cout<<"6.Exit\n";
    cout<<"\n\nEnter your Choice: ";
}


int main()
{
    Store Store_1;
    ShoppingCart Cart;
    
    while(1)
    {
        int choice = 0;
        Main_Menu();
        cin >> choice;
        cin.ignore();
        
        if(choice == 1)
        {
            string name, Author;
            float Price;
            cout<<"\nEnter Book Name: ";
            getline(cin, name);
            cout<<"\nEnter Author's Name: ";
            getline(cin, Author);
            cout<<"\nEnter Book's Price: ";
            cin>>Price;
            cin.ignore();
            Book newBook;
            newBook.setBookName(name);
            newBook.setBookAuthor(Author);
            newBook.setPrice(Price);
            newBook.setAvailability(true);
            Store_1.AddBooks(newBook);
            cout<<"\n\nBook SuccessFully Added To the Store";
        }
        
        else if(choice == 2)
        {
            Store_1.DisplayStoreBooks();
        }
        else if(choice == 3)
        {
            string Name;
            cout<<"\n\nEnter the Name of the Book you want to add: ";
            getline(cin, Name);
            int count = 0;
            for(auto &it : Store_1.getStoreBooks())
            {
                if(Name == it.getName())
                {
                    (Cart.addBooks(Name, Store_1.getStoreBooks()));
                    Store_1.getStoreBooks().at(count).setAvailability(false);
                }
                count ++;
            }
            
        }
        
        else if(choice == 4)
        {
            Cart.DisplayCart();
        }
        
        else if(choice == 5)
        {
            cout<<"\nYour Total is: $" << Cart.checkoutPrice();
        }
        
        else
        {
            break;
        }
        
    }

    cout<<"\n\nGood Bye!\n\n";
    return 0;
}

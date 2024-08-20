class library:
    def __init__(self,list_book):
        self.book=list_book
        
    def displayAvelabelbooks(self):
        print("books prasent in this library: ")
        for book in self.book:
            print("*" + book)
    
    def borrowbook(self, bookName):
        if bookName in self.book:
            print(f"You have been issued {bookName}. Please keep it safe and return it within 30 days")
            self.book.remove(bookName)
            return True
        else:
            print("Sorry, This book is either not available or has already been issued to someone else. Please wait until the book is available")
            return False
        
    def returnBook(self, bookName):
        self.book.append(bookName)
        print("Thanks for returning this book! Hope you enjoyed reading it. Have a great day ahead!")    
        
class student:
    def requestBook(self):
        self.book = input("Enter the name of the book you want to borrow: ")
        return self.book
    
    def returnBook(self):
        self.book= input("Enter  the name of the book you want to return:  ")
        return self.book
    

if __name__=="__main__":
    centralLibrary = library(["Python Programming", "Data Science", "Machine Learning","DSA","Python Notes"])
    Student=student()
    while True:
        walcomeMSG = '''\n ====== Welcome to Central Library ======
        Please choose an option:
        1. List all the books
        2. Request a book
        3. Return a book
        4. Exit the Library
        '''
        print(walcomeMSG)
        choice=int(input("Enter your choise: "))
        if choice==1:
           centralLibrary.displayAvelabelbooks()
        elif choice==2:
            centralLibrary.borrowbook(Student.requestBook())
        elif choice==3:
            centralLibrary.returnBook(Student.returnBook())  
        elif choice==4:
            print("Thanks for using Central Library. Have a great day ahead!")
            exit()
        else:
            print("Invalid choice. Please choose a valid option")
            
            
            
            
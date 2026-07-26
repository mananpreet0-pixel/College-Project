class Item():
    def __init__(self,title,author,year):
        self.title=title
        self.author=author
        self.year=year
    def display(self):
        print(f"Title:{self.title}")
        print(f"Author:{self.author}")
        print(f"year:{self.year}")
class Book(Item):
    def __init__(self,title,author,year,isbn,pages):
        super().__init__(title,author,year)
        self.isbn=isbn
        self.pages=pages
    def display(self):
        super().display()
        print(f"isbn:{self.isbn}")
        print(f"pages:{self.pages}")
class Magazine(Item):
    def __init__(self,title,author,year,issue_number,month):
        super().__init__(title,author,year)
        self.issue_number=issue_number
        self.month=month
    def display(self):
        super().display()
        print(f"issue_number:{self.issue_number}")
        print(f"month:{self.month}")
class Downloadable():
    def __init__(self,file_size,form):
        self.file_size=file_size
        self.form=form
    def download(self):
        print(f"file size:{self.file_size}")
        print(f"format:{self.form}")
class DigitalBook(Book,Downloadable):
    def __init__(self,title,author,year,isbn,pages,issue_number,month,file_size,form):
        Book.__init__(self,title,author,year,isbn,pages)
        Downloadable.__init__(self,file_size,form)
    def display(self):
        super().display()
        Downloadable.download(self)
        
b= Book("Python", "John Doe", 2822, "123456789", 300)
m= Magazine("Tech gomes", "Jone Swith", 2023, 45, "March")
d= DigitalBook("wonnderland", "Altce", 2024, "987654321",250,"235","may", 5, "POF/Word")
print("Book:")
b.display()
print("\nMogazine:")
m.display()
print("\nDigital Book:")
d. display()
        
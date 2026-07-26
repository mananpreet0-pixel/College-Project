import tkinter as tk
class Student():
    def __init__(self,name,marks):
        self.name=name
        if not self.name.isalpha():
            entry1.delete(0,tk.END)
            raise ValueError("Invalid Name")
        entry1.delete(0,tk.END)
    def display(self):
        result1.config(text=f"Name:{self.name}")
class Result(Student):
    def __init__(self,name,marks):
        try:
            super().__init__(name,marks)
            self.marks=int(marks)
        except:
            result2.config(text="Invalid input")
            entry2.delete(0,tk.END)
            return
        if self.marks<0 or self.marks>100:
            result2.config(text="Invalid input")
        elif self.marks>=40:
            super().display()
            result2.config(text="Pass")
        else:
            super().display()
            result2.config(text="Fail")
        entry2.delete(0,tk.END)
root=tk.Tk()
root.title("Result Calculator")
root.geometry("500x500")
l1=tk.Label(root,text='Enter your Name',font=("Arial",10))
l1.pack(pady=10)
entry1=tk.Entry(root,font=("Arial",8))
entry1.pack(pady=10)
l2=tk.Label(root,text='Enter your Marks',font=("Arial",10))
l2.pack(pady=10)
entry2=tk.Entry(root,font=("Arial",8))
entry2.pack(pady=10)
bt=tk.Button(root,text="Submit",font=("Arial",10),command=lambda:Result(entry1.get(),entry2.get()))
bt.pack(pady=15)
result1=tk.Label(root,text='',font=("Arial",10))
result1.pack(pady=10)
result2=tk.Label(root,text='',font=("Arial",10))
result2.pack(pady=10)
root.mainloop()

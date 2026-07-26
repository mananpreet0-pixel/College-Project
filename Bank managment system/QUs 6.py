import tkinter as tk
class Gui:
    def __init__(self):
        self.root=tk.Tk()
        self.root.title("Wicket App")
        self.root.geometry("500x500")
        self.label=tk.Label(self.root,text='wicket',font=('Arial',18))
        self.label.pack(padx=10,pady=50)
        self.entry=tk.Entry(self.root,font=('Arial',18))
        self.entry.pack(padx=10,pady=10)
        self.bt=tk.Button(self.root,text='Submit',font=('Arial',18),command=self.display)
        self.bt.pack(padx=10,pady=10)
        self.result=tk.Label(self.root,text='',font=('Arial',18))
        self.result.pack(pady=10)
        self.root.mainloop()
    def display(self):
        if self.entry.get()=='10':
            self.result.config(text="Congratulation")
        else:
            self.entry.delete(0, tk.END)
        
t=Gui()


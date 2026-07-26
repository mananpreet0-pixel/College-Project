import tkinter as tk

root=tk.Tk()
root.title("FIRST GUI")
label=tk.Label(root,text="FIRST GUI",font=('Arial',10))
label.pack(padx=10,pady=10)
textbox=tk.Text(root,height=5,font=('Arial',10))
textbox.pack(padx=10,pady=10)
bt1=tk.Button(root,text="click me",font=('Arial',10))
bt1.pack(padx=10,pady=10)
bt=tk.Label(root,text="First GUI program congratulation Manan",font=('Arial',10))
bt.pack(padx=10,pady=10)
root.mainloop()

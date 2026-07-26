import tkinter as tk
root=tk.Tk()
root.title("Result Calculator")
root.geometry("500x500")
def check():
    try:
        value=int(entry.get())
    except:
        result.config(text="Invalid input")
        entry.delete(0,tk.END)
        return
    if value<0 or value>100:
        result.config(text="Invalid input")
    elif value>=40:
        result.config(text="Pass")
    else:
        result.config(text="Fail")
    entry.delete(0,tk.END)
label=tk.Label(root,text='Enter Marks',font=("Arial",10))
label.pack(pady=10)
entry=tk.Entry(root,font=('Arial',10))
entry.pack(pady=10)
bt=tk.Button(root,text='Check Result',font=("Arial",8),command=check)
result=tk.Label(root,text="",font=("Arial",10))
result.pack(pady=10)
bt.pack(pady=10)
root.mainloop()

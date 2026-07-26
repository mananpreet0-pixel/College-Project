import tkinter as tk
root=tk.Tk()
root.title("Wicket")
root.geometry('500x500')
def Check():
    value = entry.get()
    if value=='10':
       result.config(text="Congratulations")
       entry.delete(0,tk.END)
    else:
        entry.delete(0,tk.END)
label=tk.Label(root,text='wicket',font=('Arial',18))
label.pack(padx=10,pady=10)
entry=tk.Entry(root,font=('Arial',18))
entry.pack(padx=10,pady=10)
bt=tk.Button(root,text="Submit",font=('Arial',18),command=Check)
bt.pack(padx=10,pady=10)
result =tk.Label(root, text="", font=("Arial", 14))
result.pack(pady=10)
root.mainloop()

     
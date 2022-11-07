import tkinter

import pyautogui
from tkinter import *
import time

root=Tk()
root.geometry('423x250')
root.maxsize(423 ,250)
root.minsize(423,250)
root.config()
root.title("Auto-SMS ___ Shuvo\'s GUI ")

"""
# Add image file
bg = PhotoImage(file="hack.gif")

# Show image using label
label1 = Label(root, image=bg)
label1.place(x=0, y=0)


"""

# this is Label 01
t1=Label(root,text="Auto SMS Sender", fg='blue',font=('Times',18) )
t1.pack(pady=30)



# user Enter Section

user_input=StringVar
user_entry = Entry(root,textvariable=user_input)
user_entry.pack(pady=(10,0))

time.sleep(2)
# Main Function
def shuvo():
    while True:
        time.sleep(2)
        pyautogui.write(user_entry.get())
        pyautogui.press("enter")

# Is there Button  For Aciton
b1 = Button(root,text="Send 🥰", command= shuvo )
b1.pack(side=tkinter.LEFT,padx = (150, 0))      # pack starts packing widgets on the left


# Is there Button  For Aciton
b2 = Button(root,text="Stop", command= root.quit() )
b2.pack(side=tkinter.RIGHT,padx = (0, 150))


root.mainloop()


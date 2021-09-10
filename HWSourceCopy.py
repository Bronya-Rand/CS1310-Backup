
import os
import shutil
import sys
from tkinter import filedialog,  messagebox

valid_files = ('.cpp', '.h')

folderToCopyFiles = filedialog.askdirectory(title="Select Folder to Copy Files From", 
                    initialdir=os.getcwd())

if folderToCopyFiles == "":
    messagebox.showerror("Error!", "No copy directory was set.")
    sys.exit(1)

folderToPasteFiles = filedialog.askdirectory(title="Select Folder to Paste Files To", 
                        initialdir=os.getcwd())
                        
if folderToPasteFiles == "":
    messagebox.showerror("Error!", "No paste directory was set.")
    sys.exit(1)

for x in os.listdir(folderToPasteFiles):
    os.remove(os.path.join(folderToPasteFiles, x))

for root, dirs, files in os.walk(folderToCopyFiles):
    for x in files:
        if x.endswith((valid_files)):
            shutil.copy2(os.path.join(root, x), os.path.join(folderToPasteFiles, x))

messagebox.showinfo("Success!", f"Copied all source data over to \n{folderToPasteFiles}.")
sys.exit(0)

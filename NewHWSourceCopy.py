
import os
import shutil
import sys
from tkinter import filedialog,  messagebox
from zipfile import ZipFile

folderCopy = False

def walkpath(basePath, copyPath=None, zipclass=None, zip=False):
    if zip and not zipclass:
        messagebox.showerror("Error!", "No ZIP class was defined!")
        sys.exit(1)
    elif not zip and not copyPath:
        messagebox.showerror("Error!", "No paste path was defined!")
        sys.exit(1)

    for root, dirs, files in os.walk(basePath):
        for x in files:
            if x.endswith((valid_files)):
                if not zip:
                    shutil.copy2(os.path.join(root, x), os.path.join(copyPath, x))
                else:
                    zipclass.write(os.path.join(root, x))

folderToCopyFiles = filedialog.askdirectory(title="Select Folder to Copy Files From", 
                    initialdir=os.getcwd())

if folderToCopyFiles == "":
    messagebox.showerror("Error!", "No copy directory was set.")
    sys.exit(1)

if "CS2313" in folderToCopyFiles:
    valid_files = ('.cpp', '.h')
    folderCopy = True
elif "CS2323" in folderToCopyFiles:
    valid_files = ('.java')
elif "CS2350" in folderToCopyFiles:
    valid_files = ('.c', '.sdl')
    folderCopy = True
else:
    messagebox.showerror("Error!", "Cannot determine class type from path.")
    sys.exit(1)

if folderCopy:
    folderToPasteFiles = filedialog.askdirectory(title="Select Folder to Paste Files To", 
                            initialdir=os.getcwd())
                            
    if folderToPasteFiles == "":
        messagebox.showerror("Error!", "No paste directory was set.")
        sys.exit(1)

    for x in os.listdir(folderToPasteFiles):
        os.remove(os.path.join(folderToPasteFiles, x))

    walkpath(folderToCopyFiles, folderToPasteFiles)

    messagebox.showinfo("Success!", f"Copied all source data over to \n{folderToPasteFiles}.")
else:
    with ZipFile(os.getcwd() + "/DelCarmen - " + folderToCopyFiles.replace("\\", "/").split("/")[-1] + ".zip", "w") as dc:
        walkpath(folderToCopyFiles, zipclass=dc, zip=True)

    messagebox.showinfo("Success!", f"Zipped all source data over to \n" + os.getcwd() + "/DelCarmen - " + folderToCopyFiles.replace("\\", "/").split("/")[-1] + ".zip.")

sys.exit(0)

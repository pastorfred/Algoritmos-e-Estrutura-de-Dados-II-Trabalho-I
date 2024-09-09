import sys
sys.setrecursionlimit(10**6)

def alesti2_t1(string):
    dictionary = {"AD": "N", "DA": "N", "DN": "A", "ND": "A", "AN": "D", "NA": "D"}
    for i in range(len(string)):
        if string[i:i+2] in dictionary:
            newString = string[:i] + string[i+2:] + dictionary[string[i:i+2]]
            return alesti2_t1(newString)
    return string
    
while (True):
    # Reads string from file
    string = ""
    filename = ""
    print("Please enter the name of the file you want to read from: ")
    filename = input()
    # read from file if possible
    try:
        file = open(filename, "r")
        string = file.readline()
        file.close()
    except:
        print("File not found")
        exit()
    print(alesti2_t1(string))
    print("Do you want to read another file? (y/n)")
    if input() != "y":
        break
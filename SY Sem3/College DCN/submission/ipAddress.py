#!"C:\Users\Devansh\AppData\Local\Programs\Python\Python38-32\python.exe"
import re

num = input("Enter the IP Address: ")
pattern = re.compile("\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}$")
test = pattern.match(num)

if(test):
    lis = str(num).split(".")
    flag = True
    for i in lis:

        if(not (0 <= int(i) < 256)):
            flag = False
        if(len(i) >= 2 and i[0] == "0"):
            flag = False

    if(flag == False or len(lis) != 4):
        print("Invalid IP Address")
    else:
        print("Valid")
        print(num)
        print("IP Address in binary is ", end="")
        for i in lis:
            print(format(int(i), "08b"), end=" ")
        fbyte = format(int(lis[0]), "08b")
        print()
        if(fbyte[0] == "0"):
            print("Class A")
            print("HostID: ", lis[0])
            print("NetworkID: ", ".".join(lis[1:]))
        elif(fbyte[1] == "0"):
            print("Class B")
            print("HostID: ", ".".join(lis[0:2]))
            print("NetworkID: ", ".".join(lis[2:]))
        elif(fbyte[2] == "0"):
            print("Class C")
            print("HostID: ", ".".join(lis[0:3]))
            print("NetworkID: ", lis[3])
        elif(fbyte[3] == "0"):
            print("Class D")
        else:
            print("Class E")
else:
    print("Invalid IP Address")

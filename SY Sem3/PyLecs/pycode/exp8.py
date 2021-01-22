f = open("./exp.txt", "w")
f.write("""
        It's been a long day without you, my friend
        And I'll tell you all about it when I see you again
        We've come a long way from where we began
        Oh, I'll tell you all about it when I see you again
        When I see you again
    """)
f.close()

spaces = 0
chars = 0
words = 0

f = open("./exp.txt")
f2 = open("./expOut.txt", "a+")
lines = f.readlines()
print("Number of lines :", len(lines))
for line in reversed(lines):
    words += len(line.split())
    for i in line:
        if (i == " "):
            spaces += 1
        else:
            chars += 1
    f2.write(line)

print("Number of words :", words)
print("Number of characters :", chars)
print("Number of spaces :", spaces)

f.close()
f2.close()

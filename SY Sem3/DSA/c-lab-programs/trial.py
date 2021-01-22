# cook your dish here
T = int(input())
for i in range(T):
    n = int(input())
    mlist = set((map(int, input().split())))
    count = 0
    for i in mlist:
        if(i != 0):
            count += 1
    print(count)

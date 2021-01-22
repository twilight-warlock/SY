# Question 1
# tot = 0
# flag = False
# for i in range(5):
#     val = int(input("Enter marks scored in subject " + str(i+1)+": "))
#     if(val > 100):
#         flag = True
#         print("Marks cannot be greater than 100")
#         break
#     tot += val
# if not flag:
#     print("Average is:", tot/5)

# Question 2
# for i in range(2, 11):
#     print("1/"+str(i)+" = "+str(1/i))

# Question 3
n = int(input("Enter a number: "))
while(n >= 0):
    print(n)
    n -= 1
print("Completed Countdown")

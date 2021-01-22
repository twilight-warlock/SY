class Student:
    total_marks = 500

    def __init__(self, roll_no, sub1, sub2, sub3, sub4, sub5, marks_obt):
        self.roll_no = roll_no
        self.sub1 = sub1
        self.sub2 = sub2
        self.sub3 = sub3
        self.sub4 = sub4
        self.sub5 = sub5
        self.marks_obt = marks_obt

    def marks_scored(self):
        self.marks_obt = self.sub1 + self.sub2 + self.sub3 + self.sub4 + self.sub5
        return self.marks_obt

    def percentage(self):
        return (self.marks_obt/Student.total_marks)*100

    def display(self):
        print("Roll No. : ", self.roll_no)
        print("Marks obtained in Subject 1 : ", self.sub1)
        print("Marks obtained in Subject 2 : ", self.sub2)
        print("Marks obtained in Subject 3 : ", self.sub3)
        print("Marks obtained in Subject 4 : ", self.sub4)
        print("Marks obtained in Subject 5 : ", self.sub5)
        print("Total marks obtained (out of 500) : ", self.marks_obt)


s1 = Student(1914078, 90, 99, 87, 85, 91, '')
s1.marks_scored()
s1.display()
print("Percentage : ", s1.percentage())
s2 = Student(1914079, 84, 100, 86, 90, 76, '')
s2.marks_scored()
s2.display()
print("Percentage : ", s2.percentage())
s3 = Student(1914080, 100, 91, 89, 85, 70, '')
s3.marks_scored()
s3.display()
print("Percentage : ", s3.percentage())

#!/usr/bin/python3

num = int(input())

while(num != 1):
    if(num % 3 == 0):
        print("%d  0" % num)
        num = num / 3
    elif((num + 1) % 3 == 0):
        print("%d  1" % num)
        num = (num + 1) / 3
    elif((num - 1) % 3 == 0):
        print("%d  -1" % num)
        num = (num - 1) / 3
print("1")

#!/usr/bin/python3.6

nums = [int(i) for i in input().split(" ")]
myset = set(range(1, len(nums) - 1))

calc = []

for i in range(0, len(nums) - 1):
    calc.append(abs(nums[i] - nums[i + 1]))

calc = set(calc)

if (calc.issuperset(myset)):
    print("Jolly Jumper")
else:
    print("Not Jolly Jumper")

# import math


# class SafeBetting:

#     def minRounds(self, a, b, c):
#         tempResult = float(c - a) / float(b - a)
#         tempResult = math.log(tempResult, 2)
#         tempResult = math.ceil(tempResult)
#         return int(tempResult)


# obj = SafeBetting()
# # print(obj.minRounds(1, 2, 3))
# print(obj.minRounds(15, 20, 48))
# print(obj.minRounds(10, 400, 560))
# print(obj.minRounds(5, 7, 21))
# print(obj.minRounds(5, 7, 22))
# print(obj.minRounds(17, 30, 1000))
import pprint
frequencyList = []
for eachNumberOfChar in range(1, 27):
    for eachLengthOfString in range(1, 51):
        tempResult = eachLengthOfString * eachNumberOfChar
        if tempResult not in frequencyList:
            frequencyList.append(tempResult)

print("len is: ", len(frequencyList))
frequencyList.sort()
pprint.pprint(frequencyList)
count = 1
for i in range(1, len(frequencyList)):
    if frequencyList[i] - 1 == frequencyList[i - 1]:
        count += 1
print("count is: ", count)

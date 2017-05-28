# #!/bin/python3

# # import sys


# n, c = input().strip().split(' ')
# n, c = [int(n), int(c)]
# crate = []
# for crate_i in range(c):
#     crate_t = [int(crate_temp) for crate_temp in input().strip().split(' ')]
#     crate.append(crate_t)
# # your code goes here

# allMatchBoxes = []
# for eachCrate in crate:
#     tempList = [eachCrate[1]] * eachCrate[0]
#     allMatchBoxes += tempList

# allMatchBoxes.sort(reverse=True)
# # print('allMatchBoxes are: ')
# # print(allMatchBoxes)
# # print()
# # i = 0
# totalMatchSticks = sum(allMatchBoxes[:n])
# # while i <= n and i < len(allMatchBoxes):
# #     print("n is: " + str(n) + " len of allMatchBoxes is: " + str(len(allMatchBoxes)))
# #     print("i is: " + str(i) + ' and matchsticks till now are: ' + str(totalMatchSticks))
# #     print()
# #     totalMatchSticks += allMatchBoxes[i]
# #     i += 1
# print(totalMatchSticks)


#!/bin/python3

# import sys


n, c = input().strip().split(' ')
n, c = [int(n), int(c)]
crate = []
allMatchBoxes = []
for crate_i in range(c):
    crate_t = tuple(map(int, input().strip().split(' ')))
    # crate_t = list(map(int, input().strip().split(' ')))
    allMatchBoxes.append(crate_t)
# your code goes here
# print(allMatchBoxes)
# for eachCrate in crate:
#    tempList = [eachCrate[1]] * eachCrate[0]
#    allMatchBoxes += tempList

allMatchBoxes.sort(reverse=True, key=lambda x: x[1])
# print(allMatchBoxes)
totalMatchSticks = 0
i = 0
while i < len(allMatchBoxes) and n > 0:
    if allMatchBoxes[i][0] >= n:
        totalMatchSticks += n * allMatchBoxes[i][1]
        n = 0
    else:
        totalMatchSticks += allMatchBoxes[i][0] * allMatchBoxes[i][1]
        n -= allMatchBoxes[i][0]
    i += 1
# totalMatchSticks = sum(allMatchBoxes[:n])
print(totalMatchSticks)

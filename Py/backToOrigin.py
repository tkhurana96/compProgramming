#!/bin/python3

# import sys


xTreasure, yTreasure = input().strip().split(' ')
xTreasure, yTreasure = [int(xTreasure), int(yTreasure)]
n = int(input().strip())
direction = []
for direction_i in range(n):
    direction_t = [int(direction_temp) for direction_temp in input().strip().split(' ')]
    direction.append(direction_t)

# print(direction)
xDistance = 0
yDistance = 0
for each_distance in direction:
    xDistance += each_distance[0]
    yDistance += each_distance[1]

xDistance = xTreasure - xDistance
yDistance = yTreasure - yDistance
print(str(xDistance) + " " + str(yDistance))
# your code goes here

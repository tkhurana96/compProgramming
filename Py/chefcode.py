import functools
from pprint import pprint

n, k = list(map(int, input().strip().split(' ')))

values = list(map(int, input().strip().split(' ')))

valuesOne = values

print("\n   part 1...: n = ", n, " k = ", k)
print(" values are: ", valuesOne)

subsets = []

for eachValue in valuesOne:
    currentSubsets = [[eachValue]]
    for eachSubset in subsets:
        currentSubsets.append(eachSubset + [eachValue])
    subsets += currentSubsets

print(len(subsets))
subsets.sort(key=lambda eachSubset: len(eachSubset))

for eachSubset in subsets:
    eachSubset = eachSubset.append(functools.reduce(lambda x, y: x * y, eachSubset))

subsets.sort(key=lambda eachSubset: eachSubset[len(eachSubset) - 1])
allActualgoodSubsets = list(filter(lambda l: l[len(l) - 1] < k, subsets))
NumactualGoodSubsets = len(allActualgoodSubsets)
print("NumactualGoodSubsets: ", NumactualGoodSubsets)
pprint(allActualgoodSubsets)

# =================================================================================================================

print("\n   part 2...: n = ", n, " k = ", k)
print(" values are: ", values)

prods = [[1] * n for i in range(n)]

values = list(filter(lambda val: val < k, values))
# goodSubsets = len(values)
goodSubsets = 0

for i in range(n):
    prods[i][i] = values[i]

for row in range(0, n):
    for col in range(row + 1, n):
        if prods[row][col - 1] != -1:
            tempProd = prods[row][col - 1] * values[col]
            if tempProd > k:
                prods[row][col] = -1
            else:
                prods[row][col] = tempProd
        else:
            prods[row][col] = -1

pprint(prods)

allSupposedGoodSets = []

for row in range(0, n):
    for col in range(row, n):
        if prods[row][col] != -1:
            print(" row is: ", row, " col is: ", col)
            for i in range(0, row):
                for j in range(i, row):
                    if prods[i][j] != -1:
                        print("     i is: ", i, " j is: ", j)
                        if prods[row][col] * prods[i][j] < k:
                            goodSubsets += 1
                            print("         this one is also in it: ", values[i:j + 1] + values[row:col + 1] + [prods[row][col] * prods[i][j]])
                            allSupposedGoodSets.append(values[i:j + 1] + values[row:col + 1] + [prods[row][col] * prods[i][j]])

print("allSupposedGoodSets: ")
pprint(allSupposedGoodSets)
print("\nNumSupposedgoodSubsets: ", len(allSupposedGoodSets))
print("\n\n\n goodSubsets is: ", goodSubsets)

# =================================================================================================================

print("comparison of two approaches: ...")

print("things which are extra in allSupposedGoodSets: ")
for eachThing in allSupposedGoodSets:
    if eachThing not in allActualgoodSubsets:
        print(eachThing)

print("things which are extra in allActualgoodSubsets: ")
for eachThing in allActualgoodSubsets:
    if eachThing not in allSupposedGoodSets:
        print(eachThing)

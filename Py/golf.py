def calc(S):
    ans = [x == S[-1] for x in S[::-1] + '~']
    print("	this is the ans list: ", ans)
    return ans.index(False)


# print(calc("3333"))

aList = [1, 2, 3]
newList = aList[::-1]

print("	aList is: ", aList)
print("	newList is: ", newList)

print()
aList[1] += 8

print("	aList is: ", aList)
print("	newList is: ", newList)

n = int(input())
x = int(input())

totalCombinations = (2 ** n) - 1
if x >= totalCombinations:
	print(x - totalCombinations)
else:
	print(totalCombinations - x)
	

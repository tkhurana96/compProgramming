class Xylophone:
	def countKeys(self, x):
		allBars = [0] * 8
		for eachPressedBar in x:
			allBars[eachPressedBar % 7 + 1] |= 1
		return sum(allBars)

classObj = Xylophone()
print classObj.countKeys([1,8,3])
print classObj.countKeys([7,1,5,8,9,10,11,12])
print classObj.countKeys([1,8,15])
print classObj.countKeys([25,1,17,9,8])
print classObj.countKeys([11,11,11,11,11,11,11,11,11,11,11])
print classObj.countKeys([50,10,20,30,11,30,24,38,5,2,9])

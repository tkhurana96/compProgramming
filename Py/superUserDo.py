class SuperUserDo:
	def install(self, A, B):
		# newA = list(A)
		# newA = map(int, newA)
		# newB = list(B)
		# newA = map(int, newB)
		# print max(A), max(B)
		finalList = [0]*(max(max(A), max(B)) + 1)
		# print finalList
		for i, j in zip(A, B):
			l = i
			m = j+1
			for k in range(int(l), int(m)):
				# print "orring for k =", k 
				finalList[k] |= 1
		return sum(finalList)

# obj = SuperUserDo()
# print obj.install({1}, {1})
# print obj.install({1,101}, {10,110})
# print obj.install({1}, {1000})
# print obj.install({1,2,3,4,5}, {6,7,8,9,10})
# print obj.install({1,1}, {1,1})


       

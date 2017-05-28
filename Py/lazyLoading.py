import math
t = int(raw_input(''))
total = t + 1
while t > 0:
	currentCase = total - t
	n = int(raw_input(''))
	weights = []
	while n > 0:
		ithWeight = int(raw_input(''))
		weights.append(ithWeight)
		n -= 1
	weights.sort()
	start = 0
	end = len(weights) - 1
	diffCounter = 0
	while start < end:
		# if weights[start] >= 50:
		# 	end -= 1
		# else:
		if weights[end] < 50:
			something = math.ceil(50.0 / weights[end]) - 1
			if start + something <= end:
				# weights[start: start+int(something)+1] = [weights[end]] * int(something)
				for i in range(0,int(something)):
					weights[start + i] = weights[end]
				diffCounter += 1
				start += int(something)
			else:
				weights[end] = weights[end + 1]
		else:
			diffCounter += 1
		end -= 1
	# finalSet = set(weights)
	print "Case #"+str(currentCase)+": "+str(diffCounter)
	t -= 1
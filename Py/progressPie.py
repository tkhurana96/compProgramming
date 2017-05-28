import math
t = int(raw_input(''))
total = t + 1
while t > 0:
	currentCase = total - t
	(p, x, y) = map(int, raw_input('').split(' '))
	if p == 0.0:
		print "Case #"+str(currentCase)+": white"
		t -= 1
		continue
	x = x - 50.0
	y = y - 50.0
	angleColored = (p * 360) / 100.0
	angleOfGivenPoint = math.degrees(math.atan2(x, y)) - math.degrees(math.atan2(0,50))
	if angleOfGivenPoint < 0.0:
		angleOfGivenPoint += 360.0
	if angleOfGivenPoint > angleColored:
		distanceOfGivenPoint = math.hypot(x,y)
		if distanceOfGivenPoint <= 50.000001:
			# distanceOfGivenPointFromVerticalLine = 
			if angleOfGivenPoint - angleColored < 180:
				angleColoredInAnticlockwiseDirection = -angleColored + 360.000000 
				if angleColoredInAnticlockwiseDirection < 270 :
					angleColoredInAnticlockwiseDirection += 90
				else:
					angleColoredInAnticlockwiseDirection -= 270
				slopeOfOtherLine = math.tan(math.radians(angleColoredInAnticlockwiseDirection))
				distanceOfGivenPointFromOtherLine = abs((y - slopeOfOtherLine*x) / math.sqrt(1 + (slopeOfOtherLine ** 2)))
				if distanceOfGivenPointFromOtherLine < 0.000001 : #or distanceOfGivenPointFromVerticalLine < 0.000001
					print "Case #"+str(currentCase)+": black"
				elif (x >= -50.000000 and x <= 0.000000) and (y >= 0.000000 and y <= 50.000000):
					 distanceOfGivenPointFromVerticalLine = abs(x)
					 if distanceOfGivenPointFromVerticalLine < 0.000001:
					 	print "Case #"+str(currentCase)+": black"
					 else:
					 	print "Case #"+str(currentCase)+": white"
				else:
					print "Case #"+str(currentCase)+": white"
			else:
				print "Case #"+str(currentCase)+": white"
		else:
			print "Case #"+str(currentCase)+": white" 
	else:
		distanceOfGivenPoint = math.hypot(x,y)
		if distanceOfGivenPoint <= 50.000001:
			print "Case #"+str(currentCase)+": black"
		else:
			print "Case #"+str(currentCase)+": white" 
	t -= 1
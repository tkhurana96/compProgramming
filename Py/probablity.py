import math
from functools import reduce

import operator as op
def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, range(n, n-r, -1))
    denom = reduce(op.mul, range(1, r+1))
    return numer//denom

t = int(input(''))
total = t+1
while t > 0:
	currentCase = total - t
	(h, s) = map(int, input("").split(' '))
	allSpells = input("").split(' ')
	maxSpell = None
	for eachSpell in allSpells:
		newH = h
		if '+' in eachSpell:
			eachSpellInt = eachSpell.split('+')[1]
			eachSpell = eachSpell.split('+')
			newH -= int(eachSpellInt)
		elif '-' in eachSpell:
			eachSpellInt = eachSpell.split('-')[1]
			eachSpell = eachSpell.split('-')
			newH += int(eachSpellInt)
		(X,Y) = map(int, eachSpell.split('d'))
		maxOfThis = X*Y
		minOfThis = X
		if newH > maxOfThis:
			continue
		elif newH < minOfThis:
			maxSpell = 1
		else:
			ans = 0
			for eachSum in range(newH, maxOfThis+1):
				currentAns = 0
				for i in range(0, math.floor((eachSum - X)/Y) + 1):
					currentAns += ((-1)**i * (ncr(X,i)) * ((ncr(eachSum-Y*i-1,X-1))))
				ans += currentAns
			if maxSpell is not None:
				maxSpell = max(maxSpell, ans)
			else:
				maxSpell = ans
	print("Case #"+str(currentCase)+": "+str(maxSpell))
	t -= 1
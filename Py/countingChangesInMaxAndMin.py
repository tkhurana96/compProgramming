n = input("")
scores = list(map(int, input().split(' ')))

minSoFar = scores[0]
maxSoFar = scores[0]

maxChangesCount = 0
minChangesCount = 0

for i in range(1, len(scores)):
    if scores[i] > maxSoFar:
        maxSoFar = scores[i]
        maxChangesCount += 1
    if scores[i] < minSoFar:
        minSoFar = scores[i]
        minChangesCount += 1

print(maxChangesCount, minChangesCount)

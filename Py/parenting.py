t = int(input())

totalCases = t

while t > 0:

    ac, aj = list(map(int, input().split(' ')))

    cTimings = []
    jTimings = []

    for i in range(1, ac + 1):
        cTimings.append(tuple(input().split(' ')) + ('C',))

    for j in range(1, aj + 1):
        jTimings.append(tuple(input().split(' ')) + ('J',))

    print("cTimings is: ", cTimings)
    print("jTimings is: ", jTimings)

    timings = cTimings + jTimings
    timings.sort(key=lambda tup: tup[0])

    print("timings is: ", timings)

    currentPerson = ' '
    if timings[0][2] == 'J':
        currentPerson = 'C'
    else:
        currentPerson = 'J'

    firstPerson = currentPerson
    exchanges = 0

    for eachTiming in timings:
        if eachTiming[2] == 'J' and currentPerson == 'J':
            currentPerson = 'C'
            exchanges += 1
        elif (eachTiming[2] == 'C' and currentPerson == 'C'):
            currentPerson = 'J'
            exchanges += 1

    if firstPerson != currentPerson:
        exchanges += 1
    print("Case #" + str(totalCases - t + 1) + ": " + str(exchanges))
    t -= 1

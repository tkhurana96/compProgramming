import math

t = int(input())

totalCases = t

while t > 0:

    n, k = list(map(int, input().split(' ')))

    rah = []

    for i in range(1, n + 1):
        rah.append(tuple(map(int, input().split(' '))))

    maxRadius = max(rah, key=lambda tup: tup[0])
    # otherArea = (math.pi * maxRadius[0] * maxRadius[0])

    for i in range(len(rah)):
        rah[i] = rah[i] + ((2 * math.pi * rah[i][0] * rah[i]
                            [1]), (math.pi * rah[i][0] * rah[i][0]),)

    rah.sort(key=lambda tup: (-(tup[2] + tup[3])))
    # , -tup[0]))

    curvedSurfaceArea = 0.0000000

    picked = 0

    # while picked <= k:
    #     curvedSurfaceArea += (2 * math.pi * rah[picked][0] * rah[picked][1])
    #     if (picked != k):
    #         otherArea += (math.pi * ((rah[picked][0]
    #                                   * rah[picked][0]) - (rah[picked + 1][0] * rah[picked + 1][0])))
    #     else:
    #         otherArea += (math.pi * rah[picked][0] * rah[picked][0])
    #     picked += 1

    print(rah)

    while picked != k:
        if (picked == 1):
            otherArea = rah[picked][3]
        curvedSurfaceArea += rah[picked][2]
        picked += 1

    # otherArea = rah[0][3]
    print("Case #" + str(totalCases - t + 1) + ": " +
          str(float(curvedSurfaceArea)))

    t -= 1

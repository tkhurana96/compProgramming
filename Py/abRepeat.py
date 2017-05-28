t = int(input())

while t > 0:
    (n, k) = list(map(int, input().split(' ')))
    s = input()

    countsOfB = [0] * len(s)
    # print("initially counts of b is: ", countsOfB)

    if s[len(s) - 1] == 'b':
        countsOfB[len(s) - 1] = 1

    for index in range(len(s) - 2, -1, -1):
        # print("index = " + str(index) + " countsOfB[index] is: " + str(countsOfB[index]))
        countsOfB[index] = countsOfB[index + 1]
        if s[index] == 'b':
            countsOfB[index] += 1

    # print("now counts of b is(b on right of each char): ", countsOfB)

    totalBinString = countsOfB[0]

    totalAinString = 0
    for eachChar in s:
        if eachChar == 'a':
            totalAinString += 1

    # for index in range(0, len(countsOfB)):
    #     countsOfB[index] *= k

    # print("now counts of b is(*k): ", countsOfB)

    totalPairs = 0

    for index in range(0, len(s)):
        if s[index] == 'a':
            # print("inside if")
            totalPairs = totalPairs + (countsOfB[index] * k)

    extra = ((k * (k - 1)) // 2) * totalBinString * totalAinString
    # print("extra is: " + str(extra))

    print(totalPairs + extra)

    t -= 1

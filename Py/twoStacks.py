g = int(input())
while g > 0:

    (n, m, x) = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if sum(a) + sum(b) <= x:
        print(len(a) + len(b))
    else:
        result = [[0 for i in range(len(b) + 1)] for j in range(len(a) + 1)]
        boundaries = [-1 for k in range(len(a) + 1)]
        col = 0
        row = 0
        while row < len(a) + 1:
            while col < len(b) + 1:
                if (row != 0 or col != 0):
                    if row == 0:
                        result[row][col] = sum(b[:col])
                    elif col == 0:
                        result[row][col] = sum(a[:row])
                    else:
                        result[row][col] = result[row][0] + result[0][col]
                    if (result[row][col] >= x) and (boundaries[row] == -1):
                        boundaries[row] = col
                        if col == 0:
                            row = len(a) + 1
                            break
                        else:
                            col = 0
                            break
                col += 1
            row += 1

        # for eachRow in result:
        #     print(eachRow)
        # print("boundaries are: ", boundaries)

        maxVal = None
        for index, eachEntry in enumerate(boundaries):
            eachEntry -= 1 if result[index][eachEntry] > x else 0
            temp = eachEntry + index
            maxVal = max(temp, maxVal) if maxVal is not None else temp

        print(maxVal)

    g -= 1

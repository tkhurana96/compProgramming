t = int(input())
while t > 0:
    matrix = list()
    m = input().split()
    m = [int(x) for x in m]
    matrix.append(m)
    o = input().split()
    o = [int(x) for x in o]
    matrix.append(o)
    p = input().split()
    p = [int(x) for x in p]
    matrix.append(p)
    # print(matrix)
    sum_rows = [sum(x) for x in matrix]
    sum_cols = [sum(x) for x in zip(*matrix)]
    maximum = max(max(sum_rows), max(sum_cols))
    if maximum == 0:
        print('0')
    else:
        if maximum % 2 == 0:
            print(maximum - 1)
        else:
            print(maximum)
    t -= 1

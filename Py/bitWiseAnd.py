n = 20
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        print(" ", i & j, end=" ")
    print("\n")

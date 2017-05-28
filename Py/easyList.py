def GCD(a, b):
    
    if b == 0:
        return a
    else:
        return GCD(b, a % b)

t = int(input())
while(t > 0):
    str = raw_input().split()
    n = int(str[0])
    k = int(str[1])
    str = raw_input().split()
    a = [int(num) for num in str]

    gcd = reduce(lambda x,y:GCD([x,y]), a)
        #   reduce(lambda x,y:GCD([x,y]), numbers)


    product = prod(a)

    if (product / gcd) % k == 0:
        print 'YES'
    else:
        print 'NO'
    t -= 1
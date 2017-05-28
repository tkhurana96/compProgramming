t = int(input(""))
while t > 0:
    (c, d, l) = map(int, input("").split(" "))
    spottedAnimals = l / 4
    # print('animals actually: ',c+d)
    # print('animals spotted: ',spottedAnimals)
    if l % 4 == 0:
        # spottedAnimals = l / 4
        # print('animals spotted: ',spottedAnimals)
        if c <= 2 * d:
            if (d <= spottedAnimals) and (spottedAnimals <= d + c):
                print('yes')
            else:
                print('no')
        else:
            if c - d <= spottedAnimals and spottedAnimals <= d + c:
                print('yes')
            else:
                print('no')
    else:
        print('no')
    # if l > 4*c + 4*d:
    #   print("no")
    # else:
    #   if c <= 2*d:
    #       if l >= 4*d:
    #           print('yes')
    #       else:
    #           print('no')
    #   elif c > 2*d:
    #       if l >= 4*(c - d):
    #           print('yes')
    #       else:
    #           print('no')
    t -= 1

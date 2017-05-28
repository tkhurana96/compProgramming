class ThreeIncreasing:

    def minEaten(self, a, b, c):
        MinEaten = 0
        if c > b:
            if b > a:
                pass
            elif b < a:
                if b == 1:
                    MinEaten = -1
                else:
                    MinEaten += a - (b - 1)
                    a = b - 1
            else:
                if a == 1 and b == 1:
                    MinEaten = -1
                else:
                    a = b - 1
                    MinEaten += 1
        elif c < b:
            if c == 1:
                MinEaten = -1
            else:
                MinEaten += b - (c - 1)
                b = c - 1
            if b > a:
                pass
            elif b < a:
                if b == 1:
                    MinEaten = -1
                else:
                    MinEaten += a - (b - 1)
                    a = b - 1
            else:
                if a == 1 and b == 1:
                    MinEaten = -1
                else:
                    a = b - 1
                    MinEaten += 1
        else:
            if c == 1 and b == 1:
                MinEaten = -1
            else:
                if c == 1:
                    MinEaten = -1
                else:
                    MinEaten += 1
                    b = c - 1
                if b > a:
                    pass
                elif b < a:
                    if b == 1:
                        MinEaten = -1
                    else:
                        MinEaten += a - (b - 1)
                        a = b - 1
                else:
                    if a == 1 and b == 1:
                        MinEaten = -1
                    else:
                        a = b - 1
                        MinEaten += 1
        # print(MinEaten)
        return MinEaten


obj1 = ThreeIncreasing()
obj1.minEaten(15, 40, 22)
obj1.minEaten(5, 6, 6)
obj1.minEaten(6, 1, 3000)
obj1.minEaten(6, 4, 2)
obj1.minEaten(4, 2, 6)
obj1.minEaten(1, 1234, 3000)
obj1.minEaten(2789, 2400, 1693)
obj1.minEaten(3, 2, 2)

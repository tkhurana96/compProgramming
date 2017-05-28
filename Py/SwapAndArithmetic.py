# class SwapAndArithmetic:
#     def able(self, x):
# # x = map(int, raw_input('enter list: ').split(" "))
#       x.sort()
#       diff = None
#       flag = 0
#       for i in range(len(x) - 1):
#           newDiff = x[i+1] - x[i]
#           if diff:
#               if diff != newDiff:
#                   flag = 1
#                   break
#           else:
#               diff = newDiff
#       if flag == 1:
#           print "Impossible"
#       else:
#           print "Possible"


class SwapAndArithmetic:

    def able(self, x):
        # x = map(int, raw_input('enter list: ').split(" "))
        y = list(x)
        y.sort()
        if len(y) <= 2:
            return "Possible"
        diff = y[1] - y[0]
        flag = 0
        for i in range(1, len(y) - 1):
            newDiff = y[i + 1] - y[i]
            # if diff:
            if diff != newDiff:
                flag = 1
                break
            # else:
                #diff = newDiff
        if flag == 1:
            return "Impossible"
        else:
            return "Possible"

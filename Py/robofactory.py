class Robofactory():
    """docstring for Robofactory"""

    # def __init__(self, arg):
    #     super(Robofactory, self).__init__()
    #     self.arg = arg

    def reveal(self, data, answers):
        # corruptedPos = 0
        tempList = []
        for i in range(len(data)):
            if data[i] % 2 != 0:
                currentAns = 'Odd'
            else:
                currentAns = 'Even'
            tempList.append(currentAns)

        for i in range(1, len(tempList)):
            if tempList[i] != answers[i] and tempList[i - 1] == 'Odd':
                # corruptedPos = i
                return i
            elif tempList[i] == answers[i] and tempList[i - 1] == 'Even':
                return -1

        return 0

someObj = Robofactory()
print(someObj.reveal((3, 2, 2), ('Odd', 'Odd', 'Even')))
print(someObj.reveal((1, 3, 5, 10), ('Odd', 'Odd', 'Odd', 'Even')))
print(someObj.reveal((2, 3, 5, 10), ('Even', 'Odd', 'Odd', 'Even')))
print(someObj.reveal((2, 4, 6, 10), ('Even', 'Even', 'Even', 'Even')))
print(someObj.reveal((107,), ('Odd',)))
print(someObj.reveal((1, 1, 1), ('Odd', 'Odd', 'Even')))

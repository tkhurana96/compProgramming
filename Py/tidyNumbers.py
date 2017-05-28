results = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

digitWiseResults = []
temp = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
numOfDigits = 18

for i in range(1, numOfDigits + 1):
    print("i = ", i)
    for eachDigit in range(1, 10):
        # print("eachDigit = ", eachDigit)
        for eachNumber in list(temp):
            # print("     eachNumber: ", eachNumber)
            digitWiseResults.append(str(eachDigit) + eachNumber)
            # print("         appending to digitWise: ", str(eachDigit) + eachNumber)
            if eachNumber.startswith(str(eachDigit)):
                # print("         removing ", eachNumber)
                temp.remove(eachNumber)

    results += digitWiseResults
    print("sizeof results is: ", len(results))
    temp = digitWiseResults
    digitWiseResults = []

# print("sizeof results is: ", len(results))
# print("results is: ", results)
print()

# print("sizeof digitWiseResults is: ", len(digitWiseResults))
# print("digitWiseResults is: ", digitWiseResults)
# print()

# print("sizeof temp is: ", len(temp))
# print("temp is: ", temp)
# print()

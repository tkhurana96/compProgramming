data = input()
splittedInput = data.split(' ')
for i in range(len(splittedInput)):
    splittedInput[i] = int(splittedInput[i])
    #print(type(data))
#print(splittedInput)
print(max(splittedInput) -  min(splittedInput))
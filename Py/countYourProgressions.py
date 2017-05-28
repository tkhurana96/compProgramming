n = int(input())
a = list()
for i in range(n):
	x = int(input())
	a.append(x)
validAps = list()
validAps.append([a[0]])

#for each_number in range(1,n):
for each_number in a[1:n]:
	#print(validAps)
	current_size = len(validAps)
	for each_list in validAps[:current_size]:
		temp = list()
		if len(each_list) > 2:
			if 2*each_list[-1] == each_list[-2] + each_number:
				each_list.append(each_number)
				#print('appended ',each_number,' to a list: ',each_list)
		elif len(each_list) == 2:
			temp.extend( each_list )
			if 2*temp[-1] == temp[-2] + each_number:
				temp.append(each_number)
				validAps.append(temp)
				#print('appended ',temp ,' to validAps')
		else:
			temp.extend( each_list )
			temp.append(each_number)
			validAps.append(temp)
			#print('appended ',temp ,' to validAps')
	validAps.append([each_number])
	#print('appended ',[each_number],' list to validAps')

print(validAps)
print( (len(validAps)+1) % 1000000009 ) 

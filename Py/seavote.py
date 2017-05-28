t = int(input())
while t > 0:
	n = int(input())
	arr = input().split()
	numbers = [int(x) for x in arr if int(x) > 0]
	if sum(numbers) > 100:
		if sum(numbers) - 100 < len(numbers):
			print("YES")
		else:
			print("NO")
	elif sum(numbers) < 100:
		print("NO")
	else:
		print("YES")
	t -= 1


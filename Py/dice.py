# # from pprint import pprint
import matplotlib.pyplot as plt
sums = {}
faces = 12
for i in range(1, faces + 1):
	for j in range(1, faces + 1):
		for k in range(1, faces + 1):
			sums[i+j+k] = sums.get(i+j+k, 0) + 1
# plt.bar(sums.keys(), sums.values())
# plt.show()




sortedSums = sorted(sums.items())
for (key, value)  in sortedSums:
	print(key ," : " , value , '*' * value)
# pprint(sums)

# x = range(0,100)

# plt.bar(range(0,100), x)

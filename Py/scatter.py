import matplotlib.pyplot as plt

t = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 51, 52, 53, 100, 101, 102, 150, 151, 200, 500]

cppNumReq = [25459, 46722, 70935, 93547, 99657, 141184, 161180, 179235, 204662, 230158, 934361, 1001170, 1094241, 1120183, 1984667, 1948570, 2127896, 3072784, 3032639, 3949929, 10590987]
cNumReq = [27815, 53178, 80207, 106986, 132982, 157364, 186505, 204998, 228459, 258602, 1218298, 1300077, 1294793, 1334914, 2402664, 2354194, 2085850, 3450077, 3220439, 4241432, 9226776]

plt.title('Time v/s Connections')
# plt.scatter(t, , marker='^')

width = 10

ax = plt.subplot(111)

# leftt = [x - width for x in t]
rightt = [x for x in t]

# rects1 = ax.bar(leftt, cppNumReq, width=1, color='r', align='center')
rects2 = ax.bar(rightt, cNumReq, width=1, color='b', align='center')

ax.set_ylabel('Number of Requests per Second')
# ax.set_xlabel(t + width)
# ax.set_xticklabels(t)

# ax.legend((rects1[0], rects2[0]), ('C++', 'C'))

plt.show()

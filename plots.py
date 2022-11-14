import matplotlib.pyplot as plt
import numpy as np

#read data from files
selection_data = np.loadtxt('../data/selection.txt')
bubble_data = np.loadtxt('../data/bubble.txt')
insertion_data = np.loadtxt('../data/insertion.txt')
merge_data = np.loadtxt('../data/merge.txt')
quick_data = np.loadtxt('../data/quick.txt')
heap_data = np.loadtxt('../data/heap.txt')

#create x axis values
x = np.arange(0, 10000, 100)

#create and display selection sort graph
plt.plot(x, selection_data)
plt.title('Selection Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/selection.png')
plt.show()

#create and display bubble sort graph
plt.plot(x, bubble_data)
plt.title('Bubble Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/bubble.png')
plt.show()

#create and display insertion sort graph
plt.plot(x, insertion_data)
plt.title('Insertion Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/insertion.png')
plt.show()

#create and display merge sort graph
plt.plot(x, merge_data)
plt.title('Merge Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/merge.png')
plt.show()

#create and display quick sort graph
plt.plot(x, quick_data)
plt.title('Quick Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/quick.png')
plt.show()

#create and display heap sort graph
plt.plot(x, heap_data)
plt.title('Heap Sort')
plt.xlabel('Input Size')
plt.ylabel('Duration (microseconds)')
plt.savefig('../images/heap.png')
plt.show()


plt.plot(x, selection_data, label= "selection sort")
plt.plot(x, bubble_data, label="bubble sort")
plt.plot(x, quick_data, label="quick sort")
plt.plot(x, merge_data, label="mergesort")
plt.plot(x, insertion_data, label= "insertion sort")
plt.plot(x, heap_data, label="heap sort")
plt.legend()
plt.savefig('../images/allcombined.png')
plt.show()
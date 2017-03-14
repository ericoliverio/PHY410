import sys

val = sys.argv[1]

def avg(name):
   recordsfile = open(name)
   total = 0.0
   count = 0
   for line in recordsfile:
      count += 1
      print line
      list1 = line.split(',')
      score = float(list1[2])
      total += score
   return total / count


print("The class average is: " + str(avg(val)))

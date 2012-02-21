from itertools import permutations as perm

berlin     = 0
brussels   = 1
dusseldorf = 2
luxem      = 3
munic      = 4
paris      = 5

distance = [[0, 783, 564, 764, 585, 1057],
            [783, 0, 223, 219, 771, 308],
            [564, 223, 0, 224, 613, 497],
            [764, 219, 224, 0, 517, 375],
            [585, 771, 613, 517, 0, 832],
            [1057, 308, 497, 375, 832, 0]]

def get_distance(path):
  totalDistance = 0
  vertex = 0

  while vertex < len(path):

    vertex2 = vertex + 1
    if vertex2 >= len(path):
      vertex2 = len(path)-1

    totalDistance += distance[ path[vertex] ][ path[vertex2]]
    vertex += 1

  return totalDistance


comb = list( perm([berlin, dusseldorf, luxem, munic, paris]) )
comb = [ [i for i in n] for n in comb ]

for i in comb:
  i.insert(0, brussels)
  i.insert(len(i), brussels)


print """Key: berlin = 0, brussels = 1, dusseldorf = 2 luxembourg = 3, munich = 4, paris = 5"""

longestPath  = 0
shortestPath = 0
l_path  = 0
s_path  = 0

for path in comb:
  print "path: ", path
  print "total distance: ", get_distance(path)
  print


for path in comb:
  d = get_distance(path)

  if (longestPath == 0) and (shortestPath == 0):
    longestPath  = d
    shortestPath = d
    
    l_path  = path
    s_path  = path
  
  elif d < shortestPath:
    shortestPath = d
    s_path       = path

  elif d > longestPath:
    longestPath = d
    l_path      = path


print "Longest   Path: ", l_path
print "Total distance: ", longestPath

print

print "Shortest  Path: " , s_path
print "Total distance: ", shortestPath

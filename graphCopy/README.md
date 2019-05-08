# theosGraphs
***
*A Graph and Maze library in python3*

## Installation
This project is on pip, don't use pip, use pip3, there is some python3 specific syntax that python 2 will yell at (typing)

```bash
	$ pip3 install theosGraphs
	$ Celebrate!
	$ pip3 uninstall theosGraphs
	$ Stop Celebrating
```

## Basic Usage
### Example
***
```python
from theosGraphs import Graph, Maze, HMaze

#build an empty single or double graph
myGraphDoubleLinked = Graph(double = True)
myGraphSingleLinked = Graph(double = False)

#build a graph from a dictionary
graph_dict = {"S":[("C", 2), ("A", 3), ("F", 6)], "C":[("A", 2), ("D", 3)], "A":[("D", 1), ("B", 6)], "D":[("E",4)], "E":[], "F":[("E",2)], "B":[("E", 1)], "G":[]}
my_dict_graph = Graph(double = True, graph = graph_dict)


#add vertices
myGraphDoubleLinked.addVertex("A")
myGraphDoubleLinked.addVertex(1)	#don't have to be the same types

#add edges
myGraphDoubleLinked.addEdge("A", 1, 10) 	#10 is the distance between "A" and 1

#note that for a single linked list, the single edge is taken care of and a double linked list has the double edge taken care of


#print the graph brute  force like
myGraphDoubleLinked.displayEdges()

#print the graph depth first
myGraphSingleLinked.printDFT()

#print the graph breadth first
my_dict_graph.printBFT()



#MAZES
#build a non heuristic maze
a = Maze(20, 20, 0, 15) 		#params	rows, cols, starting col, ending  col

#print the maze
a.print_map()

#solve the maze using djikstras
a.solve_maze()

#revel in your glory and maze solution by printing it again
a.print_map()

#build a heuristic maze
b = HMaze(20, 20, 0, 15)		#same as regular maze
b.print_map()

#uses A* to solve the maze
b.solve_maze()
b.print_map()


```


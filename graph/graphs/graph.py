from __future__ import print_function
from typing import Union, Optional
from math import inf
from numpy import matrix


class Edge:
    def __init__(self, vert, distance):
        self.vertex = vert
        self.distance = distance


class Vertex:
    def __init__(self, value):
        self.val = value
        self.visited = False
        self.Edges = []
        


class Graph:
    """Creates a graph
    
    double - boolean whether graph should be doubly or singly linked
    next constructor assumes double is true
    """
    def __init__(self, double:Optional[bool] = True):
        self.vertices = []      #list of vertex objects
        self.double = double    #double or singly linked

    """Adds a vertex of value

    value - a vertex object
    cannot add the same value to the graph
    """
    def addVertex(self, value):
        for i in self.vertices:
            if i.val == value:
                print(f'{value} already exists!')
                return
        val = Vertex(value)
        self.vertices = self.vertices + [val]

    """Add an edge to graph

    Edge must be an int or float
    if double is false, edge goes from 1 to 2
    """
    def addEdge(self, value1, value2, distance:Union[int, float]):
        vertex1 = None
        vertex2 = None
        inList = False
        for i in self.vertices:
            if i.val == value1:
                vertex1 = i
                for j in self.vertices:
                    if j.val == value2:
                        vertex2 = j
                        inList = True 
        if not inList:
            print("Couldn't find specified vals")
            return
        else: 
            edge1 = Edge(vertex2, distance)
            edge2 = Edge(vertex1, distance)

            vertex1.Edges = vertex1.Edges + [edge1]
            vertex2.Edges = vertex2.Edges + [edge2] if self.double else vertex2.Edges
            return

    """Displays the edges in a mundane way

    no algorithms here, just loops through the graph
    """
    def displayEdges(self):
        for i in self.vertices:
            print(f'{i.val} -- >', end=" ")
            for j in i.Edges:    
                print(f' {j.vertex.val}', end="")
            print()

    #Prints depth first
    def printDFT(self):
        self.setAllVerticesUnvisited()
        for i in self.vertices:
            if not i.visited:
                self.DFT_Traversal(i, verbose = True) 
        print()

    #prints breadth first
    def printBFT(self):
        self.setAllVerticesUnvisited()
        for i in self.vertices:  
            if not i.visited:
                self.BFT_Traversal(i, verbose = True)
        print()
            
    #sets every vertex unvisited (false)
    def setAllVerticesUnvisited(self):
        for i in self.vertices:
            i.visited = False

    #breadth first traversal print    
    def BFT_Traversal(self, vertex, verbose:Optional[bool] = False):
        queueP = [vertex]
        while len(queueP) > 0:
            for i in queueP[0].Edges:
                if not i.vertex.visited:
                    queueP.append(i.vertex)
            if not queueP[0].visited and verbose:
                print(queueP[0].val, end=" ") 
            else:
                print()
            queueP[0].visited = True
            queueP.pop(0)
    
    #depth first traversal print
    def DFT_Traversal(self, vertex, verbose:Optional[bool] = False):
        if vertex.visited:
            return
        vertex.visited = True
        if verbose:
            print(vertex.val, end=" ")
        for i in vertex.Edges:
            self.DFT_Traversal(i.vertex, verbose)

    #checks whether a given vertex is a mother index
    def check_mother_vertex(self, vertex:Vertex):
        self.setAllVerticesUnvisited()
        self.DFT_Traversal(vertex, verbose = False)
        for i in self.vertices:
            if not i.visited:
                return False
        return True

    """Finds mother vertex in graph

    A mother vertex is a vertex v such that all 
    other vertices can be reached by some path from v
    can be multiple mother vertices
    """
    def find_mother_vertices(self, verbose:Optional[bool] = False):
        motherNodes = []
        for i in self.vertices:
            if self.check_mother_vertex(i):
                if verbose: print(i.val)
                motherNodes.append(i.val)
        return motherNodes

    def djikstras(self, source):
        dist = []
        for i in self.vertices:
            dist.append(i, inf) if i.val != source else dist.append(i, 0)
        
        S = []
        Queue = [i.val for i in self.vertices]
        while len(Queue) != 0:
            minimum = min(zip(*filter(dist, lambda x: x[0].val in Queue))[0])
            S.append(
            u = minDistance(Q, dist)
    



        for i in self.vertices:
            print(i.val)

    def to_Adj_Matrix(self):
        output = matrix()



if __name__ == '__main__':
    a = Graph(True)
    b = Graph(False)
    c = Graph(True)

    a.addVertex(4)
    a.addVertex(5)
    a.addVertex(6)
    a.addVertex(7)
    a.addVertex(12)
    a.addVertex(13)
    a.addEdge(4, 5, 10)
    a.addEdge(5, 12, 11)

    b.addVertex(1)
    b.addVertex(0)
    b.addVertex(2)
    b.addVertex(3)
    b.addVertex(4)
    b.addEdge(1, 0, 10)
    b.addEdge(2, 1, 10)
    b.addEdge(0, 2, 10)
    b.addEdge(0, 3, 10)
    b.addEdge(3, 4, 10)

    c.addVertex('A')
    c.addVertex('B')
    c.addVertex('C')
    c.addVertex('D')
    c.addVertex('E')
    c.addVertex('F')
    c.addEdge('A', 'B', 10)
    c.addEdge('A', 'C', 10)
    c.addEdge('B', 'D', 10)
    c.addEdge('C', 'E', 10)
    c.addEdge('C', 'F', 10)

    q = b.find_mother_vertices(verbose = True)
    c.find_mother_vertices(verbose = True)


    #if a.check_mother_vertex(4):
    #    print("yay!")

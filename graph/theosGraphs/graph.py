from __future__ import print_function
from typing import Union, Optional
from math import inf


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
    def __init__(self, double:Optional[bool] = True, graph:Optional[dict] = None):
        self.vertices = []      #list of vertex objects
        self.double = double    #double or singly linked
        if graph != None:
            self.build_from_graph(graph)
    
    """Builds a graph from an input graph structured dictionarry

    graph = {vertex: [(vertex, dist), (vertex, dist)...], vertex:[(vertex, dist)...], .....}
    """
    def build_from_graph(self, graph:dict):
        self.vertices = []
        self.addVertices(*list(graph.keys()))
        for i in graph.keys():
            for j in graph[i]:
                self.addEdge(i, j[0], j[1])


    """Adds a vertex of value

    value - a vertex object
    cannot add the same value to the graph
    """
    def addVertices(self, *arg):
        for i in arg:
            self.addVertex(i)

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

    def getVertex(self, val):
        for i in self.vertices:
            if i.val == val: return i
        return -1

    def getVertices(self):
        return self.vertices

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

    """a djikstras toolset

    source is the val at start node
    kwargs contains end, which is the optional end node, in which the 
    program returns the path and distance
    verbose just prints the things in logical format
    """
    def djikstras(self, source, verbose:Optional[bool] = False, **kwargs):
        end = False
        if 'end' in kwargs: end = True
        dist = {}
        Q = []
        paths = {}
        for i in self.vertices:
            dist[i] = inf if i.val != source else 0
            Q.append(i)
            paths[i] = [] if i.val != source else [i]
       
        while len(Q) > 0:
           
            v = Q[0]
            for i in Q:
                if dist[i] < dist[v]: v = i
            Q.remove(v)

            for i in v.Edges:
                a = dist[v] + i.distance
                if a < dist[i.vertex]:
                    dist[i.vertex] = a
                    paths[i.vertex] = paths[v] + [i.vertex] 
        if verbose:
            for i in list(dist.keys()):
                print(f'{source} --> {i.val} --- Dist = {dist[i]}')
                print("Pathway =", end=" ")
                for j in paths[i]:
                    print(j.val, end=" ")
                print()
        if end:
            for i in list(dist.keys()):
                if i.val == kwargs.get('end'): return dist[i], paths[i]
        return dist, paths

   #def a_star(self, source, verbose:Optional[bool] = False, **kwargs):


if __name__ == '__main__':
    b_graph = {0:[(2, 10), (3,10)] ,1:[(0, 10)], 2:[(1, 10)], 3:[(4, 10)] ,4:[]}
    c_graph = {'A':[('B', 10), ('C', 10)], 'B':[('D',10)], 'C':[('E',10), ('F', 10)], 'D':[], 'E':[], 'F':[]}
    
    c = Graph(double = True, graph = c_graph)
    b = Graph(double = False, graph = b_graph)
    print("C")
    c.displayEdges()
    print("B")
    b.displayEdges()

    m = {"A":[("B", 1)], "C":[], "B":[("C", 2), ("M", 4)], "M":[("P", 2), ("L", 4)], "P":[], "L":[]}
    p = Graph(double = True, graph = m)


    d_graph = {"S":[("C", 2), ("A", 3), ("F", 6)], "C":[("A", 2), ("D", 3)], "A":[("D", 1), ("B", 6)], "D":[("E",4)], "E":[], "F":[("E",2)], "B":[("E", 1)], "G":[]}

    d = Graph(double = False, graph = d_graph)
    print("HERE")
    p, b = d.djikstras("S")
    p, b = d.djikstras("S", verbose = True)

    p, b = d.djikstras("S", verbose = False, end = "E")

    print(p)
    for i in b:
        print (i.val)





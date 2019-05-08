from graph import Graph
from typing import Optional
from math import sqrt

class Node:
    def __init__(self, x, y, euclid):
        self.pos = (x, y)
        self.dist = euclid
   
    def __str__(self):
        return f"{self.pos} {self.dist} "

class HGraph(Graph):
    def __init__(self):
        super().__init__()

    

    def update_dists(self, x, y):
        for i in self.vertices:
            i.val.dist = sqrt(float((i.val.pos[0] - x) ** 2 + (i.val.pos[1] - y) ** 2))


    def addHVertex(self, x, y, dist:Optional[int] = 0):
        a = Node(x, y, dist)
        super().addVertex(a)

    def getVertices(self):
        return Graph.getVertices(self)

    def a_star(self, start:tuple, end:tuple):
        self.update_dists(x2, y2)
        dist = {}
        Q = []
        paths = {}

        for i in super().vertices:
            dist[i] = inf if i.val.pos != start else 0
            Q.append(i)
            paths[i] = [] if i.val.pos != start else [i]
            
        while len(Q) > 0:
            v = Q[0]
            for i in Q:
                if dist[i] < dist[v]: v = i
            Q.remove(v)

            for i in v.Edges:
                a = dist[v] + i.distance + i.vertex.val.dist
                if a < dist[i.vertex]:
                    dist[i.vertex] = a
                    paths[i.vertex] = paths[v] + [i.vertex]
        return dist, paths

if __name__ == '__main__':
    a = HGraph()
    a.addHVertex(1, 1, 10)
    a.addHVertex(4, 9, 20)
    a.update_dists(4, 9)
    a.displayEdges()

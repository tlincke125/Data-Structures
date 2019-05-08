from .graph import Graph
import random
from typing import Optional
from math import sqrt, inf




class MazeNode():
    def __init__(self, x, y, dist):
        self.pos = (x, y)
        self.dist = dist
    
    def __str__(self):
        return f'{self.pos} - {self.dist}'

class HMaze(Graph):
    def __init__(self, height, width, startCol, endCol):
        super().__init__()
        self.height = height
        self.width = width
        
        for i in range(height):
            for j in range(width):
                self.add_maze_node(i, j)
        

        self.dft_init()
        self.maze = self.set_map(startCol, endCol)
        self.startCol = startCol
        self.endCol = endCol

    def getVertex(self, x:tuple):
        for i in super().getVertices():
            if i.val.pos == x: return i
        return -1

    def add_maze_edge(self, i, j, dist:Optional[float] = 0, distance:Optional[float] = 1):
        a = self.getVertex(i)
        b = self.getVertex(j)
        super().addEdge(a.val, b.val, distance)

    def dft_recurs(self, vertex):
        if vertex.visited:
            return
        
        vertex.visited = True
        #adjacent is just a list of coordinates up down right and left
        adjacent = [ (vertex.val.pos[0] + 1, vertex.val.pos[1]),
                                    (vertex.val.pos[0] - 1, vertex.val.pos[1]),
                                    (vertex.val.pos[0], vertex.val.pos[1] + 1),
                                    (vertex.val.pos[0], vertex.val.pos[1] - 1)]

        random.shuffle(adjacent)    #to add randomness to the graph
        for i in adjacent:
            a = self.getVertex(i)
            if a != -1:       #obviously if the index is at 0, then -1 dne
                if not a.visited:
                    self.add_maze_edge(i, vertex.val.pos)
                    self.dft_recurs(a)    #do it again

    def dft_init(self):
        super().setAllVerticesUnvisited()
        self.dft_recurs(self.getVertex((0, 0)))

    def set_map_recurs(self, mazeGrid, vertex):
        if vertex.visited:
            return
        vertex.visited = True
        for i in vertex.Edges:
            row = (vertex.val.pos[0] * 2 + 2) + (-(vertex.val.pos[0]) + (i.vertex.val.pos[0]))
            col = (vertex.val.pos[1] * 2 + 2) + (-(vertex.val.pos[1]) + (i.vertex.val.pos[1]))
            mazeGrid[row][col] = 0
            mazeGrid[2 * vertex.val.pos[0] + 2][2 * vertex.val.pos[1] + 2] = 0
            mazeGrid[2 * i.vertex.val.pos[0] + 2][2 * i.vertex.val.pos[1] + 2] = 0
            self.set_map_recurs(mazeGrid, i.vertex)

    def set_map(self, startCol, endCol):
        a = self.getVertex((0, startCol))
        b = self.getVertex((self.height - 1, endCol))
        if a == -1:
            print("Invalid starting index")
            return
        if b == -1:
            print("Invalid ending index")
            return

        maze = [[1 for i in range (self.width * 2 + 3)] for j in range(self.height * 2 + 3)]
        super().setAllVerticesUnvisited()
        self.set_map_recurs(maze, self.getVertex((0, 0)))

        maze[0][startCol * 2 + 2] = 0
        maze[1][startCol * 2 + 2] = 0
        maze[self.height * 2 + 1][endCol * 2 + 2] = 0
        maze[self.height * 2 + 2][endCol * 2 + 2] = 0
        return maze

    def print_map(self):
        for i in self.maze:
            for j in i:
                if j == 1: print("|", end="")
                if j == 0: print(end=" ")
                if j == 9: print("@", end="")
            print()

    def solve_maze(self):
        self.update_dists(self.height - 1, self.endCol)
        a, b = self.a_star((self.height - 1, self.endCol), (0, self.startCol))
        

        for i in range(len(b) - 1):
            row = (b[i].val.pos[0] * 2 + 2) + (-(b[i].val.pos[0]) + (b[i + 1].val.pos[0]))
            col = (b[i].val.pos[1] * 2 + 2) + (-(b[i].val.pos[1]) + (b[i+1].val.pos[1]))
            self.maze[row][col] = 9

            self.maze[b[i].val.pos[0] * 2 + 2][b[i].val.pos[1] * 2 + 2] = 9
        self.maze[0][self.startCol * 2 + 2] = 9
        self.maze[1][self.startCol * 2 + 2] = 9
        self.maze[self.height * 2 + 1][self.endCol * 2 + 2] = 9
        self.maze[self.height * 2][self.endCol * 2 + 2] = 9
        self.maze[self.height * 2 + 2][self.endCol * 2 + 2] = 9



    def update_dists(self, x, y):
        for i in self.vertices:
            i.val.dist = sqrt(float((i.val.pos[0] - x) ** 2 + (i.val.pos[1] - y) ** 2))

    
    def add_maze_node(self, x, y, dist:Optional[float] = 0):
        a = MazeNode(x, y, dist)
        super().addVertex(a)

    def a_star(self, end, start):
        dist = {}
        Q = []
        paths = {}

        for i in super().getVertices():
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
                    if i.vertex.val.pos == end: return dist[i.vertex], paths[i.vertex]
        return dist, paths


   





    

if __name__ == '__main__':
    a = HMaze(30, 30, 0, 0)
    a.print_map()
    a.solve_maze()
    a.print_map()

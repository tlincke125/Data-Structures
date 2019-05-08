from .graph import Graph
import random
import sys

class Maze():
    """Initialize a maze

    Parameters height width are height and width of the maze in grid elements
    startCol is the starting index on the top row (maze always starts on the top row)
    endCol is the ending index on the bottom row (maze always ends on the bottom row)
    """
    def __init__(self, height, width, startCol, endCol):
    
        self.height = height
        self.width = width
       
        self.graph = Graph(True)                #initialize the map graph


        for i in range(height):
            for j in range(width):
                self.graph.addVertex((i, j))    #add vertices (NOT edges) in a grid fashion

        self.dft_init()                         #initializes edges
        self.maze = self.set_map(startCol, endCol)  #creates a maze matrix (from graph to matrix)
        self.startCol = startCol
        self.endCol = endCol


    """Depth first seach uses adjacent edges instead of connected nodes

    randomly connects adjacent edges in a depth first approach
    vertex is the vertex in question
    garuntees all nodes will be hit at least once
    """
    def dft_recurs(self, vertex):
        if vertex.visited: #is never triggered - use it for sake of readability
            return

        vertex.visited = True 

        #adjacent is just a list of coordinates up down right and left
        adjacent = [ (vertex.val[0] + 1, vertex.val[1]), 
                                    (vertex.val[0] - 1, vertex.val[1]),
                                    (vertex.val[0], vertex.val[1] + 1), 
                                    (vertex.val[0], vertex.val[1] - 1)]

        random.shuffle(adjacent)    #to add randomness to the graph
        for i in adjacent:  
            if self.graph.getVertex(i) != -1:       #obviously if the index is at 0, then -1 dne
                if not self.graph.getVertex(i).visited:
                    self.graph.addEdge(i, vertex.val, 1)        #add that edge
                    self.dft_recurs(self.graph.getVertex(i))    #do it again

    """Does the dft_recurse but to self
    
    sets the graph to unvisited then attatches edges
    """
    def dft_init(self):
        self.graph.setAllVerticesUnvisited()        
        self.dft_recurs(self.graph.vertices[0])

    """Sets the map (not the nodes) in a matrix that represents the grid

    mazeGrid is just a matrix with padding so that we can remove borders. 
    If two nodes have an edge, we make the bordering wall dissapear
    vertex is the vertex in question
    depth first approach (breadth first would be fine too)
    """
    def set_map_recurs(self, mazeGrid, vertex):
        if vertex.visited:
            return
        vertex.visited = True
        for i in vertex.Edges:
            #print(vertex.val, i.vertex.val)
            row = (vertex.val[0] * 2 + 2) + (-(vertex.val[0]) + (i.vertex.val[0]))
            col = (vertex.val[1] * 2 + 2) + (-(vertex.val[1]) + (i.vertex.val[1]))
            #print(row, col)
            mazeGrid[row][col] = 0
            mazeGrid[2 * vertex.val[0] + 2][2 * vertex.val[1] + 2] = 0
            mazeGrid[2 * i.vertex.val[0] + 2][2 * i.vertex.val[1] + 2] = 0
            self.set_map_recurs(mazeGrid, i.vertex)

    """Uses set_map_recurs as a utility function to create self's maze
    
    start and end col are the starting and ending indices
    """
    def set_map(self, startCol, endCol):
        a = self.graph.getVertex((0, startCol))
        b = self.graph.getVertex((self.height - 1, endCol))
        if a == -1:
            print("Invalid starting index")
            return
        if b == -1:
            print("Invalid ending index")
            return

        maze = [[1 for i in range (self.width * 2 + 3)] for j in range(self.height * 2 + 3)]
        self.graph.setAllVerticesUnvisited()
        self.set_map_recurs(maze, self.graph.vertices[0])

        maze[0][startCol * 2 + 2] = 0
        maze[1][startCol * 2 + 2] = 0
        maze[self.height * 2 + 1][endCol * 2 + 2] = 0
        maze[self.height * 2 + 2][endCol * 2 + 2] = 0
        return maze
       
    #print the maze matrix
    def print_map(self):
        for i in self.maze:
            for j in i:
                if j == 1: print("|", end="")
                if j == 0: print(end=" ")
                if j == 9: print("@", end="")
            print()

    
    def solve_maze(self):
        a, b = self.graph.djikstras((0, self.startCol), verbose = False, end = (self.height - 1, self.endCol))
        #self.graph.displayEdges()
        #print(b[0])
        for i in range(len(b) - 1):
            row = (b[i].val[0] * 2 + 2) + (-(b[i].val[0]) + (b[i + 1].val[0]))
            col = (b[i].val[1] * 2 + 2) + (-(b[i].val[1]) + (b[i+1].val[1]))
            self.maze[row][col] = 9

            self.maze[b[i].val[0] * 2 + 2][b[i].val[1] * 2 + 2] = 9
        self.maze[0][self.startCol * 2 + 2] = 9
        self.maze[1][self.startCol * 2 + 2] = 9
        self.maze[self.height * 2 + 1][self.endCol * 2 + 2] = 9
        self.maze[self.height * 2][self.endCol * 2 + 2] = 9
        self.maze[self.height * 2 + 2][self.endCol * 2 + 2] = 9




if __name__ == '__main__':
    sys.setrecursionlimit(3000)
    a = Maze(40, 40, 0, 0)
    a.print_map()    
    a.solve_maze()
    a.print_map()

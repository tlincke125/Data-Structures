from random import randint


class Maze():
    def __init__(self, height, width):
        self.maze= [ [0 for i in range(width)] for j in range(height)]
        self.maze[0] = [1 for i in range(width)]
        self.maze[height - 1] = [1 for i in range(width)]
        for i in range(height):
            self.maze[i][0] = 1
            self.maze[i][width - 1] = 1
        
        self.height = height
        self.width = width

    
    

    def split_random_quadrants(self, row_min, row_max, col_min, col_max):
        a = -1 if row_min + 4 > row_max else randint(row_min + 2, row_max - 2)
        b = -1 if col_min + 4 > col_max else randint(col_min + 2, col_max - 2)

        if a == -1 and b == -1:
            return
    
        if a != -1:
            q = randint(col_min + 1, col_max - 1)
            for i in range(col_min, col_max):
                self.maze[a][i] = 1 if i != q else 0
        if b != -1:
            q = randint(row_min + 1, row_max - 1)
            for j in range(row_min, row_max):
                self.maze[j][b] = 1 if j != q else 0



        if a == -1:
            self.split_random_quadrants(row_min, row_max, b, col_max)
            self.split_random_quadrants(row_min, row_max, col_min, b)
            return


        if b == -1:
            self.split_random_quadrants(row_min, a, col_min, col_max)
            self.split_random_quadrants(a, row_max, col_min, col_max)
            return


        self.split_random_quadrants(a, row_max, col_min, b)
        self.split_random_quadrants(row_min, a, col_min, b)
        self.split_random_quadrants(row_min, a, b, col_max)
        self.split_random_quadrants(a, row_max, b, col_max)
    

    def printFunc(self):
        for i in range(self.height):
            for j in range(self.width):
                print(self.maze[i][j], end=" ")
            print()


if __name__ == '__main__':
    a = Maze(30, 30)
    a.split_random_quadrants(0, 29, 0, 29)
    a.printFunc()

#!/usr/bin/python3

from theosGraphs import Graph, HMaze, Maze
import sys
import time
import argparse

if __name__ == '__main__':
    sys.setrecursionlimit(10000)
    
    parser = argparse.ArgumentParser(description="Arguments")

    parser.add_argument('-a', dest='astar', action='store_true', help='solves maze using a* technique')
    parser.add_argument('-d', dest='djik', action='store_true', help='solves maze using djikstras technique')
    parser.add_argument('-t', dest='timed', action='store_true', help='times  the program')
    parser.add_argument('-v', dest='verbose', action='store_true', help='verbose')
    parser.add_argument('-s', type=int, nargs='?', default='0', help='starting col of the graph')
    parser.add_argument('-e', type=int, nargs='?', default='0', help='ending col of the graph')

    parser.add_argument('-r', nargs='?', default='10', type=int,
                        help='number of rows in the maze')
    parser.add_argument('-c', nargs='?', default='10', type=int,
                        help='number of cols in the maze')


    if not len(sys.argv) > 1:
        parser.print_help(sys.stderr)
        sys.exit(1)
    args = parser.parse_args()
    
    rows = args.r
    cols = args.c
    start = args.s
    end = args.e

    if args.s >= cols:
        start = 0
    if args.e >= cols:
        end = 0



    if args.astar:
        time1 = time.time()
        if args.timed:
            time1 = time.time()
        a = HMaze(rows, cols, start, end)
        if args.verbose:
            print("Origional")
            a.print_map()
        a.solve_maze()
        if args.verbose:
            print("Solved - A*")
            a.print_map()
        if args.timed:
            print('A* function took {:.3f} ms'.format((time.time() - time1) * 1000.0))

    if args.djik:
        time1 = time.time()
        if args.timed:
            time1 = time.time()
        a = HMaze(rows, cols, start, end)
        if args.verbose:
            print("Origional")
            a.print_map()
        a.solve_maze()
        if args.verbose:
            print("Solved - Djikstras")
            a.print_map()
        if args.timed:
            print('Djikstras function took {:.3f} ms'.format((time.time() - time1) * 1000.0))

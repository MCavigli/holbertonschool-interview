#!/usr/bin/python3
import sys


def printSolution(board, num):
    ''' Fills out queen positions and prints '''
    positions = [[0 for y in range(2)]for x in range(num)]
    for i in range(num):
        for j in range(num):
            if board[i][j] != 0:
                positions[i][0] = i
                positions[i][1] = j
                continue
    print(positions)


def isSafe(board, row, col):
    ''' Checks if queens' positions are legal '''
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, num, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def checkBoard(board, col, num):
    ''' Checks the board '''
    if col >= num:
        return True
    for i in range(num):
        if isSafe(board, i, col):
            board[i][col] = 1
            if checkBoard(board, col + 1, num) is True:
                return True
            board[i][col] = 0


if __name__ == "__main__":
    ''' Checks user input and starts program '''
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    num = 0
    try:
        num = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)

    if num < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0 for y in range(num)]for x in range(num)]
    if checkBoard(board, 0, num) is False:
        print("No solution")
        exit(1)
    printSolution(board, num)

#!/usr/bin/python3
''' Module that holds method to rotate 2D matrix 90 degrees '''


def rotate_2d_matrix(matrix):
    ''' Rotates a 2D matrix '''

    matrix[:] = matrix[::-1]

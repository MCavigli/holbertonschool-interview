#!/usr/bin/python3

import fileinput
from signal import signal, SIGINT
import sys


if __name__ == '__main__':

    lineCount = 0
    totalSize = 0
    statusCodes = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0}

    def print_info(size, codes):
        print("File size: {}".format(size))
        for k, v in codes.items():
            if v != 0:
                print("{}: {}".format(k, v))

    try:
        for line in sys.stdin:
            lineCount += 1
            info = line.split()
            totalSize += int(info[8])

            if info[7] in statusCodes:
                statusCodes[info[7]] = statusCodes.get(info[7]) + 1
            if lineCount % 10 == 0:
                print_info(totalSize, statusCodes)

    except KeyboardInterrupt:
        print_info(totalSize, statusCodes)
        raise

    print_info(totalSize, statusCodes)

#!/usr/bin/python3
""" Module that checks to see if all boxes are unlockable """


def canUnlockAll(boxes):
    """ Checks if all boxes are unlockable
        Args: boxes - a list of lists
        Return: True or False
    """
    if not isinstance(boxes, list):
        return False
    if len(boxes) == 1:
        return True
    if len(boxes) == 0 or len(boxes[0]) == 0:
        return False
    boxDict = dictInit(boxes)
    boxOfKeys = []
    for key in boxes[0]:
        boxOfKeys.append(key)
    while ('locked' in boxDict.values() and len(boxOfKeys) > 0):
        boxOfKeys = unlockBoxes(boxes, boxDict, boxOfKeys)
    if ('locked' in boxDict.values()):
        return False
    else:
        return True


def unlockBoxes(boxes, boxDict, boxOfKeys):
    """ Unlocks the boxes """
    newKeys = []
    for key in boxOfKeys:
        if key not in boxDict:
            boxOfKeys.remove(key)
            continue
        if boxDict[key] == 'locked':
            boxDict[key] = 'unlocked'
            if len(boxes[key]) == 0:
                continue
            else:
                for nk in boxes[key]:
                    newKeys.append(nk)
    boxOfKeys.clear()
    newKeys = list(set(newKeys))
    for key in newKeys:
        if key not in boxDict:
            newKeys.remove(key)
            continue
        if boxDict[key] == 'locked':
            boxOfKeys.append(key)
    newKeys.clear()
    return boxOfKeys


def dictInit(box):
    """ Initializes the dictionary """
    boxDict = {}
    for i in range(len(box)):
        boxDict[i] = 'locked'
    boxDict[0] = 'unlocked'

    return boxDict

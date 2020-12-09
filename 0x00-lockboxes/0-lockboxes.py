#!/usr/bin/python3
"""Lock Boxes"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    uniq_keys = [0]
    while (1):
        new_key_added = False
        for i, keys in enumerate(boxes):
            if i in uniq_keys:
                for key in keys:
                    if key not in uniq_keys and (0 <= key < len(boxes)):
                        if i != 0 and key != 0:
                            new_key_added = True
                        uniq_keys.append(key)
        if new_key_added is False:
            break
    if len(uniq_keys) == len(boxes):
        return True
    else:
        return False

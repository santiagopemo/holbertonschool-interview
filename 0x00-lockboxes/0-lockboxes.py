#!/usr/bin/python3
"""Lock Boxes"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    used_keys = [0]
    while (1):
        new_key_added = False
        for i, keys in enumerate(boxes):
            if i in used_keys:
                for key in keys:
                    if key not in used_keys and (0 <= key < len(boxes)):
                        new_key_added = True
                        used_keys.append(key)
        if new_key_added is False:
            break
    if len(used_keys) == len(boxes):
        return True
    else:
        return False

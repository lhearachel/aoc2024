#!/usr/bin/env python3

import collections
import sys

lines = [line[:-1] for line in sys.stdin]
search = collections.defaultdict(str) | {
    (i, j): ch
    for i, line in enumerate(lines)
    for j, ch in enumerate(line)
}

all_coords = list(search.keys())
diff = (-1, 0, 1)

find = 'XMAS'
term = (list(find),)
print(sum(
    [
        search[i + (di * n), j + (dj * n)]
        for n in range(len(find))
    ] in term
    for di in diff
    for dj in diff
    for i, j in all_coords
))

terms = (list('MAS'), list('SAM'))
print(sum(
    [search[i + d, j + d] for d in diff] in terms
    and [search[i + d, j - d] for d in diff] in terms
    for i, j in all_coords
))

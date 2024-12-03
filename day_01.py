#!/usr/bin/env python3

import collections
import sys

left, right = zip(*[tuple(map(int, line.split())) for line in sys.stdin])

left = sorted(left)
right = sorted(right)
count = collections.Counter(right)

print(sum([abs(lv - rv) for lv, rv in zip(left, right)]))
print(sum([lv * count[lv] for lv in left]))

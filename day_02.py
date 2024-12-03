#!/usr/bin/env python3

import functools
import itertools
import sys


def safe_pair(pair: tuple[int, int]) -> tuple[bool, ...]:
    curr, next = pair
    diff = next - curr
    return (diff > 0 and diff < 4, diff < 0 and diff > -4)


def safe(report: tuple[int, ...]) -> bool:
    return functools.reduce(
        lambda x, y: x or y,
        functools.reduce(
            lambda curr, next: tuple(c and n for c, n in zip(curr, next)),
            map(safe_pair, itertools.pairwise(report)),
            (True, True),
        ),
        False,
    )


def safe_dampen(report: tuple[int, ...]) -> bool:
    return functools.reduce(
        lambda x, y: x or y,
        map(safe, itertools.combinations(report, len(report) - 1)),
        False,
    )


reports = [tuple(map(int, line.split())) for line in sys.stdin]

print(sum(map(safe, reports)))
print(sum(map(safe_dampen, reports)))

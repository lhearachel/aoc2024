#!/usr/bin/env python3

from collections import abc

import functools
import re
import sys

DO = True


def prod(it: abc.Iterable[int]) -> int:
    return functools.reduce(lambda x, y: x * y, it, 1)


def parse(match: tuple[str, ...], control: bool) -> int:
    global DO
    result = 0

    if control and match[-2] == "do()":
        DO = True
    elif control and match[-1] == "don't()":
        DO = False
    elif DO and match[0] != "":
        result = prod(map(int, match[:-2]))

    return result


input = "".join([line for line in sys.stdin])
matches = list(re.findall(r"mul\((\d+),(\d+)\)|(do\(\))|(don't\(\))", input))
print(sum(map(lambda m: parse(m, False), matches)))
print(sum(map(lambda m: parse(m, True), matches)))

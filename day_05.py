#!/usr/bin/env python3

import functools
import itertools
import sys
import typing


r, u = sys.stdin.read().split("\n\n")
r = list(map(lambda ln: tuple(map(int, ln.split("|")))[:2], r.split("\n")))
rules = {
    k: list(map(lambda t: t[1], v))
    for k, v in itertools.groupby(sorted(r, key=lambda x: x[0]), key=lambda x: x[0])
}
updates = list(map(lambda ln: tuple(map(int, ln.split(","))), u.split("\n")[:-1]))


def correct(entry: typing.Sequence[int], rules: dict[int, list]) -> tuple[int, ...]:
    '''
    Given a list of integers and a set of rules which define the expected sort-ordering of arbitrary
    integers, produce the correct sort-ordering of the input.
    '''

    # Filter the input ruleset to the relevant rules: those which define a relationship between two
    # numbers which both exist in the input.
    rules = {
        k: list(filter(lambda e: e in entry, v)) for k, v in rules.items() if k in entry
    }

    # Check for any missing values from the entries. These must have no dependent sort-ordering and
    # can be tacked onto the end in any order.
    for missing in filter(lambda i: i not in rules.keys(), entry):
        rules[missing] = []

    # Sort the relevant rules according to the number of elements which must occur after them in the
    # input. The keys of this sorted set of relevant rules are the correct sort-ordering.
    return tuple(
        map(
            lambda t: t[0],
            sorted(rules.items(), key=lambda kv: len(kv[1]), reverse=True),
        )
    )


def middle(entry: typing.Sequence[int]) -> tuple[int, int]:
    expect = correct(entry, rules)
    mid = expect[len(expect) // 2]
    return (mid * (entry == expect), mid * (entry != expect))


sums = functools.reduce(
    lambda x, y: (x[0] + y[0], x[1] + y[1]), map(middle, updates), (0, 0)
)

print(sums[0])
print(sums[1])

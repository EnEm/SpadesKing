#!/usr/bin/env python3
from collections import deque


def bfs_min_distance(n, edges):
    graph = [[] for _ in range(n + 1)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    distance = [-1] * (n + 1)
    distance[1] = 0
    queue = deque([1])

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if distance[neighbor] == -1:
                distance[neighbor] = distance[node] + 1
                queue.append(neighbor)

    return distance[n]


if __name__ == "__main__":
    n, m = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v = map(int, input().split())
        edges.append((u, v))

    min_distance = bfs_min_distance(n, edges)
    print(min_distance)

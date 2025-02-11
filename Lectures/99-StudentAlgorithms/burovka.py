import concurrent.futures
import sys
from collections import defaultdict

# Sample graph represented as an adjacency list
graph = {
    0: [(1, 10), (2, 6), (3, 5)],
    1: [(0, 10), (3, 15)],
    2: [(0, 6), (3, 4)],
    3: [(0, 5), (1, 15), (2, 4)],
}


def find_min_edge(component, graph):
    min_edge = (None, None, sys.maxsize)
    for node in component:
        for neighbor, weight in graph[node]:
            if neighbor not in component and weight < min_edge[2]:
                min_edge = (node, neighbor, weight)
    return min_edge


def boruvka_parallel(graph):
    components = [{node} for node in graph.keys()]
    mst_edges = []

    while len(components) > 1:
        min_edges = []

        with concurrent.futures.ThreadPoolExecutor() as executor:
            min_edges = list(
                executor.map(lambda c: find_min_edge(c, graph), components)
            )

        new_components = defaultdict(set)

        for edge in min_edges:
            if edge[0] is not None:
                mst_edges.append(edge)
                new_components[edge[0]].add(edge[1])

        components = [
            set.union(components[i], new_components[i]) for i in new_components
        ]

    return mst_edges


mst_edges = boruvka_parallel(graph)
print("Minimum Spanning Tree Edges:", mst_edges)

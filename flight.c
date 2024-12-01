#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int to, price;
} Flight;

typedef struct {
    Flight *flights;
    int size;
    int capacity;
} Graph;

void initGraph(Graph *graph) {
    graph->flights = (Flight *)malloc(0 * sizeof(Flight));
    graph->size = 0;
    graph->capacity = 0;
}

void addFlight(Graph *graph, int to, int price) {
    if (graph->size == graph->capacity) {
        graph->capacity = graph->capacity == 0 ? 1 : graph->capacity * 2;
        graph->flights = (Flight *)realloc(graph->flights, graph->capacity * sizeof(Flight));
    }
    graph->flights[graph->size].to = to;
    graph->flights[graph->size].price = price;
    graph->size++;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    Graph *graph = (Graph *)malloc(n * sizeof(Graph));
    for (int i = 0; i < n; i++) {
        initGraph(&graph[i]);
    }

    for (int i = 0; i < flightsSize; i++) {
        addFlight(&graph[flights[i][0]], flights[i][1], flights[i][2]);
    }

    int *cost = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cost[i] = INF;
    }
    cost[src] = 0;

    for (int stops = 0; stops <= k; stops++) {
        int *tempCost = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            tempCost[i] = cost[i];
        }

        for (int i = 0; i < n; i++) {
            if (cost[i] != INF) {
                for (int j = 0; j < graph[i].size; j++) {
                    int next = graph[i].flights[j].to;
                    int price = graph[i].flights[j].price;
                    if (cost[i] + price < tempCost[next]) {
                        tempCost[next] = cost[i] + price;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cost[i] = tempCost[i];
        }

        free(tempCost);
    }

    free(graph);

    if (cost[dst] == INF) {
        free(cost);
        return -1;
    }

    int result = cost[dst];
    free(cost);
    return result;
}

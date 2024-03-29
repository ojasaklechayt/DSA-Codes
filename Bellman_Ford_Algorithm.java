import java.util.*;

class Main {
    static class CreateGraph {
        class CreateEdge {
            int src, dest, weight;

            CreateEdge(int src, int dest, int weight) {
                this.src = src;
                this.dest = dest;
                this.weight = weight;
            }
        }

        int V, E;
        CreateEdge edge[];

        CreateGraph(int v, int e) {
            V = v;
            E = e;
            edge = new CreateEdge[e];
        }

        void BellmanFord(int src) {
            int dist[] = new int[V];
            for (int i = 0; i < V; ++i) {
                dist[i] = Integer.MAX_VALUE;
            }
            dist[src] = 0;
            for (int i = 1; i < V; ++i) {
                for (int j = 0; j < E; ++j) {
                    int u = edge[j].src;
                    int v = edge[j].dest;
                    int w = edge[j].weight;
                    if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            for (int j = 0; j < E; ++j) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int w = edge[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    System.out.println("Graph contains negative weight cycle");
                    return;
                }
            }
            printSolution(dist);
        }

        void printSolution(int dist[]) {
            for (int i = 0; i < V; ++i) {
                System.out.println(i + "\t\t" + dist[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();
        
        CreateGraph graph = new CreateGraph(V, E);
        
        System.out.println("Enter edge details (source destination weight):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.edge[i] = graph.new CreateEdge(src, dest, weight);
        }
        
        System.out.print("Enter the source vertex: ");
        int sourceVertex = scanner.nextInt();
        
        graph.BellmanFord(sourceVertex);
        
        scanner.close();
    }
}

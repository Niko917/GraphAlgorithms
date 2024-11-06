#pragma once
#include <algorithm>
#include <cstddef>
#include <nlohmann/json_fwd.hpp>
#include "../../Data_Structures/Containers/Pair.hpp"
#include "../../Data_Structures/Containers/Dynamic_Array.hpp"
#include "cerrno"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


template <typename VertexType, typename WeightType>
class Graph {
private:
    size_t vertex_count_; // Count of vertices
    DynamicArray<DynamicArray<Pair<VertexType, WeightType>>> adjacency_list_;

    DynamicArray<int> discovery_time_;
    DynamicArray<int> finish_time_;

    static size_t traversal_timer_;

    json log_json_;

    void resize(size_t new_size);

public:
    Graph();

    Graph(size_t vertex_count);

    void add_edge(VertexType from, VertexType to, WeightType weight);

    void add_vertex();

    void remove_edge(VertexType from, VertexType to);

    void remove_vertex(VertexType vertex);

    bool has_edge(VertexType from, VertexType to) const;

    json to_json();

    void save_to_json(const std::string& filename);

    void load_from_json(const std::string& filename);

    void save_json_to_file(const std::string& filename, const json& data);

    const DynamicArray<Pair<VertexType, WeightType>>& get_adjacency_list(VertexType vertex) const;

    constexpr size_t vertex_count() const noexcept;

    void clear();

    const DynamicArray<int>& get_discovery_time() const;

    const DynamicArray<int>& get_finish_time() const;

    void reset_timer() const;

    // Iterations
    typename DynamicArray<DynamicArray<Pair<VertexType, WeightType>>>::iterator begin() noexcept;

    typename DynamicArray<DynamicArray<Pair<VertexType, WeightType>>>::const_iterator cbegin() const noexcept;

    typename DynamicArray<DynamicArray<Pair<VertexType, WeightType>>>::iterator end() noexcept;

    typename DynamicArray<DynamicArray<Pair<VertexType, WeightType>>>::const_iterator cend() const noexcept;


// Algorithms

    // Graph traversal
    void depth_first_search(VertexType start); // DONE
    void breadth_first_search(VertexType start); // DONE

    // Connectivity
    DynamicArray<DynamicArray<VertexType>> find_connected_components(); // DONE 
    void find_bridges_and_articulation_points(); // TODO
    void find_biconnected_components(); // TODO

    // Shortest paths
    void dijkstra(VertexType start);
    void bellman_ford(VertexType start);
    void floyd_warshall();
    void shortest_paths_unweighted(VertexType start);

    // Maximum flow and minimum cut
    void ford_fulkerson(VertexType source, VertexType sink);
    void edmonds_karp(VertexType source, VertexType sink);
    void dinic(VertexType source, VertexType sink);
    void goldberg_tarjan(VertexType source, VertexType sink);
    void karger_stein();

    // Matchings
    void kuhn_max_matching();
    void edmonds_max_matching();
    void hopcroft_karp();

    // Trees
    void kruskal();
    void prim();
    void boruvka();
    void lca(VertexType u, VertexType v);
    void heavy_light_decomposition();

    // Planarity
    void kuratowski_planarity_test();
    void outer_planarity_test();
    void fruchterman_reingold();

    // Network and flows
    void max_flow_in_network(VertexType source, VertexType sink);
    void min_cut_in_network(VertexType source, VertexType sink);
    void min_cost_flow(VertexType source, VertexType sink);
    void assignment_problem();

    // Heuristic algorithms
    void greedy_algorithms();
    void christofides_algorithm();
    void local_search();

    // Random graphs
    void erdos_renyi_model();
    void barabasi_albert_model();
    void random_graph_generation();
    void random_graph_properties();

    // Algorithms on dynamic graphs
    void dynamic_mst();
    void dynamic_connectivity();
    void dynamic_shortest_paths();

    // Algorithms on graphs with weights
    void dijkstra_with_potentials(VertexType start);
    void bellman_ford_with_negative_cycles(VertexType start);
    void johnson_all_pairs_shortest_paths();


    // Traveling Salesman Problem
    void nearest_neighbor_tsp();
    void two_opt_tsp();
    void christofides_tsp();
    void branch_and_bound_tsp();
    void genetic_algorithm_tsp();

    // Multi-criteria search
    void epsilon_constrained_search();
    void pareto_front_search();
    void nsga_ii();
    void spea2();

    // Path search with the highest capacity
    void ford_fulkerson_max_capacity_path(VertexType source, VertexType sink);
    void dinic_max_capacity_path(VertexType source, VertexType sink);

    // Knapsack problem
    void knapsack_greedy();
    void knapsack_dynamic_programming();
    void knapsack_branch_and_bound();
    void knapsack_genetic_algorithm();

    // Graph generalization with given topology and size
    void generate_random_graph_with_topology();
    void generate_regular_graph();
    void generate_graph_with_degree_distribution();
    void generate_graph_with_diameter();
};

#include "../src/graph.tpp"
#include "../src/algorithms/dfs.tpp"
#include "../src/algorithms/bfs.tpp"
#include "../src/algorithms/connected_components.tpp"

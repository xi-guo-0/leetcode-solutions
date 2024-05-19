#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<string> &ss) {
  out << "[";
  for (const auto &x : ss) {
    out << x << ",";
  }
  out << "]";
  return out;
}

using Graph = unordered_map<string, vector<string>>;
ostream &operator<<(ostream &out, const Graph &g) {
  out << "{";
  for (const auto &p : g) {
    out << p.first << ":";
    out << p.second;
  }
  out << "}";
  return out;
}

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    Graph graph = ConsGraph(tickets);
    vector<string> itinerary;
    dfs("JFK", graph, itinerary);
    ranges::reverse(itinerary);
    return itinerary;
  }

private:
  void dfs(const string &airport, Graph &tickets, vector<string> &itinerary) {
    auto &destinations = tickets[airport];
    while (!destinations.empty()) {
      string next_destination = destinations.back();
      destinations.pop_back();
      dfs(next_destination, tickets, itinerary);
    }
    itinerary.push_back(airport);
  }

  Graph ConsGraph(const vector<vector<string>> &tickets) {
    Graph graph;
    for (const auto &ticket : tickets) {
      if (!graph.count(ticket[0])) {
        graph[ticket[0]] = {ticket[1]};
      } else {
        graph[ticket[0]].push_back(ticket[1]);
      }
    }
    for (auto &p : graph) {
      ranges::sort(p.second);
      ranges::reverse(p.second);
    }
    return graph;
  }
};

int main() {
  vector<vector<string>> tickets0 = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  vector<vector<string>> tickets1 = {{"JFK", "SFO"},
                                     {"JFK", "ATL"},
                                     {"SFO", "ATL"},
                                     {"ATL", "JFK"},
                                     {"ATL", "SFO"}};
  Solution().findItinerary(tickets0);
  Solution().findItinerary(tickets1);
  return 0;
}

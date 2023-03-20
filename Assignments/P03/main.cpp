/**********************************************************************
 *
 *  Author:           Brayden Lawson
 *  Title:            Graphviz Class
 *  Course:           2143-201
 *  Semester:         Spring 2023
 *
 *  Description:
 *  This program will output a Singly linked list, Doubly linked list, 
 *  and a Binary search tree in graphiz. It uses edges and nodes and 
 *  these edges and nodes have various attributes 
 *  that can be changed such as 
 *  shape color, opacity, etc.
 *
 *
 *  Usage:
 *  The output of this program needs to be 
    copy and pasted into Graphviz. 
 *  Graphviz will show the visual diagrams representing the 
 *  Singly Linked List, 
 *  Doubly Linked List, or Binary Search Tree.
 *
 *  Files: test.out
 ***********************************************************************/
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printHeading(ofstream &fout);

typedef map<string, string> str2str;

class Attribute {
protected:
  map<string, string> att; // attributes
  // e.g. color->red

public:
  Attribute() {}

  /**
   * Very basic print method to print out some graphviz style
   * code defining an edge.
   */
  /**
   * Update an edge attribute. Assumes key is valid.
   */
  void addAttribute(string key, string val) { att[key] = val; }

  /**
   * Takes a map of attributes. Loops over them and saves them
   * locally.
   */
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      // cout << x.first << "=" << x.second << endl;
      att[x.first] = x.second;
    }
  }

  friend ostream &operator<<(ostream &os, Attribute &e) {

    os << "[";

    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }

  friend fstream &operator<<(fstream &fout, Attribute &e) {

    fout << "[";
    int i = 0;
    for (auto const &x : e.att) {
      fout << x.first << "="
           << "\"" << x.second << "\"";
      if (i < e.att.size() - 1) {

        fout << ", ";
      }
      i++;
    }

    fout << "]";
    return fout;
  }
};


// edge class that includes all the attributes needed for an edge.
class Edge : public Attribute {
  int eid;
  int start;
  int end;

public:
  Edge() {
    att["color"] = "black";    // default color
    att["arrow_type"] = "vee"; // default arrow shape
  }

  Edge(string color, string arrow) {
    att["color"] = color;      // default color
    att["arrow_type"] = arrow; // default arrow shape
  }
  Edge(int start, int end) {
    this->start = start;
    this->end = end;
  }

  friend ostream &operator<<(ostream &os, Edge &e) {
    os << e.start << "->" << e.end << " ";
    os << "[";

    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }
};

// node class that includes all the attributes needed for a node.
class Node : public Attribute {
  int nid;

public:
  Node() {
    att["color"] = "black";  // default color
    att["shape"] = "record"; // default arrow shape
  }

  Node(map<string, string> atts) {
    for (auto const &x : atts) {
      att[x.first] = x.second;
    }
  }
};


/// graphiz class that includes graphname, graphshape and nodeshape
class GraphViz {
  int edgeId;
  int nodeId;
  vector<Edge> Edges;
  vector<Node> Nodes;
  string graphName;
  string graphShape;
  string nodeShape;

 

public:
  GraphViz() {
    edgeId = 0;
    nodeId = 0;
    graphName = "foo";
  }

// sets default graph shapes.
  GraphViz(string graph_name, string graph_shape) {
    edgeId = 0;
    nodeId = 0;
    graphName = graph_name;
    graphShape = graph_shape;
    if (graph_shape == "LL") {
      nodeShape = "record";
    }

    else if (graph_shape == "DLL")
    {
       nodeShape = "record";
    }

        else if (graph_shape == "BST")
    {
       nodeShape = "record";
    }
    
    
  }

  int addNode() {
    Nodes.push_back(Node());
    return Nodes.size() - 1;
  }

  int addNode(map<string, string> atts) {
    Nodes.push_back(Node(atts));

    return Nodes.size() - 1;
  }
 // updates attributes of a node such as the shape and color.
  void updateNode(int id, string key, string value) {
    Nodes[id].addAttribute(key, value);
  }

  void addEdge(int start, int end) {
    // make and edge constructor that receives two ints so you
    // can print them out
    Edges.push_back(Edge(start, end));
  }

  void addEdge(int start, int end, map<string, string> att) {

    Edges.push_back(Edge(start, end));
    Edges[Edges.size() - 1].addAttributes(att);
  }


// helps output the edges and nodes. 
  friend ostream &operator<<(ostream &banana, GraphViz &g) {
   
    for (int i = 0; i < g.Nodes.size(); i++) {
      banana << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++) {
      banana << g.Edges[i] << endl;
    }
    return banana;
  }
};

// prints my heading to the screen.
void printHeading()
{
    cout << "Brayden Lawson" << endl;
    cout << "3-20-23" << endl;
    cout << "Spring 2143" << endl;
    cout << " " << endl;
}

// prints my heading to the output file.
void printHeading(ofstream& fout) 
{
    fout << "Brayden Lawson" << endl;
    fout << "3-20-23" << endl;
    fout << "Spring 2143" << endl;
    fout << " " << endl;
}

int main() {
  ofstream fout;
  fout.open("test.out");
  printHeading(fout);
  printHeading();
       fout << "digraph LL {" << endl;
       fout << "        rankdir=LR;" << endl;
       fout << "        node [shape=record];" << endl;
  
       cout << "digraph LL {" << endl;
       cout << "        rankdir=LR;" << endl;
       cout << "        node [shape=record];" << endl;
  // create graphviz instances with specific shapes
  GraphViz G("LinkedList", "LL");
  GraphViz D("DoublyLinkedList", "DLL");
  GraphViz B("BinarySearchTree", "BST");

  // id for the nodes.
  int id;

  // Singly Linked List Graphviz code
  id = G.addNode(); // node id 0

  G.updateNode(id, "label", "{ <data> 0 | <next>  }");
  id = G.addNode(); // node id 1
  G.updateNode(1, "color", "red");
  G.updateNode(1, "shape", "oval");
  id = G.addNode(); // node id 2
  G.updateNode(2, "color", "purple");
  G.updateNode(2, "shape", "polygon");
  id = G.addNode(); // node id 3        
  G.updateNode(3, "color", "green");
  G.updateNode(3, "shape", "tripleoctagon");
  id = G.addNode(); // node id null
  G.updateNode(id, "label", "{ <data> null | <next>  }");
  G.updateNode(4, "color", "yellow");


  G.addEdge(0, 1, str2str({{"color", "red"}, {"arrowhead", "box"}}));
  G.addEdge(1, 2, str2str({{"color", "purple"}, {"arrowhead", "crow"}}));
  G.addEdge(2, 3, str2str({{"color", "green"}, {"arrowhead", "icurve"}}));
  G.addEdge(3, 4, str2str({{"color", "blue"}, {"arrowhead", "diamond"}}));

 //Outputs LL
  
  fout << G << endl;
  cout << G << endl;
  fout << "}";
  cout << "}";
  fout << endl;
  fout << endl;
  cout << endl;
  cout << endl;

// Doubly Linked List Graphviz code.
fout << "digraph DLL {";
fout << endl;
fout << "   rankdir=LR;";
fout << endl;
fout <<   "node [shape=record,color=red];";
cout << "digraph DLL {";
cout << endl;
cout << "   rankdir=LR;";
cout << endl;
cout <<   "node [shape=record,color=red];";

id = D.addNode(); // node id 0
D.updateNode(id, "label", "{  <prev>  |<data> 0 | <next>  }");
id = D.addNode(); // node id 1
D.updateNode(id, "label", "{  <prev>  |<data> 1 | <next>  }");
id = D.addNode(); // node id 2
D.updateNode(id, "label", "{  <prev>  |<data> 2 | <next>  }");
id = D.addNode(); // node id 3
D.updateNode(id, "label", "{  <prev>  |<data> 3 | <next>  }");
id = D.addNode(); // node id null
D.updateNode(id, "label", "{  <prev>  |<data> null | <next>  }");

D.addEdge(0, 1, str2str({{"color", "orange"}, {"arrowhead", "dot"}}));
D.addEdge(1, 0, str2str({{"color", "orange"}, {"arrowhead", "dot"}}));
D.addEdge(1, 2, str2str({{"color", "black"}, {"arrowhead", "normal"}}));
D.addEdge(2, 1, str2str({{"color", "black"}, {"arrowhead", "normal"}}));
D.addEdge(2, 3, str2str({{"color", "grey"}, {"arrowhead", "tee"}}));
D.addEdge(3, 2, str2str({{"color", "grey"}, {"arrowhead", "tee"}}));
D.addEdge(3, 4, str2str({{"color", "purple"}, {"arrowhead", "vee"}}));
D.addEdge(4, 3, str2str({{"color", "purple"}, {"arrowhead", "vee"}}));
  


// Outputs DLL
fout << D;
cout << D;
fout << "}";
cout << "}"; 
fout << endl;
fout << endl;
cout << endl;
cout << endl;
  

    // Binary Search Tree Graphviz code.
      fout << "digraph BST {";
      fout << endl;
      cout << "digraph BST {";
      cout << endl;

    B.addEdge(5, 6, str2str({{"color", "pink"}, {"arrowhead", "box"}}));
      B.addEdge(5, 7, str2str({{"color", "pink"}, {"arrowhead", "box"}}));
  B.addEdge(6, 8, str2str({{"color", "blue"}, {"arrowhead", "crow"}}));
  B.addEdge(6, 9, str2str({{"color", "blue"}, {"arrowhead", "crow"}}));
    B.addEdge(7, 10, str2str({{"color", "black"}, {"arrowhead", "icurve"}}));
    B.addEdge(7, 11, str2str({{"color", "black"}, {"arrowhead", "icurve"}}));

 // Outputs BST
  
  fout << B << endl;
  fout << "}";
  fout << endl;
  fout << endl;
  
 cout << B << endl;
  cout << "}";
  cout << endl;
  cout << endl;


  fout.close();
      
 
  return 0;
}

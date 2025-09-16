#include <iostream>
#include <pugixml.hpp>
using namespace std;



int main(int argc, char* argv[]){
  cout << "file paht: " << argv[1] << endl;
  char* file_path = argv[1];

  pugi::xml_document doc;
  doc.load_file(file_path);
  pugi::xpath_node_set nodes = doc.select_nodes("tr[@class='componentes']");

  for(pugi::xpath_node node : nodes){
    pugi::xml_node x = node.node();
    x.print(cout);
    cout << endl;
  }

  
}

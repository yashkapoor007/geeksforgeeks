#include<vector>
using namespace std;
template <typename T>
class Tree{
public:
  int data;
  vector<Tree<T>*> children;
  Tree(int data)
  {
    this->data=data;
  }
};

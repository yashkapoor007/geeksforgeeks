using namespace std;
template <typename T>
class Btree
{
public:
  T data;
  Btree*left;
  Btree *right;
  Btree(T data)
  {
    this->data=data;
    left=NULL;
    right=NULL;
  }
};

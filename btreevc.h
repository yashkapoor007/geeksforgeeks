template <typename T>
class Btree
{
public:
  T data;
  int vc;
  Btree<T> *left;
  Btree<T> *right;
  Btree(T data)
  {
    this->data=data;
    vc=0;
    left=NULL;
    right=NULL;
  }
};

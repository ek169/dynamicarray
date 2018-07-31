class DynamicArray
{
private:
  int size;
  int capacity;
  int resizeFactor;
  int * arr;
  bool resize(bool);
public:
  DynamicArray();
  DynamicArray(int);
  DynamicArray(int*, int);
  DynamicArray(DynamicArray&);
  ~DynamicArray();
  int current_size(void);
  int current_capacity(void);
  int max(void);
  int min(void);
  int average(void);
  void head(int);
  void tail(int);
  bool addItem(int);
  bool removeItem();
  bool removeItem(int);
  void print(void);
  bool find(int);
  int operator[](int);
  void operator+(int);
  DynamicArray& operator=(DynamicArray& );
};

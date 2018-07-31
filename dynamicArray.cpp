#include "dynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(void)
{
  capacity = 2;
  size = 0;
  arr = new int[capacity];
  resizeFactor = 2;
}

DynamicArray::DynamicArray(int n)
{
  capacity = n;
  size = 0;
  arr = new int[capacity];
  resizeFactor = 2;
}

DynamicArray::DynamicArray(int * n, int s)
{
  if(n)
  {
    resizeFactor = 2;
    capacity = s * resizeFactor;
    size = s;
    if(s > 0)
    {
      arr = new int[capacity];
      for(int i = 0; i < s; i++)
      {
        arr[i] = n[i];
      }
    }

  }
}

DynamicArray::DynamicArray(DynamicArray& dArray)
{
  capacity = dArray.capacity;
  resizeFactor = dArray.resizeFactor;
  size = dArray.size;
  arr = new int[capacity];
  for(int i = 0; i < dArray.size; i++)
  {
    arr[i] = dArray.arr[i];
  }

}

DynamicArray::~DynamicArray(void)
{
  if(arr != NULL) delete[] arr;
}

bool DynamicArray::resize(bool increase)
{
  if(increase)
  {
    capacity = capacity * (double)resizeFactor;
  }
  else
  {
    capacity = (int)((double)capacity / (double) resizeFactor);
  }
  int * temp = new int[capacity];
  for(int i = 0; i < size; i++)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = temp;
  return true;
}

int DynamicArray::current_size(void)
{
  return size;
}

int DynamicArray::current_capacity(void)
{
  return capacity;
}

bool DynamicArray::addItem(int n)
{
  arr[size] = n;
  size++;
  if(size == capacity - 1)
  {
    resize(true);
  }
  return true;
}

bool DynamicArray::removeItem(void)
{
  if (size > 0)
  {
    size--;
    arr[size] = 0;
    if(size < (double)capacity/0.25)
    {
      resize(false);
    }
  }
  else
  {
    return false;
  }
  return true;
}

void DynamicArray::print(void)
{
  cout << "[";
  for(int i = 0; i < size; i++)
  {
    if(i == size-1)
    {
      cout << arr[i] << "]\n";
      return;
    }
    cout << arr[i] << ", ";
  }
  return;
}

bool DynamicArray::removeItem(int n)
{
  int leftover;

  if ((size > 0) && (arr[n] != 0))
  {
    size--;
    arr[n] = 0;
    leftover = size - n;
    if(leftover > 0)
    {
      for(int j = 0; j < leftover; j++)
      {
        arr[n + j] = arr[n + j + 1];
      }
    }
    if(size < (double)capacity/0.25)
    {
      resize(false);
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool DynamicArray::find(int n)
{
  for(int i = 0; i < size; i++)
  {
    if(arr[i] == n)
    {
      return true;
    }
  }
  return false;

}

int DynamicArray::max(void)
{
  int max = arr[0];
  for(int i = 1; i < size; i++)
  {
    if(arr[i] > max) max = arr[i];
  }
  return max;
}

int DynamicArray::min(void)
{
  int min = arr[0];
  for(int i = 1; i < size; i++)
  {
    if(arr[i] < min) min = arr[i];
  }
  return min;
}

int DynamicArray::average(void)
{
  int sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return ((double) sum / size);
}

void DynamicArray::head(int n)
{
  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void DynamicArray::tail(int n)
{
  for(int i = size - 1; i >= size - n; i--)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

}

int DynamicArray::operator[](int i)
{
  if(i >= 0 && i < size) return arr[i];
  return 0;

}

void DynamicArray::operator+(int a)
{
  for(int i = 0; i < size; i++)
  {
    arr[i] += a;
  }
}

DynamicArray& DynamicArray::operator=(DynamicArray& dArray)
{
  if(arr != NULL) delete[] arr;
  capacity = dArray.capacity;
  resizeFactor = dArray.resizeFactor;
  size = dArray.size;
  arr = new int[capacity];
  for(int i = 0; i < dArray.size; i++)
  {
    arr[i] = dArray.arr[i];
  }
  return *this;
}

#include <cstdint>
#include <cwchar>
#include <iostream>
#include <string.h>

// This is not the exact repo you're looking for.

using namespace std;

void print_array(char array[], int len) {
  cout << "print_array" << endl;

  char* p = array;
  while(*p)
  {
    cout << *p << endl;
    p++;
  }

}

void print_array_ptr(char *array, int len) {
  cout << "print_array_ptr" << endl;

  char* p = array;

  while(*p)
  {
    cout << *p << endl;
    p++;
  }
}

__attribute__((visibility("default"))) void do_stuff(char *a, char *b) {
  
  for (int x = 0; x < 600000; x++)
    a[x] = 'A' + x;

  a[0] = 'A';
  a[4] = 'A';
  a[4 + 1] = 'A';
  a[4 - 1] = 'A';
  a[(4 + 1) - 3] = 'A';
  a[6] = 'A';

  cout << "a[0]: " << a[0] << endl;
  cout << "a[MAX]: " << a[4] << endl;
  cout << "a[6]: " << a[6] << endl;

  print_array(a, 4);
  print_array(a, 4 + 1);
  print_array_ptr(a, 4);
  print_array_ptr(a, 4 + 1);

  b[0] = 'A';
  b[1] = 'A';
  b[2] = 'A';
  b[3] = 'A';

  print_array(b, 4);
  print_array(b, 4 + 1);
  print_array_ptr(b, 4);
  print_array_ptr(b, 4 + 1);

  b[4] = 'A';

  print_array(b, 4);
  print_array(b, 4 + 1);
  print_array_ptr(b, 4);
  print_array_ptr(b, 4 + 1);
}

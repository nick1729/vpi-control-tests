#include <windows.h>

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void menu1();
void menu2();

int set_size_int() {
  int size;
  while (!(cin >> size) || (cin.peek() != '\n') || size < 0 || size > 255) {
    cin.clear();
    while (cin.get() != '\n') {
      cout << "Error! Wrong input (need integer from 1 to 255): ";
    }
  }
  return size;
}

int set_value_int() {
  int value;
  while (!(cin >> value) || value < -16384 || value > 16383) {
    cin.clear();
    while (cin.get() != '\n') {
      cout << "Error! Wrong input (need integer from -16384 to 16383):\n";
    }
  }
  return value;
}

void from_kb_d1(int* arr, int n, string arr_name) {
  cout << "\nEnter the array element " << arr_name << " [" << n << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    arr[i] = set_value_int();
  }
}

void from_kb_d2(int** arr, int n, int m, string arr_name) {
  cout << "\nEnter the array element " << arr_name << "[" << n << "," << m
       << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = set_value_int();
    }
  }
}

void from_rnd_d1(int* arr, int n, int a, int b, string arr_name) {
  for (int i = 0; i < n; ++i) {
    arr[i] = a + rand() % (b - a + 1);
  }
}

void from_rnd_d2(int** arr, int n, int m, int a, int b, string arr_name) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = a + rand() % (b - a + 1);
    }
  }
}

void create_d1(int* arr, int n, string arr_name) {
  char key;
  cout << "\nHOW TO CREATE AN ARRAY '" << arr_name << "'?\n";
  cout << "1. ENTER MANUALLY\n";
  cout << "2. AUTOMATICALLY (RANDOM ELEMENTS)\n";
  cout << "3. AUTOMATICALLY IN THE RANGE FROM -10 TO 10 (TASK #3)\n";
  cout << "OPTION: ";
  cin >> key;
  switch (key) {
    case '1': {
      from_kb_d1(arr, n, arr_name);
      break;
    }
    case '2': {
      int a, b;
      cout << "\nCreation in automatic mode!";
      cout << "\nEnter the boundaries of the interval (integer):";
      cout << "\nLower limit: a = ";
      a = set_value_int();
      cout << "Upper limit: b = ";
      b = set_value_int();
      from_rnd_d1(arr, n, a, b, arr_name);
      break;
    }
    case '3': {
      cout << "\nAutomatic creation from the range from -10 to 10:\n";
      from_rnd_d1(arr, n, -10, 10, arr_name);
      break;
    }
    default: {
      cout << "\nERROR! WRONG INPUT. EXIT...";
      break;
    }
  }
}

void create_d2(int** arr, int n, int m, string arr_name) {
  char key;
  cout << "\nHOW TO CREATE AN ARRAY '" << arr_name << "'?\n";
  cout << "1. ENTER MANUALLY\n";
  cout << "2. AUTOMATICALLY (RANDOM ELEMENTS)\n";
  cout << "OPTION: ";
  cin >> key;
  switch (key) {
    case '1': {
      from_kb_d2(arr, n, m, arr_name);
      break;
    }
    case '2': {
      int a, b;
      cout << "\nCreation in automatic mode!";
      cout << "\nEnter the boundaries of the interval (integer):";
      cout << "\nLower limit: a = ";
      a = set_value_int();
      cout << "Upper limit: b = ";
      b = set_value_int();
      from_rnd_d2(arr, n, m, a, b, arr_name);
      break;
    }
    default: {
      cout << "\nERROR! WRONG INPUT. EXIT...";
      break;
    }
  }
}

int** def_d2(int n, int m) {
  int** M2 = new int*[n];
  for (int i = 0; i < n; i++) {
    M2[i] = new int[m];
  }
  return M2;
}

void print_d1(int* arr, int n, string arr_name) {
  cout << "\nCreated array " << arr_name << "[" << n << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << "  ";
  }
  cout << "\n";
}

void print_d2(int** arr, int n, int m, string arr_name) {
  cout << "\nCreated array " << arr_name << "[" << n << "," << m << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << setw(6) << arr[i][j] << ' ';
    }
    cout << '\n';
  }
}

void delete_d1(int* arr, int n, string arr_name) {
  cout << "\nDeleting a one-dimensional array '" << arr_name << "'...";
  delete[] arr;
  cout << "\nArray '" << arr_name << "' has been deleted!";
}

void delete_d2(int** arr, int n, int m, string arr_name) {
  cout << "\nDeleting a two-dimensional array '" << arr_name << "'...";
  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  cout << "\nArray '" << arr_name << "' has been deleted!";
}

void t1_func1(int* arr, int n, string arr_name) {
  int z = 0, count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      z = z + arr[i];
      ++count;
    }
  }
  if (count != 0) {
    cout << "\nItem #1: the sum of negative elements in the array '" << arr_name
         << "' equal to: " << z << "\n";
  } else {
    cout << "\nItem #1: in the array '" << arr_name
         << "' negative elements are missing...\n";
  }
}

void t1_func2(int* arr, int n, string arr_name) {
  int min = arr[0], index = 0, count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < min) {
      min = arr[i];
      index = i;
    }
  }
  for (int i = 0; i < index; ++i)
    if (arr[i] % 2 == 0) {
      ++count;
    }
  cout << "\nItem #2: in the array '" << arr_name
       << "' the number of required elements is equal to: " << count << "\n";
}

void t2_func1(int** arr, int n, int m, string arr_name) {
  cout << "\nItem #1:\n";
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int count2 = 0;
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == 0) {
        ++count2;
      }
    }
    if (count2 == 0) {
      ++count;
    }
  }
  cout << "The number of rows of the array '" << arr_name
       << "' having no elements equal to zero: " << count << "\n";
}

void t2_func2(int** arr, int n, int m, string arr_name) {
  cout << "\nItem #2:";
  int max1 = arr[0][0];
  for (int i = 0; i < n; ++i) {
    int max2 = arr[i][0];
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] > max2) {
        max2 = arr[i][j];
      }
    }
    cout << "\nIn row #" << i << " of array '" << arr_name
         << "' the max element is equal to: " << max2;
    if (max1 < max2) {
      max1 = max2;
    }
  }
  cout << "\nThe maximum element among them is equal to: " << max1 << "\n";
}

void t3_func1(int* arr, int n) {
  int count = 0, index = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      ++count;
      index = i;
      break;
    }
  }
  if (count == 0) {
    cout << "\nThere are no negative elements in the array\n";
  } else {
    cout << "\nModified the elements of the array:\n\n";
    for (int i = 0; i < n; ++i) {
      if (i < index) {
        arr[i] = 0;
      } else {
        if (i == index) {
          arr[i] = 1;
        } else {
          arr[i] = abs(arr[i]);
        }
      }
      cout << arr[i] << "  ";
    }
    cout << "\n";
  }
}

void t4_func1(int** arr, int n, int m, string arr_name) {
  cout << "\nEven the elements of the array '" << arr_name
       << "' on the main diagonal: ";
  double z = 0, count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i][i] % 2 == 0) {
      cout << arr[i][i] << "  ";
      z = z + arr[i][i];
      ++count;
    }
  }
  cout << "\nThe arithmetic mean of these elements: " << z / count << "\n";
}

void t5_func1(string str) {
  string tmp;
  for (int i = 0; i < str.length(); i++) {
    tmp = tmp + str[i];
    if (str[i] == '.') {
      tmp = tmp + " ";
    }
  }
  cout << "\nOutput: \"" << tmp << "\"";
}

void task1() {
  system("cls");
  cout << "COMPLETING TASK #1\n\n";
  int n;
  string arr_name = "my_aws_array";
  cout << "Enter the size of the array " << arr_name << ": n = ";
  n = set_size_int();
  int* arr = new int[n];
  create_d1(arr, n, arr_name);
  print_d1(arr, n, arr_name);
  t1_func1(arr, n, arr_name);
  t1_func2(arr, n, arr_name);
  delete_d1(arr, n, arr_name);
  menu2();
}

void task2() {
  system("cls");
  cout << "COMPLETING TASK #2\n\n";
  int n, m;
  string arr_name = "NxM";
  cout << "Enter the number of rows: n = ";
  n = set_size_int();
  cout << "Enter the number of columns: m = ";
  m = set_size_int();
  int** arr = def_d2(n, m);
  create_d2(arr, n, m, arr_name);
  print_d2(arr, n, m, arr_name);
  t2_func1(arr, n, m, arr_name);
  t2_func2(arr, n, m, arr_name);
  delete_d2(arr, n, m, arr_name);
  menu2();
}

void task3() {
  system("cls");
  cout << "COMPLETING TASK #3\n";
  int n = 20;
  string arr_name = "C";
  int* arr = new int[n];
  create_d1(arr, n, arr_name);
  print_d1(arr, n, arr_name);
  t3_func1(arr, n);
  delete_d1(arr, n, arr_name);
  menu2();
}

void task4() {
  system("cls");
  cout << "COMPLETING TASK #4\n";
  int n = 5, m = 5;
  string arr_name = "A";
  int** arr = def_d2(n, m);
  create_d2(arr, n, m, arr_name);
  print_d2(arr, n, m, arr_name);
  t4_func1(arr, n, m, arr_name);
  delete_d2(arr, n, m, arr_name);
  menu2();
}

void task5() {
  system("cls");
  cout << "COMPLETING TASK #5\n\n";
  string str;
  cout << "Enter string: ";
  cin.ignore();
  getline(cin, str);
  cout << "\nIntput: \"" << str << "\"";
  t5_func1(str);
  menu2();
}

void menu1() {
  char key;
  system("cls");
  cout << "VAR-2.\n\n";
  cout << "MAIN MENU:\n\n";
  cout << "1. TASK #1\n";
  cout << "2. TASK #2\n";
  cout << "3. TASK #3\n";
  cout << "4. TASK #4\n";
  cout << "5. TASK #5\n";
  cout << "6. EXIT\n\n";
  cout << "OPTION: ";
  cin >> key;
  switch (key) {
    case '1': {
      task1();
      break;
    }
    case '2': {
      task2();
      break;
    }
    case '3': {
      task3();
      break;
    }
    case '4': {
      task4();
      break;
    }
    case '5': {
      task5();
      break;
    }
    case '6': {
      cout << "\nEXIT\n";
      break;
    }
    default: {
      cout << "\nERROR! WRONG INPUT. EXIT...\n";
      break;
    }
  }
}

void menu2() {
  char key;
  cout << "\n\nCOMPLETED!\n\n";
  cout << "1. MAIN MENU\n";
  cout << "2. EXIT\n";
  cout << "\nOPTION: ";
  cin >> key;
  switch (key) {
    case '1': {
      menu1();
      break;
    }
    case '2': {
      exit(0);
    }
    default: {
      cout << "\nERROR! WRONG INPUT. EXIT...\n";
      break;
    }
  }
}

int main() {
  srand(time(NULL));
  menu1();
  return 0;
}
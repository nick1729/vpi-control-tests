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
  cout << "\nEnter the array element " << arr_name << "[" << n << "]:\n\n";
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
  cout << "3. AUTOMATICALLY IN THE RANGE FROM -15 TO 25 (TASK #3)\n";
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
      cout << "\nAutomatic creation from the range from -15 to 25:\n";
      from_rnd_d1(arr, n, -15, 25, arr_name);
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

void t1_func1(int* arr, int n, int c, string arr_name) {
  int z = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > c) {
      ++z;
    }
  }
  cout << "\nItem #1: number of array '" << arr_name
       << "' elements, greater than the specified value 'C': " << z << "\n";
}

void t1_func2(int* arr1, int* arr2, int n, string arr_name) {
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (arr1[i] % 2 != 0) {
      arr2[j] = arr1[i];
      ++j;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (arr1[i] % 2 == 0) {
      arr2[j] = arr1[i];
      ++j;
    }
  }
  cout << "\nItem #2: Modified array '" << arr_name << "' (odds, evens): "
       << "\n\n";
  for (int i = 0; i < n; ++i) {
    cout << arr2[i] << "  ";
  }
  cout << "\n";
}

void t2_func1(int** arr, int n, int m) {
  int z = 0;
  for (int i = 0; i < n; ++i) {
    int s = 0;
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == 0) {
        ++s;
      }
    }
    if (s == 0) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] % 2 == 0) {
          ++z;
        }
      }
    }
  }
  cout << "\nItem #1: number of even elements in rows where there are no "
          "zeros: "
       << z << "\n";
}

void t2_func2(int** arr, int n, int m, string arr_name) {
  int e = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    int z = 0;
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] > 0) {
        ++z;
      }
      if (z > e) {
        e = z;
        r = i;
      }
    }
  }
  cout << "\nItem #2: in line #" << r << " array '" << arr_name
       << "' maximum number of positive elements: " << e << "\n";
}

double t3_subfunc1(int* arr, int n) {
  double z = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > 0) {
      z = z + arr[i];
      ++c;
    }
  }
  return (z / c);
}

void t3_func1(int* arr1, int* arr2, int n, int m) {
  cout << "\nArithmetic mean of positive elements:"
       << "\n";
  if (t3_subfunc1(arr1, n) > t3_subfunc1(arr2, m)) {
    cout << "In the array 'X', equal to " << t3_subfunc1(arr1, n)
         << ", greater than in the 'Y' array, equal to: " << t3_subfunc1(arr2, m)
         << "\n";
  } else {
    cout << "In the array 'X', equal to " << t3_subfunc1(arr1, n)
         << ", less than in the 'Y' array, equal to: " << t3_subfunc1(arr2, m)
         << "\n";
  }
}

void t4_func1(int** arr, int n, int m, string arr_name) {
  int z = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == 0) {
        z++;
      }
      if (arr[i][j] > 0 && arr[i][j] < 10) {
        arr[i][j] = arr[i][j] + 10;
        cout << "\nArray element " << arr_name << "[" << i << ", "
             << j << "] increased by 10 and equal to: " << arr[i][j];
      }
      if (arr[i][j] < 0) {
        arr[i][j] = abs(arr[i][j]);
        cout << "\nModule of an element in the array " << arr_name
             << "[" << i << ", " << j
             << "] equal to: " << arr[i][j];
      }
    }
  }
  cout << "\n\nThe number of elements equal to zero in the array '" << arr_name
       << "': " << z << "\n";
}

void t5_func1(string str) {
  string res = "";
  for (int i = 0; i < int(str.length()); i++) {
    if (isalpha(str[i])) {
      res += str[i];
    }
  }
  cout << "\nOutput: \"" << res << "\"";
}

void task1() {
  system("cls");
  cout << "COMPLETING TASK #1\n\n";
  int n, c;
  string arr_name = "my_aws_array";
  cout << "Enter the size of the array " << arr_name << ": n = ";
  n = set_size_int();
  int *arr1 = new int[n], *arr2 = new int[n];
  cout << "Enter a number: C = ";
  c = set_value_int();
  create_d1(arr1, n, arr_name);
  print_d1(arr1, n, arr_name);
  t1_func1(arr1, n, c, arr_name);
  t1_func2(arr1, arr2, n, arr_name);
  delete_d1(arr1, n, arr_name);
  delete_d1(arr2, n, "tmp");
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
  t2_func1(arr, n, m);
  t2_func2(arr, n, m, arr_name);
  delete_d2(arr, n, m, arr_name);
  menu2();
}

void task3() {
  system("cls");
  cout << "COMPLETING TASK #3\n";
  int n = 12, m = 10;
  string x_name = "X", y_name = "Y";
  int *x = new int[n], *y = new int[m];
  create_d1(x, n, x_name);
  create_d1(y, m, y_name);
  print_d1(x, n, x_name);
  print_d1(y, m, y_name);
  t3_func1(x, y, n, m);
  delete_d1(x, n, x_name);
  delete_d1(y, m, y_name);
  menu2();
}

void task4() {
  system("cls");
  cout << "COMPLETING TASK #4\n";
  int n = 3, m = 5;
  string c_name = "C";
  int** c = def_d2(n, m);
  create_d2(c, n, m, c_name);
  print_d2(c, n, m, c_name);
  t4_func1(c, n, m, c_name);
  delete_d2(c, n, m, c_name);
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
  cout << "VAR-1.\n\n";
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
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
  cout << "\nEnter the array elements " << arr_name << "[" << n << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    arr[i] = set_value_int();
  }
}

void from_kb_d2(int** arr, int n, int m, string arr_name) {
  cout << "\nEnter the array elements " << arr_name << "[" << n << "," << m
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
  cout << "3. AUTOMATICALLY IN THE RANGE FROM -15 TO 5 (TASK #3)\n";
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
      cout << "\nAutomatic creation from the range from -15 to 5...\n";
      from_rnd_d1(arr, n, -15, 5, arr_name);
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
  int z = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 != 0) {
      z = z + arr[i];
    }
  }
  cout << "\nItem #1: Sum of elements of array '" << arr_name
       << "' with odd numbers is: " << z << "\n";
}

void t1_func2(int* arr, int n, string arr_name) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      ++count;
    }
  }
  if (count < 2) {
    cout << "\nItem #2: in the array '" << arr_name
         << "' less than two negative elements...\n";
  } else {
    int min_index, max_index;
    for (int i = 0; i < n; ++i) {
      if (arr[i] < 0) {
        min_index = i;
        break;
      }
    }
    for (int i = n - 1; i > 0; --i) {
      if (arr[i] < 0) {
        max_index = i;
        break;
      }
    }
    int z = 1;
    for (int i = min_index + 1; i < max_index; ++i) {
      z = z * arr[i];
    }
    cout << "\nItem #2: Multiplying of elements with indexes from " << min_index
         << " to " << max_index << " of array " << arr_name
         << " equal to: " << z << "\n";
  }
}

void t2_func1(int** arr, int n, int m, string arr_name) {
  cout << "\nItem #1:\n";
  for (int j = 0; j < m; ++j) {
    int count = 0, s = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i][j] < 0) {
        ++count;
      }
    }
    if (count != 0) {
      for (int i = 0; i < n; ++i) {
        s = s + arr[i][j];
      }
      cout << "Sum of elements in the column #" << j << " of array '"
           << arr_name << "' equal to: " << s << "\n";
    } else {
      cout << "In column #" << j << " of array '" << arr_name
           << "' negative elements are missing...\n";
    }
  }
}

void t2_func2(int** arr, int n, int m, string arr_name) {
  int e = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    int s = 0, z = 0;
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
  cout << "\nItem #2:\nIn the line #" << r << " of array '" << arr_name
       << "' maximum number of positive elements: " << e << "\n";
}

int t3_subfunc1(int* arr, int n) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] % 2 == 0) {
      ++count;
    }
  }
  return count;
}

void t3_func1(int* arr1, int* arr2, int n, int m) {
  cout << "\nNumber of even elements:\n";
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
    for (int j = 1; j + 1 < m; ++j) {
      if (arr[i][j] > 0 && arr[i][j] <= 10) {
        arr[i][j] = arr[i][j] + 10;
        cout << "\nArray element " << arr_name << "[" << i << ", " << j + 1
             << "] increased by 10 and equal to " << arr[i][j];
      }
      if (arr[i][j] < 0) {
        arr[i][j] = abs(arr[i][j]);
        cout << "\nModule of a negative array element " << arr_name << "[" << i
             << ", " << j << "] equal to " << arr[i][j];
      }
      if (arr[i][j] == 0) {
        ++z;
      }
    }
  }
  cout << "\nNumber elements of array '" << arr_name << "' equal to zero: " << z
       << "\n";
}

void t5_func1(string& str) {
  size_t first = str.find_first_not_of(' '), last = str.find_last_not_of(' ');
  str = (first != string::npos) ? str.substr(first, last - first + 1) : "";
  cout << "\nOutput (1st version): \"" << str << "\"";
}

void t5_func2(string& str) {
  str.erase(0, str.find_first_not_of(' '));
  auto f = [](char c) { return c != ' '; };
  str.erase((std::find_if(str.rbegin(), str.rend(), f)).base(), str.end());
  cout << "\nOutput (2nd version): \"" << str << "\"";
}

void task1() {
  system("cls");
  cout << "COMPLETING TASK #1\n\n";
  int n;
  string arr_name = "my_aws_array";
  cout << "Enter the size of the array '" << arr_name << "': n = ";
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
  int n = 20, m = 20;
  string arr1_name = "X", arr2_name = "Y";
  int *arr1 = new int[n], *arr2 = new int[n];
  create_d1(arr1, n, arr1_name);
  create_d1(arr2, m, arr2_name);
  print_d1(arr1, n, arr1_name);
  print_d1(arr2, m, arr2_name);
  t3_func1(arr1, arr2, n, m);
  delete_d1(arr1, n, arr1_name);
  delete_d1(arr2, m, arr2_name);
  menu2();
}

void task4() {
  system("cls");
  cout << "COMPLETING TASK #4\n";
  int n = 3, m = 5;
  string arr_name = "C";
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
  t5_func2(str);
  menu2();
}

void menu1() {
  char key;
  system("cls");
  cout << "VAR-4.\n\n";
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
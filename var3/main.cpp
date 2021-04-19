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
  cout << "\nEnter the elements of array " << arr_name << "[" << n << "]:\n\n";
  for (int i = 0; i < n; ++i) {
    arr[i] = set_value_int();
  }
}

void from_kb_d2(int** arr, int n, int m, string arr_name) {
  cout << "\nEnter the elements of array " << arr_name << "[" << n << "," << m
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
  cout << "3. AUTOMATICALLY IN THE RANGE FROM -12 TO 20 (TASK #3)\n";
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
      cout << "\nAutomatic creation from the range from -12 to 20...\n";
      from_rnd_d1(arr, n, -12, 20, arr_name);
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
    if (arr[i] >= 5 && arr[i] <= 10) {
      ++z;
    }
  }
  cout << "\nItem #1: number of array elements '" << arr_name
       << "' between 5 and 10: " << z << '\n';
}

void t1_func2(int* arr, int n, string arr_name) {
  int min = arr[n - 1], s = 0, z = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < min) {
      min = arr[i];
      z = i;
    }
  }
  for (int i = z + 1; i < n; ++i) {
    s = s + arr[i];
  }
  if (min == arr[n - 1]) {
    cout << "\nItem #2: The last element of the array '" << arr_name
         << "' is minimal...\n";
  } else {
    cout << "\nItem #2: Sum of the required array elements '" << arr_name
         << "' (after the minimum): " << s << "\n";
  }
}

void t2_func1(int** arr, int n, int m, string arr_name) {
  int z = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] < 0) {
        if (z == 0) {
          s = i;
        }
        ++z;
      }
    }
  }
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[s][i] < arr[s][j]) {
        temp = arr[s][i];
        arr[s][i] = arr[s][j];
        arr[s][j] = temp;
      }
    }
  }
  cout << "\nItem #1: Row #" << s << " array '" << arr_name
       << "' after sorting is:\n";
  for (int i = 0; i < n; ++i) {
    cout << arr[s][i] << " ";
  }
}

void t2_func2(int** arr, int n, string arr_name) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s = s + abs(arr[i][i]);
  }
  cout << "\n\nItem #2: Sum of modules of the elements of the array '"
       << arr_name << "' on the main diagonal: " << s << "\n";
}

void t3_func1(int* ArrX1, int n) {
  int z = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    if (ArrX1[i] > 0 && ArrX1[i] % 2 == 0) {
      z = z + ArrX1[i];
      ++c;
    }
  }
  cout << "\nThe arithmetic mean of positive even elements: " << z / c << "\n";
}

void t4_func1(int** arr, int n, int m, string arr_name) {
  int z;
  for (int i = 0; i < n; ++i) {
    z = 0;
    for (int j = 1; j + 1 < m; ++j) {
      if (arr[i][j] < arr[i][j + 1] && arr[i][j] > arr[i][j - 1]) {
        cout << "\nArray element " << arr_name << "[" << i << "," << j
             << "] equal to " << arr[i][j] << " is the search term!";
        z++;
      }
    }
    cout << "\nThe number of elements to search for in a row '" << i
         << "': " << z;
  }
  cout << "\n";
}

void t5_func1(string str) {
  string tmp;
  for (int i = 0; i < str.length(); i++) {
    if (isupper(str[i]) && i != 0) {
      tmp = tmp + ". ";
    }
    tmp = tmp + str[i];
  }
  cout << "\nOutput: \"" << tmp << "\"";
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
  cout << "Enter the size of the square matrix: ";
  n = m = set_size_int();
  int** arr = def_d2(n, m);
  create_d2(arr, n, m, arr_name);
  print_d2(arr, n, m, arr_name);
  t2_func1(arr, n, m, arr_name);
  t2_func2(arr, n, arr_name);
  delete_d2(arr, n, m, arr_name);
  menu2();
}

void task3() {
  system("cls");
  cout << "COMPLETING TASK #3\n";
  int n = 23;
  string arr_name = "Y";
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
  int n = 3, m = 5;
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
  cout << "VAR-3.\n\n";
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
void insertionSortC(long long int array[], int size) {
  for (int step = 1; step < size; step++) {
    long long int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
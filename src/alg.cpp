// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count; }
int countPairs2(int *arr, int len, int value) { 
  int count = 0;
  int rbound = len - 1;
  while (rbound > 0) {
    if (arr[rbound] > value) {
      rbound--;
    } else {
      break;
    }
  }
    for (int i = 0; i < len; i++) {
      for (int j = rbound; j > i; j--) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  return count; }

int binarySearch_count(int *arr, int len, int value) { 
  int value_count = 0;
  int lbound = 0;
  int rbound = len - 1;
  while (lbound <= rbound) {
    int middle = lbound + (rbound - lbound) / 2;
    if (arr[middle] > value) {
      rbound = middle - 1;
    } else if (arr[middle] < value) {
      lbound = middle + 1;
    } else {
      value_count++;
      int left_value = middle - 1;
      int right_value = middle + 1;
      while (arr[left_value] == value && left_value > -1) {
        value_count++;
        left_value--;
      }
      while (arr[right_value] == value && right_value < len) {
        value_count++;
        right_value++;
      }
      break;
    }
  }
  return value_count;
}


int countPairs3(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    int *temp_arr = &arr[i];
    int temp_len = len - i;
    int find = value - arr[i];
    if (find < 0) {
      return count;
    }
    count += binarySearch_count(temp_arr, temp_len, find);
  }
  return count; }

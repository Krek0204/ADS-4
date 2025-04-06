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


int countPairs3(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    int lbound = i + 1;
    int rbound = len - 1;
    int find = value - arr[i];
    while (lbound <= rbound) {
      int middle = lbound + (rbound - lbound) / 2;
      if (arr[middle] > find) {
        rbound = middle - 1;
      } else if (arr[middle] < find) {
        lbound = middle + 1;
      } else {
        count++;
        int left_f = middle - 1;
        int right_f = middle + 1;
        while (left_f > i && arr[left_f] == find) {
          count++;
          left_f--;
        }
        while (right_f < len && arr[right_f] == find) {
          count++;
          right_f++;
        }
        break;
      }
    }
  }
  return count; }

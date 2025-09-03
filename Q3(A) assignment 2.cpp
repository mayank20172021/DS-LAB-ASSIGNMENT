def find_missing_linear(arr, n):
    for i in range(len(arr)):
        if arr[i] != i + 1:
            return i + 1
    return n

arr = [1, 2, 3, 5, 6] 
print(find_missing_linear(arr, 6))

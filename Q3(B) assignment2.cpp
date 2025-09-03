def find_missing_binary(arr, n):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == mid + 1:
            low = mid + 1
        else:
            high = mid - 1
    return low + 1

arr = [1, 2, 3, 5, 6]
print(find_missing_binary(arr, 6))

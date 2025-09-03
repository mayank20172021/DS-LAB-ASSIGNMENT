def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid  # Target found at index mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1  

sorted_array = [11, 12, 22, 25, 34, 64, 90]
target = 25
result = binary_search(sorted_array, target)
print(f"Binary Search: Element found at index {result}" if result != -1 else "Binary Search: El
ement not found.")

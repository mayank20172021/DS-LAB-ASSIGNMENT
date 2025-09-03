class UpperTriangularMatrix:
    def _init_(self, n):
        self.n = n
        self.arr = [0] * (n * (n + 1) // 2)

    def _index(self, i, j):
        return (j * (j + 1)) // 2 + i

    def set(self, i, j, val):
        if i <= j:
            self.arr[self._index(i, j)] = val

    def get(self, i, j):
        if i <= j:
            return self.arr[self._index(i, j)]
 
       return 0

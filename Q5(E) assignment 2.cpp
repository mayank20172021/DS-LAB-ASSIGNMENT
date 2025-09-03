class SymmetricMatrix:
    def _init_(self, n):
        self.n = n
        self.arr = [0] * (n * (n + 1) // 2)

    def _index(self, i, j):
        if i >= j:
            return (i * (i + 1)) // 2 + j
        else:
            return (j * (j + 1)) // 2 + i

    def set(self, i, j, val):
        self.arr[self._index(i, j)] = val

    def get(self, i, j):
        return self.arr[sel
f._index(i, j)]

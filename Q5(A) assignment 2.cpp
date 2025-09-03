class DiagonalMatrix:
    def _init_(self, n):
        self.n = n
        self.arr = [0] * n  # only diagonal elements

    def set(self, i, j, val):
        if i == j:
            self.arr[i] = val

    def get(self, i, j):
        if i == j:
            return self.arr[i]
    
    return 0

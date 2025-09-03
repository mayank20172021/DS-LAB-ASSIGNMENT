class TriDiagonalMatrix:
    def _init_(self, n):
        self.n = n
        self.lower = [0] * (n - 1)
        self.main = [0] * n
        self.upper = [0] * (n - 1)

    def set(self, i, j, val):
        if i - j == 1:
            self.lower[j] = val
        elif i == j:
            self.main[i] = val
        elif j - i == 1:
            self.upper[i] = val

    def get(self, i, j):
        if i - j == 1:
            return self.lower[j]
        elif i == j:
            return self.main[i]
        elif j - i == 1:
            return self.uppe
r[i]
        return 0

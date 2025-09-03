class SparseMatrix:
    def _init_(self, rows, cols, triplets):
        self.rows = rows
        self.cols = cols
        self.triplets = triplets  # list of (row, col, val)

    def transpose(self):
        transposed = [(c, r, v) for (r, c, v) in self.triplets]
        return SparseMatrix(self.cols, self.rows, transposed)

    def add(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("Dimension mismatch")

        result_dict = {}
        for r, c, v in self.triplets:
            result_dict[(r, c)] = v
        for r, c, v in other.triplets:
            if (r, c) in result_dict:
                result_dict[(r, c)] += v
            else:
                result_dict[(r, c)] = v

        result_triplets = [(r, c, v) for (r, c), v in result_dict.items() if v != 0]
        return SparseMatrix(self.rows, self.cols, result_triplets)

    def multiply(self, other):
        if self.cols != other.rows:
            raise ValueError("Incompatible matrices")

        result_dict = {}
        # Convert other's triplets to a dictionary for quick access by row
        other_dict = {}
        for r, c, v in other.triplets:
            other_dict.setdefault(r, []).append((c, v))

        for r1, c1, v1 in self.triplets:
            if c1 in other_dict:
                for c2, v2 in other_dict[c1]:
                    result_dict[(r1, c2)] = result_dict.get((r1, c2), 0) + v1 * v2

        result_triplets = [(r, c, v) for (r, c), v in result_dict.items() if v != 0]
        return SparseMatr
ix(self.rows, other.cols, result_triplets)

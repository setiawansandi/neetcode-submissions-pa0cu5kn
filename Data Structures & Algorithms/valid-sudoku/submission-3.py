class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        col_seen = [set() for _ in range(9)]
        square_seen = [set() for _ in range(9)]

        for row in range(9):
            row_seen = set()

            for col in range(9):
                val = board[row][col]
                square_idx = (row // 3) * 3 + (col // 3)

                if val == ".":
                    continue
                
                if val not in row_seen:
                    row_seen.add(val)
                else:
                    return False
                
                if val not in col_seen[col]:
                    col_seen[col].add(val)
                else:
                    return False
                
                if val not in square_seen[square_idx]:
                    square_seen[square_idx].add(val)
                else:
                    return False

        print(col_seen)
        return True
        
                
                

        



                

class Solution(object):
    def numIslands(self, grid):
        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0

        def dfs(row, col): 
            if not (0 <= row < rows and 0 <= col < cols): return
            if grid[row][col] == '0': return
            if (row, col) in visited: return
            visited.add((row, col))
            dfs(row - 1, col)
            dfs(row + 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)
        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == '1' and (row, col) not in visited:
                    islands += 1
                    dfs(row, col)
        return islands